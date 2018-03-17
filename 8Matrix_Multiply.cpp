#include <iostream>
#include <vector>
#include <string>
using namespace std;

//////////////////////////Vector Multiplication function///////////////////

///The below function changes an input function
void matrix_multiply(int n,vector<vector<float> > A, vector<vector<float> > B, vector<vector<float> > &C )
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n ; ++j)
		{
			C[i][j]=0;
			for (int k = 0; k < n; ++k)
			{
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}
	return ;
}

///The below function gives output a vector
vector<vector<float> > multiply_matrices(int n,vector<vector<float> > A, vector<vector<float> > B)
{
	vector<vector<float> >C(n,vector<float>(n,0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n ; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}
	return C;
}

//////////////////////////Main//////////////////////////

int main()
{
	int n;
	n = 2;
	vector<vector<float> >A(n,vector<float>(n,0));
	vector<vector<float> >B(n,vector<float>(n,0));
	vector<vector<float> >C(n,vector<float>(n,0));

	for (int i = 0; i < n; ++i)
	{
		A[i][i]=1;
		B[i][i]=2;
	}
	B[1][0]=45;
	matrix_multiply(n,A,B,C);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<C[i][j]<<" ";
		}
		cout<<endl;
	}

	vector<vector<float> > D = multiply_matrices(n,A,B);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<D[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
