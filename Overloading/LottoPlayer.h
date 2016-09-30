#ifndef LOTTO_PLAYER
#define LOTTO_PLAYER

#include <iostream>
#include <functional>
#include <random>
#include <vector>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <fstream>

class Lottery;
class LottoPlayer {
	friend std::ostream& operator << (std::ostream& os, LottoPlayer const& lotto);
public:
	LottoPlayer(); //Constructor to generate 1 number for player
	LottoPlayer(size_t); // Constructor to generate the amount of lines

	int checkNumbers(Lottery);

	static const int PLAYER_SIZE = 6;


private:
	std::vector<int> player_numbers_;
	std::vector<std::vector<int>> line_holder;
};



#endif // !LOTTO_PLAYER

