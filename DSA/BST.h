#include <iostream>

using namespace std;

struct BstNode{
	int data;
	BstNode* left;
	BstNode* right;
};
BstNode* GetNewNode(int data)
{
	BstNode* newNode=new BstNode();
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}
BstNode* Insert(BstNode* root, int data)
{
	if(root==NULL)
	{
		root=GetNewNode(data);
		return root;
	}
	else if(data<=root->data)
	{
		root->left=Insert(root->left,data)
	}
}
bool search(BstNode* root, int data)
{
	if(root==NULL)	return false;
	else if(root->data==data) return true;
	else if(data<=root->data)	return Search(root->left,data)
	else return Search(root->right,data)
}
int main()
{
	BstNode* root=NULL;
	root=Insert(root,15);
	root=Insert(root,10);
	root=Insert(root,23);
	root=Insert(root,50);
	root=Insert(root,20);
	root=Insert(root,6);
	int number;
	cout<<"\n enter a number: ";
	cin>>number;
	if(Search(root,number)==true)
		cout<<"\nfound";
	else cout<<"\nNot found";
}