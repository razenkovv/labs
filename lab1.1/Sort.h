#pragma once

#include <functional>

#include "Sequences.h"

template<typename T>
void quick_sort(Sequence<T>& seq, std::function <bool(const T&, const T&)> cmp) {
    std::cout << "BEGIN:\n";
    std::cout << seq.print();
}
