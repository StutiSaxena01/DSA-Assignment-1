#include <iostream>
//#define n 100
using namespace std;

template<class D>
class Deque
{
private:
int rear,front,capacity,count=0;
D *ar;

public:
Deque()
{
	rear=front=-1;
	capacity=0;
	count=0;
	ar=new D[capacity];
}
Deque(int n, D x)
{
	capacity=n;
	count=0;
	ar=new D[capacity];
	rear=front=-1;
	for(int i=0;i<capacity;i++)
	{ar[i]=x;count++;}
}
void push_back(D x)
{	
if(capacity!=0)
{
	if(front==0 && rear==capacity-1 || front==rear+1)
	{
		D *newar;
		newar=new D[2*capacity];
		int i=front; int j=front;
		while(i!=rear)
		{
			newar[j]=ar[i];
			//cout << newar[j] << endl;
			i=(i+1)%capacity;
			j++;
		
		}
		newar[j]=ar[i];
		delete[] ar;
		ar=newar;
		capacity=2*capacity;
		rear=j;
		if(rear!=capacity-1)
		{
			rear ++;
			ar[rear]=x;
		}
		else
		{
			rear=0;
			ar[rear]=x;
		}
	}
	else if(front == -1 && rear==-1)
	{
		front =rear=0;
		ar[rear]=x;
	}
	else if(rear==capacity-1)
	{
		rear=0;
		ar[rear]=x;
	}
	else
	{
		rear ++;
		ar[rear]=x;
	}
}
else
{
	capacity++;
	front=rear=0;
	ar[rear]=x;
}
count ++;
}
void push_front(D x)
{
if(capacity!=0)
{	
	if(front==0 && rear==capacity-1 || front==rear+1)
	{
		D *newar;
		newar=new D[2*capacity];
		int i=front; int j=front;
		while(i!=rear)
		{
			newar[j]=ar[i];
			//cout << newar[j] << endl;
			i=(i+1)%capacity;
			j++;
		
		}
		newar[j]=ar[i];
		delete[] ar;
		capacity=2*capacity;
		ar=newar;
		rear=j;
		if(front!=0)
		{
			front --;
			ar[front]=x;
		}
		else
		{
			front=capacity-1;
			ar[front]=x;
		}
	}
	else if(front == -1 && rear==-1)
	{
		front =rear=0;
		ar[front]=x;
	}
	else if(front==0)
	{
		front=capacity-1;
		ar[front]=x;
	}
	else
	{
		front --;
		ar[front]=x;
	}
}
else
{
	capacity++;
	front=rear=0;
	ar[front]=x;
}
count++;
}
void pop_back()
{
	if(front == rear)
	front = rear =-1;
	else if(rear ==0)
	rear=capacity-1;
	else
	rear=rear-1;
	
	count--;
}
void pop_front()
{
	if(front == rear) front =rear=-1;
	else if( front == capacity-1)
	front =0;
	else
	front = front +1;
	
	count--;
}
D showfront()
{
 	return ar[front];
}
D back()
{
 	return ar[rear];
}
void display()
{
	
	int i=front;
	while(i!=rear)
	{	
		
		cout << ar[i] << " ";
		i=(i+1)%capacity;
	}
	cout << ar[rear] << " ";
	cout << endl;
}
bool empty()
{
 	if (front==-1) return true;
 	else
 	return false;
}
D operator [] (int n)
{
	if(count!=0) 
	{ 
	if(n<count) 
	return ar[(front+n)%capacity];
	else
	cout << "Invalid Query";
	}
	else
	cout << "Invalid Query";
	exit (3) ;
}
int size()
{
	//capacity=this->capacity;
	return this->count;
}
void clear()
{
	delete[] ar;
	capacity=0;
	count=0;
	front=rear=-1;
	D *newar;
	newar =new D[capacity];
	ar=newar;
}
void resize(int d,D x)
{
	int t=rear;
	if(d<capacity && d>count)
	{
		while(count!=d)
		{
		push_back(x);
		}
	}
	else if(d<count)
	{
		while(count!=d)
		{
		pop_back();
		}	
	}
	else if(d>capacity)
	{
		D *temp;
		temp=new D[d];
		int i=front ; int j=front;
		while(i!=rear)
		{
			temp[j]=ar[i];
			//cout << newar[j] << endl;
			i=(i+1)%capacity;
			j++;
		}
		temp[j]=ar[i];
		delete[] ar;
		capacity=d;
		
		ar=temp;
		rear=j;
		while(count!=d)
		{
		push_back(x);	
		}
	}
}
};

int main()
{ 
	Deque<int> d;
    	int Q,c,n;
    	int x;
    	cin>>Q;

	for(int i=0;i<Q;i++)
	{     
	cin>>c;
	switch (c)
 	{	

 	 case 1: cin>>x;
         	 d.push_front(x);  
         	 d.display();
         	 break;
	 case 2: d.pop_front();
		 d.display();
		 break;
	 
	 case 3: cin>>x;
		 d.push_back(x);
		 d.display();
		 break;
	 
	 case 4: d.pop_back();
		 d.display();
		 break;

	 case 7: cout<<d.showfront()<<endl;
		 break;

	 case 8: cout<<d.back()<<endl;
		 break;
	 
	 case 9: if(d.empty())
		  cout<<"true\n";
		 else
		  cout<<"false\n";
		 break;

	 case 10: cout<<d.size()<<endl;
		  break;

	 case 11: cin>>n>>x;
		  d.resize(n,x);
		 d.display();
		  break;

	 case 12: d.clear();
		  break;
	 
	 case 13: cin>>n;
		  cout<<d[n]<<endl;
		  break;

	 case 14: d.display();
		 break;

	 default:
	     break;
	 }
	
	}

return 0;
}
