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


struct MoveOrder {
	int source;
	int destination;
	int amount;

	MoveOrder(int source, int destination, int amount) {
		this->source = source;
		this->destination = destination;
		this->amount = amount;
	}
};


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


	// Create stacks.
	vector<char>* stacks = new vector<char>[stackCount];

	for (int stack = 0; stack < stackCount; stack++) {
		int stackIndex = indexOf(indexLine, std::to_string(stack + 1)[0]);

		for (int row = labelIndex - 1; row >= 0; row--) {
			if (input[row][stackIndex] == ' ') break;
			stacks[stack].push_back(input[row][stackIndex]);
		}
	}

	// Parse move list.
	vector<string> moveList(input.begin() + labelIndex + 2, input.end());
	auto mapFn = [](const string& order) {
		vector<string> spl = split(order, ' ');
		return MoveOrder(atoi(spl[3].c_str()) - 1, atoi(spl[5].c_str()) - 1, atoi(spl[1].c_str()));
	};
	vector<MoveOrder> moves = vectorMap<string, MoveOrder>(moveList, mapFn);

	// Execute moves.
	for (MoveOrder move : moves) {
		for (int i = 0; i < move.amount; i++) {
			char item = stacks[move.source].back();
			stacks[move.source].pop_back();
			stacks[move.destination].push_back(item);
		}
	}

	// Get top crates.
	string result = "";
	for (int i = 0; i < stackCount; i++) {
		result += stacks[i].back();
	}
	
	return result;
}


string day_5_part_2(const vector<string>& input) {
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


	// Create stacks.
	vector<char>* stacks = new vector<char>[stackCount];

	for (int stack = 0; stack < stackCount; stack++) {
		int stackIndex = indexOf(indexLine, std::to_string(stack + 1)[0]);

		for (int row = labelIndex - 1; row >= 0; row--) {
			if (input[row][stackIndex] == ' ') break;
			stacks[stack].push_back(input[row][stackIndex]);
		}
	}

	// Parse move list.
	vector<string> moveList(input.begin() + labelIndex + 2, input.end());
	auto mapFn = [](const string& order) {
		vector<string> spl = split(order, ' ');
		return MoveOrder(atoi(spl[3].c_str()) - 1, atoi(spl[5].c_str()) - 1, atoi(spl[1].c_str()));
	};
	vector<MoveOrder> moves = vectorMap<string, MoveOrder>(moveList, mapFn);

	// Execute moves.
	for (MoveOrder move : moves) {
		vector<char> moving;

		for (int i = 0; i < move.amount; i++) {
			char item = stacks[move.source].back();
			stacks[move.source].pop_back();
			moving.push_back(item);
		}

		while (!moving.empty()) {
			char item = moving.back();
			stacks[move.destination].push_back(item);
			moving.pop_back();
		}
	}

	// Get top crates.
	string result = "";
	for (int i = 0; i < stackCount; i++) {
		result += stacks[i].back();
	}

	return result;
}
