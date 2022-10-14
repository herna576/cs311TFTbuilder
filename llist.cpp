//CS311 Yoshii Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes

//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  cntr-K cuts and cntr-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Joshua Hernandez
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist()
{ 
  Front = NULL;
  Rear = NULL;
  Count = 0;
}

llist::~llist()
{  

  el_t OldNum;
  while (!isEmpty()) // destroys all nodes in a linked list by checking the amount of nodes in a list until it hits 0
    {
      deleteFront(OldNum);
    }
}


//PURPOSE: This function checks is the linked list is empty or not, it returns true if it is and false if it is not
//PARAMETER: N/A
bool llist::isEmpty()  // be sure to check all 3 data members
{
  if (Front == NULL && Rear == NULL && Count == 0) // if this is true then the linked list is empty
    return true;
  else
    return false;
}

//PURPOSE: This fucntion is to display all nodes in a linked list starting from Front
//PARAMETER: N/A
void llist::displayAll()  // be sure to display horizontally in [  ] with // blanks between elements
{

  Node *nodePtr = Front; // creates a pointer tha points to the front of the linked list
  if (isEmpty()) // if empty diplay linked list is empty
    {
      cout << "[EMPTY]";
    }
  else
    {
      //      cout <<"[" ;
      while (nodePtr != NULL) // loops until nodePtr hits NULL which it hits when it gets to the last node/rear node
	{
	  cout << nodePtr -> Elem << " ";
	  nodePtr = nodePtr -> Next;

	}

      //  cout << "]";	       
    }
  cout << endl;
}
  
//PURPOSE: The purpose of this function is to add a node to the rear of a linked list
//PARAMETER: NewNum is the element that is going to be passed to the node and implemented into the linked list
void llist::addRear(el_t NewNum)// comment the 2 cases
{
  //create a node that can be added to the linked list with the element that was passed to the function
  Node *nodePtr = new Node;
  nodePtr -> Elem = NewNum;
  nodePtr -> Next = NULL;
  
  //this case is if the linked list is empty and the first node that is being added to the linked list
  if (isEmpty())
    {
      Front = nodePtr; // sets the new node to the Front (this is because the first node in a linked list is also the rear as well as the Front)
      Rear = nodePtr; // set the new node to the Rear (this is because the first node in a linked list is also the rear as well as the Front)
      Count++; // increment count to keep track of the amount of nodes in the linked list
    }

  //this case is if the linked list already has one node or more in the linked list
  else
    {
      Rear -> Next = new Node; // Rear (a pre defined node) points to next which is = to a new node struct
      Rear = Rear -> Next; // rear is now set equal to rear pointing to next (which is = to a new node struct)
      Rear -> Elem = NewNum; // the element in the new rear is now equal to the element we passed to the function (right now it is an int)
      Rear -> Next = NULL; // the node now points to the next node in the linked list, since this is the end of the linked list it points to NULL
      Count++; // count is incremented to keep track of the amount of nodes in the linked list
    }


}

