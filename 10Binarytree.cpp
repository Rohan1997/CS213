#include <iostream>		//For input output
#include <string>		//For strings
#include <vector>		//For Vectors
#include <algorithm>	//To sort vectors and arrays, refer lec 8 of CS213
#include <map>			//To use maps

using namespace std;


//////////////////////////////Implementing a binary tree//////////////////////////////


struct Node
{
	Node *left, *right;
	int value;
};

//////////////////////////////Function initialisation//////////////////////////////

bool find(Node* myset, int x);
void insert(Node* &myset, int x); //Need to pass by reference
void print(Node* myset);
void remove(Node* myset, int x);

//////////////////////////////Functions//////////////////////////////

bool find(Node* myset, int x)
{
	if(myset == NULL)
		return false;
	if(x == myset->value)
		return true;
	if(x < myset->value)
		return find(myset->left, x);
	else
		return find(myset->right, x);
}

void insert(Node* &myset, int x)
{
	if(myset == NULL)
	{
		myset = new Node;
		myset->left = myset->right = NULL;
		myset->value = x;
	}
	else
	{
		if(x == myset->value)
			return;
		else if(x < myset->value)
			insert(myset->left, x);
		else
			insert(myset->right, x);
	}
}

void print(Node* myset)
{
	if(myset == NULL)
		return;
	print(myset->left);
	cout << myset->value <<endl;
	print(myset->right);
}
/*
void remove(Node* myset, int x)
{
	if
}
*/
///////////////////////////////Main///////////////////////////////
int main()
{
	Node* myset = NULL;
	insert(myset, 40);
	insert(myset, 20);
	cout <<"Finding 30: " <<
	find(myset, 30) << endl;		// Should print 0.
	cout <<"Finding 40: " <<
	find(myset, 40) << endl;		// Should print 1.
	return 0;
}
