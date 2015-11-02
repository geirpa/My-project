#include "mandelbrot.hpp"

int main(int argc, char *argv[])
{
    int M = 500, N = 500;
    char *data;

    //compute mandelbrot set
    mandelbrotSet(M, N, data);

    delete data;
    return 0;
}
	
