// CS311 Yoshii Complete all functions with their comments

// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Joshua Hernandez
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist()
{}


// positions always start at 1

int slist::search(el_t key)
{
  Node* nodePtr = Front; // create a pointer pointing to Front
  for (int i =1; nodePtr != NULL; i++) // this loop goes through the linked list stops when it hits NULL
    {
      if(key == nodePtr -> Elem) // if the Key is equal to the element in one of the nodes, then return the position of that node
	return i;
      else // go to the next node in the linked list
	{
	  nodePtr = nodePtr -> Next;
	}
    }
  return 0; // return 0 if the key was not found within the linked list
}

// don't forget to throw OutOfRange for bad pos 
void slist::replace(el_t element, int pos)
{
  if (pos < 1 || pos > Count) // this checks if the position given is valid and not out of bounds
    throw OutOfRange();
  else
    {
      Node *posPointer = Front; // create a pointer  to the front
      moveTo(pos, posPointer); // mose that pointer to the node specified
      posPointer -> Elem = element; // replace the element in that node with the element that was passed to the function 
    }

}

bool slist::operator==(const slist& OtherOne)
{
  if (Count != OtherOne.Count) // if the linked lists do not have the same amount of nodes than return false
    {
      return false;
    }
  else
    {     
      Node* ogPointer = Front; // create a pointer to the Front of the first  linked list
      Node* OtherOnePointer = OtherOne.Front; // create a pointer to the Front of the linked list you are comapring the orignial to

      for(int i = 1; i < Count + 1; i++) // this loop goes through both linked lists ending when it reaches the last node by keeping track of count
	{
	  if (ogPointer -> Elem != OtherOnePointer -> Elem) // checks to see if the elements are equal to each other if not then return false
	    {
	      return false;
	    }
	  else // if the elements are equal to each other go on to the next node of each linked list and compare again
	    {
	      ogPointer = ogPointer -> Next;
	      OtherOnePointer = OtherOnePointer -> Next;
	    }
	}
      
      // if not the same length, return false
      // if the same lengths,
      // check each node to see if the elements are the same
      return true;      // the linked lists are identical
    }
}

el_t slist::search2(el_t key)
{
  el_t empty; // empty element meaning not found
  Node * nodePtr = Front; // create a pointer pointing to Front
  for (int i = 1 ; nodePtr != NULL; i++) // this loop goes through the linked list stops when it hits NULL
    {
      if(key == nodePtr -> Elem) // if the Key is equal to the element in one of the nodes, then return the position of that node
        return nodePtr -> Elem;
      else // go to the next node in the linked list
        {
	  nodePtr = nodePtr -> Next;
        }
      
    }
  return empty; // returns nothing if nothing was found
}
