#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int STONE = 1;
    int PAPER = 2;
    int SCISSOR = 3;
    int userChoice;
    int computerChoice;

    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));

    char playAgain;

    do {
        cout << "******************************************MENU********************************************" << endl;
        cout << "STONE (Write 1)" << endl;
        cout << "PAPER (Write 2)" << endl;
        cout << "SCISSOR (Write 3)" << endl<<endl;
        cout << "*********************************************choice******************************" << endl;

        computerChoice = rand() % 3 + 1;

        cout << "Enter your choice: ";
        cin >> userChoice;

        if (userChoice < 1 || userChoice > 3) {
            cout << "Invalid choice. Please choose a number between 1 and 3." << endl;
            continue; // Restart the loop to get a valid choice
        }

        cout << "*********************************************RESULT******************************" << endl;

        switch (computerChoice) {
            case 1:
                cout << "Computer's choice: STONE (1)" << endl;
                break;
            case 2:
                cout << "Computer's choice: PAPER (2)" << endl;
                break;
            case 3:
                cout << "Computer's choice: SCISSOR (3)" << endl;
                break;
        }

        if (userChoice == computerChoice) {
            cout << "It's a tie!" << endl;
        } else if ((userChoice == STONE && computerChoice == SCISSOR) ||
                   (userChoice == PAPER && computerChoice == STONE) ||
                   (userChoice == SCISSOR && computerChoice == PAPER)) {
            cout << "You won!" << endl;
        } else {
            cout << "Computer won!" << endl;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "THANK YOU!! BYE!!" << endl;

    return 0;
}
