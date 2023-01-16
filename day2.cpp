#include "solutions.h";

#include <map>


enum class Hand {
	Rock,
	Paper,
	Scissors
};


std::string day_2_part_1(const std::vector<std::string>& input) {
	std::map<Hand, Hand> beats = {
		{ Hand::Rock, Hand::Scissors },
		{ Hand::Paper, Hand::Rock },
		{ Hand::Scissors, Hand::Paper }
	};

}
