#include "solve.h"

#include "utils.h"

std::string solve(
	int day, int part,
	const std::function<std::string(std::vector<std::string>&)>& solver
) {
	FileReader reader("./input/" + std::to_string(day) + "-" + std::to_string(part));
	std::vector<std::string>* input = reader.readLines();
	std::string solution = solver(*input);
	delete input;
	return solution;
}
