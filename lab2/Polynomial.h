#pragma once

#include "List.h"
#include "Sequences.h"

template <typename T>
class Polynomial {
private:
    unsigned int m_degree; //степень многочлена
    List<T> m_data; //список коэффициентов

public:
    Polynomial(); //создание многочлена по умолчанию

    explicit Polynomial(unsigned int degree, const T &value = T()); //создание многочлена

    Polynomial(unsigned int degree, T *items); //создание многочлена заполненного значениями из массива

    Polynomial(const Polynomial<T> &other_pol); //конструктор копирования

    ~Polynomial(); //деструктор

    T& get(int index);

    void set(int index, const T &value);

    T& value(const T &p);

    std::unique_ptr<Polynomial<T>> add(Polynomial<T> &other_pol); //сложение двух многочленов

    std::unique_ptr<Polynomial<T>> multiply(Polynomial<T> &other_pol); //умножение двух многочленов

    std::unique_ptr<Polynomial<T>> scalar_multiply(const T &value);

    std::unique_ptr<Polynomial<T>> composition(Polynomial<T> &other_pol);

    void print();

    void clear(); //очищает многочлен

    T& operator() (int index);

    Polynomial<T>& operator= (const Polynomial<T> &other_pol);

};

template <typename T>
Polynomial<T>::Polynomial() : m_degree{0}, m_data() {}

template<typename T>
Polynomial<T>::Polynomial(unsigned int degree, const T &value) :
        m_degree(degree), m_data(degree + 1, value) {}

template<typename T>
Polynomial<T>::Polynomial(unsigned int degree, T *items) :
    m_degree(degree), m_data(degree + 1, items) {}

template<typename T>
Polynomial<T>::Polynomial(const Polynomial<T> &other_pol) :
    m_degree(other_pol.m_degree), m_data(other_pol.m_data) {}

template<typename T>
Polynomial<T>::~Polynomial() {
    clear();
}

template<typename T>
void Polynomial<T>::clear() {
    m_data.clear();
    m_degree = 0;
}

template<typename T>
void Polynomial<T>::print() {
    for (int i = 0; i < m_degree; ++i) {
        std::cout << this->m_data.get(i) <<" *x^" << i << " + ";
    }
    std::cout << this->m_data.get(m_degree) <<" *x^" << m_degree;
    std::cout << std::endl;
}

template<typename T>
void Polynomial<T>::set(int index, const T &value) {
    if (index > m_degree)
        throw std::runtime_error("\n(Polynomial) Set Message: Index Out Of Range\n");
    m_data.set(index, value);
}

template<typename T>
T &Polynomial<T>::get(int index) {
    if (index > m_degree)
        throw std::runtime_error("\n(Polynomial) Get Message: Index Out Of Range\n");
    return m_data.get(index);
}

template<typename T>
std::unique_ptr<Polynomial<T>> Polynomial<T>::add(Polynomial<T> &other_pol) {
    if (m_degree < other_pol.m_degree) {
        std::unique_ptr<Polynomial<T>> res(new Polynomial<T>{other_pol});
        for (int i = 0; i <= m_degree; ++i) {
            res->get(i) = this->get(i) + other_pol.get(i);
        }
        for (int i = m_degree + 1; i <= other_pol.m_degree; ++i) {
            res->get(i) = other_pol.get(i);
        }
        return res;
    } else {
        std::unique_ptr<Polynomial<T>> res(new Polynomial<T>{*this});
        for (int i = 0; i <= other_pol.m_degree; ++i) {
            res->get(i) = this->get(i) + other_pol.get(i);
        }
        for (int i = other_pol.m_degree + 1; i <= m_degree; ++i) {
            res->get(i) = this->get(i);
        }
        return res;
    }
}

template<typename T>
std::unique_ptr<Polynomial<T>> Polynomial<T>::multiply(Polynomial<T> &other_pol) {
    std::unique_ptr<Polynomial<T>> res(new Polynomial<T>{m_degree + other_pol.m_degree});
    for (int i = 0; i <= m_degree; ++i) {
        for (int j = 0; j <= other_pol.m_degree; ++j) {
            res->get(i + j) += this->get(i) * other_pol.get(j);
        }
    }
    return res;
}

template<typename T>
std::unique_ptr<Polynomial<T>> Polynomial<T>::scalar_multiply(const T& value) {
    std::unique_ptr<Polynomial<T>> res(new Polynomial<T>{m_degree});
    for (int i = 0; i <= m_degree; ++i) {
        res->get(i) = this->get(i) * value;
    }
    return res;
}


template<typename T>
std::unique_ptr<Polynomial<T>> Polynomial<T>::composition(Polynomial<T> &other_pol) {
    std::unique_ptr<Polynomial<T>> res(new Polynomial<T>{0});
    res->set(0, this->get(m_degree));
    for (int i = m_degree - 1; i >= 0; --i) {
        res = res->multiply(other_pol);
        res->get(0) += this->get(i);
    }
    return res;
}


template<typename T>
T &Polynomial<T>::value(const T &p) {
    auto *res = new T{};
    for (int i = 0; i <= m_degree; ++i) {
        *res *= p;
        *res += this->get(m_degree - i);
    }
    return *res;
}

template<typename T>
T &Polynomial<T>::operator()(int index) {
    if (index > m_degree)
        throw std::runtime_error("\n(Polynomial) Operator() Message: Index Out Of Range\n");
    return m_data.get(index);
}

template<typename T>
Polynomial<T>& Polynomial<T>::operator= (const Polynomial<T> &other_pol) {
    if (other_pol.m_degree != m_degree)
        throw std::runtime_error("\n(Polynomial) operator= Message: Polynomial can't be equated\n");
    if (this == &other_pol)
        return *this;
    m_degree = other_pol.m_degree;
    for (int i = 0; i <= m_degree; ++i) {
            this->get(i) = other_pol.get(i);
    }
    return *this;
}