

#include<iostream>
#include<cstring>
#define max 10
using namespace std;

 class hashtable
 {
 	public :
 		char key[10],meaning[10];
 		string h[max][2];
 		int count;
 		
		void insert();
 		void display();
		int hfunction(char []);
  		void linearp(string key,int);
 	        int search(char []);
 	        void Delete();
		void update();
 	hashtable()
 	{
	for(int i=0;i<max;i++)
	 {
	       for(int j=0;j<2;j++)
		 	 {
	 		    h[i][j] = "$";
			 }
	    }
		 count=0;
 	}

 };
 
 void hashtable :: insert()
 {
	int ch; 	
	cout<<"\n\n\t\tEnter the key:  ";
 	cin>>key;
 	cout<<"\n\t\tEnter the meaning :  ";
 	cin>>meaning;
	//Hash Function
	ch=hfunction(key);
	
 	linearp(key,ch);
 	
 }
  int hashtable::hfunction(char key[])
{
	int ch,sum=0;	
	for(int i=0 ;i<strlen(key) ;i++)
  	 {
 		sum = sum + int(key[i]);
 	 }
 	ch = sum % max;
	return ch;
}
  void hashtable :: linearp(string key,int ch)
 {
 
 		if(count==max)
 		{
 			cout<<"\n\n\tTable is Full";
 		}
 		else
 		{
 			while(h[ch][0]!="$" && count != max)
 			{
 				
 					ch++;
 					ch = ch % max;
 			}
 				h[ch][0] = key;
 				h[ch][1] = meaning;
 				count++;		
 		}	
 }
 
 
  void hashtable :: display()
 {
		
	cout<<"\n\t\t*** Hashing Dictionary ***";
	cout<<"\n\t-----------------------------------------------";
	cout<<endl<<"\tIndex\t\tKeyword\t\tMeaning"<<endl;
	cout<<"\n\t-----------------------------------------------\n\n"; 
	
	for(int i=0;i<max;i++)
		 {
		    cout<<"\t["<<i<<"]";
		for(int j=0;j<2;j++)
		   {
		 	 cout<<"\t\t"<<h[i][j];
		 	 
		 	}
		 	cout<<"\n\n";
		 }
 }
  int hashtable::search(char k[])
  {
    	int ch;
     	ch= hfunction(k);
 	 
 					
		while(h[ch][0]!=k && count != max)
 			{				
 					ch++;
 					ch = ch % max;
					count++;
 			}
 			
 			if(h[ch][0]==k)
 			{
 			   cout<<"\n\n\t\tstring is found at index  "<<ch<<"\n";
 			 }
 		/*if(count==max-1)
 		{ 
 			cout<<"\n\t\tsearch is not found \n";
 		 }*/				
 	return ch;
  }
  void hashtable :: Delete()
  {
	int ch;
	char k[10];    	
	cout<<"\n\n\t\tEnter the string to be delete: \n";
    	cin>>k;
     	ch= hfunction(k);
 	if(count==max)
 		{ 
 			cout<<"search is not found \n";
  		}
 		else
 		{
 			while(h[ch][0]!=k && count != max)
 			{
 				
 					ch++;
 					ch = ch % max;
 			}
 	  	 }
 	  
 			 h[ch][0]="$";
 			 h[ch][1]="$";
 			 cout<<"\n\n\t\tstring is delete from  index  "<<ch<<"\n";
 				  
   }
void hashtable :: update()
  {
    	char mean[10],k[10];
	int ch;
	cout<<"\n\n\t\tEnter the string to be Modify: \n";
    	cin>>k;
     	ch= search(k);
 	cout<<"\n\n\t\t Enter new meaning:- ";
 	cin>>mean;		 //h[ch][0]="$";
 			 h[ch][1]=mean;
 			 cout<<"\n\n\t\tmeaning is updated from index  "<<ch<<"\n";
 				  
   }
    
 int main()
 {
 int ch,s;
 char c,k[10];
 
 hashtable h1;
 
	do
	{	cout<<"\n\n\t------------------------------------";
		cout<<"\n\n\n\t\t*** Hashing Dictionary ***\n";
		cout<<"\n\n\t------------------------------------";
		cout<<"\n\n\t\t1.Insert\n\n\t\t2.Display\n\n\t\t3.Search";
		cout<<"\n\n\t\t4.Delete \n\n\t\t5.Modify\n\n\t\t6.Exit";
		cout<<"\n\n\t\tEnter your choice\n";
		cin>>ch;
		
		switch(ch)
		{
		case 1:
			h1.insert();
			break;
		case 2:
			h1.display();
			break;	
		 case 3:
		        cout<<"\n\n\t\tEnter the string to be search :\n";
    		        cin>>k;
			s=h1.search(k);
			
		        break;
		 case 4:
		          h1.Delete();
		          break;
		 case 5:
		          h1.update();
		          break;
		 
		default:
			cout<<"\n\n\tEnter wrong Choice";
			
		}
		cout<<"\n\t\tDo you want to continue ?(y/n) \n";
		cin>>c;
	}while(c=='y'|| c=='Y');
 
 return 0;
 }
 
 
