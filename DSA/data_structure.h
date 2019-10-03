#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node{
	int data;
	node* next;

};
struct node* head;							//defined as a global variable

void insert(int x)							//function to insert at beginning
{
	node* temp=new node();
	temp->data=x;
	temp->next=head;
	head=temp;
}

void insert(int data, int n)				//function to insert at nth position
{
	node* temp1=new node();
	temp1->data=data;
	temp1->next=NULL;
	if(n==1)
	{
		temp1->next=head;
		head=temp1;
		return;
	}
	node* temp2=head;
	for(int i=0;i<n-2;i++)
	{
		temp2=temp2->next;
	}
	temp1->next=temp2->next;
	temp2->next=temp1;
}
void Delete(int n)
{
	struct node* temp1=head;
	if(n==1)
	{
		head=temp1->next;
		delete(temp1);
		return;
	}
	for(int i=0;i<n-2;i++)
	{
		temp1=temp1->next;
	}
	struct node* temp2=temp1->next;
	temp1->next=temp2->next;
	delete(temp2);

}
void print()
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
}
int main()
{
	int n,x,pos;
	head=NULL;								//empty list
	cout<<"How many numbers? ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter the number: ";
		cin>>x;
		insert(x);
		print();
	}
	cout<<"\n enter a position and element: ";
	cin>>pos>>x;
	insert(x,pos);
	print();
}
