#include <iostream>
using namespace std;


class String
{
	char* ptr;
	public:
		String()
		{ // constructor
			ptr = NULL; // initially empty string
		}
		void print(){ // print function
		if(ptr != NULL)
			cout << ptr;
		else
			cout <<“NULL”;
	}

}

String& operator=(const String &rhs)
{
	// To be very general, we must allow self assignment.
	// If it is a self assignment, we do nothing.
	if(this == &rhs) return *this;
	// Release the memory that ptr already points to.
	delete ptr;
	// Make a copy of rhs.ptr on the heap
	// Allocate length(rhs.ptr) + 1 byte to store ‘\0’
	// Assume we have a length function (Section 15.1.4)
	ptr = new char[length(rhs.ptr)+1];
	// Actually copy. Function scopy from 15.1.4
	scopy(ptr, rhs.ptr);
	return *this;
}