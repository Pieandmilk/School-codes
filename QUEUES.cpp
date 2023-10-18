#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

const int MAX = 7;

// Function to set the cursor position
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Queue {
private:
    int QUEUE[MAX] = {0};
    int ii; // Head index
    int di; // Tail index

public:
    Queue() {
        ii = 0;
        di = 0;
    }

    bool isFull() {
        // Determine if the queue is full 
        return ((ii == di - 2) || (ii == di - 2 + MAX));
    }

    void push(int item) {
        if (isFull()) {
            cout << "Queue full" << endl;
            Sleep(900);
            return;
        }

        QUEUE[ii] = item;
        ii = (ii + 1) % MAX;
    }

    void pop(int &item) {
        if (di == ii) {
            cout << "Queue empty" << endl;
            Sleep(900);
            return;
        }

        item = QUEUE[di];
        QUEUE[di] = 0; // Clear the item in the queue
        di = (di + 1) % MAX;
    }

    void display() {
        // Box drawing characters
        char topLeft = 201;
        char topRight = 187;
        char bottomLeft = 200;
        char bottomRight = 188;
        char horizontal = 205;
        char vertical = 186;

        // Set the position for the box
        int x = 5;
        int y = 5;
        int width = 45; 
        int height = 13;

        // Draw the box
        gotoxy(x, y);
        cout << topLeft;
        gotoxy(x + width, y);
        cout << topRight;
        gotoxy(x, y + height);
        cout << bottomLeft;
        gotoxy(x + width, y + height);
        cout << bottomRight;

        for (int i = x + 1; i < x + width; i++) {
            gotoxy(i, y);
            cout << horizontal;
            gotoxy(i, y + height);
            cout << horizontal;
        }

        for (int i = y + 1; i < y + height; i++) {
            gotoxy(x, i);
            cout << vertical;
            gotoxy(x + width, i);
            cout << vertical;
        }

        // Set the position for the text and queue display
        int textX = x + 2;
        int textY = y + 1;

        // Clear the area inside the box
        for (int i = 0; i < height - 2; i++) {
            gotoxy(textX, textY + i);
            cout << "                                           ";
        }

        // Display the queue and indexes
        gotoxy(textX, textY);
        cout << "Queue:";
        gotoxy(textX, textY + 1);
        cout << "      ";

        int start = di;  // Starting index for display
        int count = 0;   // Count of displayed elements

        while (count < MAX) {
            if (QUEUE[start] != 0) {
                cout << setw(2) << QUEUE[start] << " ";
            }
            start = (start + 1) % MAX;
            count++;
        }

        gotoxy(textX, textY + 2);
        cout << "Index:";
        gotoxy(textX, textY + 3);
        cout << "      ";

        start = di;  // Starting index for display
        count = 0;   // Count of displayed elements

        while (count < MAX) {
            if (QUEUE[start] != 0) {
                cout << setw(2) << start << " ";
            }
            start = (start + 1) % MAX;
            count++;
        }
    }
};

int main() {
    Queue queue;
    int choice, item;

    while (true) {
        system("CLS");
        queue.display(); // Display the queue and indexes inside a box

        gotoxy(9, 12); // Set the position for the menu and input
        cout << "1. Push" << endl;
        gotoxy(9, 13);
        cout << "2. Pop" << endl;
        gotoxy(9, 14);
        cout << "3. Exit" << endl;
        gotoxy(9, 15);
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (queue.isFull()) {
                    gotoxy(9, 17);
                    cout << "Queue full" << endl;
                    Sleep(900);
                } else {
                    gotoxy(9, 17);
                    cout << "Enter item to push: ";
                    cin >> item;
                    queue.push(item);
                }
                break;
            case 2:
                queue.pop(item);
                gotoxy(9, 17);
                cout << "Popped: " << item << endl;
                Sleep(600);
                break;
            case 3:
                return 0;
            default:
                gotoxy(9, 17);
                cout << "Invalid choice. Try again." << endl;
                Sleep(600);
        }
    }

    return 0;
}
