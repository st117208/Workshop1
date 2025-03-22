#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>


void in (float a[], double n)
{
    std::ifstream inF("Rough measuring.csv");
    for (int i = 0; i < n; i++)
    {
        inF >> a[i];
    }
}

float fx (float a[], double n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    sum = sum / n;
    return sum;
}

float rel (float a[], double n, float T)
{
    float rel = (5 * pow(10, -7.0) + (1 / (fx(a, n) * 1000 * T))) * 100;
    return rel;
}

float abs (float a[], double n, float T)
{
    float abs = rel(a, n, T) * fx(a, n) / 100;
    return abs;
}

void out (float a[], double n, float T)
{
    std::ofstream outF("Rough result.csv");
    outF << fx(a, n) << std::endl;
    outF << std::setprecision(4) << abs(a, n, T) << std::endl;
}

int main()
{
    float T = 0.1;
    int n = 10;
    float a[10];

    in(a, n);
    out(a, n, T);

    return EXIT_SUCCESS;
}