#include <iostream>

using namespace std;

/**
@AUTHOR: HANNAH FERDOWS
@DATE: 10/23/23
@PROGRAM: BUILD A QUEUE WITH 2 STACKS
**/

// Data Class: TicketItem, holds all the data that goes inside the node
class TicketItem {
public:
  string personName;
  string reserveCode;

  TicketItem(string name, string value) {
    this->personName = name;
    this->reserveCode = value;
  }

  ~TicketItem() {
    this->personName = "";
    this->reserveCode= "";
  }
  void print() {
    cout << personName << " " << endl;
    cout << reserveCode << " " << endl;
  }
};

// Node Class: Node for the LinkedList
template <typename T> class Node {
public:
  T *data;
  Node<T> *nextNode;

  Node(T *data) {
    this->data = data;
    nextNode = nullptr;
  }
  void print() { data->print(); }
};

// LinkedList Class: Container for Nodes
template <typename T> class LLStack {
public:
  Node<T> *top;
  int stackSize;
  const int MAXITEMS = 999999;

  // Constructor
  LLStack(T *value) {
    Node<T> *newNode = new Node<T>(value);
    top = newNode;
    stackSize = 1;
  }

  LLStack() {
    top = nullptr;
    stackSize = 0;
  }

  // Destructor
  ~LLStack() {
    while (top) {
      Node<T> *temp = top;
      top = temp->nextNode;
      pop();
    }
  }

  // Print Stack
  void print() {
   int i = 0;
   int size = stackSize;
   
  if(!this->isEmpty()) { 
  LLStack<T> *tempStack = new LLStack<T>();
  
  while(i < size) {   
    top->print();
    tempStack->push(top->data);
    pop();
    i++;
  }
    cout << endl;
    
    while(!tempStack->isEmpty()) {
      this->push(tempStack->top->data);
      tempStack->pop();
    }
    delete tempStack;
  }
    else {
      cout << "Cannot print an empty stack. " << endl;
    }
  }

  // Overflow and Underflow check
  bool isFull() {
    if (this->stackSize == MAXITEMS) {
      return true;
    }

    else {
      return false;
    }
  }

  bool isEmpty() {
    if (this->stackSize == 0) {
      return true;
    }

    else {
      return false;
    }
  }

  // get, set and delete (Push, Pop, Peek)
  void push(T *item) {
    Node<T> *newNode = new Node<T>(item);
    bool full = isFull();

    if (full) {
      cout << "Stack is full. Cannot add item." << endl;
      return;
    }

    else if (!full) {
      if (stackSize == 0) {
        this->top = newNode;
        stackSize++; 
      }
      else {
        Node<T> *temp = this->top;
        this->top = newNode;
        this->top->nextNode = temp;
        stackSize++;
      }
    }
  }

//Stack peek
  T* peek() {
    if (this->isEmpty()) {
      cout << "Stack is empty. No values to print." << endl;
      return nullptr;
    } 
    else {
      cout << "Top value is ";
      this->top->print();
      cout << endl;
      return this->top->data;
    }
  }

//Stack pop
  void pop() {
    bool empty = isEmpty();

    if (empty) {
      cout << "Cannot pop from an empty Stack." << endl;
      return;
    } 
    else {
      Node<T> *temp = this->top;
      this->top = this->top->nextNode;
      delete temp;
      stackSize--;
    }
  }
};


