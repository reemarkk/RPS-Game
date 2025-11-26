#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

char getcompmove() {
    int move = rand() % 3;
    if (move == 0) return 'p';
    else if (move == 1) return 's';
    else return 'r';
}

int getresult(char playermove, char computermove) {
    if (computermove == playermove) return 0;
    if (computermove == 'p' && playermove == 's') return -1;
    if (computermove == 'p' && playermove == 'r') return 1;
    if (computermove == 's' && playermove == 'p') return 1;
    if (computermove == 's' && playermove == 'r') return -1;
    if (computermove == 'r' && playermove == 's') return 1;
    if (computermove == 'r' && playermove == 'p') return -1;
    return 0;
}

int main() {
    srand(time(0));

    cout << "\n\t\tWelcome to Rock-Paper-Scissors Game\n";
    cout << "\tEnter r for ROCK, p for PAPER, s for SCISSOR, q to quit\n\n";

    string input;
    int playerScore = 0, computerScore = 0, tieCount = 0;

    while (true) {
        cout << "Your move: ";
        getline(cin, input); // Read entire line

        if (input.empty()) continue; // skip empty input

        char move = tolower(input[0]); // take first character, convert to lowercase

        if (move == 'q') {
            cout << "\nGame Over!\n";
            cout << "Final Scores -> Player: " << playerScore
                 << ", Computer: " << computerScore
                 << ", Ties: " << tieCount << endl;
            break;
        }

        if (move != 'r' && move != 'p' && move != 's') {
            cout << "\tInvalid move. Please try again!" << endl;
            continue;
        }

        char compmove = getcompmove();
        int result = getresult(move, compmove);

        cout << "\tYour move: " << move << endl;
        cout << "\tComputer move: " << compmove << endl;

        if (result == 0) {
            cout << "\tIt is a tie!" << endl;
            tieCount++;
        } else if (result == 1) {
            cout << "\tComputer won the round!" << endl;
            computerScore++;
        } else if (result == -1) {
            cout << "\tCongratulations! Player won the round!" << endl;
            playerScore++;
        }

        cout << "\tCurrent Scores -> Player: " << playerScore
             << ", Computer: " << computerScore
             << ", Ties: " << tieCount << "\n" << endl;
    }

    return 0;
}
