#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <fstream>
#include <functional>


class FileReader {
private:
	std::ifstream file;

public:
	FileReader(const std::string& path);
	~FileReader();
	std::vector<std::string>* readLines();
};


std::vector<std::string> split(const std::string& str, char target);


template <typename T> 
std::vector<std::vector<T>> vectorChunk(const std::vector<T>& vect, int chunkSize) {
	std::vector<std::vector<T>> chunks;
	std::vector<T> currChunk;

	for (int i = 0; i < vect.size(); i++) {
		currChunk.push_back(vect[i]);
		if (currChunk.size() == chunkSize) {
			chunks.push_back(currChunk);
			currChunk = {};
		}
	}

	if (!currChunk.empty()) {
		chunks.push_back(currChunk);
	}

	return chunks;
}


template <typename T>
std::vector<std::vector<T>> vectorGroup(const std::vector<T>& vect, const std::function<bool(const T&)>& predicate) {
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
std::vector<K> vectorCast(const std::vector<T>& vect, const std::function<K(const T&)>& caster) {
	std::vector<K> result;
	for (T item : vect) {
		result.push_back(caster(item));
	}
	return result;
}


template  <typename T, typename K>
std::vector<K> vectorMap(const std::vector<T>& vect, const std::function<K(const T&)>& func) {
	std::vector<K> result;
	for (T item : vect) {
		result.push_back(func(item));
	}
	return result;
}


template <typename T>
std::vector<T> vectorFilter(const std::vector<T>& vect, const std::function<bool(const T&)>& predicate) {
	std::vector<T> result;
	for (T item : vect) {
		if (predicate(item)) {
			result.push_back(item);
		}
	}
	return result;
}


template <typename T>
int vectorFindIndex(const std::vector<T>& vect, const std::function<bool(const T&)>& predicate) {
	for (int i = 0; i < vect.size(); i++) {
		if (predicate(vect[i])) {
			return i;
		}
	}
	return -1;
}

template <typename T>
int vectorCount(const std::vector<T>& vect, const std::function<bool(const T&)>& predicate) {
	int count = 0;
	for (T item : vect) {
		if (predicate(item)) {
			count += 1;
		}
	}
	return count;
}


int vectorSum(const std::vector<int>& vect);

int vectorMax(const std::vector<int>& vect);


template <typename T, const int size>
std::unordered_set<T> intersection(const std::unordered_set<T>* sets) {
	std::unordered_set<T> result;
	if (sets->size() == 0) {
		return result;
	}

	for (T item : sets[0]) {
		bool allContains = true;
		for (int i = 1; i < size; i++) {
			if (sets[i].find(item) == sets[i].end()) {
				allContains = false;
				break;
			}
		}

		if (allContains) {
			result.insert(item);
		}
	}

	return result;
}
