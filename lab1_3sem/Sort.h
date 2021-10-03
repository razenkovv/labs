#pragma once

#include "Sequences.h"
#include "Iterator.h"

template <typename T>
void swap(T& x, T& y);

template <typename T>
void insert_sort(Sequence<T>& seq, int start, int n, int (*cmp) (const T&, const T&));

template <typename T>
void quick_sort_array(ArraySequence<T>& seq, int start, int n, int (*cmp) (const T&, const T&));

template <typename T>
void merge_sort_array(ArraySequence<T>& seq, int start, int n, int (*cmp) (const T&, const T&));

template <typename T>
void quick_sort_list(ListSequence<T>& seq, typename List<T>::Node* start, typename List<T>::Node* end, int (*cmp) (const T&, const T&));

template <typename T>
void check_sorted_array(ArraySequence<T>& seq, int (*cmp) (const T&, const T&));

template <typename T>
void check_sorted_list(ListSequence<T>& seq, int (*cmp) (const T&, const T&));


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
void quick_sort(Iterator<T>& b, Iterator<T>& e, int (*cmp) (const T&, const T&)) {
    if ((e - b) <= 1) {
        if ((e - b) <= 0) return;
        else {
            if (cmp(*b, *e) > 0) swap(*b, *e);
            return;
        }
    }
    auto begin = b.copy();
    auto end = e.copy();
    T pivot_value = **(b + (e - b)/2);
    int pivot(b.get_index() + (e - b)/2);
    do {
        while (cmp(*b, pivot_value) < 0)
            ++b;
        while (cmp(*e, pivot_value) > 0)
            --e;
        if (b < e) {
            swap(*b, *e);
            if (pivot == b.get_index())
                pivot = e.get_index();
            else if (pivot == e.get_index())
                pivot = b.get_index();
            ++b;
            --e;
        } else if (b == e) {
            ++b;
            --e;
            break;
        }
    } while (b <= e);
    quick_sort(*begin, e, cmp);
    quick_sort(++e, *end, cmp);
}

template <typename T>
void merge_sort_array(ArraySequence<T>& seq, int start, int n, int (*cmp) (const T&, const T&)) {

}

template <typename T>
bool check_sorted(Iterator<T>& b, Iterator<T>& e, int (*cmp) (const T&, const T&)) {
    bool check = true;
    auto c = b.copy();
    ++*c;
    for (b; b != e; ++b, ++*c) {
        if (cmp(*b, **c) > 0) {
            check = false;
            break;
        }
    }
    if (!check)
        std::cout << "Check_sorted: ERROR.\n";
    else
        std::cout << "Check_sorted: OK.\n";
    return check;
}

template <typename T>
void quick_sort_list(ListSequence<T>& seq, typename List<T>::Node* start, typename List<T>::Node* end, int (*cmp) (const T&, const T&)) {
    if (start == end)
        return;
    typename List<T>::Node* b = start;
    typename List<T>::Node* pivot = end;
    while (b != pivot) {
        if (cmp(b->value, pivot->value) > 0) {
            if (b == start)
                start = b->next;
            typename List<T>::Node *tmp = b;
            b = b->next;
            seq.insert_after(tmp, end);
            end = tmp;
        } else {
            b = b->next;
        }
    }

    if (b->prev)
        quick_sort_list(seq, start, b->prev, cmp);
    if (b->next)
        quick_sort_list(seq, b, end, cmp);
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