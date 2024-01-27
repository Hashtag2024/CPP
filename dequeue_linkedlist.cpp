#include<iostream> 
using namespace std;
struct node
{
int info; node *next; node *prev;
}
*front, *rear;

class dqueue
{
public:
int top1,top2; 
void insert(); 
void del(); 
void display(); 
dqueue()
{
top1=0; top2=0; 
front=NULL; 
rear=NULL;
}};

void dqueue::insert()
{
struct node *temp; 
int ch,value; 
if(top1+top2>=50)
{
cout<<"Dequeue Overflow"<<endl; 
return;
}
if(top1+top2==0)
{
cout<<"Enter the value to be Inserted:"; 
cin>>value;
front=new(struct node); 
front->info=value;
front->next=NULL;
front->prev=NULL; 
rear=front; 
top1++;
cout<<"Element inserted into empty dequeue"<<endl;
}
else
{
while(1)
{
cout<<endl;
cout<<"1.Insert Element at First"<<endl; 
cout<<"2.Insert Element at Last"<<endl; 
cout<<"3.Exit"<<endl;
cout<<endl;
cout<<"Enter your choice:"; 
cin>>ch;
cout<<endl; switch(ch)
{
case 1:					cout<<"Enter the value to be inserted:"; 
cin>>value;					temp=new (struct node); 				temp->info=value;					temp->next=front; 				temp->prev=NULL; 				front->prev=temp; 				front=temp; 
top1++;
break;

case 2:					cout<<"Enter the value to be inserted:"; 		cin>>value;					temp=new (struct node); 
temp->info=value;					temp->next=NULL; 				temp->prev=rear; 					rear->next=temp; 					rear=temp;
top2++; 
break; 

case 3: return; break;
default: cout<<"Wrong Choice"<<endl;
}}}}

void dqueue::del()
{
if(top1+top2<=0)
{
cout<<"Deque underflow"<<endl; 
return;
}
int ch; 
while(1)
{
cout<<endl;
cout<<"1.Delete Element at First"<<endl; 
cout<<"2.Delete Element at last"<<endl; 
cout<<"3.Exit"<<endl;
cout<<endl;
cout<<"Enter your choice:"; 
cin>>ch;
cout<<endl; 
switch(ch)
{
case 1: 
front=front->next; 				front->prev=NULL; 
top1--;
break;
case 2:
rear=rear->prev; 
rear->next=NULL; 
top2--;
break;
case 3: return; break;
default: cout<<"Wrong Choice"<<endl;
}}}

void dqueue::display()
{
struct node *temp; 
int ch; 
if(top1+top2<=0)
{
cout<<"Dequeue Underflow"<<endl;
}
while(1)
{
cout<<endl;
cout<<"1.Display deque from Begining"<<endl; 
cout<<"2.Display deque from End"<<endl; 
cout<<"3.exit"<<endl;
cout<<endl;
cout<<"Enter your choice:"; 
cin>>ch;
cout<<endl; 
switch(ch)
{
case 1: 
temp=front;
cout<<"Deque from Begining:"<<endl; 		while(temp!=NULL)
{					cout<<temp->info<<" "; 				temp=temp->next;
}
cout<<endl; 
break;
case 2:
cout<<"Dequeue from End:"<<endl; 
temp=rear;				while(temp!=NULL)
{					cout<<temp->info<<" "; 				temp=temp->prev; 
}
temp=rear; 
cout<<endl; 
break;
case 3: return; break;
default: cout<<"Wrong Choice"<<endl;
}}}

int main()
{
int choice; 
dqueue d1; 
while(1)
{
cout<<"\n	"<<endl;
cout<<"Operations on dequeue"<<endl; 
cout<<"\n	"<<endl;
cout<<"1.Insert Element into Queue"<<endl; 
cout<<"2.Delete Element from Queue"<<endl; 
cout<<"3.Traverse the Dequeue"<<endl; 
cout<<"4.Quit"<<endl;
cout<<"Enter your choice:"; 
cin>>choice;
cout<<endl; 
switch(choice)
{
case 1: d1.insert(); break;
case 2: d1.del(); break;
case 3: d1.display(); break;
case 4: exit(1); break;
default: cout<<"Wrong choice"<<endl;
}}} 


