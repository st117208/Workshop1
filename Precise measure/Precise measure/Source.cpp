#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>


void in(double a[], double n)
{
    std::ifstream inputFile("Precise measuring.csv");
    for (int i = 0; i < n; i++)
    {
        inputFile >> a[i];
    }
}

double fx(double a[], double n)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    sum = static_cast<double>(round(1000 * (sum / n))) / 1000;
    return sum;
}

double rel(double a[], double n, double T)
{
    double rel = (5 * pow(10, -7.0) + 1 / (fx(a, n) * 1000 * T)) * 100;
    return rel;
}

double abs(double a[], double n, double T)
{
    double abs = rel(a, n, T) * fx(a, n) / 100;
    return abs;
}

float sygma(double c[], double n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + c[i];
    }
    sum = sqrt(sum / (n - 1));

    return sum;
}

double sygma_x(double c[], double n)
{
    double sygma_x = sygma(c, n) / sqrt(n);
    return sygma_x;
}

double sum_err(double a[], double c[], double n, double T)
{
    double sum_err = sqrt(pow(sygma_x(c, n), 2) + pow(abs(a, n, T) / 3, 2));
    return sum_err;
}

void columns(double a[], double b[], double c[], double n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i] - fx(a, n);
        c[i] = pow(b[i], 2);
    }
}

void out(double a[], double b[], double c[], double n, double T)
{
    std::ofstream outF("Precise result.csv");
    outF << fx(a, n) << std::endl;
    outF << abs(a, n, T) << std::endl;
    outF << sygma(c, n) << std::endl;
    outF << sygma_x(c, n) << std::endl;
    outF << sum_err(a, c, n, T) << std::endl;

    float s1 = 0;
    float s2 = 0;
    for (int i = 0; i < n; i++)
    {
        outF << b[i] << " " << c[i] << std::endl;
        s1 = s1 + b[i];
        s2 = s2 + c[i];
    }
    outF << std::endl << std::setprecision(3) << s1 << " " << std::setprecision(6) << s2 << std::endl;
}

int main()
{
    double T = 1;
    int n = 43;
    double a[43];
    double b[43];
    double c[43];

    in(a, n);
    columns(a, b, c, n);
    out(a, b, c, n, T);

    return EXIT_SUCCESS;
}