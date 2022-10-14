// CS311 Yoshii - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: Joshua Hernandez
// File Type: implementation htable.cpp
// =============================================

using namespace std;
#include <iostream>
#include "htable.h"
#include <fstream>
#include <string>
ifstream fin; // file input stream
ofstream fout; // file output stream

htable::htable()
{}

htable::~htable()
{}


// a simple hash function that takes a string (the champion name in this case) and converts it into an integer through ascii values and then % my TSIZE
int htable::hash(string stringConvert)
{ 
  int sum = 0;
  for (int i = 0; i < stringConvert.size(); i++) // convert the string until there are no more letters in the string
    {
      sum += stringConvert[i]; // a simple hash function that takes the ascii values of each letter and adds it until there are no more letters in the string
    }
 
  sum = sum % TSIZE; // modulos by TSIZE to make sure it is within the bounds of the hash table
  return sum;
}

// adds the element to the table and returns slot#
int htable::add(el_t element )
{
  int slot = hash(element.championName);  // hash with the key part
  table[slot].addRear(element);
  return slot; // ** Note that this means adding the element to a slist in the slot
}

// this function just returns the slot number by hashing the champion name again and returning the slot number 
int htable::displaySlotNumber(string conversion)
{
  el_t champion = find(conversion);
  int slot = hash(champion.championName);
  return slot;
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(string skey)
{ 
 int slot = hash(skey); // hash with skey
 el_t selement;  // this is the element to look for in slist
 el_t elem;
 selement.championName = skey; // initialize selement with just the skey
 elem = table[slot].search2(selement); // call slist's search2 with selement which returns the found element 
 return elem; // return the found element from here (it could be blank)
}

// displays the entire table with slot#s too
void htable::displayTable()
{
  for (int i = 0; i < TSIZE; i++)
    { cout << i << ":" ;   
      table[i].displayAll(); // call slist's displayAll
    }
}

// PURPOSE: This function is to allowt he user to input a file into the database. The database cna only read files in order from 3 strings and a number.
void htable::inputFile(string inputName)
{
  string champName, champOrigin, champClass;
  int cost;
  fin.open(inputName.c_str()); // takes the file name the user gave
  
  if(!fin) // if file was not found
    cout << "The file could not be found or read" << endl;
  
  else
    {
      while (fin >> champName) // while the file is still inputting names
	{
	  fin >> champOrigin >> champClass >> cost; // put into database
	  el_t tempVariable(champName, champOrigin, champClass, cost); // create an element of the class 
	  add(tempVariable); // calls the add function to add it into the database
	  cout << " adding " << endl; // couts adding to make sure that the things are being added into the file
	}
      fin.close(); // close
    }
}

//PURPOSE: This fucntion allows the user to enter a champion that they would like into the database
void htable::addAChampion(string champsName)
{
  
  string championOrigin, championClass;
  int championCost;
    
  cout << "What origin is it? ";
  cin >> championOrigin;
  cout << "What class is it? ";
  cin >> championClass;
  cout << "How much does it cost? ";
  cin >> championCost;
  el_t newChampion(champsName, championOrigin, championClass, championCost); // creates a new element with the info from user
  add(newChampion); // calls add function to add to the database
  cout << "You have added " << champsName << " to your roster!" << endl;
  
}

//PURPOSE: The purpose of this function is to delete a champion from the database using a name that the user gives 
void htable::deleteItem(string champName)
{
  el_t tempChamp = find(champName); // creates an element of the champ based off the name 
  el_t emptyChamp; // empty champion to compare
  int slotNum = displaySlotNumber(champName); // finds the slot num that the champion is in if it's able to be found
  int positionInLL = table[slotNum].search(tempChamp); // finds the position of the champion in he linked list in the hash table if there are multiple champions to make sure it deltes the right one
  if (emptyChamp == tempChamp) // compares to check if there actaully is a champ in the databse that can be deleted
    cout << "There is no champion that can be deleted";
  else
    table[slotNum].deleteIth(positionInLL, tempChamp); // calls the slot num in hash table and deltes from the linked list in that slot


}

//PURPOSE: This outputs the databse to a file including all the data that may have been added from the user.
void htable::outputFile()
{

  el_t temp;
  fout.open("championRoster.txt");
  for(int i = 0; i < TSIZE ; i++) // loops until the the entire table is done
    {
      fout << i << " : ";
      while (!table[i].isEmpty()) // loops while there are still objects in the linked list of the slot in the hash table. 
	{
	  table[i].deleteRear(temp); // uses deleterear since deleterear returnst he element that was deleted and thn writes it to a file since the user will be using a new file every time the database wants to be used. 
	  fout << temp;
	}
      fout << endl;
    }
  fout.close(); // close
}

