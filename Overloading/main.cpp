#include "Lottery.h"
#include "LottoPlayer.h"
#include <thread>
using namespace std;
using std::chrono::system_clock;


void run() {
	
	int count = 0;
	int draws = 1;
	unsigned lines = 1;
	ofstream file("results.txt", ostream::app);

	cout << "Welcome Player!!" << endl << "Please Enter the amount of draws you would like to be in -> ";

	while (cin >> draws) {
		if (draws >= 1)
			break;
		else
			cout << "Invalid Input Must be 1 or greater. " << endl << "Please Try again ->";
	}

	cout << endl << "How many lines in each draw would you like to play? -> ";
	while (cin >> lines) {
		if (lines >= 1)
			break;
		else
			cout << "Invalid Input Must be 1 or greater. " << endl << "Please Try again ->";
	}

	while (count < draws) {

		
		file << endl << endl << "[ Draw # " << count + 1 << " ] [ Lines Played = " << lines << " ]" << endl;

		//Create winning numbers
		Lottery yo;


		// Create n # of lines to play against the winning numbers
		
		LottoPlayer player(lines);

		cout << endl << "Checking Numbers" << endl;
		int check = player.checkNumbers(yo);

		cout << endl << "Check results.txt for Draw # [" << count+1 << "]" << endl;
		count++;

		cout << endl;
		std::this_thread::sleep_for(1s);
	}
}

int main() {

	thread th(run);
		


	th.join();
	
}