#include <iostream>
#include <new>

void computeMandelbrotSet(int M, int N, char *data);

int main(int argc, char *argv[])
{
    int M = 500, N = 500;
    char *data = new char[M*N];

    computeMandelbrotSet(M, N, data);

    delete data;
    return 0;
}
        
void computeMandelbrotSet(int M, int N, char *data)
{
    int j, k, val;

    //variables in the for loop
    double c_re, c_im, x, y, xtemp;
    int iter, max_iter = 255;

    //compute pixels
    for (j = 0; j < M; ++j)
    {
        for (k = 0; k < N; ++k)
        {
            c_re = (k - N/2.0)*4.0/N;
            c_im = (j - M/2.0)*4.0/M;

            x = 0.0;
            y = 0.0;

            iter = 0;
            while ((x*x + y*y) < 4 && iter < max_iter)
            {
                xtemp = x*x - y*y + c_re;
                y = 2*x*y + c_im;
                x = xtemp;

                iter += 1;
            }
            data[j*N + k] = iter;
        }
    }
}	
