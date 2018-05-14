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
        int r,
        bool asc) {
    int n = last - first, m = r * 2;
    if (m < n) {
        merge(first, last, m, asc);
        merge(first + r, last, m, asc);

        for (auto itr = first + r; itr + r < last; itr += m) {
            this->compare(itr, itr + r, asc);
        }
    } else {
        this->compare(first, first + r);
    }
}

template <class T>
void OddEvenSorter<T>::sort(
        typename std::vector<T>::iterator first,
        typename std::vector<T>::iterator last,
        bool asc) {
    int n = last - first;
    if (n > 1) {
        int m = n / 2;
        this->sort(first, first + m, asc);
        this->sort(first + m, last, asc);
        this->merge(first, last, 1, asc);
    }
}
