#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
#include<random>
#include<iomanip>

using namespace std;

int smartModeGen(int pile);

int main() {

	bool play = true;
	char playagain;

	do {

		int mode;
		int valid = 0;
		unsigned seed = time(0);
		
		
		do {

			srand(seed);
			cout << "Welcome to the game of NIM!" << endl;
			cout << "___________________________" << endl;
			cout << "What mode would you like to play?" << endl;
			cout << "0 for Smart Mode, 1 for Dumb Mode, 2 for Random" << endl;
			cin >> mode;
			cin.ignore();

			if (mode < 0 || mode > 2) {
				cout << "Invalid Input." << endl;
			}
			else {

				if (mode == 2) {
					int randmode = rand() % 2;
					mode = randmode;
				}

				if (mode == 0) {
					cout << "Smart Mode Enabled." << endl;
				}
				else if (mode == 1) {
					cout << "Dumb Mode Enabled." << endl;
				}

				valid++;
			}

		} while (valid == 0);

		
			int dumbsize = rand() % 91 + 10; // Generate random number between 10 - 100 to determine pile size
		
			int dumbfirst = rand() % 2; // Generate random number between 0 - 1 to determine first turn

			cout << "Starting pile size: " << dumbsize << " Marbles." << endl;

			// Computer goes first

			if (dumbfirst == 1) {

				bool gameover = false;
				bool humanwin = false;
				bool compwin = false;
				
				cout << "Computer goes first." << endl;

				do {

					int ctake;

					if (mode == 1) { // Dumb Mode
						ctake = rand() % (dumbsize / 2) + 1; 
					}
					else if (mode == 0) { // Smart Mode
						ctake = smartModeGen(dumbsize);
					}

					int dumbhtake;

					if (dumbsize - ctake <= 2) {

						cout << "Computer took " << ctake << " Marble." << endl;
						cout << endl << "You leave the computer with the last marble. You Win!" << endl << endl;
						humanwin = true;
						gameover = true;

					}
					else {

						dumbsize = dumbsize - ctake;

						cout << "Computer took " << ctake << " Marbles. " << endl;
						cout << "Current pile size: " << dumbsize << " Marbles. " << endl;

					}

					if (humanwin == false) {

						for (int dumbvalid = 1; dumbvalid < 2; dumbvalid++) {

							cout << "How many marbles would you like to take (No more than half the pile)? " << endl;
							cin >> dumbhtake;
							cin.ignore();

							if (dumbhtake < 1 || dumbhtake > (dumbsize / 2)) {

								cout << "Invalid number. Enter a number between 1 and " << (dumbsize / 2) << endl;
								dumbvalid = 0;

							}
							else {

								if (dumbsize - dumbhtake <= 2) {

									cout << "You took " << 1 << " Marble." << endl;
									cout << endl << "Computer left you with the last marble. You Lose!" << endl << endl;
									compwin = true;
									gameover = true;

								} else {

									dumbsize = dumbsize - dumbhtake;
									cout << "You took " << dumbhtake << " Marbles." << endl;
									cout << "Current pile size: " << dumbsize << " Marbles." << endl;

								}
							}

						}

					}

	
				} while (gameover == false);

			}

			// Human goes first

			else {

				bool gameover = false;
				bool humanwin = false;
				bool compwin = false;

				cout << "Human goes first." << endl;

				do {

					int dumbhtake;

					for (int dumbvalid = 1; dumbvalid < 2; dumbvalid++) {

						cout << "How many marbles would you like to take (No more than half the pile)? " << endl;
						cin >> dumbhtake;
						cin.ignore();

						if (dumbhtake < 1 || dumbhtake >(dumbsize / 2)) {

							cout << "Invalid number. Enter a number between 1 and " << (dumbsize / 2) << endl;
							dumbvalid = 0;

						}

						else if (dumbsize - dumbhtake <= 2) {

							cout << "You took " << 1 << " Marble." << endl;
							cout << endl << "Computer left you with the last marble. You Lose!" << endl << endl;
							gameover = true;
							compwin = true;

						}
						else {

							dumbsize = dumbsize - dumbhtake;

							cout << "You took " << dumbhtake << " Marbles. " << endl;
							cout << "Current pile size: " << dumbsize << " Marbles. " << endl;

						}

					}

					if (compwin == false) {

						int ctake;

						if (mode == 1) { // Dumb Mode
							ctake = rand() % (dumbsize / 2) + 1;
						}
						else if (mode == 0) { // Smart Mode
							ctake = smartModeGen(dumbsize);
						}

						if (dumbsize - ctake <= 2) {
							cout << "Computer took " << ctake << " Marble." << endl;
							cout << endl << "You leave the computer with the last marble. You Win!" << endl << endl;
							humanwin = true;
							gameover = true;

						}
						else {

							dumbsize = dumbsize - ctake;

							cout << "Computer took " << ctake << " Marbles. " << endl;
							cout << "Current pile size: " << dumbsize << " Marbles. " << endl;

						}


					}


				} while (gameover == false);

			

		}

		for (int i = 1; i < 2; i++) {
			cout << "Would you like to play again (y/n)? " << endl;
			cin.get(playagain);

			switch (playagain) {
			case 'y':
			case 'Y': break;
			case 'n':
			case 'N': play = false; break;
			default: cout << "Invalid Input." << endl; int i = 0;

			}

		} 	

	} while (play == true);

	system("pause");
	return 0;

}

int smartModeGen(int pile) {
	
	unsigned seedtwo = time(0);
	srand(seedtwo);

	int start = pile;
	int endpile = 2;
	while (endpile < pile)
	{
		endpile *= 2;
	}

	endpile = endpile / 2; 
	endpile = endpile - 1;
	
	if (start - endpile == 0 || start - endpile == 1) {
		return rand() % (start / 2) + 1;
	}
	else {
		return start - endpile;
	}



}