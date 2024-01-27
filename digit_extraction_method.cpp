#include<iostream>
#include<conio.h>

using namespace std;

int main() {
    int hash[19], i = 0, j = 0, x, index, k, first, last, fifth, third;
    
    cout << "Hashing using Digit extraction and linear probing\n";
    cout << "Hash table creation\n";

    for (i = 0; i < 19; i++)
        hash[i] = -1;

    for (j = 0; j < 7; j++) {
        i = 0;
        cout << "Enter number\n";
        cin >> x;
        int temp = x;

        while (x > 0) {
            last = x % 10;
            if (i == 1) {
                fifth = last;
            }
            if (i == 3) {
                third = last;
            }
            if (i == 5) {
                first = last;
            }
            x = x / 10;
            i++;
        }

        index = first * 100 + third * 10 + fifth;
        index = index % 19;

        while (hash[index] != -1)
            index = (index + 1) % 19;

        hash[index] = temp;
    }

    cout << "Hash table:\n";
    for (i = 0; i < 19; i++) {
        cout << i << "\t" << hash[i] << "\n";
    }

    getch();
    return 0;
}

