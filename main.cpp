#include <iostream>
#include <fstream>
#include "mandelbrot.hpp"

int main(int argc, char *argv[])
{
    int j, k;
    std::ofstream fp("output.txt");
    
    int M = 500, N = 500;
    int *data;

    //compute mandelbrot set
    mandelbrotSet(M, N, &data);

    //write to file
    for (j = 0; j < M; ++j)
    {
        for (k = 0; k < N; ++k)
            fp << data[j*N + k] << " ";
        fp << "\n";
    }

    delete data;
    return 0;
}
	
