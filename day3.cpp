#include "solutions.h"

#include <unordered_set>
#include <map>

using std::string;
using std::vector;
using std::map;
using std::unordered_set;

map<char, int> priorityMap() {
	string priorities = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	map<char, int> map;

	for (int c = 0; c < priorities.length(); c++) {
		map[priorities[c]] = c + 1;
	}

	return map;
}


string day_3_part_1(const vector<string>& input) {
	map<char, int> priorities = priorityMap();
	int result = 0;

	for (string row : input) {
		unordered_set<char> left(row.begin(), row.begin() + (row.length() / 2));
		unordered_set<char> right(row.begin() + (row.length() / 2), row.end());
		
		for (char item : left) {
			if (right.count(item) > 0) {
				result += priorities[item];
				break;
			}
		}
	}

	return std::to_string(result);
}


string day_3_part_2(const vector<string>& input) {
	map<char, int> priorities = priorityMap();
	
	const int chunkSize = 3;
	vector<vector<string>> groups = vectorChunk(input, chunkSize);
	int result = 0;

	for (vector<string> group : groups) {
		unordered_set<char> sacks[chunkSize];
		for (int i = 0; i < chunkSize; i++) {
			sacks[i] = unordered_set<char>(group[i].begin(), group[i].end());
		}

		unordered_set<char> intersect = intersection<char, chunkSize>(sacks);
		char item = *(intersect.begin());
		result += priorities[item];
	}

	return std::to_string(result);
}