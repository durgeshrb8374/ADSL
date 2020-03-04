#include<iostream>
using namespace std;
 class treenode
 {
	public:
		int data;
		treenode *rchild,*lchild;
                      
 };
 class stack
 {
	public:
		int top;
	treenode *tempstack[15];
	public:
		void push(treenode *);
		treenode* pop();
	stack()
	{
		top=-1;
	}

 };
 class tree
 {
	public:
		void create();
		void insert(treenode *,treenode*);
		treenode * ccopy(treenode *);
		void display(treenode *);
		void preorder(treenode *);
		void postorder(treenode *);
		void inorder(treenode *);
		void preorder1(treenode *);
		void postorder1(treenode *);
		void inorder1(treenode *);
		void deltree(treenode * );
		int count(treenode *root1);
		treenode * mirror(treenode *);
	treenode *root;
	tree()
	{
		root=NULL;
	}
 };

 /*Using create function we just create new node of tree*/

 void tree::create()
 {

		char ch;
		treenode *freshnode,*root1;
		while(1)
		{
			freshnode=new treenode;
			freshnode->rchild=NULL;
			freshnode->lchild=NULL;

			cout<<"\n\n Enter data to create new node\t";
			cin>>freshnode->data;
			if(root==NULL)
			{
				root=freshnode;
				//root1=root;
			}
			else
				insert(root,freshnode);
			cout<<"\n You Wnat to add more nodes\t\t";
			cin>>ch;
			if(ch=='n')
			{
					break;
			}
		}

	}


	/*using insert function we insert node into tree at given position*/

void tree::insert(treenode *root,treenode *freshnode)
{
	char ch;

		cout<<"\n\nwhere you want to insert r/l of node "<<root->data<<"\t";
		cin>>ch;

		if(ch=='r')
		{
			if(root->rchild==NULL)
			{
				root->rchild=freshnode;
			}
			else
			{
				insert(root->rchild,freshnode);
			}
		}
		else
		{
		  if(root->lchild==NULL)
			{
				root->lchild=freshnode;
			}
			else
			{
				insert(root->lchild,freshnode);
			}
		}

}
void tree::display(treenode *root1)
{
	int ans;
if(root1==NULL)
	cout<<"\n\n\t\tTree is empty";
else
{

	do
	{
		cout<<"\n\n\t\tMethods of tree traversal";
		cout<<"\n\n\t1.Rec-Preorder\n\t2.Rec-Postorder\n\t3.Rec-Inorder\n";
		cout<<"\t4.NonRec-Preorder\n\t5.NonRec-Postorder\n\t6.NonRec-Inorder\n\t7.Exit\n";
		cout<<"\nEnter your choice\t";
		cin>>ans;
		switch(ans)
		{
			case 1:

					cout<<"\n\nPreorder travrsal of Tree\n\n";
					cout<<"\n-------------------------------------\n";
					preorder(root1);
					cout<<"\n-------------------------------------\n";

					break;
			case 2:

					cout<<"\n\nPostorder travrsal of Tree\n\n";
					cout<<"\n-------------------------------------\n";
					postorder(root1);
					cout<<"\n-------------------------------------\n";

					break;
			case 3:

					cout<<"\n\nInorder travrsal of Tree\n\n";
					cout<<"\n-------------------------------------\n";
					inorder(root1);
					cout<<"\n-------------------------------------\n";
					break;
			case 4:
				//p->lchild
					cout<<"\n\nNon-Rec Preorder travrsal of Tree\n\n";
					cout<<"\n-------------------------------------\n";
					preorder1(root1);
					cout<<"\n-------------------------------------\n";

					break;
			case 5:

					cout<<"\n\n Non-Rec Postorder travrsal of Tree\n\n";
					cout<<"\n-------------------------------------\n";
					postorder1(root1);
					cout<<"\n-------------------------------------\n";

					break;
			case 6:

					cout<<"\n\nNon-Rec Inorder travrsal of Tree\n\n";
					cout<<"\n-------------------------------------\n";
					inorder1(root1);
					cout<<"\n-------------------------------------\n";
					break;
			case 7:
					break;
		}

	}  while(ans<7);
  }
}

