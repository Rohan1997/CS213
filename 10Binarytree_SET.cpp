#include <iostream>		//For input output
#include <string>		//For strings
#include <vector>		//For Vectors
#include <algorithm>	//To sort vectors and arrays, refer lec 8 of CS213
#include <map>			//To use maps

using namespace std;


//////////////////////////////Implementing a binary tree//////////////////////////////


struct Node; // forward declaration

class Set
{
	Node *pRoot; // pointer to root
	public:

	Set()
	{
		pRoot = NULL;
	} // empty set

	void insert(int elt);
	bool find(int elt);
};

struct Node
{
	Set left, right;
	int value;
	Node(int v){value = v;}
};


//////////////////////////////Function initialisation//////////////////////////////

//bool find(Node* myset, int x);
//void insert(Node* &myset, int x); //Need to pass by reference
void print(Node* myset);
void remove(Node* myset, int x);

//////////////////////////////Functions//////////////////////////////

bool Set::find(int elt)
{
	if(pRoot == NULL)
		return false;
	if(elt == pRoot->value)
		return true;
	else if(elt < pRoot->value)
		return pRoot->left.find(elt);
	else
		return pRoot->right.find(elt);
}

void Set::insert(int elt)
{
	if(pRoot == NULL)
		pRoot = new Node(elt);
	else if(elt < pRoot->value)
		pRoot->left.insert(elt);
	else
		pRoot->right.insert(elt);
}
/*
void print(Node* myset)
{
	if(myset == NULL)
		return;
	print(myset->left);
	cout << myset->value <<endl;
	print(myset->right);
}*/
///////////////////////////////Main///////////////////////////////
int main()
{
	Set myset; 						// constructor makes it empty
	myset.insert(40);
	myset.insert(20);
	cout <<"Finding 30: " <<
	myset.find(30) << endl;			// Should print 0.
	cout <<"Finding 40: " <<
	myset.find(40) << endl;			// Should print 1.
	return 0;
}
