#include<iostream> 
#include<conio.h> 
using namespace std; 
int main()
{
int hash[19],i=0,j=0,x,index,k,first, second, four, last, fifth, third, six;
cout<<"Hashing using linear probing\n"; 
cout<<"Hash table creation\n"; for(i=0;i<19;i++)
hash[i]=-1; 
for(j=0;j<9;j++)
{
i=1;
cout<<"Enter number\n"; cin>>x;
int temp =x; while(x>0)
{
last = x%10; if(i==2)
{
fifth = last;
}
if(i==4)
{
third = last;
}
if(i==6)
{
first = last;
}
if(i==1)
{
six = last;
}
 

if(i==3)
{
four = last;
}
if(i==5)
{
second = last;
}
x = x/10; i++;
}
int temp1 = second*10+first; 
int temp2 = third*10+four; 
int temp3 = six*10+fifth;
int tempres = temp1+temp2+temp3; 
cout << tempres;
int r=0; if(tempres>19)
{
index = tempres % 19;
}
else
{
index = tempres;
}
cout<<"("<<index<<")\n"; 
while(hash[index]!=-1) 
index=(index+1)%19; 
hash[index] = temp;
}
for(i=0;i<19;i++)
{
cout<<i<<"\t"<<hash[i]<<"\n";
}
getch();
}
 


