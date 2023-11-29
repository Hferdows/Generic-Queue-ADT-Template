# Generic-Queue-ADT-Template

Hannah Ferdows PA 2 ReadMe


  Class TicketItem:
The Function: to hold the data that will be used within the stacks / queue. (a ticket)

variables:
personName: holds the value (string) of a person name for a ticket
reserveCode: holds the value (string) of a number as an individual code to the ticket
Constructor: creates a new ticket, and updates the class’ 2 variables by having both the strings be passed in as parameters and then assigned as so.
Destructor: Will delete the values assigned to PersonName and reserveCode and revert them to a null value (“ “)

Methods:
Print will format and print out the values of the ticket, first the name, then return and the code


  Class Node:
The Function: to hold values and distinct types of data within the nodes that a linked list is constructed of, in order to actually place that data into a linked list, or a stack created by a linked list, or hell- even a queue created by two stacks that are created by two singly linked lists

Variables:
Data: of the generic type T, will be initialized what the user passes into the Node constructor. NextNode: points to the next value in a linked list, and in a stack, will represent the last value added before
Constructor: user must pass some form of data, of any type, and the member variables will be initialized accordingly, with the nextNode pointer being null until the node is placed (push will update this)

Method:
Print: calls whatever data that is passed print function from that class. Will be printed as detailed in that class’ formatting


  Class LLStack:
The function: the function of the class LLStack is to implement a stack and its rules (as an abstract data type) through the means of a singly linked list.

Variables:
The node, top- is the very top (or last added) value of a stack- this is due to the stack property that you can only see, access and remove the top value. (FIFO)
stackSize keeps track of the stack size in order to check for overflow and underflow conditions (so you don't pop from an empty stack, or add to a full one)
MAXITEMS: sets the maximum number of items a stack can hold before it is considered full
Constructor: by having the user pass in the parameter of the value they’d like their stack to hold, a new node is made with it and then added to the top of the stack
Destructor: will individually delete each top node (by popping until all items have been popped and deleted

Methods:
Print: Same as the destructor, will individually access each top node-however in order to keep the FIFO order, it first transfers all the nodes to a temporary stack, and prints them as it pushes it back onto the original stack and then pops the temp stack to access the next value. This prints all the values, keeps the order, and then finally the temp stack is deleted.
- Error handling in place, to prevent someone trying to print from an empty stack. Will only print if the stack is not empty, and if it is empty gives an error message
isFull: Checks to see if the stackSize is equal to the maxitems, and if it returns true for the boolean, if not, returns false. Used to check overflow later on
isEmpty: Checks to see if the stackSize is 0, and therefore empty. Will return false if there are any values, and true if not. Will later be used to check underflow conditions
Push: Adds items to the stack by obeying the rules of the stack data type, and places the value a user would like to add to the top. The value passed however must be of a data type itself, in order to be made into a new node and placed. The previous top, if there was one, will then be assigned and made the new tops nextNode. Method also checks for overflow, to stop from adding a value to a full stack.
- The size also increments, because obviously everytime you add, it grows
Peek: will return and print the top value of the stack, as long as there is a value- if there in none, it will print an error message for an empty stack
Pop: will remove and delete the top node of the stack, and appropriately reassign the second to last value added as the new top value. Will only do so if there is a value to delete, (checks underflow conditions with isEmpty())
 
  Class StackQ
The Function: to replicate a queue by creating two stacks, and enqueue and dequeue, that will obey the rules of (LILO - last in last out) but also has to simultaneously follow the constraints of implementing it through a stack

Variables:
LLStack enQStack: The first of the two stacks that represent the queue- this one being the stack that everything will be added on to (so the top value is the last one added)
LLStack deQStack: The second of the stacks, and this is the one that everything is deleted from (the first values are the first to go and be popped from this one)
queueSize: keeps track of the queues size, in order to check for possible overflow and underflow
QMAX ITEMS: tells us what the maxItems the queue can have is, so that the overflow will be accordingly, and only accept the set amount of values/nodes.
Constructor: will create a new enqueue and dequeue stack every time you try to create a queue. The enqueue stack will be initialized with the value the parameter requires to be passed, however the dequeue stack will be created with a default constructor, since there are no items to be removed yet
Destructor: calls the Stack destructor to delete the two stacks which makeup the queue, and hence then also destroys/deletes the queue’s existence by doing so

Methods:
Print: has several different ways it can work- one being, that if both stacks are NOT empty, it will first print and pop each item stored in the dequeue stack first (send it to a tempstack to be stored temporarily and then placed back into dequeue), and then moves each item from enqueue to a tempstack, on order to abide by the LILO rules, and prints them as they are popped off and placed back onto enqueue. This ensures that all the data is in the appropriate order since dequeue will only hold items from an enqueue stack that were placed first, since they have to be put in there directly from that stack.
- If one or the other stack is empty however, it will perform one of the operations that i just described on the appropriate stack, instead of both (since you cannot print from an empty stack. Duh)
- Also checks the underflow condition, and will only print if there are values, if there are none it gives an error message that it cannot print from an empty stack
- Finally it deletes the tempstack
isFull: checks to make sure the size of the queue does not meet/exceed the maximum items set to be able to be stored within the queue. Returns true if full, false if not
  isEmpty: checks to make sure the size of the queue does not = 0, for future underflow checking. Returns true if empty, false if not
Enqueue: checks to make sure neither stack is full, and pushes the passed item onto the enQStack if not. Also increases queueSize since a value is being added.
If it is full, prints error.
Also additionally prints the value the user is adding, for visual confirmation
Dequeue: checks to make sure the dequeue stack has a value to be popped, if it does, great- it will pop that top value and give confirmation of such being done so
IF NOT, and there are values in the enqueue stack, it will move over every enqueue stack value in order to access the first pushed one (LILO), and pop it from there
However, if both are empty, it will display an error, that you cannot remove from an empty queue
- Also decrements the queues size
- Checks underflow, that there is a value (between both stacks) to be removed
Peek: checks that there is a value to peek and return, if both are empty, goves error message. If not, it will push all the enqueue items onto a not-full dequeue stack, (to keep LILO) and then use the stack peek method to perform a peek on the value
- Also returns that data, and prints it, same as the stack peek does
printBothStacks: Uses the stack print method to print out each individual stack, as separate components rather than one singular queue
- I created this as a helper method for my main, which presents this option
displayQueueSize: simply prints a message, as well as the queue size as a helper method for my main, which presents/requires this option for the user
PICTORIAL REPRESENTATIONS ON NEXT PAGE:

 
 
 
