#include <iostream>
#include<fstream>
#include <iomanip>
#include <string>
#include <random>
#include <ctime>

#include "AVLTree.h"

bool where_test(int x) {
    if (x > 0)
        return true;
    else
        return false;
}

int map_test(int x) {
    return x*x;
}

int reduce_test(int x, int y) {
    return x+y;
}

//time_test
//    std::default_random_engine gen(time(nullptr));
//    std::uniform_int_distribution<int> distr(0, 1000000);
//    for (int size = 70000; size <= 70000; size+=10000) {
//        int amount = 1000;
//        double all_time{ 0 };
//        int max_height{ 0 };
//        for (int j = 0; j < amount; ++j) {
//            double start_time = clock();
//            auto* test1 = new AVLTree<int>;
//            for (int i = 0; i < size; ++i) {
//                test1->insert(distr(gen));
//            }
//            double end_time = clock();
//            double search_time = end_time - start_time;
//            all_time += search_time;
//            if (test1->height() > max_height)
//                max_height = test1->height();
//        }
//        std::cout << "Size: " << size << " ";
//        std::cout << "Time: " << all_time / amount << " ";
//        std::cout << "Height: " << max_height << "\n";
//    }

int main() {
    AVLTree<int> a{};
    std::ifstream fin;
    std::string Path1 = R"(C:\Users\Ivan\programming\labs\lab3\AVLTreeTest.txt)";
    fin.open(Path1);
    std::string Path2 = R"(C:\Users\Ivan\programming\labs\lab3\AVLTreeLog.txt)";
    std::ofstream fout(Path2);
    try {
        if (!fout)
            throw std::runtime_error("\nVectorLog.txt: File wasn't opened\n");
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        if (!fin.is_open())
            throw std::runtime_error("\nVectorTest.txt: File wasn't opened\n");
        std::string data{};
        fin >> data;
        data.clear();
        int n{};
        fin >> n;
        for (int i = 0; i < n; ++i) {
            int x{};
            fin >> x;
            a.insert(x);
        }
        if (a.check_balance()) {
            fout << "Insert balance OK.\n";
        } else {
            fout << "Insert balance ERROR.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string data{};
        fin >> data;
        data.clear();
        int n{};
        fin >> n;
        for (int i = 0; i < n; ++i) {
            int x{};
            fin >> x;
            data += std::to_string(x);
        }
        if (a.tree_to_string() == data) {
            fout << "Tree build OK.\n";
        } else {
            fout << "Tree build ERROR.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string data{};
        fin >> data;
        data.clear();
        int x{};
        fin >> x;
        if (a.contain(x)) {
            fout << "Contain OK.\n";
        } else {
            fout << "Contain ERROR.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string data{};
        fin >> data;
        data.clear();
        int n{};
        fin >> n;
        for (int i = 0; i < n; ++i) {
            int x{};
            fin >> x;
            data += std::to_string(x);
        }
        auto b = a.map(map_test);
        if (b->tree_to_string() == data) {
            fout << "Map OK.\n";
        } else {
            fout << "Map ERROR.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string data{};
        fin >> data;
        data.clear();
        int n{};
        fin >> n;
        for (int i = 0; i < n; ++i) {
            int x{};
            fin >> x;
            data += std::to_string(x);
        }
        auto b = a.where(where_test);
        if (b->tree_to_string() == data) {
            fout << "Where OK.\n";
        } else {
            fout << "Where ERROR.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string data{};
        fin >> data;
        data.clear();
        int x{};
        fin >> x;
        auto b = a.reduce(reduce_test);
        if (b == x) {
            fout << "Reduce OK.\n";
        } else {
            fout << "Reduce ERROR.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string data{};
        fin >> data;
        data.clear();
        int y{};
        fin >> y;
        int n{};
        fin >> n;
        for (int i = 0; i < n; ++i) {
            int x{};
            fin >> x;
            data += std::to_string(x);
        }
        std::vector<int> heights{n,0};
        for (int i = 0; i < n; ++i) {
            int x{};
            fin >> x;
            heights.push_back(x);
        }
        auto b = a.get_subtree(y);
        std::vector<int> heights2{n, 0};
        b->get_heights(heights2);
        bool k{true};
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != heights2[i])
                k = false;
        }
        if ((b->tree_to_string() == data) && k) {
            fout << "Get_subtree OK.\n";
        } else {
            fout << "Get_subtree ERROR.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string data{};
        fin >> data;
        data.clear();
        AVLTree<int> b;
        int n{};
        fin >> n;
        for (int i = 0; i < n; ++i) {
            int x{};
            fin >> x;
            b.insert(x);
        }
        if (a.is_subtree(b)) {
            fout << "Is_subtree OK.\n";
        } else {
            fout << "Is_subtree ERROR.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string data{};
        fin >> data;
        data.clear();
        int y{};
        fin >> y;
        a.remove(y);
        if (a.check_balance()) {
            fout << "Remove balance OK.\n";
        } else {
            fout << "Remove balance ERROR.\n";
        }
        int n{};
        fin >> n;
        for (int i = 0; i < n; ++i) {
            int x{};
            fin >> x;
            data += std::to_string(x);
        }
        if (a.tree_to_string() == data) {
            fout << "Remove OK.\n";
        } else {
            fout << "Remove ERROR.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    return 0;
}