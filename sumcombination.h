#ifndef SUMCOMBINATION_H
#define SUMCOMBINATION_H

#include <vector>
#include <iostream>

class SumCombination
{
public:
    std::vector<std::vector<uint8_t> > solutions;

    SumCombination();

    void getPossibilitiesSub(
            double const limit,
            std::vector<double> const& summands,
            size_t index,
            double const sum,
            std::vector<uint8_t> selection
            );

    void getPossibilities(double const sum, std::vector<double> const& summands);

    static void printSolutions(
            std::vector<std::vector<uint8_t> > const& solutions,
            std::vector<double> const& summands
            );
    static void printSolution(
            std::vector<uint8_t> const& solution,
            std::vector<double> const& summands);
};



#endif // SUMCOMBINATION_H
