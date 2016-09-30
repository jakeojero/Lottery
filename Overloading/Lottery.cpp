#include "Lottery.h"

std::ostream& operator << (std::ostream& os, Lottery const& lotto) {
	os << "Winning Numbers" << std::endl;
	for (int i{ 0 }; i < Lottery::LOTTO_SIZE + 1; ++i) {
		if (i == Lottery::LOTTO_SIZE)
			os << "Bonus: " << lotto.numbers_[i] << " ";
		else
			os << lotto.numbers_[i] << " ";
	}

	return os;
}

bool operator < (Lottery &lhs, Lottery &rhs) {
	return lhs.numbers_[0] < rhs.numbers_[0];
}

// Constructor
Lottery::Lottery() {

	if (LOTTO_SIZE > 49) {
		std::cerr << "Infinite loop caused, Number must be greater than 49" << std::endl;
			exit(1);
	}
		

	numbers_.reserve(Lottery::LOTTO_SIZE+1);
	numbers_.resize(Lottery::LOTTO_SIZE+1);

	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine engine(seed);
	std::uniform_int_distribution<> dist(1, 49);		// functor == object that behaves like a function
	auto generator = bind(dist, engine);

	//fill
	auto beg = numbers_.begin();

	for (int i{ 0 }; i < Lottery::LOTTO_SIZE; ++i) {

		int num = generator();

		auto it = find(beg, numbers_.end(), num);

		if (it != numbers_.end())
			i--;
		else {
			numbers_[i] = num;
		}

	}
	
	sort(numbers_.begin(), numbers_.end()-1);


	while (true) {
		int bonus = generator();

		auto it = find(beg, numbers_.end()-1, bonus);
		
		// add bonus to last element
		if (it == numbers_.end() - 1) {
			numbers_[Lottery::LOTTO_SIZE] = bonus;
			break;
		}
		else
			continue;

	}
	

}

Lottery::Lottery(std::vector<int> &player_vec) {

	if (LOTTO_SIZE > 49) {
		std::cerr << "Infinite loop caused, Number must be greater than 49" << std::endl;
		exit(1);
	}


	player_vec.reserve(Lottery::LOTTO_SIZE + 1);
	player_vec.resize(Lottery::LOTTO_SIZE + 1);

	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine engine(seed);
	std::uniform_int_distribution<> dist(1, 49);		// functor == object that behaves like a function
	auto generator = bind(dist, engine);

	//fill
	auto beg = player_vec.begin();

	for (int i{ 0 }; i < Lottery::LOTTO_SIZE; ++i) {

		int num = generator();

		auto it = find(beg, player_vec.end(), num);

		if (it != player_vec.end())
			i--;
		else {
			player_vec[i] = num;
		}

	}

	sort(player_vec.begin(), player_vec.end() - 1);


	while (true) {
		int bonus = generator();

		auto it = find(beg, player_vec.end() - 1, bonus);

		// add bonus to last element
		if (it == player_vec.end() - 1) {
			player_vec[Lottery::LOTTO_SIZE] = bonus;
			break;
		}
		else
			continue;

	}


}



void Lottery::displayNumbers() const {
	std::cout << "Winning Numbers" << std::endl;

	for (int i{ 0 }; i < Lottery::LOTTO_SIZE+1; ++i) {
			
		if(i == LOTTO_SIZE)
			std::cout << "Bonus: " << numbers_[i] << " ";
		else
			std::cout << numbers_[i] << " ";
	}

	std::cout << std::endl;
}








