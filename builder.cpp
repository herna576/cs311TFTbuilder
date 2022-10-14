using namespace std;
#include "htable.h"

// Joshua Hernandez Final Project 
int main()
{
  
  int menuChoice;
  string fileName;
  htable hashTable;
  string cName;
  string addAChamp;
  string deleteAChamp;
  // loops until the user inputs 7 and ends the program
  do
    {
      cout << "Welcome to the TFT team builder program! What would you like to do?" << endl << endl;
      cout << "1) Load a data file" << endl;
      cout << "2) Search by Name (no spaces)" << endl;
      cout << "3) Display the data on the screen" << endl;
      cout << "4) Add a champion to the roster" << endl;
      cout << "5) Delete a champion from the roster" << endl;
      cout << "6) Save the data to a file" << endl;
      cout << "7) Exit the program" << endl;
      cout << "Please eneter your choice: ";
      cin >> menuChoice;
      
      switch(menuChoice)
	{
	case 1: // if the user inputs 1 
	  {
	    cout << "Please input the file name: ";
	    cin >> fileName; 
	    hashTable.inputFile(fileName); // load the file into the database
	    break;
	  }
	case 2: 
	  {
	    cout << "What champion name would you like to look for(all caps)? ";
	    cin >> cName; // asks the user for a name since it's the unique key used to search for things
	    
	    el_t searchedFor = hashTable.find(cName);
	    el_t comparison; // empty values in the element if it returned blank and if its equal to the blank then it was not found
	    if(searchedFor == comparison)
	      cout << cName << " was not found." << endl << endl;
	    else
	      cout << "Champion was found in slot # " << hashTable.displaySlotNumber(cName) << ": " << searchedFor << endl << endl;
	    break;
	  }
	case 3:
	  {
	    hashTable.displayTable(); // displays database
	    break;
	  }
	  
	case 4:
	  {
	    cout << "Which champion would you like to add to your roster? ";
	    cin >> addAChamp;
	    hashTable.addAChampion(addAChamp); // adds a champion to the database based on user input
	    break;
	  }
	  
	case 5:
	  cout << "What champion would you like to delete? ";
	  cin >> deleteAChamp;
	  hashTable.deleteItem(deleteAChamp); // deletes a champion from the databse as long as the user inputs a valid name
	  break;
	  
	case 6:
	  hashTable.outputFile();// writes the database to a file that the user can use
	  cout << "Data has been written to a file, thank you!" << endl;
	  break;
	  
	  
	  
	}
      
      
      
      
    }while(menuChoice != 7);
    
    cout << "thank you for using the TFT builder program!" << endl;
  return 0;
}
