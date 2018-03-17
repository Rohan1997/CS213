#include <iostream>

using namespace std;

//////////////////////////Definition of heap//////////////////////////

class heap{
	const int n=30;
	int A[n]; // will hold keys
	int next; // next index at which to insert
	public:
		heap(){ next = 0; }			//Constructor
		bool add(int v);
		int remove();
		void exchange(int &u,int &v);
		void trickledown(int i);
		void heapify(int i);
	private:
		int p(int i){return (i-1)/2;} // index of parent
		int l(int i){return 2*i+1;} // index of left child
		int r(int i){return 2*i+2;} // index of right child
		bool noleftchild(int i){return l(i) >= next;}
		bool norightchild(int i){return r(i) >= next;}
}
////////////////////////// Functions //////////////////////////

bool heap::add(int v)
{
	if(next >= n)
		return false; //overflow
	A[next] = v;
	bubbleup(next);
	next++;
	return true;
}

void heap::bubbleup(int r)
{
	while(r != 0 && A[p(r)] > A[r])
	{
		exchange( A[p(r)], A[r] );
		r = p(r);
	}
}

void heap::exchange(int &u, int &v)
{
	int temp = u;
	u= v;
	v = temp;
	return ;
}

int heap::remove()
{
	if(next == 0) 
		std::abort();
	int v = A[0];
	A[0] = A[next-1];
	next--;
	trickledown(0);
	return v;
}

void heap::trickledown(int i)
{
	int nexti;
	if(noleftchild()) 
		return;
	if(norightchild())
	{
		if(A[i] <= A[l(i)]) return;
		nexti = l(i);
	}
	else 
		nexti = A[l(i)]<A[r(i)]?
				l(i) : r(i);
	exchange(A[i], A[nexti]);
	trickledown(nexti);
}

void heap::heapify(int i)
{
	if(i >= next) return;
	heapify(l(i));
	heapify(r(i));
	trickledown(i);
}
////////////////////////// main //////////////////////////


int main()
{
	
	return 0;
}