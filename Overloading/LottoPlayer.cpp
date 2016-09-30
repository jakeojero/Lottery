#include "LottoPlayer.h"
#include "Lottery.h"
#include <bitset>

int free_cnt = 0;
int cnt_2B = 0;
int cnt_3 = 0;
int cnt_4 = 0;
int cnt_5 = 0;
int cnt_5B = 0;
int cnt_6 = 0;

std::ostream& operator << (std::ostream& os, LottoPlayer const& player) {
	os << "Player Numbers" << std::endl;
	for (unsigned i = 0; i < player.line_holder.size(); ++i) {
		os << "[ Line " << i << " ] ";
		for (unsigned j{ 0 }; j < player.line_holder[i].size(); ++j) {

			if (j == LottoPlayer::PLAYER_SIZE)
				os << "Bonus: " << player.line_holder[i][j] << " ";
			else
				os << player.line_holder[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
}


LottoPlayer::LottoPlayer() {
	Lottery::Lottery(this->player_numbers_);
	line_holder.push_back(player_numbers_);
}

LottoPlayer::LottoPlayer(size_t amt) {
	std::cout << "Generating Numbers" << std::endl;
	for (unsigned i{ 0 }; i < amt; ++i) {
		Lottery::Lottery(this->player_numbers_);
		line_holder.reserve(amt);
		line_holder.push_back(player_numbers_);
	}
	
	//sort(line_holder.begin(), line_holder.end());
}

// Returns 1 if all numbers are the same
int LottoPlayer::checkNumbers(Lottery win) {

	unsigned  count = 0;
	auto winner = win.getNumbers();
	bool bonus = false;
	std::ofstream file("results.txt", std::ostream::app);
	std::string prize = "";
	unsigned win_count = 0;

	// current date/time based on current system
	time_t now = time(0);

	// convert now to string form
	char* dt = ctime(&now);

	file << std::endl << std::endl << dt;

	file << "Winning Nums" <<  std::endl;
	for (auto a : winner)
		file << a << " ";

	file << std::endl;


	for (unsigned i = 0; i < line_holder.size(); ++i) {
		for (unsigned j{ 0 }; j < line_holder[i].size()-1; ++j) {

			auto it = find(winner.begin(), winner.end()-1, line_holder[i][j]);

			if (it != winner.end()-1) {
				count++;
			}

			if (line_holder[i][6] == winner[6]) {
				bonus = true;
			}

		}
		
		//If count has 4 matches print winning nums to file
		if (count >= 2) {

			win_count++;

			file << std::endl << "Line " << i << " had " << count << " correct numbers.   Bonus = " << bonus << " [ Numbers ] ";
			for (unsigned j{ 0 }; j < line_holder[i].size(); ++j)
				file << line_holder[i][j] << " ";

			if (bonus) {
				switch (count) {
					case 2:
						cnt_2B++;
						prize = "$5.00";
						file << "[ Prize ] - " << prize << std::endl;
						break;
					case 3:
						cnt_3++;
						prize = "$10.00";
						file << "[ Prize ] - " << prize << std::endl;
						break;
					case 4:
						cnt_4++;
						prize = "$94.30";
						file << "[ Prize ] - " << prize << std::endl;
						break;
					case 5:
						cnt_5B++;
						prize = "$126,330.80";
						file << "[ Prize ] - " << prize << std::endl;
						break;
				}
			}
			else {
				switch (count) {
					case 2:
						free_cnt++;
						prize = "FREE PLAY";
						file << "[ Prize ] - " << prize << std::endl;
						break;
					case 3:
						cnt_3++;
						prize = "$10.00";
						file << "[ Prize ] - " << prize << std::endl;
						break;
					case 4:
						cnt_4++;
						prize = "$94.30";
						file << "[ Prize ] - " << prize << std::endl;
						break;
					case 5:
						cnt_5++;
						prize = "$2,665.20";
						file << "[ Prize ] - " << prize << std::endl;
						break;
					case 6:
						cnt_6++;
						prize = "$7,000,000.00";
						file << "[ Prize ] - " << prize << std::endl;
						break;
				}
			}

			
		}
		
	

		bonus = false;
		count = 0;
	}


	file << std::endl << "[ NUMBER OF WINNERS ] -> " << win_count;
	file << std::endl << "[ Free Plays ] -> " << free_cnt << " [ $5.00 ] -> " << cnt_2B << " [ $10.00 ] -> " << cnt_3 << " [ $96.30 ] -> "
		<< cnt_4 << " [ $2665.20 ] -> " << cnt_5 << " [ $126,330.80 ] -> " << cnt_5B << " [ $7,000,000.00] -> " << cnt_6  << std::endl
		<< "___________________________________________________________________________________________________________________________________________________";

	free_cnt = 0;
	cnt_2B = 0;
	cnt_3 = 0;
	cnt_4 = 0;
	cnt_5 = 0;
	cnt_5B = 0;

	return false;

}
