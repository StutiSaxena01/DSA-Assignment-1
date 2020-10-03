#include <iostream>
#include<iomanip>
using namespace std;

template <class D>
class Node
{
public:
D data;
Node <D> *next;
};

template <class D>
class Stack{
private:
Node <D> *top;

public:
Stack()
{
	top=NULL;
}
void push(D x)
{
	Node <D> *temp;
	temp=new Node<D>;
	temp->data =x;
	
	if(top == NULL)
		temp->next=NULL;
	else
		temp->next=top;
		
	top=temp;
}
D pop()
{
	D y;
	if(top!=NULL)
	{
		Node <D> *temp;
		temp=top;
		top = top->next;
		y=temp->data;
		delete(temp);
		
	}
	return y;
}

D peek()
{
	return top-> data;
}

void print()
{
	Node <D> *temp =top; 
	while(temp != NULL)
	{
	cout << temp->data << " ";
	temp=temp->next;
	}
}

string intopost(string s)
{ 
	string s2="",s1="";
	//cout << s2 << endl;
 	int l=s.length();
	for(int i=0;i<l;i++)
	{
	if((s[i] =='+') || (s[i] =='-') || (s[i] =='*') || (s[i] =='%') || (s[i] =='/') || (s[i] =='(') || (s[i] ==')'))
	{
		s2+=',';
		if(s[i] == '(') 
          	push(s[i]); 
       	//print();
        	else if(s[i] == ')') 
        	{ 
            		while(peek() != 'N' && peek() != '(') 
            		{  
            		//cout << s2 << endl;	 
                	char x=pop(); 
                	
               	s2 += x ;
               	//s2+=" "; 
            		} 
            		//cout << s2 << endl;	 
            		if(peek() == '(') 
            		{ 
                	char c = pop();
                	
            		}
            		//cout << s2 << endl;	 
        	} 
          	
       
        	else
        	{ 
        		while(peek() != 'N' && priority(s[i]) >= priority(peek())) 
            		{ 
                	char c = pop();
                	//cout << c;
                	s2 += c;
                	s2+=','; 
                	//s2+=" "; 
            		} 
            		push(s[i]); 
               } 
    		
  	}
    	else
    	{
    	
    	s2+=s[i];
    	//s2+=" ";
	}
	}
	while(peek() != 'N') 
   	{ 
        char c = pop();
        s2+=','; 
        s2+=c;
        //s2+=" ";
  	} 	
	//print();
	//cout << endl;
	return s2;
	
	
}
int priority(char ch) 
{ 
    if(ch == '+' || ch == '-') 
    return 1; 
    else if(ch == '*' || ch == '/' || ch == '%') 
    return 0; 
    else
    return 2; 
} 

double postevaluation(string str)
{
	//cout << str << "#" << endl;
	int i=0;std::string s1="";
	int l=str.length();
	while (i<l)
	{
	  if((str[i] =='+') || (str[i] =='-') || (str[i] =='*') || (str[i] =='/') )
	  {
	  	char op=str[i];
	  	double op2=pop();
	  	
	  	double op1=pop();
	  	double ans;
	  	
	  	switch(op)
	  	{
	  	case '+': ans=op1+op2;
	  	break;
	  	case '-': ans=op1-op2;
	  	break;
	  	case '/': ans=op1/op2;
	  	break;
	  	case '*': ans=op1*op2;
	  	break;
	  	}
	  	

		push(ans);
		//cout << endl;
	  	//print();
	  }
	  else if(str[i]=='%')
	  {
	  	int op2=pop();
	  	int op1=pop();
	  	int ans= op1%op2;
	  	push(ans);
	  }
	  else
	  {
	  	while(str[i]!=',')
	  	{
	  	s1+=str[i];
	  	i++;
	  	}
	  	//cout << s1  << endl;
	  	if(s1!="")
	  	{
	  	double ans1= std::stod(s1);
	  	//cout << ans1 << endl;
	  	push(ans1);
	  	//print();
	  	s1="";
	  	}
	  }
	  i++;
	}
	
	double fans=pop();
	return fans;
}
};


int main()
{
	string str,s1;
	double answer;
	cin >> str;
	int l=str.length();
	Stack <char> convert;	
	convert.push('N');
	s1=convert.intopost(str);
	
	//cout << s1 << endl;
	Stack<double> evaluate;
	answer=evaluate.postevaluation(s1);
	//cout << endl;
	cout << fixed << std::setprecision(5) << answer << endl;

}
