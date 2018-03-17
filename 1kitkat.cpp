#include <iostream>

using namespace std;

int main()
{
	char x;
	int m=0;
	while(m!=6)
	{
		cin>>x;
		if (m==0 )
		{
			if(x=='k')
				m++;
			else m=0;
		}
		else if (m==1 )
		{
			if(x=='i')
				m++;
			else m=0;
		}
		else if (m==2 )
		{
			if(x=='t')
				m++;
			else m=0;
		}
		else if (m==3 )
		{
			if(x=='k')
				m++;
			else m=0;
		}
		else if (m==4 )
		{
			if(x=='a')
				m++;
			else m=0;
		}
		else if (m==5)
		{
			if(x=='t')
				m++;
			else m=0;
		}
	}

	return 0;
}