//Class StackQ
template <typename T> class StackQ {
public:
LLStack<T> *enQStack;
LLStack<T> *deQStack;
int queueSize;
const int QMAXITEMS = 99999;

//Constrcutor 
StackQ(T *value) {
  enQStack = new LLStack<T>(value);
  deQStack = new LLStack<T>();
  queueSize = 1;
}

//Destructor
~StackQ() {
  delete enQStack;
  delete deQStack;
}

//Queue print method 
void print() {
  int i = 0;
  int size = enQStack->stackSize;
  LLStack<T> *tempStack = new LLStack<T>();
 
  if(!deQStack->isEmpty() && !enQStack->isEmpty()) { //if both stacks are not empty, will first unload and print dequeue, then move onto enqueue
    while(!deQStack->isEmpty()) {   
      deQStack->top->print();
      tempStack->push(deQStack->top->data);
      deQStack->pop();
  }
    while(!tempStack->isEmpty()){
      deQStack->push(tempStack->top->data);
      tempStack->pop();
    }
    while(!enQStack->isEmpty()) {
      tempStack->push(enQStack->top->data);
      enQStack->pop();
      }
    while(!tempStack->isEmpty()) {
      tempStack->top->print();
      enQStack->push(tempStack->top->data);
      tempStack->pop();
    }
    cout << endl;
  }

  else if(!deQStack->isEmpty() && enQStack->isEmpty()) { //when there are values only in the dequeue stack to print
    while(!deQStack->isEmpty()) {   
      //deQStack->top->print();
      tempStack->push(deQStack->top->data);
      deQStack->pop();
    }
     while(!tempStack->isEmpty()) {
      deQStack->top->print();
      deQStack->push(tempStack->top->data);
      tempStack->pop();
     }
    cout << endl;
  }

  else if(deQStack->isEmpty() && !enQStack->isEmpty()) { //when there are only values in the enqueue stack to print 
    cout << "Only values being stored in Enqueue Stack: " << endl << endl;
    while(!enQStack->isEmpty()) {
      tempStack->push(enQStack->top->data);
      enQStack->pop();
      }
    while(!tempStack->isEmpty()) {
      tempStack->top->print();
      enQStack->push(tempStack->top->data);
      tempStack->pop();
    }
    cout << endl;
  }
  delete tempStack;
}

//Overflow and Underflow checking methods 
bool isFull() {
  if(queueSize == QMAXITEMS) {
    return true;
  }
  else {
    return false;
  }
}


bool isEmpty() {
  if(queueSize == 0) {
    return true;
  }
  else {
    return false;
  }
}

//Queue Enqueue
void enqueue(T *item) {
  if(!enQStack->isFull() && !isFull()){
    enQStack->push(item);
    queueSize++;
    cout << "Adding item to queue. " << endl;
    enQStack->top->print(); 
    cout << endl;
  }
  else {
    cout << "Cannot queue anymore items. Queue is currently full. Try again later. " << endl;
  }
}

//Queue Dequeue
void dequeue() {
  if(!deQStack->isEmpty()) {
    cout << "Dequeuing item: " << endl;
    deQStack->top->print();
    deQStack->pop();
    queueSize--;
  }

  else if(deQStack->isEmpty()) { //populates dequeue with enqeue values in case it is empty
    while(!enQStack->isEmpty()) {
      deQStack->push(enQStack->top->data);
      enQStack->pop();
    }
    cout << "Dequeuing item: " << endl;
    deQStack->top->print();
    deQStack->pop();
    queueSize--;
  }
}

//returns and prints the front value of the queue
T* peek() {
  if(enQStack->isEmpty() && deQStack->isEmpty()) {
  cout << "No more values left to peek at. Try again later" << endl;
  }
  
  if(deQStack->isEmpty() && !enQStack->isEmpty()) {
    while(!enQStack->isEmpty()) {
      deQStack->push(enQStack->top->data);
      enQStack->pop();
    }
    cout << "Peeking at front item: " << endl;
    deQStack->top->print();
    cout << endl;
    
    return deQStack->top->data;
  }
    
  else {
    cout << "Peeking at front item: "<< endl;
    deQStack->top->print();
    cout << endl;
    
    return deQStack->top->data;
  }  
}

//prints out the two seperate stacks that are used to simulate a qeueue
void printBothStacks() {
  cout << "I SEE YOU FOUND MY SECRET... YES I AM TWO STACKS..."
       << " NOT ONE QUEUE - MUHUAHAH" << endl << endl;

  cout << "Enqueue Stack is: " << endl;
  enQStack->print();
  cout << endl;

  cout << "Dequeue Stack is: " << endl;
  deQStack->print();
  cout << endl;
}

//prints the queue's size
void displayQueueSize() { 
  cout << "The current size of the queue is " << queueSize << " items. " << endl;
}

};


int main() {

int userChoice;

  TicketItem *t1 = new TicketItem("Hannah", "99687");
  TicketItem *t2 = new TicketItem("Cole", "14436");
  TicketItem *t3 = new TicketItem("Aidan", "55243");
  TicketItem *t4 = new TicketItem("Taya", "78910");
  TicketItem *t5 = new TicketItem("Sofia", "78654");
  TicketItem *t6 = new TicketItem("Eli", "88235");
  TicketItem *t7 = new TicketItem("Jenni", "66745");

  cout << "Standby... Populating queue..." << endl << endl;
  
  StackQ<TicketItem> *queue = new StackQ<TicketItem>(t1);
  queue->peek();
  queue->enqueue(t2);
  queue->enqueue(t3);
  queue->enqueue(t4);
  queue->enqueue(t5);
  queue->enqueue(t6);
  queue->enqueue(t7);


  cout << "Welcome! There is currently a ticket queue as you can see above me. " << endl; 

  bool exit = false;

    while(exit != true) {
  cout << endl << "Please choose one of the options below: " << endl << endl;

  cout << "1 -- Add an Item to Ticket Queue. " << endl;
  cout << "2 -- Delete from Ticket Queue. " << endl;
  cout << "3 -- Peek from Ticket Queue, " << endl;
  cout << "4 -- Display the Ticket Queue. " << endl;
  cout << "5 -- Display Ticket Queue size. " << endl;
  cout << "6 -- Display enQStack and deQStack. " << endl;
  cout << "7 -- Exit" << endl << endl;
    
    cin >> userChoice;

    switch (userChoice) {
      case 1: {
        string userName;
        string ticketCode;
        
      cout << endl << "Awesome! Please enter a valid name, followed by a ticket reserve code." << endl;
        cin >> userName;
        cin >> ticketCode;
        TicketItem *userItem = new TicketItem(userName, ticketCode);
      queue->enqueue(userItem);
      break;
      }
      case 2: 
        cout << "BYE BYE TICKET! " << endl;
        queue->dequeue();
        break;

      case 3:
        queue->peek();
        break;

      case 4: 
        cout << "Here is the current Ticket Queue: " << endl;
        queue->print();
        break;

      case 5:
        queue->displayQueueSize();
        break;

      case 6:
        queue->printBothStacks();
        break;

      case 7:
         cout << "GOODBYE! " << endl;
        exit = true;
        delete queue;
        return 0;
        
       

      default:
       cout << "Please enter a valid choice. " <<
        "Your options are from 1 - 7." << endl << endl;
       continue;
    }
   }

return 0;
}
