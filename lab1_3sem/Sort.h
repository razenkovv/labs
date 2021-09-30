#pragma once

#include "Sequences.h"

template <typename T>
void swap(T& x, T& y);

template <typename T>
void insert_sort(Sequence<T>& seq, int start, int n, int (*cmp) (const T&, const T&));

template <typename T>
void quick_sort_array(ArraySequence<T>& seq, int start, int n, int (*cmp) (const T&, const T&));

template <typename T>
void quick_sort_list(typename List<T>::Node* start, typename List<T>::Node* end, int (*cmp) (const T&, const T&));

template <typename T>
void check_sorted(ArraySequence<T>& seq, int start, int n, int (*cmp) (const T&, const T&));


template<typename T>
void swap(T& x, T& y)
{
    T tmp { std::move(x) };
    x = std::move(y);
    y = std::move(tmp);
}

template <typename T>
void insert_sort(Sequence<T>& seq, int start, int n, int (*cmp) (const T&, const T&)) {
    if ((start + n > seq.size()) || (start < 0) || (n < 0))
        throw std::runtime_error("\nInsert_sort Message: index out of range\n");
    for (int i = start; i < start + n; ++i) {
        int j = i - 1;
        while ((j >= 0) && (cmp(seq.get(j), seq.get(j+1))) > 0) {
            swap(seq.get(j), seq.get(j+1));
            --j;
        }
    }
}

template <typename T>
void quick_sort_array(ArraySequence<T>& seq, int start, int n, int (*cmp) (const T&, const T&)) {
    if (n <= 1)
        return;
    int i{start}, j{start + n - 1};
    int pivot{start + n / 2};
    do {
        while (cmp(seq.get(i), seq.get(pivot)) < 0)
            ++i;
        while (cmp(seq.get(j), seq.get(pivot)) > 0)
            --j;
        if (i < j) {
            swap(seq.get(i), seq.get(j));
            if (pivot == i)
                pivot = j;
            else if (pivot == j)
                pivot = i;
            ++i;
            --j;
        } else if (i == j) {
            ++i;
            --j;
            break;
        }
    } while (i <= j);
    int len = j - start + 1;
    int new_start = start + len;
    quick_sort_array(seq, start, len, cmp);
    quick_sort_array(seq, new_start, n - len, cmp);
}

template <typename T>
void quick_sort_list(typename List<T>::Node* start, typename List<T>::Node* end, int (*cmp) (const T&, const T&)) {

}

template <typename T>
void check_sorted(ArraySequence<T>& seq, int start, int n, int (*cmp) (const T&, const T&)) {
    bool check = true;
    for (int i = 0; i < (n-1); ++i) {
        if (cmp(seq.get(i), seq.get(i+1)) > 0) {
            check = false;
            break;
        }
    }
    if (!check)
        std::cout << "Check_sorted: ERROR.\n";
    else
        std::cout << "Check_sorted: OK.\n";
}