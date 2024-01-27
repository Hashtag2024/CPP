#include<iostream>
#include<conio.h>
#define MAX 5

using namespace std;
int top=-1;
int stack_arr[MAX];
void push()
{
int pushed_item;
if(top == (MAX-1))
cout<<"Stack Overflow \n";
else
{
cout<<"Enter the item to be pushed in stack: ";
cin>>pushed_item;
top=top+1;
stack_arr[top]=pushed_item;
}}

void pop()
{
int i;
if(top == -1)
cout<<"Stack Underflow \n";
else
{
cout<<"Popped item is : "<<stack_arr[top]<<"\n";
top = top-1;
}}
void display()
{
int i;
if(top == -1)
cout<<"Stack is empty\n";
else
{
cout<<"Stack element :\n";
for(i=top; i>=0; i--)
cout<<"\n"<<stack_arr[i]<<"\n";
}}
int main()
{
int choice;
while(1)
{
		cout<<"1: Push\n";
		cout<<"2: Pop\n";
		cout<<"3: Display\n";
		cout<<"4: Quit\n";
		cout<<"Enter your choice: ";
		cin>>(choice);
		switch(choice)
		{
		case 1:push();break;
		case 2:pop();break;
		case 3:display();break;
		case 4:default:exit(1);
		cout<<"Wrong choice\n";
		}}}

