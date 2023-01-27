#include "solutions.h"
#include "utils.h"

#include <tuple>

using std::string;
using std::vector;
using std::tuple;


struct Range {
	int min;
	int max;

	Range(int initMin, int initMax) {
		min = initMin;
		max = initMax;
	}

	bool contains(Range& other) {
		return max >= other.max && min <= other.min;
	}

	bool intersects(Range& other) {
		return contains(other) || other.contains(*this);
	}

	bool partialContains(Range& other) {
		return max >= other.min ? min <= other.max : max >= other.min;
	}

	bool partialIntersects(Range& other) {
		return partialContains(other) || other.partialContains(*this);
	}
};


tuple<Range, Range> getRanges(const string& str) {
	vector<string> spl = split(str, ',');
	string left = spl[0];
	string right = spl[1];
	return tuple<Range, Range>(
		Range(stoi(split(left, '-')[0]), stoi(split(left, '-')[1])),
		Range(stoi(split(right, '-')[0]), stoi(split(right, '-')[1]))
	);
}


string day_4_part_1(const vector<string>& input) {
	using std::stoi;

	vector<tuple<Range, Range>> assignments;

	for (string row : input) {
		assignments.push_back(getRanges(row));
	}

	auto filter = [](tuple<Range, Range> ranges) {
		return std::get<0>(ranges).intersects(std::get<1>(ranges));
	};

	return std::to_string(vectorCount<tuple<Range, Range>>(assignments, filter));
}


string day_4_part_2(const vector<string>& input) {
	using std::stoi;

	vector<tuple<Range, Range>> assignments;

	for (string row : input) {
		assignments.push_back(getRanges(row));
	}

	auto filter = [](tuple<Range, Range> ranges) {
		return std::get<0>(ranges).partialIntersects(std::get<1>(ranges));
	};

	return std::to_string(vectorCount<tuple<Range, Range>>(assignments, filter));
}
