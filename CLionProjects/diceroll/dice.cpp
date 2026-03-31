#include  <iostream>
#include <iomanip>
using namespace std;

int main() {
    int rounds; int xWins = 0, yWins = 0;
    // Ask for number of rounds (1–10)
    cout << "How many rounds? ";
    cin >> rounds;
    while (rounds < 1 || rounds > 10) {
        cout << "Enter a number between 1 and 10: ";
        cin >> rounds;

    }

    for (int r = 1; r <= rounds; r++) {
        int x1, x2, y1, y2;
        int xScore = 0, yScore = 0;
        cout << "Round " << r << ":" << endl;
        cout << "Enter the dice numbers for X: ";
        cin >> x1 >> x2;
        cout << "Enter the dice numbers for Y: ";
        cin >> y1 >> y2;

        // Score for X
        if ((x1 == 1 && x2 ==2) || (x1 == 2 && x2 ==2)) {
            xScore = 1000;
        }
        else if (x1 == x2) {
            xScore = (x1 * 10 + x2) * 10;
        }
        else {
            xScore = x1 * 10 + x2;
        }
        if ((y1 == 1 && y2 == 2) || (y1 == 2 && y2 == 1)) {
            yScore = 1000;
        }
        else if (y1 == y2) {
            yScore = (y1 * 10 + y2) * 10;
        }
        else {
            yScore = y1 * 10 + y2;
        }
        // Determine winner of the round
        if (xScore > yScore) {
            xWins++;
        }
        else if (yScore > xScore) {
            yWins++;
        }
        cout << "X wins " << xWins << " rounds and Y wins " << yWins << " rounds." << endl;
        return 0;
    }
}







