#include "slist.h"
#include <cstring>
#include <iostream>
#include <string>
/*
Class Library File
*/

// Constructor

Linkedlist::Linkedlist() { head = NULL; };

// Destructor

Linkedlist::~Linkedlist(){

};

// add(value)				//Adds a new value to the end of this
// list.

void Linkedlist::add(Node *newNode) {
  int i = 0;
  if (head == NULL) {
    head = newNode;
  } else {
    Node *temp = head;
    while (temp->next != NULL) {

      temp = temp->next;
    }
    temp->next = newNode;
  }
};
// clear()					//Removes all elements from this
// list.

void Linkedlist::clear() {

  while (head != NULL) {
    Node *temp = head;
    while (temp->next->next != NULL) {
      temp = temp->next;
    }
    if (temp->next == NULL) {
      head = NULL;
    } else {
      temp->next = nullptr;
    }
  }
};

// equals(list)				//Returns true if the two lists contain the
// same elements in the same order.

bool Linkedlist::equals(Linkedlist l) {
  Node *temp1 = head;
  Node *temp2 = l.head;

  while (temp1 != NULL && temp2 != NULL) {
    std::string s1 = temp1->code;
    std::string s2 = temp2->code;
    if (s1 != s2 || temp1->latitude != temp2->latitude ||
        temp1->longitude != temp2->longitude) {
      return false;
    }
    temp1 = temp1->next;
    temp2 = temp2->next;
  }
  if (temp1 == NULL && temp2 == NULL) {
    return true;
  } else {
    return false;
  }
};
// get(index)				//Returns the element at the specified index in
// this list.

Node *Linkedlist::get(int index) {
  Node *temporary = new Node;
  temporary = head;
  int c = 0;
  while (c < index) {
    /*
    std::cout << "count: " << c << std::endl;
    std::cout << temp << std::endl;
    std::cout << temp->code << std::endl;
    std::cout<< index << std::endl;
    */
    temporary = temporary->next;
    c++;
    /* if( index == 210){
      std::cout <<"hi" <<std::endl;
    } */
  }
  return temporary;
};
// insert(index, value)		//Inserts the element into this list before the
// specified index.
void Linkedlist::insert(int index, Node newNode) {
  Node *temp = head;
  Node *prev = NULL;
  int c = 0;
  while (c < index) {
    prev = temp;
    temp = temp->next;
    c++;
  }
  prev->next = &newNode;
  newNode.next = temp;
};

// exchg(index1, index2)		//Switches the payload data of specified
// indexex.
void Linkedlist::exchg(int index1, int index2) {
  Node *temp1 = head;
  Node *temp2 = head;
  char tempcode[5];
  double templon;
  double templat;
  int c1 = 0;
  int c2 = 0;
  while (c1 < index1) {
    temp1 = temp1->next;
    c1++;
  }
  while (c2 < index2) {
    temp2 = temp2->next;
    c2++;
  }

  memcpy(tempcode, temp1->code, 5);
  memcpy(temp1->code, temp2->code, 5);
  memcpy(temp2->code, tempcode, 5);
  templon = temp1->longitude;
  temp1->longitude = temp2->longitude;
  temp2->longitude = temp1->longitude;
  templat = temp1->latitude;
  temp1->latitude = temp2->latitude;
  temp2->latitude = templat;
};

// swap(index1,index2)		//Swaps node located at index1 with node at
// index2

void Linkedlist::swap(int index1, int index2) {
  //std::cout << "indexes" << index1 << "," <<index2 << std::endl;
  
  Node *temp1 = head;
  Node *prev1 = NULL;
  Node *temp2 = head;
  Node *prev2 = NULL;
  Node *temp3 = NULL;

  int c1 = 0;
  int c2 = 0;
  while (c1 < index1) {
    prev1 = temp1;
    temp1 = temp1->next;
    c1++;
  }
  while (c2 < index2) {
    prev2 = temp2;
    temp2 = temp2->next;
    c2++;
  }
  temp3 = temp2->next;
  
  if (index1 != 0){
    if( index2-index1==1){
      prev1->next = temp2;
      temp2->next = temp1;
      temp1->next = temp3;
    } else{
    
    prev1->next = temp2;

    temp2->next = temp1->next;

    prev2->next = temp1;
    temp1->next = temp3;
    }
  } else {

    if( index2-index1==1){

      temp2->next = temp1;
      temp1->next = temp3;
      head = temp2;
    
    } else{
    temp2->next = temp1->next;
    prev2->next = temp1;
    temp1->next = temp3;

    head = temp2;
    }
  }
};



void Linkedlist::fasterSwap(Node** node1p, Node** node2p,Node* node1, Node* node2, int index1, int index2) {
  //std::cout << "indexes" << index1 << "," <<index2 << std::endl;
  
  Node *temp1 = node1->next;
  Node *temp2 = node2->next;
  

  
    if( index2-index1 == 1){
      //std::cout <<"0near" << std::endl;

      *node1p = node2;
      node2->next = node1;
      node1->next = temp2;
    
    } else{

    //  std::cout <<"0far" << std::endl;
      
      Node* temp3 = *node1p;
      *node1p = *node2p;
      *node2p = temp3;

      Node* temp4 = temp1;
      temp1 = temp2;
      temp2 = temp4;
      
    }
  
  
};


// isEmpty()				//Returns true if this list contains no
// elements.

bool Linkedlist::isEmpty() {

  if (head == NULL) {
    return true;
  } else {
    return false;
  }
};

// remove(index)			//Removes the element at the specified index from
// this list.

void Linkedlist::remove(int index) {
  Node *temp = head;
  Node *prev = NULL;
  int c = 0;
  while (c < index) {
    prev = temp;
    temp = temp->next;
    c++;
  }
  prev->next = temp->next;
  delete temp;
};

// set(index, value)		//Replaces the element at the specified index in
// this list with a new value.

void Linkedlist::set(int index, Node newNode) {

  Node *temp = head;
  int c = 0;
  while (c < index) {

    temp = temp->next;
    c++;
  }
  temp = &newNode;
};
// size()					//Returns the number of elements in this
// list.
int Linkedlist::size() {
  Node *temp = head;
  int c = 0;
  while (temp != NULL) {
    c++;
    temp = temp->next;
  }

  return c;
};




void Linkedlist::shape() {
  Node *curr = this->head;
  int d = 0;
  std::cout << "#" << this->size() << ": ";
  while (d <5) {
    std::cout << curr->code << ", ";
    curr = curr->next;
    d++;
  }
  std::cout << "EOS\n";
}

// DO NOT IMPLEMENT >>> subList(start, length)	//Returns a new list containing
// elements from a sub-range of this list.

// DO NOT IMPLEMENT >>> toString()				//Converts the list to a
// printable string representation.