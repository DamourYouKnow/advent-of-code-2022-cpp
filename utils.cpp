#include "utils.h"

using std::string;
using std::vector;

FileReader::FileReader(std::string path) {
	this->file = std::ifstream(path);
}

FileReader::~FileReader() {
	this->file.close();
}

vector<string>* FileReader::readLines() {
	
	if (!this->file.is_open()) {
		throw std::exception("File not open");
	}

	string currLine;
	vector<string>* lines = new vector<string>();

	while (std::getline(this->file, currLine)) {
		lines->push_back(currLine);
	}

	return lines;
}


int vectorSum(const vector<int>& vect) {
	int sum = 0;
	for (int value : vect) {
		sum += value;
	}
	return sum;
}


int vectorMax(const vector<int>& vect) {
	int max = INT_MIN;
	for (int value : vect) {
		if (value > max) {
			max = value;
		}
	}
	return max;
}

