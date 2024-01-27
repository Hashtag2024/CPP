#include<iostream>
#include<string>

using namespace std;
const int MAX=10;

class stack
{
public:
int count, top;
char arr[MAX];
stack()
{
count=0;
top=-1;
}
void push(char);
void pop();
};
void stack::push(char d)
{
int flag;
if(count==MAX)
{
cout<<"\n Stack is full";
}
else
{
count++;
top++;
arr[top]=d;
}}
void stack::pop()
{
if(top==-1)
{
cout<<"\n Stack is empty";
}
else
{
char d = arr[top];
top--;
count--;
}}
int main()
{
stack s1;
string exp;
	int num, n, i;
	cout<<"\n Enter expression: \n";
	cin>>exp;
	num=exp.length();
	for(i=0; i<num; i++)
	{
	if(exp[i]=='(')
	{
	s1.push(exp[i]);
	}
else if(exp[i]==')')
	{
	s1.pop();
	}
}
if(s1.top!=-1)
{
cout<<"\n No matching parenthesis \n wrong expression \n";
}
else
{
cout<<"\n Matching parenthesis found \n expression is correct \n";
}
return 0;
}

