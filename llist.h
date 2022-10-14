//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Joshua Hernandez
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition

//typedef char el_t; element is now a class so this is no longer needed anymore!
#include"elem.h"
//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void  moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //PURPOSE: check to see if the linked list ie empty
  //PARAMETERS: N/A
  bool isEmpty();
    
  //PURPOSE: displays all the elements in the linked list
  //PARAMETERS: N/A
  void displayAll();

  //PURPOSE: adds an element to the front of the linked list
  //PARAMETERS: element to be added to the front
  void addFront(el_t);
    
  //PURPOSE: adds an element to the rear of the linked list
  //PARAMETERS: element to be added to the rear
  void addRear(el_t);

  //PURPOSE: deletes the first element and puts it into old num
  //PARAMETERS: element to be deleted from the front 
  void deleteFront(el_t&);
    
  //PURPOSE: deletes the rear element in the linked list
  //PARAMETERS: element to be deleted from the rear
  void deleteRear(el_t&);
    
  //PURPOSE: deletes a certain element in linked list
  //PARAMETERS: integer to find the right place in the linked list and the element to be deleted
  void deleteIth(int, el_t&);  // calls moveTo

  //PURPOSE: inserts certain element in linked list
  //PARAMETERS: integer to find the place in the linked list and the element to be inserted
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};

