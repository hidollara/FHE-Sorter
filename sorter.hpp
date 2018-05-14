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
    Sorter(Comparator<T> *c) : comparator(c) {};
    void compare(
            typename std::vector<T>::iterator x,
            typename std::vector<T>::iterator y,
            bool asc = true);
    virtual void sort(
            typename std::vector<T>::iterator first,
            typename std::vector<T>::iterator last,
            bool asc = true) = 0;
};

template <class T>
void Sorter<T>::compare(
        typename std::vector<T>::iterator x,
        typename std::vector<T>::iterator y,
        bool asc) {
    auto p = this->comparator->compare(*x, *y);

    if (asc) {
        *x = p.first;
        *y = p.second;
    } else {
        *x = p.second;
        *y = p.first;
    }
}

template <class T>
bool need_sort(
        typename std::vector<T>::iterator first,
        typename std::vector<T>::iterator last) {
    return last - first >= 2;
}
