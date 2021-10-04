#include <iostream>
#include<fstream>
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
//    std::string Path2 = R"(C:\Users\Ivan\programming\labs\lab1_3sem\Mergesort.txt)";
//    std::ofstream fout(Path2);
//    for (int i = 10000; i <= 100000; i+=10000) {
//        fout <<  i << ", ";
//    }
//    fout << "\n";
//    int k = 1;
//    for (unsigned int n = 10000; n <= 100000; n+=10000) {
//        double T(0);
//        for (int i = 0; i < k; ++i) {
//            std::default_random_engine gen(n + i);
//            std::uniform_int_distribution<int> distr(-100000, 100000);
//            ArraySequence<int> a{n,0};
//            for (int & it : a) {
//                it = distr(gen);
//            }
//            auto it1 = a.begin();
//            auto it2 = a.last();
//            Timer t;
//            merge_sort(it1, it2, cmp);
//            T += t.elapsed();
//        }
//        T = T/k;
//        fout << T << ", ";
//    }
    unsigned int n = 20;
    std::default_random_engine gen(100);
    std::uniform_int_distribution<int> distr(0, 10);
    ListSequence<int> a{n,0};
    for (int & it : a) {
        it = distr(gen);
    }
    auto it1 = a.begin();
    auto it2 = a.last();
    a.print();
    merge_sort(it1, it2, cmp);
    a.print();
    auto it11 = a.begin();
    auto it22 = a.last();
    check_sorted(it11, it22, cmp);
}