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
