//ELEGADO

#include <iostream>
#include <string>
#include<windows.h>

using namespace std;

void gotoxy(short x, short y);

int main() {

    string word = "FIVE";
	int size =(word.length()*2);


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
        for (int j = 0; j < size - 2; ++j) 
		{
			// Print the word
	int x=size/2,y=size/2;
	gotoxy(x,y);
	cout<<word;
	return 0;
		cout << " ";
            
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
void gotoxy(short x, short y)           //definition of gotoxy function//                                               
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
