#pragma once

#include <vector>
#include <utility>

template <class T>
using v_itr = typename std::vector<T>::iterator;

template <class T>
class Comparator {
public:
    virtual ~Comparator() {};
    virtual std::pair<T, T> compare(const T &x, const T &y) const = 0;
};

template <class T>
class Sorter {
    const Comparator<T> *comparator;
public:
    virtual ~Sorter() {};
    Sorter(const Comparator<T> *c) : comparator(c) {};
    void compare(v_itr<T> x, v_itr<T> y, bool asc = true) const;
    virtual void sort(v_itr<T> first, v_itr<T> last, bool asc = true) const = 0;
};

template <class T>
void Sorter<T>::compare(v_itr<T> x, v_itr<T> y, bool asc) const {
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
bool need_sort(const v_itr<T> first, const v_itr<T> last) {
    return last - first >= 2;
}
