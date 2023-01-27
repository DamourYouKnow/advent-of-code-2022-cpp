#include "solve.h"

#include "utils.h"

std::string solve(
	int day, int part,
	const std::function<std::string(const std::vector<std::string>&)>& solver
) {
	FileReader reader("./input/day-" + std::to_string(day));
	std::vector<std::string>* input = reader.readLines();
	std::string solution = solver(*input);
	delete input;

	return solution;
}
