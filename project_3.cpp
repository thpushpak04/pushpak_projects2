#include <iostream>
using namespace std;

void displayBoard(int space[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (space[i][j] == -1) cout << "X";        //displays the 
            else if (space[i][j] == -2) cout << "O";    //3 x 3 matrices 
            else cout << space[i][j];                   // for tic tac toe game frame
            
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "--+---+--" << endl;
    }
}

bool isMoveValid(int space[3][3], int move) {
    switch(move) {
        case 1: return space[0][0] > 0;
        case 2: return space[0][1] > 0;
        case 3: return space[0][2] > 0;
        case 4: return space[1][0] > 0;          // this function with return type boolean 
        case 5: return space[1][1] > 0;          // will check the user input is valid or not.
        case 6: return space[1][2] > 0;          // if already changed no block can't be change...
        case 7: return space[2][0] > 0;
        case 8: return space[2][1] > 0;
        case 9: return space[2][2] > 0;
        default: return false;
    }
}

void change(int space[3][3], int k, int player) {
    int value = (player == 1) ? -1 : -2;
    switch(k) {
        case 1: space[0][0] = value; break;
        case 2: space[0][1] = value; break;             //will replace the values from block 
        case 3: space[0][2] = value; break;             //with the use of player value as -1 and -2 set value 
        case 4: space[1][0] = value; break;             
        case 5: space[1][1] = value; break;              
        case 6: space[1][2] = value; break;
        case 7: space[2][0] = value; break;
        case 8: space[2][1] = value; break;
        case 9: space[2][2] = value; break;
        default: cout << "Invalid move" << endl; break;
    }
}

bool checkWin(int space[3][3], int player) {
    int value = (player == 1) ? -1 : -2;
                                                                   // will check the conditions for winning the game such as by rows,columns and diagonals.
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (space[i][0] == value && space[i][1] == value && space[i][2] == value) return true;
    }

    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (space[0][i] == value && space[1][i] == value && space[2][i] == value) return true;
    }

    // Check diagonals
    if (space[0][0] == value && space[1][1] == value && space[2][2] == value) return true;     //left diagonal
    if (space[0][2] == value && space[1][1] == value && space[2][0] == value) return true;     //right diagonal

    return false;
}

int main() {
    int space[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    string player1, player2;
    cout << "Enter the name of player 1: ";
    cin >> player1;
    cout << "Enter the name of player 2: ";                     //will take inputs such as name of players 
    cin >> player2;
    
    cout <<endl<< "The name of player 1 is: " << player1 << " and you will mark X" << endl;
    cout << "The name of player 2 is: " << player2 << " and you will mark O" << endl;

    cout <<endl<< "Here is the initial game board:" << endl;
    displayBoard(space);

    int currentPlayer = 1;
    int moveCount = 0;                            // here currentplayer floats between 1 and 2(integer value) 
    const int maxMoves = 9;                       //move count will be from 1 to 9...by which it repeats for 9 times max until winning or draw game

    while (moveCount < maxMoves) {
        int move;
        cout << (currentPlayer == 1 ? player1 : player2) << ", enter the number corresponding to the position you want to mark: ";
        cin >> move;

        if (isMoveValid(space, move)) {
            change(space, move, currentPlayer);                 //if condition takes that move is valid or not
            displayBoard(space);                                //if true than executed chamge func to replace values and displays the final blocks and executes checkwin func
            if (checkWin(space, currentPlayer)) {               // if move is above block values then consider as invalid.
                cout << (currentPlayer == 1 ? player1 : player2) << " IS THE WINNER!" << endl;
                cout << "Game over!" << endl;
                break;
            }
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
            moveCount++;
        } else {
            cout << "Invalid move! Please try again." << endl;
        }
    }

    if (moveCount == maxMoves) {
        cout << "It's a draw!" << endl;                          //if there is all 9 cycles then it considers as draw and displays game over
        cout << "Game over!" << endl;
    }                                                           // Thankyou!! this project was one of the best and challenging ... learnt so much out of it...

    return 0;
}