/* Recursive Functions*/
void tree::preorder(treenode *root1)
{
	if(root1!=NULL)
	{
		cout<<"\t"<<root1->data;
		preorder(root1->lchild);
		preorder(root1->rchild);
	}

}
void tree::postorder(treenode *root1)
{
	if(root1!=NULL)
	{
		postorder(root1->lchild);
		postorder(root1->rchild);
		cout<<"\t"<<root1->data;
	}

}
void tree::inorder(treenode *root1)
{
	if(root1!=NULL)
	{
		inorder(root1->lchild);
		cout<<"\t"<<root1->data;
		inorder(root1->rchild);
	}

}
/* Non-Recursive Functions*/
void tree::preorder1(treenode *root)
{
	treenode *temp;
	temp=root;
	stack s;
	s.tempstack[0]=temp;
	s.top=0;

	while(1)
	{
			if(s.top==-1)
				break;
			else
			{
				temp=s.pop();
				s.top--;
			}
			
			cout<<"\t"<<temp->data;
			if(temp->rchild!=NULL)
				s.push(temp->rchild);
			if(temp->lchild!=NULL)
				s.push(temp->lchild);

			

	}
}


void tree::postorder1(treenode *root)
{
	treenode *temp=root;
	stack s,s1;

		while(temp!=NULL)
		{
			s.push(temp);
			s1.push(NULL);
			temp=temp->lchild;
		}

		while(s.top!=-1)
		{
			temp=s.pop();

			if(s1.pop()==NULL)
			{
				s.push(temp);
				s1.push((treenode* )1);
				temp=temp->rchild;

			   while(temp!=NULL)
			   {
					s.push(temp);
					s1.push(NULL);
					temp=temp->lchild;
			   }

			}
			else
			cout<<"\t"<<temp->data;

	   }

}
void tree::inorder1(treenode *root)
{
	treenode *temp;
	temp=root;
	stack s;
	s.top=-1;
	cout<<"\n";
	while(1)
	{

			if(temp!=NULL)
			{
				s.push(temp);
				temp=temp->lchild;
			}
			else
			{
				if(s.top==-1)
					break;
				else
				{
					temp=s.pop();
					cout<<"\t"<<temp->data;
					s.top--;
					temp=temp->rchild;
				}
			}
	}
}

//Functions for Stack//
void stack::push(treenode *visited)
{
   top=top+1;
   tempstack[top]=visited;
}
treenode * stack::pop()
{
	return(tempstack[top]);

}

 //Main function//
 int main()
 {

	tree t;
	treenode *copyroot,*mroot;
	int ch,total;

	do
	{

	   cout<<"\n\n-----------------TREE------------------------ \n\n";
		cout<<"\n\t1.Create\n\t2.Disply\n\t3.Copy the tree \n\t4.Display copy tree \n\t5.Delete tree6.\n\t6.Total no of Nodes \n\t7.Mirror Image\n\t8.Exit\n";
		cout<<"\nEnter your choice\t";
		cin>>ch;

		switch(ch)
		{
			case 1:
					t.create();
					break;
			case 2:
					t.display(t.root);
					break;

			case 3 :
					copyroot=t.ccopy(t.root);
					break;

			case 4:
					t.display(copyroot);
					break;
			case 5:
					t.deltree(t.root);
					t.root=NULL;
					break;
			case 6:
					total=t.count(t.root);
					//t.root=NULL;
				cout<<"\n\nTotal no of nodes in Tree    "<<total;
					break;
			case 7:
					mroot=t.mirror(t.root);
					cout<<"\n\n\t Original tree\n";
					t.preorder(t.root);
					cout<<"\n\t Mirror Image of tree \n";
					t.preorder(mroot);
					break;
		}

	}  while(ch<8);
	return(0);

 }

 treenode * tree::ccopy(treenode *root1)
 {
 	treenode *temp;
 	temp=NULL;
 	if(root1!=NULL)
 	{
 		temp=new(treenode);
 		temp->data=root1->data;
 		temp->lchild=ccopy(root1->lchild);
 		temp->rchild=ccopy(root1->rchild);
 	}
 	return(temp);
 }

 void tree::deltree(treenode * root1)
 {
     if (root1)
     {
         deltree(root1->lchild);
         deltree(root1->rchild);
 	     cout<<endl<<"Deleting"<<root1->data;
         delete root1;
     }
}
   int  tree::count(treenode *root1)
 {
 		int cnt=0;
 	 	if(root1==NULL)
 		{			
			return 0;
			cout<<"\n\nTotal no of nodes in Tree  0  ";
		}
		else
			{
			cnt=1+count(root1->lchild)+count(root1->rchild);
			cout<<"\n\nTotal no of nodes in Tree    "<<cnt;
}
 			 return (cnt);		
 }
 treenode * tree::mirror(treenode *root1)
 {
 	treenode *temp;
 	temp=NULL;
 	if(root1!=NULL)
 	{
 		temp=new(treenode);
 		temp->data=root1->data;
 		temp->lchild=ccopy(root1->rchild);
 		temp->rchild=ccopy(root1->lchild);
 	}
 	return(temp);
 }








