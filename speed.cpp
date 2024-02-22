#include <iostream>
#include <chrono>
#include "Matrixes.hpp"
#include <random>
#include <numeric>
int main()
{
    for(int i=100; i<=1000; i+=100)
    {
        std::vector<double> b(i);
        std::iota(b.begin(), b.end(), 1);
        std::vector<double> h(i*i, 0);
        for(int j;j<i*i; j+=i)
        {
            h[j] = 264;
        }
        Dense_matrix D(h, i, i);
        auto start = std::chrono::high_resolution_clock::now();
        D*b;
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        std::cout<<i<<" "<<diff.count()<<std::endl;
    }
}