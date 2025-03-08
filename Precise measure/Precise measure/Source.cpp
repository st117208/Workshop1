#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

int main()
{
    std::ifstream inputFile("Precise measuring.csv");
    std::ofstream outputFile("Precise result.csv");

    float n = 50;
    double value = 0.0;
    double tmp = 0.0;
    float sum = 0.0;
    double data[50];

    for (int i = 0; i < n; ++i)
    {
        inputFile >> value;
        data[i] = value;
        sum = sum + value;
    }

    float fx = round(sum / n * 1000) / 1000;
    float T = 1;

    float abs = rel * fx * 1000 / 100;
    float rel = (5 * pow(10, -7.0) + 1 / (fx * 1000 * T)) * 100;

    for (int i = 0; i < n; ++i)
    {
        tmp = tmp + pow((data[i] - fx), 2);
    }

    double sygma = sqrt(tmp / (n - 1));
    double sygma_x = sygma / sqrt(n);

    outputFile << fx << std::endl;
    outputFile << std::fixed<<std::setprecision(6) << abs / 1000 << std::endl;

    outputFile << sygma << std::endl;
    outputFile << sygma_x << std::endl;

    return EXIT_SUCCESS;
}
