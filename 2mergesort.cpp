#include <iostream>
using namespace std;


void mergesort(int S[], int n);
void merge(int U[], int p, int V[], int q, int S[], int n);


void mergesort(int S[], int n)
{
	// Sorts sequence S of length n.
	if(n==1) return;
	int U[n/2], V[n-n/2];
	for(int i=0; i<n/2; i++) U[i]=S[i];
	for(int i=0; i<n-n/2; i++) V[i]=S[i+n/2];
	mergesort(U,n/2);
	mergesort(V,n-n/2);
	//”Merge” sorted U, V into S.
	merge(U, n/2, V, n-n/2, S, n);
}

void merge(int U[], int p, int V[], int q, int S[], int n)
{
	// S should receive all elements of U,V, in sorted order.
	for(int uf=0, vf=0, sb=0;
		sb < p + q; // while all elements havent moved
		sb++)
	{
		if(uf<p && vf<q)
		{ 
			// both U,V are non empty
			if(U[uf] < V[vf])
			{
				S[sb] = U[uf]; uf++;
			}
			else
			{
				S[sb] = V[vf]; vf++;
			}
		}
		else if(uf < p)
		{ 
			// only U is non empty
			S[sb] = U[uf]; uf++;
		}
		else
		{
 			// only V is non empty
			S[sb] = V[vf]; vf++;
		}
	}
}
//After i iterations, the smallest i elements move into S from U,V

int main()
{
	int n;
	cin>>n;
	int s[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>s[i];
	}
	mergesort(s,n);
	for (int i = 0; i < n; ++i)
	{
		cout<<s[i]<<" ";
	}
	cout<<endl;
	return 0;
}