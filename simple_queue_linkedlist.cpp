#include<iostream>
using namespace std;
struct node
{
int info;
struct node *link;
}
*front=NULL, *rear=NULL; 

void insert()
{
struct node *temp;
int add_item,no;
cout<<"how many elements u want to insert into queue: ";
cin>>no;
for(int i=1;i<=no;i++){
temp=new node ;
cout<<"input the new value to be pushed on the stack:";
cin>>add_item;
temp->info=add_item;
temp->link=NULL;
if(front==NULL)
front=temp;
else
rear->link=temp;
rear=temp;
}}
void del(){
struct node *temp;

if(front== NULL)
cout<<"queue is empty\n";
else
{
temp=front;
cout<<"deleted items is "<<"->"<<temp->info<<"\n";
front=front->link;
delete temp;
}}
void display(){
struct node *ptr;
ptr=front;
if(front==NULL)
cout<<"queue is empty\n";
else
{
cout<<"queue elements\n";
while(ptr!=NULL)
{
cout<<"\n"<<ptr->info<<"\n";
ptr=ptr->link;
}
cout<<"\n";
}}
int main(){
int choice;
while(1)
{
cout<<"\n";                    
cout<<"1. Insert\n";
cout<<"2. Delete\n";
cout<<"3. Display\n";
cout<<"4. Quit\n";
cout<<"Enter ur choice:";
cin>>choice;
switch(choice)

{
case 1: insert();
break;
case 2: del();
break;
case 3: display();
break;
case 4: exit(1);
default: cout<< "wrong choice\n";
}}}

