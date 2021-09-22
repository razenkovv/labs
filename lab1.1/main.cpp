#include <iostream>
#include "Sequences.h"
#include <functional>

bool cmp(int a, int b) {
    if (a > b) return true;
    else return false;
}

template<typename T>
void quick_sort(Sequence<T>& seq, std::function <bool(const T&, const T&)> cmp) {
    std::cout << "BEGIN:\n";
    std::cout << seq.print();
}


int main() {
    ArraySequence<int> a{5, 0};
    a.set(2,3);
    a.set(4,6);
    quick_sort(a, cmp);
    return 0;
}
