#include<iostream>
using namespace std;
class binary_search
{
public:
int a[5], flag;
int i, j, index, num, temp, mid, low, high;

void getdata();
void search();
void sort_array();
binary_search() {
flag = false;
}};
void binary_search::sort_array()
{
for(int i = 0; i < 5; i++)
{
for(int j = 0; j < 4; j++) // Changed i < 5 to j < 4
{
if(a[j] > a[j + 1])
{
temp = a[j + 1];
a[j + 1] = a[j];
a[j] = temp;
}}}}

void binary_search::getdata()
{
cout << "\n Enter array elements: ";
for(i = 0; i < 5; i++)
{
cin >> a[i];
}
sort_array();
cout << "\n Sorted array elements: ";
for(i = 0; i < 5; i++)
{
cout << a[i] << " ";
}}
void binary_search::search()
{
cout << "\n Enter an element to search: ";
cin >> num;
low = 0;
high = 4;
flag = false; // Reset flag to false before searching
while(low <= high)
{
mid = (low + high) / 2;
if(a[mid] == num)
{
cout << "\n Number is found at position " << mid;
flag = true; // Set flag to true when the number is found
break;
}
if(a[mid] > num)
{
high = mid - 1;
}
if(a[mid] < num)
{
low = mid + 1;
}}
if(!flag)
{
cout << "\n Number is not found!!!";
}}
int main()
{
binary_search b;
b.getdata();
b.search();
cin.get();
return 0;
}

