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
    try {
        unsigned int N{10000};
        std::default_random_engine gen(13);
        std::uniform_int_distribution<int> distr(-10, 10);

        ArraySequence<int> a{N,0};
        for (int i = 0; i < N; ++i) {
            a.set(i, distr(gen));
        }
        //a.print();
        auto it1 = a.begin();
        auto it2 = a.last();
        Timer t;
    try {
        quick_sort(it1, it2, cmp);
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }
    std::cout << "Time taken: " << t.elapsed() << " sec" << '\n';
    auto it11 = a.begin();
    auto it22 = a.last();
    check_sorted(it11, it22, cmp);
    //a.print();
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }
}