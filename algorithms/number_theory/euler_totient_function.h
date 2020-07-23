#ifndef EULER_TOTIENT_FUNCTION_H
#define EULER_TOTIENT_FUNCTION_H

#include <bits/stdc++.h>

using std::vector;

template <typename T> //euler totient in O(sqrt(n))
T get_phi(T n)
{
    T res = n;
    for (T i = 2; i <= n * n; ++i)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    }
    if (n > 1)
        res -= res / n;
    return res;
}

template <class T>
class EulerTotients
{

public:
    using size_type = size_t;
    using value_type = T;

private:
    vector<T> phi;
    size_type SZ;

public:
    EulerTotients(size_type __n = 0);
    void compute(size_type __n); //precomputation of O(nlog(logn)) , to get euler totient of any number from 1 to n , in O(1)
    T& operator[](const size_type index);
    const T& operator[](const size_type index) const;

};

template <class T>
EulerTotients<T>::EulerTotients(size_type __n) : SZ(__n)
{
    if (__n)
        compute(__n);
}

template <class T>
void EulerTotients<T>::compute(size_type __n)
{
    SZ = __n;
    phi.resize(SZ + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (unsigned i = 2; i <= SZ; ++i)
        phi[i] = i;
    for (unsigned i = 2; i <= SZ; ++i)
    {
        if (phi[i] == i)
        {
            for (unsigned j = i; j <= SZ; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

template<class T>
T& EulerTotients<T>::operator[](const size_type index)
{
    return phi[index];
}

template<class T>
const T& EulerTotients<T>::operator[](const size_type index) const
{
    return phi[index];
}

#endif
//To see an example of it's implementation see euler_totient_function_example.cpp