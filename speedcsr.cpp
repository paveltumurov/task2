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
        int lim;
        lim = 500*i;
        std::iota(b.begin(), b.end(), 1);
        std::vector<double> vals(lim, 0);
        for (int k =0;k<lim; k++){
            vals[k] = k;
        };
        std::vector<double> cols(lim, 0);
        for (int k=0; k<lim; k++)
        {
            cols[k] = 2*k;
        }
        std::vector<double> rows(i+1, 0);
        for (int k =0; k<i+1; k++)
        {
            rows[k] = k;
        }
        CSRMatrix D(vals, cols, rows, i, i);
        auto start = std::chrono::high_resolution_clock::now();
        D*b;
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        std::cout<<i<<" "<<diff.count()<<std::endl;
    }
}