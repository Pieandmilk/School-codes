#include <iostream>
#include <string>
using namespace std;

int main() {
    int size = 30; // Adjust the size of the square
    string word = "CUTE";

    if (size < word.length()) {
        std::cerr << "Size is too small for the word." << std::endl;
        return 1;
    }

    char topLeft = 201;     
    char topRight = 187;    
    char bottomLeft = 200;  
    char bottomRight = 188; 
    char horizontal = 205;  
    char vertical = 186;    

    // Print the top of the square
    cout << topLeft;
    for (int i = 0; i < size - 2; ++i)
        cout << horizontal;
    cout << topRight << endl;

    // Print the sides of the square
    for (int i = 0; i < size - 2; ++i) {
        cout << vertical;
        for (int j = 0; j < size - 2; ++j) {
            if (i == (size - 2) / 2 && j == (size - word.length()) / 2) {
                cout << word;
                j += word.length() - 1;
            } else {
                cout << " ";
            }
        }
        cout << vertical << endl;
    }

    // Print the bottom of the square
    cout << bottomLeft;
    for (int i = 0; i < size - 2; ++i)
        cout << horizontal;
    cout << bottomRight << endl;

    return 0;
}
