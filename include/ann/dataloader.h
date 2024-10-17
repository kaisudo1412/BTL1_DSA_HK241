/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/*
 * File:   dataloader.h
 * Author: ltsach
 *
 * Created on September 2, 2024, 4:01 PM
 */

#ifndef DATALOADER_H
#define DATALOADER_H
#include "ann/xtensor_lib.h"
#include "ann/dataset.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

using namespace std;

template <typename DType, typename LType>
class DataLoader
{
private:
    Dataset<DType, LType> *ptr_dataset;
    int batch_size;
    int m_seed;
    bool shuffle;
    bool drop_last;
    size_t dataset_size;
    vector<size_t> indices;

    void shuffle_indices()
    {
        if (shuffle && m_seed >= 0)
        {
            xt::random::seed(m_seed);
        }

        if (shuffle)
        {
            auto xt_indices = xt::adapt(indices);
            xt::random::shuffle(xt_indices);
            std::copy(xt_indices.begin(), xt_indices.end(), indices.begin());
        }
    }
    /*DONE: add more member variables to support the iteration*/

public:
    DataLoader(Dataset<DType, LType> *ptr_dataset,
               int batch_size,
               bool shuffle = true,
               bool drop_last = false,
               int seed = -1)
        : ptr_dataset(ptr_dataset),
          batch_size(batch_size),
          shuffle(shuffle),
          drop_last(drop_last),
          dataset_size(ptr_dataset->len()),
          m_seed(seed)
    {
        /*DONE: Add your code to do the initialization */
        if (batch_size <= 0)
        {
            throw invalid_argument("Batch size must be greater than 0.");
        }

        indices.resize(dataset_size);
        iota(indices.begin(), indices.end(), 0);
    }

    virtual ~DataLoader() {}

    /////////////////////////////////////////////////////////////////////////
    // The section for supporting the iteration and for-each to DataLoader //
    /// START: Section                                                     //
    /////////////////////////////////////////////////////////////////////////

    /*DONE: Add your code here to support iteration on batch*/
    class Iterator
    {
    public:
        Iterator(DataLoader &loader, size_t index)
            : loader(loader), index(index)
        {
            if (loader.shuffle)
            {
                loader.shuffle_indices();
            }
        }

        bool operator!=(const Iterator &other) const
        {
            return index != other.index;
        }

        Iterator &operator++()
        {
            index += loader.batch_size;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator temp = *this;
            index += loader.batch_size;
            return temp;
        }

        DataLabel<DType, LType> operator*()
        {
            size_t end_index = std::min(index + loader.batch_size, loader.dataset_size);

            xt::xarray<DType> batch_data = loader.ptr_dataset->getitem(loader.indices[index]).getData();
            xt::xarray<LType> batch_labels = loader.ptr_dataset->getitem(loader.indices[index]).getLabel();

            for (size_t i = index + 1; i < end_index; ++i)
            {
                auto item = loader.ptr_dataset->getitem(loader.indices[i]);
                batch_data = xt::concatenate(xt::xtuple(batch_data, item.getData()), 0);
                batch_labels = xt::concatenate(xt::xtuple(batch_labels, item.getLabel()), 0);
            }

            return DataLabel<DType, LType>(batch_data, batch_labels);
        }

    private:
        DataLoader &loader;
        size_t index;
    };

    Iterator begin()
    {
        return Iterator(*this, 0);
    }

    Iterator end()
    {
        size_t end_index = drop_last ? (dataset_size / batch_size) * batch_size : dataset_size;
        return Iterator(*this, end_index);
    }

    /////////////////////////////////////////////////////////////////////////
    // The section for supporting the iteration and for-each to DataLoader //
    /// END: Section                                                       //
    /////////////////////////////////////////////////////////////////////////
};

#endif /* DATALOADER_H */
