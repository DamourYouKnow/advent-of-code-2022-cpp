#include "solutions.h";

#include <map>


enum class Hand : int {
	Rock,
	Paper,
	Scissors
};


struct Round {
	Hand player;
	Hand opponent;
	
	Round(Hand player, Hand opponent) {
		player = player;
		opponent = opponent;
	}
};


Round parseRound(std::string& round) {
	std::vector<std::string> spl = split(round, " ");

	std::map<std::string, Hand> handMap = {
		{ "X", Hand::Rock },
		{ "Y", Hand::Paper },
		{ "Z", Hand::Scissors },
		{ "A", Hand::Rock },
		{ "B", Hand::Paper },
		{ "C", Hand::Scissors }
	};

	return Round(handMap[spl[0]], handMap[spl[1]]);
	
}


std::string day_2_part_1(const std::vector<std::string>& input) {
	std::map<Hand, Hand> beats = {
		{ Hand::Rock, Hand::Scissors },
		{ Hand::Paper, Hand::Rock },
		{ Hand::Scissors, Hand::Paper }
	};

	
}
