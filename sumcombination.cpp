#include "sumcombination.h"

SumCombination::SumCombination()
{

}

void SumCombination::getPossibilitiesSub(
        const double limit,
        const std::vector<double> &summands,
        size_t index,
        const double sum,
        std::vector<uint8_t> selection) {
    if (sum == limit) {
        solutions.push_back(selection);
        return;
    }
    if (sum > limit) {
        return;
    }
    if (index >= summands.size()) {
        return;
    }
    getPossibilitiesSub(limit, summands, index+1, sum, selection);

    selection[index] = true;
    getPossibilitiesSub(limit, summands, index+1, sum + summands[index], selection);
}

void SumCombination::getPossibilities(const double sum, const std::vector<double> &summands) {
    if (summands.empty()) {
        return;
    }
    std::vector<uint8_t> selection(summands.size(), uint8_t(0));
    getPossibilitiesSub(sum, summands, 0, 0, selection);
}

void SumCombination::printSolutions(
        const std::vector<std::vector<uint8_t> > &solutions,
        const std::vector<double> &summands) {
    std::cout << "Number of solutions: " << solutions.size() << std::endl;
    for (size_t ii = 0; ii < solutions.size(); ++ii) {
        printSolution(solutions[ii], summands);
    }
}

void SumCombination::printSolution(
        const std::vector<uint8_t> &solution,
        const std::vector<double> &summands) {
    if (solution.size() != summands.size()) {
        throw std::runtime_error("Number of indices in solution doesn't match number of summands.");
    }
    for (size_t ii = 0; ii < solution.size(); ++ii) {
        std::cout << int(solution[ii]);
    }
    std::cout << "  ";
    for (size_t ii = 0; ii < solution.size(); ++ii) {
        if (solution[ii]) {
            std::cout << summands[ii] << ", ";
        }
    }
    std::cout << std::endl;
}
