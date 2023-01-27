#include "solutions.h"

#include <algorithm>

using std::string;
using std::vector;

string day_1_part_1(const vector<string>& input) {
	auto predicate = [](string item) { return item == ""; };
	auto caster = [](string value) { return stoi(value); };

	vector<vector<string>> groups = vectorGroup<string>(input, predicate);
	vector<int> sums;
	
	for (vector<string> group : groups) {
		sums.push_back(vectorSum(vectorCast<string, int>(group, caster)));
	}
	return std::to_string(vectorMax(sums));
}


string day_1_part_2(const vector<string>& input) {
	auto predicate = [](string item) { return item == ""; };
	auto caster = [](string value) { return stoi(value); };

	vector<vector<string>> groups = vectorGroup<string>(input, predicate);
	vector<int> sums;

	for (vector<string> group : groups) {
		sums.push_back(vectorSum(vectorCast<string, int>(group, caster)));
	}

	auto compare = [](int a, int b) { return a > b; };
	std::sort(sums.begin(), sums.end(), compare);
	vector<int> largest = vector<int>(sums.begin(), sums.begin() + 3);
	return std::to_string(vectorSum(largest));
}
