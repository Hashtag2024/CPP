#include<iostream>
using namespace std;
void push();
void pop();
void display();

struct node
{
int info;
struct node *link;
}
*top=NULL;
int main()
{
int choice;
while(1)
{
cout<<"\n";                    
cout<<"1. Push\n";
cout<<"2. Pop\n";
cout<<"3. Display\n";
cout<<"4. Quit\n";
cout<<"Enter ur choice:";
cin>>choice;
switch(choice)
{
case 1: push();
break;
case 2: pop();
break;
case 3: display();
break;
case 4: exit(1);
default: cout<< "wrong choice\n";
}}}
void push()
{
struct node *temp;
int pushed_item,no;
cout<<"how many elements u want to insert:";
cin>> no;
for(int i=1;i<=no;i++)
{
temp= new node;
cout<<"input the values to be pushed on the stack:";
cin>>pushed_item;
temp->info=pushed_item;
temp->link=top;
top=temp;
}}
void pop()
{
struct node *temp;
if(top== NULL)
cout<<"stack is empty\n";
else
{
temp=top;
cout<<"poped items is "<<"->"<<temp->info<<"\n";
top=top->link;
delete temp;
}}
void display()
{
struct node *ptr;
ptr=top;
if(top==NULL)
cout<<"stack is empty\n";
else
{
cout<<"stack elements\n";
while(ptr!=NULL)
{
cout<<"\n"<<ptr->info<<"\n";
ptr=ptr->link;
}}}

