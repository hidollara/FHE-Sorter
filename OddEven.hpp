#pragma once

#include "Sorter.hpp"
#include <iostream>

template <class T>
class OddEvenSorter : public Sorter<T> {
private:
    void merge(v_itr<T> first, v_itr<T> last, int r, bool asc) const;
public:
    OddEvenSorter(const Comparator<T> *c) : Sorter<T>(c) {};
    void sort(v_itr<T> first, v_itr<T> last, bool asc) const;
};

template <class T>
void OddEvenSorter<T>::merge(v_itr<T> first, v_itr<T> last, int q, bool asc) const{
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
void OddEvenSorter<T>::sort(v_itr<T> first, v_itr<T> last, bool asc) const {
    if (!need_sort<T>(first, last)) return;

    auto mid = first + ((last - first) / 2);
    this->sort(first, mid, asc);
    this->sort(mid, last, asc);
    this->merge(first, last, 1, asc);
}
