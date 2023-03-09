#include "solutions.h"
#include "utils.h"

#include <tuple>

using std::string;
using std::vector;


int indexOf(string str, char character) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == character) {
			return i;
		}
	}
	return -1;
}


string day_5_part_1(const vector<string>& input) {
	// Identify stack indices line.
	auto predicate = [](const string& item) { 
		return item.length() >= 2 && item[1] == '1';
	};
	int labelIndex = vectorFindIndex<string>(input, predicate);
	string indexLine = input[labelIndex];
	
	// Get number of stacks.
	vector<string> indices = split(indexLine, ' ');
	string last = indices[indices.size() - 1];
	int stackCount = atoi(last.c_str());


	// Create stacks
	vector<char>* stacks = new vector<char>[stackCount];

	for (int stack = 0; stack < stackCount; stack++) {
		int stackIndex = indexOf(indexLine, std::to_string(stack + 1)[0]);

		for (int row = labelIndex - 1; row >= 0; row--) {
			if (input[row][stackIndex] == ' ') break;
			stacks[stack].push_back(input[row][stackIndex]);
		}
	}

	// Process crate moves.
	
	return "";
}
