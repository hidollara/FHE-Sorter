#pragma once

#include "sorter.hpp"
#include <iostream>

template <class T>
class OddEvenSorter : public Sorter<T> {
private:
    void merge(
            typename std::vector<T>::iterator first,
            typename std::vector<T>::iterator last,
            int r,
            bool asc);
public:
    OddEvenSorter(Comparator<T> *c) : Sorter<T>(c) {};
    void sort(
            typename std::vector<T>::iterator first,
            typename std::vector<T>::iterator last,
            bool asc);
};

template <class T>
void OddEvenSorter<T>::merge(
        typename std::vector<T>::iterator first,
        typename std::vector<T>::iterator last,
        int q,
        bool asc) {
    int len = last - first, n = q * 2;
    if (n < len) {
        merge(first, last, n, asc);
        merge(first + q, last, n, asc);

        for (auto itr = first + q; itr + q < last; itr += n) {
            this->compare(itr, itr + q, asc);
        }
    } else {
        this->compare(first, first + q, asc);
    }
}

template <class T>
void OddEvenSorter<T>::sort(
        typename std::vector<T>::iterator first,
        typename std::vector<T>::iterator last,
        bool asc) {
    if (!need_sort<T>(first, last)) return;

    auto mid = first + ((last - first) / 2);
    this->sort(first, mid, asc);
    this->sort(mid, last, asc);
    this->merge(first, last, 1, asc);
}