//PURPOSE: The purpose of this function is to add a node to the front of the linked list
//PARAMETER: NewNum is the element that is going to be passed to the node and implemented into the linked list
void llist::addFront(el_t NewNum) // comment the 2 cases
{
  // this is if the linked list is empty and it is the first node being added to the linked list
  if (isEmpty())
    {
      Node *nodePtr = new Node; // created new Node
      nodePtr -> Elem = NewNum;// nodePtr is pointing to new element that we passed from function
      nodePtr -> Next = NULL; // nodePtr next is pointing to NULL Since it is the first node in the linked list
      Front = nodePtr; // Front is set equal to nodePtr, since nodePtr's elem is pointing to NewElem and next is also pointed to NULL
      Rear = nodePtr;// Rear is set equal to nodePtr, since nodePtr's elem is pointing to NewElem and next is also pointed to NULL
      Count++; // count is incremented
    }
  
  // this case is if the linked list already has one node or more in the linked list
  else
    {
      Node *nodePtr = new Node; // new node is created
      nodePtr -> Elem = NewNum; // the new node's element is now equal to the element we passed from the function
      nodePtr-> Next = Front; // the new node's next is now pointing to the previous Front (the one that was the the front of the linked list before the creation of this node)
      Front = nodePtr; // the new Front of the linked list is now the new node that we created
      Count++;
    }
}
//PURPOSE: The purpose of this function is to delete the Front node of a linked list and replace it with a new front node
//PARAMETER: OldNum is used here to store the element that was in the Front element
void llist::deleteFront(el_t& OldNum)// comment the 3 cases
{
  // this case is if the linked list is empty, it will throw underflow since it cannot delete a front if there is no linked list
  if(isEmpty())
    {
      throw Underflow();
    }

  // this is case for if the linked list only has one Node, and deleting that node will cause the linked list to become empty
  else if(Front == Rear)// if Front and Rear are equal then we know that there is only one node in the linked list
    {
      OldNum = Front -> Elem; // gives oldNum whatever element was in Front
      Front = NULL;
      delete Front; // delete Front
      Rear =  NULL; // set Rear to NULL to not create a dangling pointer
      delete Rear;
      Count = 0; // set Count = 0 since there are no more nodes in the linked list
    }

  // this is the case for if the linked list already has more than one node in the linked list, it will delete the current Front one and replace it the new Front node
  else
    {
      OldNum = Front -> Elem; // gives oldNum whatever element was in Front
      Node *Second; // create a new Node called Second
      Second = Front -> Next; // Second is equal to whatever node Front was pointing to Next (i.e. node 1 points to node 2, second is now pointing to node 2)
      delete Front; // delete Front (technically node 1)
      Front = Second; // now we set the new front = second (which is technically the second node in the linked list before we deleted the previous Front)
      Count--;
    }
  
  
}

//PURPOSE: The prupose of this function is to delete the Rear node of a linked list, and replace it with a new Rear
//PARAMETER: OldNum is used here to store the element that was previously in the Rear element so it's not lost forever
void llist::deleteRear(el_t& OldNum) // comment the 3 cases
{
  if (isEmpty())// if the linked list is empty
    {
      throw Underflow(); //throws underflow since it cannot delete anyhting if the linked list is empty already
    }
  else if(Front == Rear) // if the linked list will be empty after deleting the rear node
    {
      OldNum = Rear -> Elem; // OldNum is set to the element that was in Rear most element
      Rear = NULL; 
      delete Rear; 
      Front = NULL; 
      Count = 0;
    }
  else // all other cases
    {
       Node *prevPtr = Front; // set a new Node to front to make it a node that can traverse to the rear node 
      while(prevPtr -> Next != Rear) // make the node traverse all the way to the last node in the linked list
	{
	  prevPtr  = prevPtr -> Next; // traverses the linked list by following next pointers till it hits the node that is also set as Rear
	}

      OldNum = Rear -> Elem; // set the element from OldNum eqaul to the element that was in the Rear Node
      Rear -> Next = NULL; // set the next pointer fo Rear to NULL
      delete Rear; // delete rear
      Rear = prevPtr; // set Rear equal to previous pointer
      Rear -> Next = NULL; // set the next pointer of Rear to NULL since it is the new Rear pointer 
      Count--; // increment count
     
    }

}


/* harder ones follow */

// Utility Function to move a local pointer to the Ith node
void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times
  
  for ( int K = 1; K <= J - 1; K++) 
    temp = temp->Next;
}

