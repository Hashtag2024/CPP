#include<iostream>
#include<conio.h>
using namespace std;
struct dnode
{
int data;
struct dnode *prev;
struct dnode *next;
};
struct dnode *start=NULL, *last=NULL;
void create();
void insert();
void display();
void delete1();
void search();
void count();
void rev();
int main()
{  
int choice;    
cout<<"1:Create\n 2:Insert\n 3.Display\n 4.Delete\n 5.Search\n 6.Count\n 7.Reverse\n 8.Exit\n";
cout<<"Enter Your choice:";
cin>>choice;
while(choice)
{   
switch(choice)
{     
case 1:create();display();break;
case 2:insert();display();break;
case 3:display();break;
case 4:delete1();display();break;
case 5:search();break;
case 6:count();break;
case 7:rev();break;
case 8:exit(1);break;
default : cout<<"\nInvalid Choice";break;     
}
cout<<"\nEnter Your choice\n";	           cout<<"1:Create\n2:Insert\n3.Display\n4.Delete\n5.Search\n6.Count\n7.Reverse\n 8.Exit\n";
cout<<"\nEnter Your choice:";
cin>>choice;   
}
}

void create()
{  
struct dnode *tmp;
int no;
     cout<<"How many element u want to insert: ";
     cin>>no;
     for(int i=1;i<=no;i++)
     {   
tmp=new dnode;
         cout<<"Enter the item to be created: ";
         cin>>tmp->data;
         tmp->prev=NULL;
         tmp->next=NULL;
         if(start==NULL)
         start=tmp;
         else
         {       
                 last->next=tmp;
                 tmp->prev=last;   	
         }
         last=tmp;	  
     } 
}

void display()
{  
     if(start==NULL)
     cout<<"\nNo element to be displayed";
     else	
     {     
           struct dnode *temp=start;
           cout<<"\nThe element of a doubly linked list are:\n";
           while(temp!=NULL)
           {	
               cout<<temp->data<<"->\t";
	           temp=temp->next;
            }   
     }	
}

void search()
{   
    if(start==NULL)
    cout<<"\n!!! No Element !!!\n";
    else
    {      
           struct dnode *temp=start;
           int ele,posi=1;
           cout<<"Enter the element to be searched: ";
           cin>>ele; 
           while((temp!=last)&&(temp->data!=ele))
           {       
                   temp=temp->next;
                   posi++;   
           }
           if(temp->data==ele)
	       cout<<"The element is present in the position : \n"<<posi;
	       else
           cout<<"The element is not present\n";	
    }
}

void insert()
{ 
     struct dnode *tmp,*q,*cur,*temp;
     int count=1,posi,choice,length=1;
     q=NULL; cur=start; temp=start;
     tmp = new dnode;
     cout<<"\nEnter the data to be inserted : ";
     cin>>tmp->data;
     tmp->prev=NULL;
     tmp->next=NULL;
     cout<<"\nSelect the option of insertion";
     cout<<"\n1.At the begin\n2.At the end\n3.In between :\n ";
     cin>>choice;
     switch(choice)
     {   
         case 1:
              tmp->next=start;
	          start->prev=tmp;
	          start=tmp;
           break;
           case 2:
                last->next=tmp;
	            tmp->prev=last;
	            last=tmp;
             break;
             case 3:
             while(temp!=last)
	         {	    
                   temp=temp->next;
		           length=length+1;    
             }
             cout<<"\nEnter the position between 1st &"<<length;
             cin>>posi;
             if((posi<1)||(posi>length))
	         {	   
                  cout<<"Invalid Position";
	              break;
             }
	         else
             {
                 while((count<posi)&&(cur!=NULL))
                 {   
                     q=cur;
	                 cur=cur->next;
	                 count++;  
                  }
                  q->next=tmp;
                  tmp->prev=q;
                  tmp->next=cur;
	              cur->prev=tmp;
                  break;	
             }
             default:
                     cout<<"\nInvalid Choice\n";   
     }
}

void delete1()
{  
     struct dnode
     *temp=start,*q=NULL,*cur=start;
     int choice,posi,count=1,item,length=1;
     if(start==NULL)
     cout<<"\nNo node";
     else	
     {
          cout<<"\nEnter the type of deletion:\n";
          cout<<"\n1.Delete the start node\n 2.Delete the last node\n 3.Delete based on position\n 4.Delete all\n ";
          cin>>choice;
          if(choice<1||choice>4)
          cout<<"\nInvalid choice";
          else
          {
              switch(choice)
              {
                   case 1:
                        cout<<"The deleted element is"<<start->data;
		                start=start->next;
		                start->prev=NULL;
                   break;
                   case 2:
                        cout<<"\nThe deleted element is:\n"<<last->data;
                        last=last->prev;
		                last->next=NULL;
                  break;
                  case 3:
                       while(temp!=last)
		               {		  
                            temp=temp->next;
                            length++;      
                       }
                       cout<<"\nEnter the position of deletion : ";
                       cin>>posi;			   
                       if((posi<1)||(posi>length))
                       {  
                            cout<<"\nInvalid Position";
                            break; 
                       }
                       else
                       {  
                           while((count<posi)&&(cur!=NULL))
                           {     
                                 q=cur;
                                 cur=cur->next;						 
                                 count++;   
                           }
                           cout<<"\nThe deleted element is:\n"<<cur->data;
                           cur=cur->next;
                           q->next=cur;
                           cur->prev=q;
                           break; 
                       }
                       case 4: 
                            start=last=NULL;
                            cout<<"\nAll elements have been deleted";
                            break;
                 }   
          } 
     }
}

void rev()
{   
    struct dnode *p1,*p2;
    p1=start;
    p2=p1->next;
    p1->next=NULL;
    p1->prev=p2;
    while(p2!=NULL)
    {	
        p2->prev=p2->next;
	    p2->next=p1;
        p1=p2;
        p2=p2->prev;      
     }
     start=p1;
     display();
}

void count()
{ 
     struct dnode *q=start;
     int cnt=0;
     while(q!=NULL) 
     {
          q=q->next;
          cnt++; 
     }
     cout<<"Number of elements are "<<cnt<<"\n";
}


