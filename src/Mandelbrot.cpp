#include <cmath>
#include <iostream>
#include <fstream>
#include <complex>

#define MAX_WIDTH = 1980;
#define MAX_HEIGHT = 1024;

// using namespace std;

std::complex<double> normalize(std::complex<double>, std::complex<double>, std::complex<double>, int);
double mapToReal(double, double, double, int);
double mapToImag(double, double, double, int);
int findMandelbrot(double, double, int);
double sqr(double);

int main(int argc, const char * argv[])
{

}

std::complex<double> normalize(std::complex<double> axis, std::complex<)

double mapToReal(double x, double rMin, double rMax, int imageWidth)
{
    double range = rMax - rMin;
    return x * (range / imageWidth) + rMin;
}

double mapToImag(double y, double iMin, double iMax, int imageHeight)
{
    double range = iMax - iMin;
    return y * (range / imageHeight) + iMin;
}

int findMandelbrot(double r, double i, int maxIter)
{
    int i = 0;
    std::complex<double> z{0, 0};
    std::complex<double> square_temp{0, 0};

    while (square_temp.real() + square_temp.imag() <= 4.0)
    {
        z = {
            square_temp.real() - square_temp.imag() + c.real(),
            sqr(z.real() + z.imag()) - square_temp.real() - square_temp.imag() + c.imag()
        };
        square_temp = {
            sqr(z.real()),
            sqr(z.imag())
        };
        ++i;
    }

    // while (i < maxIter && sqr(zr) + sqr(zi) < 4.0)
    // {
    //     double temp = sqr(zr) + sqr(zi) + r;
    //     zi = 2.0 * zr * zi + i;
    //     zr = temp;
    //     ++i;
    // }

    return i;
}

double sqr(double num)
{
    return num * num;
}