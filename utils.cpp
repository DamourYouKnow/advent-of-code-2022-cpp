#include "utils.h"

FileReader::FileReader(std::string path) {
	this->file = std::ifstream(path);
}

FileReader::~FileReader() {
	this->file.close();
}

std::vector<std::string>* FileReader::readLines() {
	
	if (!this->file.is_open()) {
		throw std::exception("File not open");
	}

	std::string currLine;
	std::vector<std::string>* lines = new std::vector<std::string>();

	while (std::getline(this->file, currLine)) {
		lines->push_back(currLine);
	}

	return lines;
}


int vectorSum(const std::vector<int>& vect) {
	int sum = 0;
	for (int value : vect) {
		sum += value;
	}
	return sum;
}


int vectorMax(const std::vector<int>& vect) {
	int max = INT_MIN;
	for (int value : vect) {
		if (value > max) {
			max = value;
		}
	}
	return max;
}

