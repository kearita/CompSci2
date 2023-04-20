#include <iostream>
#include <fstream>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

/**
    Builds a linked list of integers from an external file and searches and displays data from list
    @author Keara Taylor Lopez
    @date February 23, 2023
*/
int main()
{
    LinkedList myList;

    myList.fillListFromFile();

    myList.printList();

    cout << "Size of the linked list is: " << myList.getSize() << endl;


    cout << "Attempting to search for value (0 = not found, 1 = found): " << myList.searchVal(253) << endl;


    cout << "Value appears in the list " << myList.countFrequencyOf(253) << " time(s)" << endl;


    cout << "Displaying from Front to N: " << endl;
    cout << "-----------------------------------------------" << endl;
    myList.displayFromFrontToN(5);


    cout << "Displaying from N to End: " << endl;
    cout << "-----------------------------------------------" << endl;
    myList.displayFromNToEnd(5);

    myList.displayInRows();

    return 0;

}//end main()
