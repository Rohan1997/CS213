#include <iostream>

using namespace std;
//Using Recursion
bool Bsearch(int *a, int s, int l, int x)//search x in a[] starting index s, length of region l
{
	// Search in A[S..S+L-1]
	if(l == 1) return a[s] == x;
	int h = l/2;
	if(x < a[s+h]) return Bsearch(a, s, h, x);
	else
 	return Bsearch(a, s+h, s+l-h, x);
}

//Without using recursion
bool BinSearch(int *a, int s, int l, int x)
{
	
	int p;
	p=s + l/2;
	if(a[s]==x) return 1;
	while(l!=0 )
	{
		if(a[s+l/2]==x) return 1;
		if(x>a[s+l/2]) 
			{
				s = s+l/2;
				l= l/2;
			}
		else 
			{
				s = s - l/2;
				l=l/2;
			}
	}
	return 0;
}

int main()
{
	cout<<"Enter the no of digits in your array: ";
	int n;
	cin>>n;
	int a[n];
	cout<<endl<<"Start entering your inputs:"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<"Starting index=";
	int s,l,x;
	cin>>s;
	cout<<endl<<"Length of array=";
	cin>>l;
	cout<<endl<<"Find the no.=";
	cin>>x;
	cout<<endl<<Bsearch(a,s,l,x)<<endl;
	cout<<BinSearch(a,s,l,x)<<endl;

	return 0;
}