#include "solutions.h"

#include <unordered_set>
#include <map>


std::map<char, int> priorityMap() {
	std::string priorities = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::map<char, int> map;

	for (int c = 0; c < priorities.length(); c++) {
		map[priorities[c]] = c + 1;
	}

	return map;
}


std::string day_3_part_1(const std::vector<std::string>& input) {
	std::map<char, int> priorities = priorityMap();
	int result = 0;

	for (std::string row : input) {
		std::unordered_set<char> left(row.begin(), row.begin() + (row.length() / 2));
		std::unordered_set<char> right(row.begin() + (row.length() / 2), row.end());
		
		for (char item : left) {
			if (right.count(item) > 0) {
				result += priorities[item];
				break;
			}
		}
	}

	return std::to_string(result);
}