#include <iostream>		//For input output
#include <string>		//For strings
#include <vector>		//For Vectors
#include <algorithm>	//To sort vectors and arrays, refer lec 8 of CS213
#include <map>
using namespace std;

int main()
{
////////Initialising a map
	map<string,double> population;
	population["India"] = 1.21;				// in billions. Map entry created.
	population["China"] = 1.35;
	population["USA"] = 0.31;
	cout << population["China"] << endl;	// will print 1.35
	population["India"] = 1.22;				//update allowed.
/////////Initialisng an iterator
	map<string,double>::iterator mi;
	mi = population.begin();				// population.begin() : “constant” iterator
											// points to the first element of population
											// mi points to (India,1.21)
	cout << mi->first << endl;				// will print out "China".
	cout << mi->second << endl;				// will print out 1.35.

///////////////Using Iterators
	for(map<string,double>::iterator mi = population.begin(); mi != population.end(); mi++)
	// ++ sets mi to point to the next element of the map.
	{
		cout << mi->first << " : " << mi->second << endl;
		// will print out countries and population in alphabetical order.
	}

	return 0;
}
