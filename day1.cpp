#include "solutions.h"

#include <algorithm>

std::string day_1_part_1(const std::vector<std::string>& input) {
	auto predicate = [](std::string item) { return item == ""; };
	auto caster = [](std::string value) { return stoi(value); };

	std::vector<std::vector<std::string>> groups = vectorGroup<std::string>(input, predicate);
	std::vector<int> sums;
	
	for (std::vector<std::string> group : groups) {
		sums.push_back(vectorSum(vectorCast<std::string, int>(group, caster)));
	}
	return std::to_string(vectorMax(sums));
}


std::string day_1_part_2(const std::vector<std::string>& input) {
	auto predicate = [](std::string item) { return item == ""; };
	auto caster = [](std::string value) { return stoi(value); };

	std::vector<std::vector<std::string>> groups = vectorGroup<std::string>(input, predicate);
	std::vector<int> sums;

	for (std::vector<std::string> group : groups) {
		sums.push_back(vectorSum(vectorCast<std::string, int>(group, caster)));
	}

	auto compare = [](int a, int b) { return a > b; };
	std::sort(sums.begin(), sums.end(), compare);
	std::vector<int> largest = std::vector<int>(sums.begin(), sums.begin() + 3);
	return std::to_string(vectorSum(largest));
}

