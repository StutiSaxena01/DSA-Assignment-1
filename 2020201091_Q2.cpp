#include <iostream>
using namespace std;

long long int gcd(long long int a,long long int b)
{
while(a!=b)
{
	if(a>b)
	a=a-b;
	else
	b=b-a;
}
return a;
}
string multiply(string num1, string num2) 
   {
   	//if(num2.size() > num1.size()) swap(num1,num2);
        int m = num1.size(), n = num2.size();
        string mult(m+n,0);
        int carry,index1=0,index2=0; 
      
        int i=m-1;
        
        while(i>=0)
        {
        	carry=0;
        	index2=0;
        	int j=n-1;
        	
        	while(j>=0)
        	{
                int mul = (num1[i]- '0') * (num2[j] - '0') ;
                int sum2 = mul+ mult[index1+index2];
                int sum = sum2 + carry;
                carry = (sum / 10);
                mult[index1+index2] = (sum % 10);
		index2++;
		j--;
            	}
            	
            if(carry>0)
            mult[index1+index2] +=carry;
            index1++;
            i--; 
               
        }
        
        int size=mult.size()-1;
        while(size>=0 && mult[size] ==0)
        {
        size--;
        }
        if(size==-1)
        return "0";
        
        string s="";
        while(size>=0)
        {
        s+=to_string(mult[size]);
        //cout << s << endl;
        size--;
        }
        //ans=to_string(sum1);
        return s;
    }
 string exponent(string s1, int s2)
   {
   	if(s2==0) return "1";
   	string s="",ans="";
   	string res=exponent(s1,s2/2);
  	if(s2%2==1)
  		{
		s= multiply(res,res);
		ans=multiply(s,s1);
		}
	else
		{	
		ans=multiply(res,res);	
		}
	return ans;
   } 
   string factorial(int num1)
	   {
	    	string fact="1";
		for(int i=2;i<=num1;i++)
		{
		string j=to_string(i);
		fact=multiply(fact,j);
		}
		return fact;
	    }

//

int main()
{

int Q;
cin >> Q;
string s,s2,ans="";
int s1,c,a,b;
	for(int i=0;i<Q;i++)
	{
	cin >> c;
	switch(c)
	{
	case 1: 
	cin >> s >> s1 ;
	ans=exponent(s,s1);
	cout << ans << endl;
	break;
	case 2: cin >> a>> b;
	cout << gcd(a,b) << endl;
	break;
	case 3:
	cin >> s1;
	ans=factorial(s1);
	cout << ans << endl;
	break;
	default : break;
	}
	}
return 0;
}
