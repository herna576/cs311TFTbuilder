

// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//----------------------------------------------------

#include "elem.h"
#include <string>

// blank element
el_t::el_t()
{
  championName = "";
  championOrigin = "";
  championClass = "";
  cost = 0;
}

// initializing constructor to create an el_t object 
el_t::el_t(string aname, string origin, string champClass, int aCost)
{
  championName = aname;
  championOrigin = origin;
  championClass = champClass;
  cost = aCost;
}



// overload == for search based on the key part only
bool el_t::operator==(el_t OtherOne)
{
  if (championName == OtherOne.championName) return true; else return false;
}

// overload != for search based on the key part only
bool el_t::operator!=(el_t OtherOne)
{
  if (championName != OtherOne.championName) return true; else return false;
}

// overload cout 
// this overloads the cout function so that it allows someone to write it out to a file and cout it to the file by sending the element and using the . operator in order to access different parts
ostream& operator<<(ostream& os, const el_t& E)  
{  
  os << "[Name: " << E.championName << " Origin: " << E.championOrigin << " Class: " << E.championClass << " Cost: " << E.cost << "] ";
  return os;  
}  
