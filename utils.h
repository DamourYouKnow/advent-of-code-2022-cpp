#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <functional>


class FileReader {
private:
	std::ifstream file;

public:
	FileReader(std::string path);
	~FileReader();
	std::vector<std::string>* readLines();
};


template <typename T>
std::vector<std::vector<T>> vectorGroup(const std::vector<T>& vect, std::function<bool(T)> predicate) {
	std::vector<std::vector<T>> groups;
	std::vector<T> currGroup;

	for (T item : vect) {
		if (predicate(item)) {
			groups.push_back(currGroup);
			currGroup = {};
		}
		else {
			currGroup.push_back(item);
		}
	}

	if (!currGroup.empty()) {
		groups.push_back(currGroup);
	}

	return groups;
}


template <typename T, typename K>
std::vector<K> vectorCast(const std::vector<T>& vect, std::function<K(T)> caster) {
	std::vector<K> result;
	for (T item : vect) {
		result.push_back(caster(item));
	}
	return result;
}


int vectorSum(const std::vector<int>& vect);

int vectorMax(const std::vector<int>& vect);

std::vector<std::vector<std::string>> split(const std::string& target, const std::string& delimiter);

