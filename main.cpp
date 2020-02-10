#include <iostream>
#include <vector>

#include "sumcombination.h"

int main(int argc, char ** argv) {
    SumCombination s;
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " sum summand1 summand2...." << std::endl;
        return 0;
    }
    double sum = std::stod(argv[1]);
    std::vector<double> summands;
    for (size_t ii = 2; ii < size_t(argc); ++ii) {
        summands.push_back(std::stod(argv[ii]));
    }
    s.getPossibilities(sum, summands);
    s.printSolutions(s.solutions, summands);
    return 0;
}
