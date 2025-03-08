#include <iostream>
#include <fstream>
#include <cmath>

int main()
{
    std::ifstream inputFile("Rough measuring.csv");
    std::ofstream outputFile("Rough result.csv");

    float T = 0.1;
    float n = 10;
    float sum = 0.0;
    double value = 0.0;
    for (int i = 0; i < n; ++i)
    {
        inputFile >> value;
            sum = sum + value;
    }

    float fx = sum / n;
    float rel = (5 * pow(10, -7.0) + 1 / (fx * 1000 * T)) * 100;
    float abs = rel * fx * 1000 / 100;

    outputFile << fx << std::endl;
    outputFile << abs / 1000 << std::endl;

    return EXIT_SUCCESS;
}
