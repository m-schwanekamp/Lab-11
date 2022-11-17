// Lab 11 
#include <iostream>
#include <cstdlib>

#define COLUMNS 6
#define ROWS 13

using namespace std;

int findSeatIndex(char thisSeat);
int findRowIndex(int thisRow);
void displaySeatColumn(char seats[][ROWS], int column);
char seatLetter(int column);

int main() {
    char seats[COLUMNS][ROWS];
    int row;
    int column;
    int index = 0;

    for (int i = 0; i < COLUMNS; i++) {
        for (int j = 0; j < ROWS; j++) {
            if (i == 2) {
                if (j > 8) {
                    seats[i][j] = '1';
                }
                else {
                    seats[i][j] = ' ';
                }
            }
            else if (i == 3) {
                seats[i][j] = (j + 1) % 10 + 48;
            }
            else {
                seats[i][j] = seatLetter(index);
            }
        }
        if (i != 2 && i != 3) {
            index++;
        }
    }
    for (int i = 0; i < COLUMNS; i++) {
        displaySeatColumn(seats, i);
    }

    cout << "Enter a seat or Q to quit: ";
    cin >> row;
    cin >> column;

    while (!cin.fail()) {
        if (column == 'C' && row == 13 || findRowIndex(row) == -1 || column == 'D' && row == 13 || findSeatIndex(column) == -1) {
            cout << "Sorry, no such seat existss on the CRJ 200." << endl;
        }

        else if (column == 'D' && row == 13 && column == 'C') {
            cout << "Sorry, no such seat exists on the CRJ 200." << endl;
        }

        else if(seats[findSeatIndex(column)][findRowIndex(row)] == 'X') {
            cout << "Sorry, this seat is already taken." << endl;
        }

        else {
            seats[findSeatIndex(column)][findRowIndex(row)] = 'X';
        }

        for (int i = 0; i < COLUMNS; i++) {
            displaySeatColumn(seats, i);
        }

        cout << "Enter a seat or Q to quit: ";
        cin >> row;
        cin >> column;
    }
}

int findSeatIndex(char thisSeat) {
    if (thisSeat == 'A') {
        return(5);
    }

    if (thisSeat == 'B') {
        return(4);
    }

    if (thisSeat == 'C') {
        return(1);
    }

    if (thisSeat == 'D') {
        return(0);
    }

    return -1;
}

int findRowIndex(int thisRow) {
    if (thisRow > 13 || thisRow < 1) {
        return(-1);
    }
    else {
        return(thisRow - 1);
    }
}

void displaySeatColumn(char seats[][ROWS], int column) {
    for (int j = 0; j < ROWS; j++) {
        cout << seats[column][j];
        cout << " ";
    }
    cout << endl;
}

char seatLetter(int column) {
    if (column == 0) {
        return 'D';
    }

    if (column == 1) {
        return 'C';
    }

    if (column == 2) {
        return 'B';
    }

    if (column == 3) {
        return 'A';
    }
}