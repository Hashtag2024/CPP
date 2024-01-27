
#include<iostream> 
#include<conio.h> 
#include <stdlib.h>
using namespace std; 
class node
{
public:
int priority;
int data; node *next;};
node *front = NULL;

void insert()
{
node *tmp,*q;
int added_item,item_priority; 
tmp = new node;	
cout<<"input the item value to be added in the queue: ";
cin>>added_item; 
cout<<"enter it's priority: "; 
cin>>item_priority;
tmp->data = added_item; 
tmp->priority = item_priority;
if(front == NULL || item_priority < front->priority){
tmp->next = front; 
front = tmp;
}
else
{
q = front;
while(q->next != NULL && q->next->priority <= item_priority) 
q=q->next;
tmp->next = q->next; 
q->next = tmp;
}}

void del()
{
node *tmp; 
if(front == NULL)
cout<<"queue underflow"; 
else
{
tmp=front;
cout<<"deleted item is "<<tmp->data; 
front = front->next;
delete tmp;
}}
void display()
{
node *ptr; 
ptr = front;
if(front == NULL) 
cout<<"queue is empty"; 
else{
cout<<"priority -> "; 
cout<<"queue"; 
while(ptr != NULL){
cout<<endl<<ptr->priority <<"->"<<ptr->data;
ptr = ptr->next;
}}}
int main()
{
int choice; 
while(1)
{
cout<<"\n main menu"; 
cout<<"\n 1.insert\n"; 
cout<<"2.delete\n";
cout<<"3.display\n"; 
cout<<"4.quit\n";
cout<<"enter your choice: "; 
cin>>choice;
switch(choice)
{
case 1: insert(); break;
case 2: del(); break;
case 3: display(); break;
case 4: exit(1); default:
cout<<"wrong choice";
}}}

