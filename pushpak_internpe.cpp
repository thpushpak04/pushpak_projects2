#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int x; // throughout the program
int guess; // throughout the program
int trial = 0;

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));

    // Menu for users suitable gameplay
    while (true) {
        cout << "******************************************MENU********************************************" << endl;
        cout << "EASY MODE (WRITE 1)" << endl;
        cout << "intermediate Mode (Write 2)" << endl;
        cout << "Hard Mode (write 3)" << endl;

        int choice;
        cin >> choice;

        switch(choice) {
            case 1:
                x = 10;
                trial=trial+1; // increment by 1
                cout<<"trial:"<<trial<< endl;
                cout << "Enter Guess (1-" << x << "): "<< endl;
                //easy();
                break;
            case 2:
                x = 100;
                trial=trial+1;
                cout<<"trial:"<<trial<< endl;
                cout << "Enter Guess (1-" << x << "): "<< endl;
                break;
            case 3:
                x = 1000;
                trial=trial+1;
                cout<<"trial:"<<trial<< endl;
                cout << "Enter Guess (1-" << x << "): "<< endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                continue; // Go back to the start of the loop
        }

        int number = rand() % x + 1;
        
        do {
            cin >> guess; // getting the user input (guess value number)

            if (guess > x || guess <= 0) {
                cout << "Invalid guess! Enter a number within the range (1-" << x << ")." << endl;
                continue; // Skip the rest of the loop and get a new guess
            }

            if (guess > number){
                cout << "Guess lower!" << endl;
                trial=trial+1;
                cout<<"trial:"<<trial<< endl;

            }
            else if (guess < number){
                cout << "Guess higher!" << endl;
                trial=trial+1;
                cout<<"trial:"<<trial<< endl;
            }
            else {
                cout << "You won!" << endl;
                cout<<"Total trial count : "<< trial <<endl; // total trial count for a user
            }

        } while (guess != number);

        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        trial = 0;

        if (playAgain != 'y') {
            cout << "THANK YOU!! BYE!!";
            break; // Exit the loop if the user doesn't want to play again
        }
    }

    return 0; // This line should be outside the while loop
}
