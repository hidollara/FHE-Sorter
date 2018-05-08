#pragma once

#include <vector>
#include <utility>

template <class T>
class Comparator {
public:
    virtual std::pair<T, T> compare(T x, T y) = 0;
};

template <class T>
class Sorter {
    Comparator<T> *comparator;
public:
    std::pair<T, T> compare(T x, T y);
    Sorter(Comparator<T> *c) : comparator(c) {};
    virtual void sort(
            typename std::vector<T>::iterator begin,
            typename std::vector<T>::iterator end,
            bool asc = true) = 0;
};

template <class T>
std::pair<T, T> Sorter<T>::compare(T x, T y) {
    return this->comparator->compare(x, y);
}