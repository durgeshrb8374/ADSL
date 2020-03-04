/* Assignment C14 
Consider telephone book database of N clients. Make use of a hash table implementation to
quickly look up client‘s telephone number.*/


#include<iostream>
using namespace std;
#define MAX 10
class hash
{
	public:
		long htable[MAX],n;
		int count;
	public:
	    hash()
		{
			for(int i=0;i<MAX;i++)
				htable[i]=-1;
			count=0;
		}
		void insert();
		void linearprobe(int,long);
		void display();
		void search();

};

void hash::insert()
{
	int index;
	if(count!=MAX)
	{
			cout<<"\n\n\t\tEnter the phone numbers:\n";
			cin>>n;
			
			index=(n%MAX);		//HASH FUNCTION
			linearprobe(index,n);			
			
	}
	else
		cout<<"\n\n\tTable is Full\n";
}

void hash::display()
{
	if(count==1)
		cout<<"\n\n\tTable is Empty\n";
	
	cout<<"\n\t\t*** Hash Table ***";
	cout<<"\n-----------------------------------------------";
	cout<<endl<<"\t"<<"Index"<<"\t\t"<<"Value"<<endl;
	cout<<"\n-----------------------------------------------";
	for(int i=0;i<MAX;i++)
	{
		cout<<endl<<"\t["<<i<<"]\t\t"<<htable[i]<<endl;
	}
}

void hash::linearprobe(int index,long no)
{
	int r;
	r=1;
	if(count==MAX)
		cout<<"\n\n\t\tTable is Full";
	else
	{
		while(htable[index]!=-1 && count!=MAX)
		{
			cout<<"\n\n\tCollision Occured at "<<index<<" collision no: "<<r<<"\n";
			index++;
			r++;
		}
		htable[index]=no;
		count++;
	}
}	

void hash::search()
{
	int key,count1=0,index;
	cout<<"\n\n\tEnter no to be searched\n";
	cin>>key;
	index=(key%MAX);
	if(count==1)
		cout<<"\nTable Empty\n";
	else
	{
		if(htable[index]==key)
			cout<<"\n\n\tNumber found at  "<<index<<"\n";
		else
		{
			while(count1!=MAX)
			{
				index++;
				if(htable[index]==key)
				{
					cout<<"\n\n\tNoumber found at   "<<index<<"\n";
					break;
				}
				count1++;
			}
			if(count1==MAX)
				cout<<"\n\n\tNumber Not Found\n";
		}	
	}				
}				
				
		
int main()
{
	hash h;
	int choice;
	do
	{	cout<<"\n\n---------------------------------------------";
		cout<<"\n\n\t\tTelephone Book";
		cout<<"\n\n---------------------------------------------";
		cout<<"\n\n\t\t1.Insert\n";
		cout<<"\n\n\t\t2.Display\n";
		cout<<"\n\n\t\t3.Search\n";
		cout<<"\n\n\t\t4.Exit\n";
		cout<<"\n\t\t\tEnter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				h.insert();
				break;
			case 2:
				h.display();
				break;
			case 3:
				h.search();
				break;
			/*default:
				cout<<"\nSomething went wrong\n";
				break;*/
		}
	}while(choice!=4);
	return 0;
}	
