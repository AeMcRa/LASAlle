#include <cstring>

class Node{
  public:
    char    code[5];
    double   longitude;
    double   latitude;
    Node* next;

    Node() 
      { 
          longitude = 0;
          latitude = 0;
          next = NULL; 
      } 

      // Parameterised Constructor 
      Node(char c[5],double lon, double lat) 
      {   
          memcpy(this->code,c,5);
          longitude = lon;
          latitude = lat;
          this->next = NULL; 
      } 

  }; 

  class Linkedlist{
   public:
  Node* head;

    Linkedlist();
    ~Linkedlist();

    void add(Node*);

    void clear();

    bool equals(Linkedlist);

    Node* get(int);

    void insert(int, Node);

    void exchg(int, int);		

    void swap(int,int);

    void fasterSwap(Node**,Node**,Node*,Node*,int,int);

    bool isEmpty();				

    void remove(int);		

    void set(int, Node);	

    int size();			

    void shape();
    
  };


