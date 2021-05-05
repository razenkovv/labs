#include <iostream>
#include<fstream>
#include <iomanip>
#include <string>

#include "Vector.h"
#include "List.h"
#include "Matrix.h"
#include "Polynomial.h"
#include "Sequences.h"

//class Complex {
//private:
//    double m_r;
//    double m_im;
//public:
//    explicit Complex(double r = 0.0, double im = 0.0) : m_r(r), m_im(im) {}
//
//    friend std::ostream& operator<< (std::ostream &out, const Complex &value);
//    friend bool operator== (const Complex &value1, const Complex &value2);
//    friend bool operator!= (const Complex &value1, const Complex &value2);
//};

//std::ostream &operator<<(std::ostream &out, const Complex &value) {
//    out << std::setw(4) << std::right << value.m_r << ";" << std::setw(2) << std::right << value.m_im;
//    return out;
//}
//
//bool operator==(const Complex &value1, const Complex &value2) {
//    return ((value1.m_r == value2.m_r) && (value1.m_im == value2.m_im));
//}
//
//bool operator!=(const Complex &value1, const Complex &value2) {
//    return !(value1 == value2);
//}

void VectorTest() {
    Vector<int> a{5, 0};
    std::ifstream fin;
    std::string Path1 = R"(C:\Users\Ivan\programming\labs\lab2\VectorTest.txt)";
    fin.open(Path1);
    std::string Path2 = R"(C:\Users\Ivan\programming\labs\lab2\VectorLog.txt)";
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
        std::string tmp;
        fin >> tmp;
        for (int i = 0; i < 5; ++i) {
            double n;
            fin >> n;
            a.set(i, n);
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    a.reserve(10);
    try {
        std::string tmp;
        fin >> tmp;
        int value;
        fin >> value;
        if (a.size() == value) {
            fout << "Size OK.\n";
        } else {
            fout << "Error in Size test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string tmp;
        fin >> tmp;
        int value;
        fin >> value;
        if (a.capacity() == value) {
            fout << "Capacity OK.\n";
        } else {
            fout << "Error in Capacity test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string tmp;
        fin >> tmp;
        int value;
        fin >> value;
        if (a.get(2) == value) {
            fout << "Get OK.\n";
        } else {
            fout << "Error in Get test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string tmp;
        fin >> tmp;
        int value;
        fin >> value;
        a.push_back(value);
        if (a.back() == value) {
            fout << "Push_back OK.\n";
        } else {
            fout << "Error in Push_back test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }
}

void ListTest() {
    List<int> a{5, 0};
    std::ifstream fin;
    std::string Path1 = R"(C:\Users\Ivan\programming\labs\lab2\ListTest.txt)";
    fin.open(Path1);
    std::string Path2 = R"(C:\Users\Ivan\programming\labs\lab2\ListLog.txt)";
    std::ofstream fout(Path2);
    try {
        if (!fout)
            throw std::runtime_error("\nListLog.txt: File wasn't opened\n");
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        if (!fin.is_open())
            throw std::runtime_error("\nListTest.txt: File wasn't opened\n");
        std::string tmp;
        fin >> tmp;
        for (int i = 0; i < 5; ++i) {
            double n;
            fin >> n;
            a.set(i, n);
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string tmp;
        fin >> tmp;
        int value;
        fin >> value;
        if (a.size() == value) {
            fout << "Size OK.\n";
        } else {
            fout << "Error in Size test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string tmp;
        fin >> tmp;
        int value;
        fin >> value;
        if (a.front() == value) {
            fout << "Front OK.\n";
        } else {
            fout << "Error in Front test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string tmp;
        fin >> tmp;
        int value;
        fin >> value;
        if (a.back() == value) {
            fout << "Back OK.\n";
        } else {
            fout << "Error in Back test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string tmp;
        fin >> tmp;
        List<int> b{};
        for (int i = 0; i < 2; ++i) {
            int n;
            fin >> n;
            b.push_back(n);
        }
        auto c = a.get_sublist(2,3);
        int error = 0;
        for (int i = 0; i < 2; ++i) {
            if (b.get(i) != c->get(i)) {
                error = 1;
            }
        }
        if (b.size() != c->size())
            error = 1;
        if (!error) {
            fout << "Get_sublist OK.\n";
        } else {
            fout << "Error in Get_sublist test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string tmp;
        fin >> tmp;
        List<int> b{};
        for (int i = 0; i < 6; ++i) {
            int n;
            fin >> n;
            b.push_back(n);
        }
        a.insert_at(1,4);
        int error = 0;
        for (int i = 0; i < 6; ++i) {
            if (b.get(i) != a.get(i)) {
                error = 1;
            }
        }
        if (b.size() != a.size())
            error = 1;
        if (!error) {
            fout << "Insert_at OK.\n";
        } else {
            fout << "Error in Insert_at test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string tmp;
        fin >> tmp;
        List<int> b{};
        for (int i = 0; i < 10; ++i) {
            int n;
            fin >> n;
            b.push_back(n);
        }
        std::string tmp2;
        fin >> tmp2;
        List<int> c{};
        for (int i = 0; i < 16; ++i) {
            int n;
            fin >> n;
            c.push_back(n);
        }
        a.concat(b);
        int error = 0;
        for (int i = 0; i < 16; ++i) {
            if (a.get(i) != c.get(i)) {
                error = 1;
            }
        }
        if (a.size() != c.size())
            error = 1;
        if (!error) {
            fout << "Concat OK.\n";
        } else {
            fout << "Error in Concat test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }
}

void ArraySequenceTest() {
    ArraySequence<int> a{5, 0};
    std::ifstream fin;
    std::string Path1 = R"(C:\Users\Ivan\programming\labs\lab2\ArraySequenceTest.txt)";
    fin.open(Path1);
    std::string Path2 = R"(C:\Users\Ivan\programming\labs\lab2\ArraySequenceLog.txt)";
    std::ofstream fout(Path2);
    try {
        if (!fout)
            throw std::runtime_error("\nArraySequenceLog.txt: File wasn't opened\n");
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        if (!fin.is_open())
            throw std::runtime_error("\nArraySequenceTest.txt: File wasn't opened\n");
        std::string tmp;
        fin >> tmp;
        for (int i = 0; i < 5; ++i) {
            double n;
            fin >> n;
            a.set(i, n);
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string tmp;
        fin >> tmp;
        ArraySequence<int> b{};
        for (int i = 0; i < 3; ++i) {
            int n;
            fin >> n;
            b.push_back(n);
        }
        auto c = a.get_subsequence(2,4);
        int error = 0;
        for (int i = 0; i < 3; ++i) {
            if (b.get(i) != c->get(i)) {
                error = 1;
            }
        }
        if (b.size() != c->size())
            error = 1;
        if (!error) {
            fout << "Get_subsequence OK.\n";
        } else {
            fout << "Error in Get_subsequence test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string tmp;
        fin >> tmp;
        ArraySequence<int> b{};
        for (int i = 0; i < 6; ++i) {
            int n;
            fin >> n;
            b.push_back(n);
        }
        std::string tmp2;
        fin >> tmp2;
        ArraySequence<int> c{};
        for (int i = 0; i < 11; ++i) {
            int n;
            fin >> n;
            c.push_back(n);
        }
        a.concat(b);
        int error = 0;
        for (int i = 0; i < 11; ++i) {
            if (c.get(i) != a.get(i)) {
                error = 1;
            }
        }
        if (c.size() != a.size())
            error = 1;
        if (!error) {
            fout << "Concat OK.\n";
        } else {
            fout << "Error in Concat test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string tmp;
        fin >> tmp;
        int value;
        fin>>value;
        std::string tmp2;
        fin >> tmp2;
        ArraySequence<int> b{};
        for (int i = 0; i < 12; ++i) {
            int n;
            fin >> n;
            b.push_back(n);
        }
        a.insert_at(0,value);
        int error = 0;
        for (int i = 0; i < 12; ++i) {
            if (a.get(i) != b.get(i)) {
                error = 1;
            }
        }
        if (a.size() != b.size())
            error = 1;
        if (!error) {
            fout << "Insert_at OK.\n";
        } else {
            fout << "Error in Insert_at test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }
}

void ListSequenceTest() {
    ListSequence<int> a{5, 0};
    std::ifstream fin;
    std::string Path1 = R"(C:\Users\Ivan\programming\labs\lab2\ListSequenceTest.txt)";
    fin.open(Path1);
    std::string Path2 = R"(C:\Users\Ivan\programming\labs\lab2\ListSequenceLog.txt)";
    std::ofstream fout(Path2);
    try {
        if (!fout)
            throw std::runtime_error("\nListSequenceLog.txt: File wasn't opened\n");
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        if (!fin.is_open())
            throw std::runtime_error("\nListSequenceTest.txt: File wasn't opened\n");
        std::string tmp;
        fin >> tmp;
        for (int i = 0; i < 5; ++i) {
            double n;
            fin >> n;
            a.set(i, n);
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string tmp;
        fin >> tmp;
        ListSequence<int> b{};
        for (int i = 0; i < 8; ++i) {
            int n;
            fin >> n;
            b.push_back(n);
        }
        std::string tmp2;
        fin >> tmp2;
        ArraySequence<int> c{};
        for (int i = 0; i < 13; ++i) {
            int n;
            fin >> n;
            c.push_back(n);
        }
        a.concat(b);
        int error = 0;
        for (int i = 0; i < 13; ++i) {
            if (c.get(i) != a.get(i)) {
                error = 1;
            }
        }
        if (c.size() != a.size())
            error = 1;
        if (!error) {
            fout << "Concat OK.\n";
        } else {
            fout << "Error in Concat test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }
}

void MatrixTest() {
    Matrix<int> a{3, 3};
    std::ifstream fin;
    std::string Path1 = R"(C:\Users\Ivan\programming\labs\lab2\MatrixTest.txt)";
    fin.open(Path1);
    std::string Path2 = R"(C:\Users\Ivan\programming\labs\lab2\MatrixLog.txt)";
    std::ofstream fout(Path2);
    try {
        if (!fout)
            throw std::runtime_error("\nMatrixLog.txt: File wasn't opened\n");
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        if (!fin.is_open())
            throw std::runtime_error("\nMatrixTest.txt: File wasn't opened\n");
        std::string tmp;
        fin >> tmp;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                double n;
                fin >> n;
                a.set(i, j, n);
            }
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    Matrix<int> b{a};
    try {
        if (a.is_equal(b)) {
            fout << "Copy Constructor OK.\n";
        } else {
            fout << "Error in Copy Constructor\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string tmp;
        fin >> tmp;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                double n;
                fin >> n;
                b.set(i, j, n);
            }
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    int scalar;
    try {
        std::string tmp;
        fin >> tmp;
        fin >> scalar;
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        auto c = b.multiply_scalar(scalar);
        std::string tmp;
        fin >> tmp;
        Matrix<int> d{3, 3};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int n;
                fin >> n;
                d.set(i, j, n);
            }
        }
        if (c->is_equal(d)) {
            fout << "Multiply_scalar OK.\n";
        } else {
            fout << "Error in Multiply_scalar test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        auto c = b.add(a);
        std::string tmp;
        fin >> tmp;
        Matrix<int> d{3, 3};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int n;
                fin >> n;
                d.set(i, j, n);
            }
        }
        if (c->is_equal(d)) {
            fout << "Add OK.\n";
        } else {
            fout << "Error in Add test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        auto c = a.multiply(b);
        std::string tmp;
        fin >> tmp;
        Matrix<int> d{3, 3};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int n;
                fin >> n;
                d.set(i, j, n);
            }
        }
        if (c->is_equal(d)) {
            fout << "Multiply OK.\n";
        } else {
            fout << "Error in Multiply test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        Matrix<int> c{b};
        c.add_str(0, 1);
        std::string tmp;
        fin >> tmp;
        Matrix<int> d{3, 3};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int n;
                fin >> n;
                d.set(i, j, n);
            }
        }
        if (c.is_equal(d)) {
            fout << "Add_str OK.\n";
        } else {
            fout << "Error in Add_str test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string tmp;
        fin >> tmp;
        fin >> scalar;
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        Matrix<int> c{b};
        c.multiply_str(2, scalar);
        std::string tmp;
        fin >> tmp;
        Matrix<int> d{3, 3};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int n;
                fin >> n;
                d.set(i, j, n);
            }
        }
        if (c.is_equal(d)) {
            fout << "Multiply_str OK.\n";
        } else {
            fout << "Error in Multiply_str test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        int norm{b.norm()};
        std::string tmp;
        fin >> tmp;
        fin >> scalar;
        if (norm == scalar) {
            fout << "Norm OK.\n";
        } else {
            fout << "Error in Norm test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        int get = b.get(0, 2);
        std::string tmp;
        fin >> tmp;
        fin >> scalar;
        if (get == scalar) {
            fout << "Get OK.\n";
        } else {
            fout << "Error in Get test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        Matrix<double> t{3,3, 0.0};
        t.get(3,2);
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        Matrix<double> t{3,3, 0.0};
        t.set(3,2, 1.0);
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        Matrix<double> x{1,2, 0.0};
        Matrix<double> y{3,2,0.0};
        x.multiply(y);
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

}

void PolynomialTest() {
    Polynomial<int> a{4, 0};
    std::ifstream fin;
    std::string Path1 = R"(C:\Users\Ivan\programming\labs\lab2\PolynomialTest.txt)";
    fin.open(Path1);
    std::string Path2 = R"(C:\Users\Ivan\programming\labs\lab2\PolynomialLog.txt)";
    std::ofstream fout(Path2);
    try {
        if (!fout)
            throw std::runtime_error("\nPolynomialLog.txt: File wasn't opened\n");
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        if (!fin.is_open())
            throw std::runtime_error("\nPolynomialTest.txt: File wasn't opened\n");
        std::string tmp;
        fin >> tmp;
        for (int i = 0; i <= 4; ++i) {
            double n;
            fin >> n;
            a.set(i, n);
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    Polynomial<int> b{a};
    try {
        if (a.is_equal(b)) {
            fout << "Copy Constructor OK.\n";
        } else {
            fout << "Error in Copy Constructor\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string tmp;
        fin >> tmp;
        for (int i = 0; i <= 4; ++i) {
            double n;
            fin >> n;
            b.set(i, n);
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    int scalar;
    try {
        std::string tmp;
        fin >> tmp;
        fin >> scalar;
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        auto c = b.multiply_scalar(scalar);
        std::string tmp;
        fin >> tmp;
        Polynomial<int> d{4, 0};
        for (int i = 0; i <= 4; ++i) {
            int n;
            fin >> n;
            d.set(i, n);
        }
        if (c->is_equal(d)) {
            fout << "Multiply_scalar OK.\n";
        } else {
            fout << "Error in Multiply_scalar test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        auto c = b.multiply(a);
        std::string tmp;
        fin >> tmp;
        Polynomial<int> d{8, 0};
        for (int i = 0; i <= 8; ++i) {
            int n;
            fin >> n;
            d.set(i, n);
        }
        if (c->is_equal(d)) {
            fout << "Multiply OK.\n";
        } else {
            fout << "Error in Multiply test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        auto c = b.add(a);
        std::string tmp;
        fin >> tmp;
        Polynomial<int> d{4, 0};
        for (int i = 0; i <= 4; ++i) {
            int n;
            fin >> n;
            d.set(i, n);
        }
        if (c->is_equal(d)) {
            fout << "Add OK.\n";
        } else {
            fout << "Error in Add test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        std::string tmp;
        fin >> tmp;
        fin >> scalar;
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        int c = b.value(scalar);
        std::string tmp;
        fin >> tmp;
        int value;
        fin >> value;
        if (c == value) {
            fout << "nValue OK.\n";
        } else {
            fout << "Error in Value test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        auto c = b.composition(a);
        std::string tmp;
        fin >> tmp;
        Polynomial<int> d{16, 0};
        for (int i = 0; i <= 16; ++i) {
            int n;
            fin >> n;
            d.set(i, n);
        }
        if (c->is_equal(d)) {
            fout << "Composition OK.\n";
        } else {
            fout << "Error in Composition test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        int get = b.get(2);
        std::string tmp;
        fin >> tmp;
        fin >> scalar;
        if (get == scalar) {
            fout << "Get OK.\n";
        } else {
            fout << "Error in Get test.\n";
        }
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        Polynomial<double> t{3, 0.0};
        t.get(4);
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }

    try {
        Polynomial<double> t{4, 0.0};
        t.set(-1, 4);
    } catch (const std::runtime_error &msg) {
        std::cerr << msg.what();
    }
}

int main() {
    //VectorTest();
    //ListTest();
    //ArraySequenceTest();
    //ListSequenceTest();
    //MatrixTest();
    //PolynomialTest();
}