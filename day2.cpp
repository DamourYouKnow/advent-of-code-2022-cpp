#include "solutions.h"

#include <map>


enum class Hand : int {
	Rock,
	Paper,
	Scissors
};


struct Round {
	Hand player;
	Hand opponent;
	
	Round(Hand initPlayer, Hand initOpponent) {
		player = initPlayer;
		opponent = initOpponent;
	}
};


Round parseRound(std::string& round, const std::map<char, Hand>& hands) {
	return Round(hands.at(round[0]), hands.at(round[2]));
}


int scoreRound(const Round& round, const std::map<Hand, int>& worth, const std::map<Hand, Hand>& beats) {
	int playerWorth = worth.at(round.player);

	if (beats.at(round.player) == round.opponent) {
		// Player wins
		return playerWorth + 6;
	}
	else if (beats.at(round.opponent) == round.player) {
		// Player loses
		return playerWorth;
	}
	else {
		// Draw
		return playerWorth + 3;
	}
}


std::string day_2_part_1(const std::vector<std::string>& input) {
	std::map<char, Hand> hands = {
		{ 'X', Hand::Rock },
		{ 'Y', Hand::Paper },
		{ 'Z', Hand::Scissors },
		{ 'A', Hand::Rock },
		{ 'B', Hand::Paper },
		{ 'C', Hand::Scissors }
	};
	
	std::map<Hand, Hand> beats = {
		{ Hand::Rock, Hand::Scissors },
		{ Hand::Paper, Hand::Rock },
		{ Hand::Scissors, Hand::Paper }
	};

	std::map<Hand, int> worth = {
		{ Hand::Rock, 1 },
		{ Hand::Paper, 2 },
		{ Hand::Scissors, 3 }
	};

	int score = 0;
	for (std::string row : input) {
		Round round = parseRound(row, hands);
		score += scoreRound(round, worth, beats);
	}

	return std::to_string(score);
}


std::string day_2_part_2(const std::vector<std::string>& input) {
	std::map<char, Hand> hands = {
		{ 'X', Hand::Rock },
		{ 'Y', Hand::Paper },
		{ 'Z', Hand::Scissors },
		{ 'A', Hand::Rock },
		{ 'B', Hand::Paper },
		{ 'C', Hand::Scissors }
	};

	std::map<Hand, Hand> beats = {
		{ Hand::Rock, Hand::Scissors },
		{ Hand::Paper, Hand::Rock },
		{ Hand::Scissors, Hand::Paper }
	};

	std::map<Hand, Hand> loses = {
		{ Hand::Rock, Hand::Paper },
		{ Hand::Paper, Hand::Scissors },
		{ Hand::Scissors, Hand::Rock }
	};

	std::map<Hand, int> worth = {
		{ Hand::Rock, 1 },
		{ Hand::Paper, 2 },
		{ Hand::Scissors, 3 }
	};

	int score = 0;
	for (std::string row : input) {
		char opponent = row[0];
		char action = row[2];

		if (action == 'Z') {
			// Player must win
			score += worth[beats[hands[opponent]]] + 6;

		}
		else if (action == 'X') {
			// Player must lose
			score += worth[loses[hands[opponent]]];
		}
		else {
			// Round must end in a draw
			score += worth[hands[opponent]];
		}
	}
	
	return std::to_string(score);
}