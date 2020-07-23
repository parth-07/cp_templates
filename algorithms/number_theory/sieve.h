#ifndef SIEVE_H
#define SIEVE_H

#include <bits/stdc++.h>

using std::vector;

template <class T>
class PrimeNumbers
{
private:
    using bvec = vector<bool>;
    using t_vec = vector<T>;
public:
    using value_type = T;
    using size_type = size_t;
    bvec is_prime;
    t_vec prime;
    size_type SZ;
    PrimeNumbers(size_type __n=0);
    void compute(size_type __n);
};

template<class T>
PrimeNumbers<T>::PrimeNumbers(size_type __n)
{
    if(__n)
    {
        compute(__n);
    }
}

template<class T>
void PrimeNumbers<T>::compute(size_type __n)
{
    SZ = __n;
    is_prime=bvec(SZ+1,1);
    is_prime[0]=is_prime[1]=0;
    for(size_type i=4;i<=SZ;i+=2)
        is_prime[i]=0;
    for(size_type i=3;i*i<=SZ;i+=2)
    {
        if(is_prime[i])
        {
            for(size_type j=i*i;j<=SZ;j+=i)
            {
                is_prime[j]=0;
            }
        }
    }
    for(size_type i=2;i<=SZ;++i)
    {
        if(is_prime[i])
            prime.push_back(i);
    }
}

#endif

//To see example of it's implementation , see sieve_example.cpp in the same directory