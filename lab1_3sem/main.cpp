#include <iostream>
#include <random>
#include <array>
#include <chrono>
#include <algorithm>

#include "Sequences.h"
#include "Sort.h"

class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;
    std::chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now()) {}

    void reset() {
        m_beg = clock_t::now();
    }

    double elapsed() const {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

int cmp(const int& x,const int& y) {
    if (x > y) return 1;
    else if (x == y) return 0;
    else return -1;
}

int main() {
    unsigned int N{10000000};
    std::default_random_engine gen(13);
    std::uniform_int_distribution<int> distr(-100000, 100000);

    ArraySequence<int> a{N,0};
    for (int i = 0; i < N; ++i) {
        a.set(i, distr(gen));
    }

//    ListSequence<int> b;
//    for (int i = 0; i < N; ++i) {
//        b.push_back(distr(gen));
//    }

    Timer t;
    try {
        quick_sort_array(a, 0, a.size(), cmp);
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }
    std::cout << "ARRAY Time taken: " << t.elapsed() << " sec" << '\n';
    check_sorted_array(a, cmp);

//    Timer t2;
//    try {
//        quick_sort_list(b, b.get_first_node(), b.get_last_node(), cmp);
//    } catch (const std::runtime_error &msg) {
//        std::cerr << msg.what();
//    }
//    std::cout << "LIST Time taken: " << t2.elapsed() << " sec" << '\n';
//    check_sorted_list(b, cmp);
}