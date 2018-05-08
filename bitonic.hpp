#pragma once

#include "sorter.hpp"
#include <iostream>

template <class T>
class BitonicSorter : public Sorter<T> {
private:
    void merge(
            typename std::vector<T>::iterator begin,
            typename std::vector<T>::iterator end,
            bool asc);
public:
    BitonicSorter(Comparator<T> *c) : Sorter<T>(c) {};
    void sort(
            typename std::vector<T>::iterator begin,
            typename std::vector<T>::iterator end,
            bool asc);
};

template <class T>
void BitonicSorter<T>::merge(
        typename std::vector<T>::iterator begin,
        typename std::vector<T>::iterator end,
        bool asc) {
    if (end - begin <= 1) return;

    int n = end - begin, k = 1;
    while ((k << 1) < n) k <<= 1;

    for (auto itr = begin; itr + k != end; itr++) {
        auto p = this->compare(*itr, *(itr + k));
        if (asc) {
            *itr = p.first;
            *(itr + k) = p.second;
        } else {
            *itr = p.second;
            *(itr + k) = p.first;
        }
    }
    this->merge(begin, begin + k, asc);
    this->merge(begin + k, end, asc);

    return;
}

template <class T>
void BitonicSorter<T>::sort(
        typename std::vector<T>::iterator begin,
        typename std::vector<T>::iterator end,
        bool asc) {
    if (end - begin <= 1) return;

    int n = (end - begin) / 2;

    this->sort(begin, begin + n, !asc);
    this->sort(begin + n, end, asc);
    this->merge(begin, end, asc);

    return;
}
