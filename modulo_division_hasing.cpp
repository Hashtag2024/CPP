#include<iostream> 
#include<conio.h> 
using namespace std;
int hashsearch(int a[],int x , int n)
{ 
int index,start; 
index=x%n; 
if(a[index]==x)
return index; 
else
{ 
start=index; 
do
{ 
index=(index+1)%n; 
if(a[index]==x)
return index; 
else
if(a[index]==-1) 
break; 
} 
while(index!=start); 
return -1; 
}}
int main()
{
int hash[13],i,x,index,k;
cout<<"Hashing using Modulo division and linear probing\n";
cout<<"Hash table creation\n"; for(i=0;i<13;i++)
 

hash[i]=-1; 
for(i=0;i<7;i++)
{ 
cout<<"Enter number\n"; 
cin>>x;
index=x%13; 
while(hash[index]!=-1) 
index=(index+1)%13; 
hash[index]=x; }
cout<<"Hash table\n"; 
for(i=0;i<13;i++) 
cout<<i<<"\t"<<hash[i]<<"\n"; 
do
{cout<<"Elements to be searched to stop enter -1\n";
cin>>x; 
if(x>=0)
{ k=hashsearch(hash,x,13); 
if(k>=0)
cout<<"Element"<<x<<"is present at hash index["<<k<<"]"<<endl;
else
cout<<"not present";
}}
while(x>=0); 
getch();
}

