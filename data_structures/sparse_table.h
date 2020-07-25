#ifndef SPARSE_TABLE_H
#define SPARSE_TABLE_H

#include <bits/stdc++.h>

// using std::clog;
// using std::cout;
// using std::endl;
using std::function;
using std::string;
using std::vector;

/* #define show(args...) describe(#args, args);
template <typename T>
void describe(string var_name, T value)
{
    clog << var_name << " = " << value << "\n";
}

template <typename T, typename... Args>
void describe(string var_names, T value, Args... args)
{
    string::size_type pos = var_names.find(',');
    string name = var_names.substr(0, pos);
    var_names = var_names.substr(pos + 1);
    clog << name << " = " << value << " ";
    describe(var_names, args...);
} */

template <class T>
class SparseTable
{
public:
    using size_type = size_t;

private:
    using t_vec = vector<T>;
    using t_grid = vector<t_vec>;
    using vec = vector<int>;
    using function_type = function<T(T, T)>;
    using query_function_type = function<T(SparseTable *, size_type, size_type)>;

    const bool idempotent;
    const T INITIAL_RESULT;
    const function_type f;
    const t_vec a;
    t_grid st;
    const size_type N,K;

    static vec lg;
    const static size_type SIZE_TYPE_ONE;
    static void configure_lg(size_type sz);

    T general_query(size_type l, size_type r) const;
    T idempotent_query(size_type l, size_type r) const;

public:
    // static void display_static_variables();
    using value_type = T;
    // query_function_type query;
    T query(size_type l, size_type r) const;
    SparseTable(const t_vec &__a, const function_type &__f, const T &__initial_result, bool __idempotent = 0);
};

template <class T>
typename SparseTable<T>::vec SparseTable<T>::lg = {0, 0};

template <class T>
void SparseTable<T>::configure_lg(size_type sz)
{
    for (size_type i = lg.size(); i <= sz; ++i)
        lg.push_back(lg[i/2] + 1);
}

template <class T>
const typename SparseTable<T>::size_type SparseTable<T>::SIZE_TYPE_ONE = static_cast<typename SparseTable<T>::size_type>(1);

/* template <class T>
void SparseTable<T>::display_static_variables()
{
    cout << "lg" << endl;
    for (auto item : lg)
        cout << item << " ";
    cout << endl;
    show(SIZE_TYPE_ONE);
} */

template <class T>
SparseTable<T>::SparseTable(const t_vec &__a, const function_type &__f, const T &__initial_result, bool __idempotent) : a(__a), f(__f), idempotent(__idempotent), N(__a.size()), INITIAL_RESULT(__initial_result) , K(log2(__a.size()) + 1)
{
    if (idempotent)
    {
        // query = &SparseTable::general_query;
        if (lg.size() <= N)
        {
            configure_lg(N);
        }
    }
    /* else
    {
        query = &SparseTable::idempotent_query;
    } */

    st.resize(N + 1, t_vec(K + 1));

    for (size_type i = 0; i < N; ++i)
    {
        st[i][0] = f(a[i], INITIAL_RESULT);
    }

    for (size_type j = 1; j <= K; ++j)
    {
        for (size_type i = 0; (i + (SIZE_TYPE_ONE << j) - 1) < N; ++i)
        {
            st[i][j] = f(st[i][j - 1], st[i + (SIZE_TYPE_ONE << (j-1))][j - 1]);
        }
    }
}

template <class T>
T SparseTable<T>::general_query(size_type l, size_type r) const
{
    T res = INITIAL_RESULT;
    for (size_type j = K; j != static_cast<size_type>(-1); --j)
    {
        if ((static_cast<T>(1) << j) <= (r - l + 1))
        {
            res = f(res, st[l][j]);
            l += (SIZE_TYPE_ONE << j);
        }
    }
    return res;
}

template <class T>
T SparseTable<T>::idempotent_query(size_type l, size_type r) const
{
    size_type j = lg[r - l + 1];
    return f(st[l][j], st[r - (SIZE_TYPE_ONE << j) + 1][j]);
}

template <class T>
T SparseTable<T>::query(size_type l, size_type r) const
{
    if (idempotent)
    {
        return idempotent_query(l, r);
    }
    else
        return general_query(l, r);
}

#endif

//To see example of it's implementation , see SparseTable_example.cpp file in the same directory