#include "solutions.h"

std::string day_1_part_1(std::vector<std::string>& input) {

	auto predicate = [](std::string item) { return item == ""; };
	auto caster = [](std::string value) { return stoi(value); };

	std::vector<std::vector<std::string>> groups = vectorGroup<std::string>(input, predicate);
	
	int max = 0;
	for (std::vector<std::string> group : groups) {
		std::vector<int> values = vectorCast<std::string, int>(group, caster);
		int sum = 0;
		for (int value : values) {
			sum += value;
		}
		if (sum > max) max = sum;
	}
	return std::to_string(max);
}
