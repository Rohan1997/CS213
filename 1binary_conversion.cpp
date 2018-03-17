#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int x=0,i=0;
	while(n!=0)
	{
		x=x*10 + n%2;
		n=n/2;
		++i;
	}
	int y=0;
	while(i!=0)
	{
		y = 10*y + x%10;
		x=x/10;
		i--;
	}
	cout<<y<<endl;
	return 0;
}