#ifndef LOTTERY_H
#define LOTTERY_H

#include <iostream>
#include <functional>
#include <random>
#include <vector>
#include <chrono>
#include <ctime>
#include <algorithm>

class LottoPlayer;
class Lottery {
	friend std::ostream& operator << (std::ostream& os, Lottery const& lotto);
	friend bool operator < (Lottery &, Lottery &);

public:
	Lottery();
	Lottery(std::vector<int> &);

	void displayNumbers() const;

	std::vector<int> getNumbers() {
		return this->numbers_;
	}

	static const int LOTTO_SIZE = 6;

private:
	std::vector<int> numbers_;
};





#endif // !LOTTERY_H