//PURPOSE: The purpose of this function is to delete a specific node within a linked list
//PARAMETER: I is given to give the position of the Node in the linked List, while OldNum is given to store the element in the specific node given so it is not lost forever
void llist::deleteIth(int I, el_t& OldNum) // use moveTo to move local pointers. Be sure to comment to which node you are moving them.  
{
  if((I < 1 || Count < I)) // I is the position in the linked list checking to see if it is within range
    {
      throw OutOfRange();
    }
  else if(isEmpty()) // if the linked list is empty
    {
      throw Underflow();
    }
  else if(I == 1) // if the Node given is the Front node, then call the deleteFront function to delete the Front Node
    {
      deleteFront(OldNum);
    }
  else if(I == Count) // if the Node given is the Rear node in the linked list, then call the deleteRear function to delete the Rear node
    {
      deleteRear(OldNum);
    }
  
  // this case is if the linked list has more than one node
  else
    {
      Node *ithNode = Front; // create a pointer to the Specific ode given
      Node *pointerAfter = Front; // create a pointer to the Node after the Specific node given
      Node *pointerBefore = Front; // create a pointer to the Node before the Specific node given
      moveTo(I - 1, pointerBefore); // moves the pointer to the Node before the specific node
      moveTo(I + 1, pointerAfter); // moves the pointer to the Node after the specific node
      moveTo(I, ithNode); // moves the pointer to the specific Node that would like to get deleted
      OldNum = ithNode -> Elem; // stores the element that is in the specific node given into oldNum so it is not lost forever
      delete ithNode; // delete the specific Node
      pointerBefore -> Next = pointerAfter; // Set the next node that was before the specific node to the node that was after the specific node instead
      Count--;
    }
}
//PURPOSE: The purpose of this function is to insert a node into a specific spot in the linked list
//PARAMETER: I is given to give the position of the specific Node in the linked list, while newNum is the element that is passed to the node we are trying to add to the linked list
void llist::insertIth(int I, el_t newNum) // use moveTo to move local pointers. Be sure to comment to which node you are moving them.
{ 
  if((I < 1) || (I > Count + 1)) // if the user is trying to enter a number that is not within the range of the linked list
    {
      throw OutOfRange();
    }
  else if(I == 1) // if the position of the Node that is trying to be inserted is the Front of the linked list, then just call addFront to add it to the linked list
    {
      addFront(newNum);
    }
  else if(I == Count + 1) // if the position of the Node that is trying to be inserted is the Rear of the linked list, then just call the addRead to add it to the linked list
    {
      addRear(newNum);
    }

  // this case is if the linked list has more than one node in it already and you're trying to put it in between two nodes
  else 
    {
      Node *newNode; // create a pointer
      newNode = new Node; // have the pointer point to a new Node Struct that we created
      newNode -> Elem = newNum; // set the Element of the new Node to the value that we passed to the function
      Node *pointerAfter = Front; // Create a pointer that points to the Front of the linked list
      Node *pointerBefore = Front; // Create a pointer that points to the Front of the linked list
      moveTo(I, pointerAfter); // moves the second pointer we created to the location of the Ith Node
      moveTo(I - 1, pointerBefore); // moves the third pointer we created to the location of the Node before the Ith node
      pointerBefore -> Next = newNode; // sets the Before pointer to point to the newNode that we created 
      newNode -> Next = pointerAfter; // sets the pointer of the newNode that we created to the node that is now after the pointer in the Ith position
      Count++; // increment count

    }
  
  

}

//PURPOSE: The purpose of this is to allow the poassing of a list by value and returning of a list by value, this creates a new object this -> as a copy of the Original 
//PARAMETER: Original is the llist that we would like to copy
llist::llist(const llist& Original) // use my code
{ 
  // this ->'s data nmemebers need to initialized here first
  Front = NULL;
  Rear = NULL;
  Count = 0;
  // this -> object has to be built up by allocating new cells and copying the values from Original into each cell using the overloaded = operator below
  Node* P;
  P = Original.Front;
  while (P != NULL)
    {
      this -> addRear(P -> Elem);
      P = P -> Next;
    }
  // this returns nothing since this is just a copy constructor
}


//PURPOSE: The purpose of this is to overload the = operator in order to create a copy of a linked list 
//PARAMETER: OtherOne is a different linked list than the one we are trying to copy
llist& llist::operator=(const llist& OtherOne) // use my code
{
  el_t x;
  // First we make sure this -> and OtherOne are not the smae object, adn we do this by comparing the pointers to the objects
  if(&OtherOne != this)
    {
      // this -> object has to be emptied first
      while(!this -> isEmpty())
	this ->deleteRear(x);
      // this -> object has to be built up by allocating new cells with OtherOne elements (**)
      Node* P; // local pointer for the OtherOne
      P = OtherOne.Front;
      while(P != NULL) // a loop which repeats until you reach the end of the OtherOne
	{
	  this -> addRear(P-> Elem); // P's element is added to this
	  P = P-> Next; // Go to the next node in OtherOne

	}
    }
  return *this; // return the result unconditionally. Note that the result is returned by reference
}
