#include <iostream>
#include <string>
#include <windows.h> 

using namespace std;


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    string word = "CUTIE";
    int wordLength = word.length();

    int boxWidth = wordLength + 2; // Adjusted box width

    char topLeft = 201;     
    char topRight = 187;    
    char bottomLeft = 200;  
    char bottomRight = 188; 
    char horizontal = 205;  
    char vertical = 186;   

    // Print the top of the square
    gotoxy(1, 1);
    cout << topLeft;
    for (int i = 0; i < boxWidth ; ++i)
        cout << horizontal;
    cout << topRight << endl;

    // Print the sides of the square
    gotoxy(1, 2);
    cout << vertical;
    for (int j = 0; j < boxWidth ; ++j) {
        if (j == 1) {
            cout << word;
            j += wordLength - 1;
        } else {
            cout << " ";
        }
    }
    cout << vertical << endl;

    // Print the bottom of the square
    gotoxy(1, 3);
    cout << bottomLeft;
    for (int i = 0; i < boxWidth ; ++i)
        cout << horizontal;
    cout << bottomRight << endl;

    return 0;
}
