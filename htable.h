// CS311 Yoshii - Hash Table header DO NOT CHANGE!!! 
// ------------------------------------------------

#include "slist.h"

const int TSIZE = 61;  // 61 slots ; a prime number 

class htable
{
 private:
 slist table[TSIZE]; // each node of slist is el_t 
 // as defined in elem.h

 int hash(string);  // private hash function


 public:
  htable();
  ~htable();
  void deleteItem(string champName); // delete a champion from the database
  void addAChampion(string champsName); // this adds a champion to a roster 
  int displaySlotNumber(string conversion);// this returns the slot # of whatever the string was in
  int stringConvert(string); // this function is used to convert a string to an integer in order for it to be hashed
  int add(el_t);  // adds an element to the table and returns slot#
  el_t find(string); // finds an element based on key and returns it
  void displayTable(); // displays the table with slot#s
  void inputFile(string); // takes data from a file and puts it into the hash table
  void outputFile(); // things that are added to the champion roster

};
