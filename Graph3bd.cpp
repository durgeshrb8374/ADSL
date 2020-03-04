// There are flight paths between cities. If there is a flight between
//city A and city B then there is an edge between the cities. The cost of the edge can
//be the time that flight takes to reach city B from A, or the amount of fuel used for
//the journey. Represent this as a graph. The node can be represented by airport name
//or name of the city. Use adjacency list representation of the graph or use adjacency
//matrix representation of the graph. Justify the storage representation used.


#include <iostream>

using namespace std;

//Queue for BFS TRAVERSAL
//-------------------------------------------------------------------------------------------------
class Queue 
{
public:	
	int front,rear;
	string data[30];
public:
	Queue()
{
		front=-1;
		rear=-1;
}
	
	void inqueue(string str)
	{
		if(front==-1 && rear==-1)
		{
			front=rear=0;
			data[rear]=str;
		}
		else
		{
			rear=rear+1;
			data[rear]=str;
		}
	}
	string dequeue()
	{
		string  p;
		if(front==rear)
		{
			p=data[front];
			front=-1;
			rear=-1;
		}
		else
		{
			p=data[front];
			front=front+1;
		}
		return p;
	}

};
/*//-------------------------------------------------------------------------------------------------
//Stack for DFS TRAVERSAL
//-------------------------------------------------------------------------------------------------
class Stack
{
public:	
	int top;
	string data[30];
public:
	Stack()
{
		top=-1;
}
	
	void push(string str)
	{
			top=top+1;
			data[top]=str;
	}
	string pop()
	{
		string  p;
		
			p=data[top];
			top=top-1;
		
		return p;
	}

};*/
class node //node class for each airport
{
public:
	node *next;
	string city;
};
class graph //Contains total graph of airports
{

	node *head[30];
		
public:
	
	void create();
	void insert(string city1,string city2);
	
	void display();
	void BFS();
	void DFS(string s1);
	int getindex(string s1);
	int visited[30];
	int n;
};
void graph::create()
{	
	int flight,fcost;
	string city1,city2,tmpcity;
	cout<<"\n\n\t\t***Welcome***\n ";
	cout<<"\n\n\t\tEnter Number of Airport Stations:";
	cin>>n;
	for(int i=0;i<n;i++)
			head[i]=NULL;
	cout<<"\n\t\tEnter City Details:\n ";
	for(int i=0;i<n;i++)
	{
		head[i]=new node;
		cout<<"\n\t\tEnter City "<<i+1<<" ";
		cin>>head[i]->city;
		head[i]->next=NULL;
			
	}
	cout<<"\n\n\t\tEnter Flights Details(Enter the Edges of Flight Graph): ";
	
	
		while(1)
		{
			cout<<"\n\n\t\tEnter Source:";
			cin>>city1;
			cout<<"\t\tEnter Destination:";
			cin>>city2;
			
			insert(city1,city2);
			
			cout<<"\n\n\tWant to enter more?\t";
			char ch;
			cin>>ch;
				if(ch=='n')
					break;
		}

	
display();
}
void graph::BFS()
{
	string str;
	int j,i;
	Queue queue;
	
	for(int i=0;i<n;i++)
		visited[i]=0;

	cout<<"\n\n\t-------------------------------------------------------";
	cout<<"\n\n\t\t*** BFS Traversal *** \n";
	cout<<"\n\n\t-------------------------------------------------------";
	str=head[0]->city;
	
	queue.inqueue(str);
	cout<<"\n\n\t\t\t**--";
		while(queue.rear!=-1)
		{
			string p=queue.dequeue();
			i=getindex(p);
			node *temp=head[i];
			while(temp!=NULL)
			{                                               
				i=getindex(temp->city);
				str=temp->city;
				if(!visited[i])
				{
					queue.inqueue(temp->city);
					visited[i]=1;
					cout<<" "<<str<<" ";
				}
				temp=temp->next;
			}
		}
		cout<<"--**\n";
}
void graph::DFS(string str)
{
	//string str;
	node *temp;
	cout<<"    "<<str;
	int j,i;
	i=getindex(str);
	temp=head[i];
	visited[i]=1;
	while(temp!=NULL)
	{
		str=temp->city;
		i=getindex(str);
		if(!visited[i])
		{
			DFS(str);
		}
		temp=temp->next;
	}
	
}

void graph::insert(string city1,string city2)
{
	node *temp;
	node *dest=new node();
	dest->city=city2;
	dest->next=NULL;

	for(int i=0;i<n;i++)
	{
		if(head[i]->city==city1)
		{	
			if(head[i]->next==NULL)
			head[i]->next=dest;
			else
			{
				temp=head[i];
				while(temp->next!=NULL)
					temp=temp->next;

					temp->next=dest;
			}
		}
	}
}
void graph::display()
{
	node *temp;
	cout<<"\n\n\t\tNode\tAdjacent Nodes\tEdge Cost\n";
	cout<<"---------------------------------------------------";
	for(int i=0;i<n;i++)
	{
		//cout<<"\n\t\t"<<head[i]->city;
		temp=head[i];
		cout<<"\n\t\t"<<head[i]->city<<"->    ";
		while(temp->next!=NULL)
		{
			temp=temp->next;
			cout<<"\t"<<temp->city;
			
		}
		
	}
}
int graph::getindex(string s1)
{
	for(int i=0;i<n;i++)
	{
		if(head[i]->city==s1)
			return i;
	}
	return -1;
}
int main() 
{
	int no,ch;
	string str;
	graph g1;
	
	
	do
	{
	cout<<"\n\n\n\t\t-------- Menu --------"<<"\n\n\t\t1.Create the Flight Graph"<<"\n\n\t\t2.DFS"
	<<"\n\n\t\t3.BFS"<<"\n\n\t\t4.Exit";
	
	cout<<"\n\n\t\tEnter your choice: ";
	cin>>ch;
		switch(ch)
		{
		case 1:
			cout <<"" << endl;
			g1.create();	
			break;
		case 2:
			cout <<"\n\n\t Enter the starting node" << endl;
			cin >>str;
			for(int i=0;i<g1.n;i++)
				g1.visited[i]=0;

			cout<<"\n\n\t-------------------------------------------------------";
			cout<<"\n\n\t\t*** DFS Traversal *** \n";
			cout<<"\n\n\t-------------------------------------------------------\n";
			g1.DFS(str);
			break;
		case 3:
			g1.BFS();
			break;
		default:
			cout<<"\nWrong Choice";
		}
	}while(ch!=4);


	return 0;
}

