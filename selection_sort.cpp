#include<iostream>
#include<conio.h>
using namespace std;

class selection
{
public:
int a[30];
int n, i, j, temp, loc, min;
	
void get_value()
{
cout<<"Enter the size of your array";
cin>>n; //n is no of element
cout<<"\n Enter the elements of the array\n";
for(i=0;i<n;i++)
{
cin>>a[i]; //inserting element
}
}
	
void display()
{
cout<<"\n Before sorting list is as follow: \n";
for(i=0;i<n;i++)
{
cout<<a[i]<<" ";
}
}
	
void sort()
{	
for(i=0;i<n-1;i++)
{
min=a[i];
loc=i;
for(j=i+1;j<n;j++)
{
if(min>a[j])
{					min=a[j];
loc=j;
}
}
temp=a[i];
a[i]=a[loc];
a[loc]=temp;
}
}
	
void show()
{
cout<<"\n After sorting list is as follow: \n";
for(i=0;i<n;i++)
{
cout<<a[i]<<" ";
}
}
};

int main()
{
cout<<"Selection Sort"<<endl;
selection s;
s.get_value();
s.display();
s.sort();
s.show();	
}

