#include "solve.h"

#include "utils.h"

using std::string;
using std::vector;
using std::function;

string solve(
	int day, int part,
	const function<string(const vector<string>&)>& solver
) {
	FileReader reader("./input/day-" + std::to_string(day));
	vector<string>* input = reader.readLines();
	string solution = solver(*input);
	delete input;

	return solution;
}
