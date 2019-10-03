


// Program: LinkedList insertion, deletion and display using pointers
// Author: Mahendri Ramesh

#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
    
};

class list{
    private:
    node* head;
    node* tail;
    
    public:
    list(){
        head=NULL;
        tail=NULL;
    }
    void length()
    {
        int length=0;
        node* temp=new node;
        temp=head;
        do
        {
            ++length;
            temp=temp->next;
        }while(temp!=NULL);
        cout<<length;
    }
    void createnode(int value)
    {
        node* temp=new node;
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
        
    }
    void displaynode()
    {
        
        node* temp=new node;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
    }
    void insert_start(int value)
    {
        node* temp=new node;
        temp->data=value;
        temp->next=head;
        head=temp;
    }
    void insert_position(int pos,int value)
    {
        node* pre= new node;
        node* cur= new node;
        node* temp= new node;
        cur=head;
        for(int i=1;i<pos;i++)
        {
            pre=cur;
            cur=cur->next;
            
        }
        temp->data=value;
        pre->next=temp;
        temp->next=cur;
        
    }
    
    void del_start()
    {
        node* temp=new node;
        temp=head;
        head=head->next;
        delete temp;
        
    }
	void del_last()
	{ 
		node* cur=new node;
		node* pre=new node;
		cur=head;
		while(cur->next!=NULL)
		{
			pre=cur;
			cur=cur->next;
		}
		tail=pre;
		pre->next=NULL;
		delete cur;	
	}
	
	void del_pos(int pos)
	{
		//node* temp=new node;
		node* pre= new node;
		node* cur=new node;
		cur=head;
		for (int i=1;i<pos;i++)
		{
		    pre=cur;
		    cur=cur->next;
		}
		pre->next=cur->next;
		delete cur;
	}
};

int main()
{
    list obj;
    int x=0,y=0;
	
    //creating a list with 4 objects
    obj.createnode(25);
    obj.createnode(30);
    obj.createnode(35);
    obj.createnode(45);
    obj.createnode(50);
    obj.createnode(55);
    cout<<"\ndisplaying all nodes:"<<endl;
    obj.displaynode();
    cout<<"\ndeleting node at start\n";
    obj.del_start();
    cout<<"after deletion: \n";
	obj.displaynode();
	
	// this part of the program accepts the position and value from user, to insert in the linkedlist
	
    cout<<"\ninsert node at position: \n";
    cin>>x;
    cout<<"\nenter the value: ";
    cin>>y;
    obj.insert_position(x,y);
    cout<<"\ndisplaying the node: \n";
    obj.displaynode();

	cout<<"\ndeleting last node";	
	obj.del_last();
	cout<<"\nafter deletion: ";
	obj.displaynode();
	int z=0;
	cout<<"\nwhich node to be deleted? ";
	cin>>z;
	obj.del_pos(z);
	cout<<"\n the list is as follows: ";
	obj.displaynode();
	cout<<"\n the length of the list is as follows: ";
	obj.length();
    return 0;
}
