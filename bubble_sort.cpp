#include<conio.h> 
#include<stdio.h> 
#include<iostream> 
using namespace std;

class bubble
{
private:
int array[10]; int n;
public:
void insert(); 
void sort(); 
void display();
};
void bubble::insert()
{
cout<<"enter the number of array:"; cin>>n;
cout<<"now enter elements"<<"\n"; for(int i=0;i<n;i++)
{

cin>>array[i];
}
}
void bubble::sort()
{
int i,j,temp;
 
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(array[j]>array[j+1])
{
temp=array[j]; 
array[j]=array[j+1]; 
array[j+1]=temp;
}
}
}
}
void bubble::display()
{
cout<<"the sorted numbers are"<<"\n"; for(int i=0;i<n;i++)
cout<<array[i]<<"\t"; cout<<endl;
}
int main()
{
bubble obj; 
obj.insert();
obj.sort(); 
obj.display(); 
getch(); 
return 0;
}

