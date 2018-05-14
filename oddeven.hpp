#pragma once

#include "sorter.hpp"
#include <iostream>

template <class T>
class OddEvenSorter : public Sorter<T> {
private:
    void merge(
            typename std::vector<T>::iterator begin,
            typename std::vector<T>::iterator end,
            int r,
            bool asc);
public:
    OddEvenSorter(Comparator<T> *c) : Sorter<T>(c) {};
    void sort(
            typename std::vector<T>::iterator begin,
            typename std::vector<T>::iterator end,
            bool asc);
};

template <class T>
void OddEvenSorter<T>::merge(
        typename std::vector<T>::iterator begin,
        typename std::vector<T>::iterator end,
        int r,
        bool asc) {
    int n = end - begin, m = r * 2;
    if (m < n) {
        merge(begin, end, m, asc);
        merge(begin + r, end, m, asc);

        for (auto itr = begin + r; itr + r < end; itr += m) {
            auto p = this->compare(*itr, *(itr + r));
            if (asc) {
                *itr = p.first;
                *(itr + r) = p.second;
            } else {
                *itr = p.second;
                *(itr + r) = p.first;
            }
        }
    } else {
        auto p = this->compare(*begin, *(begin + r));
        if (asc) {
            *begin = p.first;
            *(begin + r) = p.second;
        } else {
            *begin = p.second;
            *(begin + r) = p.first;
        }
    }
}

template <class T>
void OddEvenSorter<T>::sort(
        typename std::vector<T>::iterator begin,
        typename std::vector<T>::iterator end,
        bool asc) {
    int n = end - begin;
    if (n > 1) {
        int m = n / 2;
        this->sort(begin, begin + m, asc);
        this->sort(begin + m, end, asc);
        this->merge(begin, end, 1, asc);
    }
}
