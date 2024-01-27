#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct node
{
int data;
struct node *link;             
}*start;      
class linklist
{
public:
void create_list();
void disp();
void inslast(int);
void insbeg(int);
void insnext(int,int);
void delbeg();
void delelement(int);
void dellast();
             
linklist()
{
start=NULL;
}};
void linklist::create_list()
{
struct node *q,*tmp;
int d, n;
tmp= new node;
cout<<"Enter how many elements u want to enter";
cin>>n;
for(int i=0;i<n;i++)
{
cout<<"Enter the element:";
cin>>d;
tmp= new node;
tmp->data=d;
tmp->link=NULL;
if(start==NULL)
start=tmp;
else
{
q=start;               
while(q->link!=NULL)
{
q=q->link;
}
q->link=tmp;
} }
return;     
}

void linklist::disp()
{
node *q;
q=start;
if(q==NULL)
{
cout<<" No data is in thelist..";
}
cout<<" The items present in the list are :"<<endl;
while(q!=NULL)
{
cout<<"	"<<q->data;
q=q->link;
cout<<endl;
}}

void linklist:: insbeg(int x)
{
node *q;
q=start;
start=new node;
start->data=x;
start->link=q;
cout<<" Inserted successfully at the begining.."<<endl;
disp();
} 

void linklist:: insnext(int value,int position)
{
node *temp,*q;
int i;
q=start;
for(i=0;i<position-1;i++)
{ 
q=q->link;                                  
if(q==NULL) 
{ 
cout<<"there are less than "<<position << "elements";                                           
return;  
}}
temp=new node;     
temp->link=q->link;
temp->data=value;
q->link=temp;	 
}

void linklist::inslast(int x)
{  
node *q,*t;
if(start==NULL)
{   
start=new node;
start->data=x;
start->link=NULL;
}
else
{	
q=start;
while(q->link!=NULL)
q=q->link;
t=new node;
t->data=x;
t->link=NULL;
q->link=t;
}
cout<<" Inserted successfully at the end.."<<endl;
disp();
}

void linklist::delbeg()
{
node *tmp;
tmp=start;
start=start->link;
delete tmp;
return;
}

void linklist::delelement(int x)
{
node *q,*r;
q=start;
if(q->data==x)
{
start=q->link;
delete q;
return;
}
r=q;
while(q!=NULL)
{
if(q->data==x)
	      {
r->link=q->link;
delete q;
return;
}
r=q;
q=q->link;
}
cout<<" Element u entered"<<x<<"is not found.."<<endl;
}
     
void linklist::dellast()
{
cout<<" The list before deletion:"<<endl;
disp();
node *q,*t;
q=start;
if(q==NULL)
{
cout<<" There is no data in thelist.."<<endl;
return; 
}
if(q->link==NULL)
{
start=q->link;
delete q;
return;
}
while(q->link->link!=NULL)
q=q->link;
q->link=NULL;
}

int main()
{  
linklist l;
linklist l1,l2,l3;
int ch,v,p,ps;
do
{	
cout<<"*****Operations on SINGLY LINKED LIST*****"<<endl;
cout<<"1.Create linklist"<<endl;
cout<<"2.Insertion"<<endl;
cout<<"3.Deletion"<<endl;
cout<<"4.Display"<<endl;
cout<<"5.Exit"<<endl;
cout<<" Enter ur choice:"<<endl;
cin>>ch;
switch(ch)
{   
case 1:
l.create_list();
l.disp(); 
break;
case 2:
cout<<"1.Insertion at begining"<<endl;
cout<<"2.Insertion at the end"<<endl;
cout<<"3.Insertion after the mentioned position"<<endl;
cin>>ps; 
cout<<" Enter the value to insert:"<<endl;
cin>>v;
switch(ps)
{
case 1:l.insbeg(v);break;
case 2:l.inslast(v);break;
case 3:
 cout<<" Enter the position to insert the value:"<<endl;
cin>>p;
l.insnext(v,p);
l.disp();
break;
default:
cout<<" The choice is invalid";	
}
break;
case 3:
cout<<"1.Delete the first element "<<endl;
cout<<"2.Delete the last element"<<endl;
cout<<"3.Enter the element to delete from the list"<<endl;
cout<<" Enter ur choice:"<<endl;
cin>>ps;
switch(ps)
{   
case 1: 
l.delbeg();
cout<<" Thelist after deletion:"<<endl;
l.disp();
break;
case 2:
l.dellast();
cout<<" The list after deletion:"<<endl;
l.disp();
break;
case 3:	
l.disp();
cout<<"Enter the element to delete :"<<endl;
cin>>v;
l.delelement(v);
cout<<" Thelist after deletion:"<<endl;
l.disp(); 
break;
default:
cout<<" The option is invalid...";
break;
}
break;
case 4:l.disp();break;		
case 5:exit(1);
default:
cout<<" The option is invalid...";	 
}
getch();
}
while(1);
getch();
}

