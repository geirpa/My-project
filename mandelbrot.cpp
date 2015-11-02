#include <new>

void mandelbrotSet(int M, int N, char *data)
{
    int j, k;

    //allocate data
    data = new char[M*N];

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

                iter++;
            }
            data[j*N + k] = iter;
        }
    }
}
