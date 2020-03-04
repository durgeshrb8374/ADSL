
#include <iostream>
using namespace std;

class TBTnode
{
public:	
	TBTnode *lchild,*rchild;
	int data;
	int rthread,lthread;
};

class TBT
{
	TBTnode *head; //acts as a dummy node
public:
	TBT() //dummy node initialization
	{
		head=new TBTnode();
		head->data=9999;
		head->lchild=head;
		head->rchild=head;
		head->rthread=0;
		head->lthread=0;
		
	}
	void create();
	void insert(int data);
	TBTnode *inorder_suc(TBTnode *);
	void inorder_traversal();
	TBTnode * preorder_suc(TBTnode *);
	void preorder_traversal();
};
//--------------------------------------------
void TBT::preorder_traversal()
{
	TBTnode *temp=head->lchild;
	while(temp!=head)
	{
		cout<<" "<<temp->data;
		temp=preorder_suc(temp);
	}
}
void TBT::inorder_traversal()
{
	TBTnode *temp=head->lchild;
	while(temp->lthread==1)
		temp=temp->lchild;
	while(temp!=head)
	{
		cout<<" "<<temp->data;
		temp=inorder_suc(temp);
	}
}
TBTnode* TBT::inorder_suc(TBTnode *temp)
{
	if(temp->rthread==0)
		return temp->rchild;
	else
		temp=temp->rchild;
	while(temp->lthread==1)
	{
		temp=temp->lchild;
	}
	return temp;
}
TBTnode *TBT::preorder_suc(TBTnode *temp)
{
	if(temp->lthread==1)
	{
		return temp->lchild;
	}
	while(temp->rthread==0)
	{
		temp=temp->rchild;
	}
	return temp->rchild;
}
//-------- Create Method
void TBT::create()
{

	int data;
	char ch;
	if(head->lchild==head&&head->rchild==head)
	{
		while(1)
		{
			cout<<"\n\n\tEnter new node Data to insert in TBT:";
			cin>>data;
			insert(data);
			cout<<"\n\tYou Want to add more nodes\t\t";
			cin>>ch;
			if(ch=='n')
			{      
				break;
			}	
		}
	}
	else
	{
		cout<<"\n\tTree is Already created.\n";
	}
}
void TBT::insert(int data)
{

	if(head->lchild==head&&head->rchild==head) //no node in tree
	{
		TBTnode *freshnode=new TBTnode();
		freshnode->data=data;
		freshnode->lchild=head;
		freshnode->rchild=head;
		freshnode->lthread=freshnode->rthread=0;
		head->lchild=freshnode;
		head->lthread=1;
		cout<<"\n\n\tCreate TBT with start node "<<data<<"\n";
		return;
	}
	TBTnode *temp;
	temp=head->lchild ;
	while(1)
	{

		if(data>temp->data)   //insert rchild
		{
			TBTnode *freshnode=new TBTnode();

			if(temp->rthread==0)
			{
				freshnode->data=data;
				freshnode->rchild=temp->rchild;
				freshnode->lchild=temp;
				freshnode->rthread=freshnode->lthread=0;				
				temp->rthread=1;
				temp->rchild=freshnode;
				cout<<"\n\n\tInserted Right child   "<<data;
				return;
			}
			else
				temp=temp->rchild;
		}
		if(data<temp->data )//insert lchild
		{
			TBTnode *freshnode=new TBTnode();
			if(temp->lthread==0)
			{
				freshnode->data=data;
				freshnode->lchild=temp->lchild;
				freshnode->rchild=temp; //successor
				freshnode->lthread=freshnode->rthread=0;	
				temp->lthread=1;
				temp->lchild=freshnode;
				cout<<"\n\n\tInserted Left child  "<<data;
				return;
			}
			else
				temp=temp->lchild;
		}
	}

}



int main() {
	TBT t1;
	int value;
	int ch;
	do
	{	cout<<"\n\n\t-----------------TBT-------------------------------\n";
		cout<<"\n\n\t1.Create Threaded Tree\n\n\t2.Insert into tree\n\n\t3.Preorder Traversal\n\n\t4.Inorder Taversal\n\n\t5.Exit"; 		
		cout<<"\n\n\t\tEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			t1.create();
			break;
		case 2:
			cout<<"\n\n\tEnter Number(data): ";
			cin>>value;
			t1.insert(value);
			break;
		case 3:
			cout<<"\nPreorder traversal of TBT\n";
			cout<<"--------------------------------------------------------------\n\n";
			t1.preorder_traversal();
			cout<<"\n\n--------------------------------------------------------------\n";
			break;
		case 4:
			cout<<"\nInoder Traversal of TBT\n";
			cout<<"--------------------------------------------------------------\n\n";
			t1.inorder_traversal();
			cout<<"\n\n--------------------------------------------------------------\n";
			break;
		
		default:
			cout<<"\nWrong choice";
		}

	}while(ch!=0);


	return 0;
}

