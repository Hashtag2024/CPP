#include<iostream>
#include<conio.h>
using namespace std;

class linear_search {
public:
int a[5], num, i;
void getdata();
void search();
};

void linear_search::getdata() {
cout << "Enter the array elements: ";
for (i = 0; i < 5; i++) {
cin >> a[i];
}
cout << "\nEntered array elements: ";
for (i = 0; i < 5; i++) {
cout << a[i] << " ";
}
cout << "\nEnter the number to search: ";
cin >> num;
}

void linear_search::search() {
for (i = 0; i < 5; i++) {
if (a[i] == num) {
cout << "\nNumber found at position " << i;
return; 
}
}
cout << "\nNumber not found";
}

int main() {
linear_search s;
s.getdata();
s.search();
getch(); 
return 0; 
}


