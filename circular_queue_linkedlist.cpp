#include<iostream> 
#include<conio.h> 
using namespace std; 
struct cnode
{
int data;
struct cnode *link;
};
struct cnode *start=NULL, *last=NULL; void create();
void display(); void search(); void insert(); void delete1(); void count();

int main()
{
int choice; cout<<"1:Create\n2:Display\n3.Insert\n4.Delete\n5.Exit\n"; cout<<"\nEnter Your choice\n"; cin>>choice;
while(choice)
{
switch(choice)
{
case 1:
create(); break;
case 2:
display(); break;
case 3:
insert(); break;
case 4:
delete1(); break;
case 5:
exit(0); default :
cout<<"\nInvalid Choice";break;
}
cout<<"\n1:Create\n2:Display\n3.Ins ert\n4.Delete\n5.Exit\n";
cout<<"\nEnter Your choice\n"; cin>>choice;
}}

void create()
{
struct cnode *tmp; int no;
cout<<"How many node u want to enter\n";
cin>>no;
for(int i=1; i<=no;i++)
{
tmp=new cnode;
cout<<"Enter the item to be created: "; cin>>tmp->data;
tmp->link=NULL; if(start==NULL)
start=tmp; else
last->link=tmp; last=tmp;
last->link=start;
}}

void display()
{
if(start==NULL)
cout<<"\ndata element to be displayed"; else
{
struct cnode *temp=start;
cout<<"The element of a linked p are:\n"; do
{
cout<<temp->data<<"->\t";
temp=temp->link;
}
while(temp!=start);
}}

void insert()
{
struct cnode *tmp,*prev,*cur,*temp; int count=1,posi,choice,length=1; tmp = new cnode;
cout<<"\nEnter the data to be inserted : "; cin>>tmp->data;
tmp->link=NULL;
prev=NULL; cur=start; temp=start; cout<<"\nSelect the option of insertion"; cout<<"\n1.At the begin\n2.At the end\n3.In between : ";
cin>>choice; switch(choice)
{
case 1:
tmp->link=start; start=tmp;
last->link=start; break;
case 2:
last->link=tmp; last=tmp;
last->link=start; break;
case 3:
while(temp!=last)
{
temp=temp->link;
length=length+1;
}
cout<<"\nEnter the position between 1st & "<<length<<"\t";
cin>>posi; if((posi<2)||(posi>length))
{
cout<<"Invalid Position"; break;
}
while((count<posi)&&(cur!=NULL))
{
prev=cur;
cur=cur->link; count++;
}
prev->link=tmp; tmp->link=cur; break;
default:
cout<<"\nInvalid Choice\n";
}}
void delete1()
{
struct cnode
*temp=start,*prev=NULL,*cur=start; int choice,posi,count=1,item,length=1; if(start==NULL)
cout<<"\ndata cnode"; else
{
cout<<"\nEnter the type of deletion:";
cout<<"\n1.Delete the start cnode\n 2.Delete the last cnode\n 3.Delete based on position\n 4.Delete all \n";
cin>>choice;
if(choice<1||choice>4)
cout<<"\nInvalid choice";	else
{
switch(choice)
{
case 1:
cout<<"The deleted element is "<<start->data;
start=start->link; last->link=start; break;
case 2:
cout<<"\nThe deleted element is"<<last->data;
if(start==last) start=last=NULL; else
{
while(temp!=last)
{
prev=temp; temp=temp->link;
}
prev->link=start; last=prev;
}
break; case 3:
while(temp!=last)
{
temp=temp->link; length++;
}
cout<<"\nEnter the position of deletion : ";
cin>>posi; if((posi<1)||(posi>length))
{
cout<<"\nInvalid Position"; break;
}
else
{

while(count<posi)
{
prev=cur; cur=cur->link;
count++;
}
cout<<"\nThe deleted element is"<<cur->data;
cur=cur->link; prev->link=cur; break;
}
case 4:
start=last=NULL;
cout<<"\nAll elements have been deleted";
break;
}}}}

