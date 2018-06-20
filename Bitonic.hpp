#pragma once

#include "Sorter.hpp"
#include <iostream>

template <class T>
class BitonicSorter : public Sorter<T> {
private:
    void merge(v_itr<T> first, v_itr<T> last, bool asc) const;
public:
    BitonicSorter(const Comparator<T> *c) : Sorter<T>(c) {};
    void sort(v_itr<T> first, v_itr<T> last, bool asc) const;
};

template <class T>
void BitonicSorter<T>::merge(v_itr<T> first, v_itr<T> last, bool asc) const {
    if (!need_sort<T>(first, last)) return;

    int k = 1; while ((k << 1) < last - first) k <<= 1;

    for (auto itr = first; itr + k < last; itr++) {
        this->compare(itr, itr + k, asc);
    }
    this->merge(first, first + k, asc);
    this->merge(first + k, last, asc);

    return;
}

template <class T>
void BitonicSorter<T>::sort(v_itr<T> first, v_itr<T> last, bool asc) const {
    if (!need_sort<T>(first, last)) return;

    auto mid = first + ((last - first) / 2);
    this->sort(first, mid, !asc);
    this->sort(mid, last, asc);
    this->merge(first, last, asc);

    return;
}
