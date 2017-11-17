For this lab, you will be implementing a linked list, but not just any linked list, a doubly linked list. One more link than you are used to. 

This additional link lets us traverse both ways on the list, in addition to letting us create a hybrid structure that has the best features of both a stack and a queue. We can add an item to the beginning or end of the list in *O(1)* and we can access the beginning and end of the list in *O(1)* as well. Also, just like stacks and queues, they can be arbitrarily long because their size isn't defined at initialization.  

We were looking for something to do with this list that would be cool, and Wikipedia gave us what we were looking for. To simulate a deck of cards we need all the functionality of a doubly linked list, as well as some specially accessors and mutators, so we might as well make a class that can simulate a deck of cards. We aren�t only doing this for fun though, you will be using this deck object when we cover sorting algorithms.
### Lab Instructions ###
You will be writing all the code that makes the doubly linked list works. We have provided you with the `node.h`, as well as all the function declarations for the linked list. You just need to fill in the code to make it work. On top of making the doubly linked list work, you will need to make sure it interfaces with the deck class properly. All the code for that class has been provided as well.
### Hints ###
- When you are accessing and changing the list, remember that this is a linked list; you should only be changing the pointer values, and not the value stored inside the node.
- Some of these functions are basically the same. Don�t rewrite or paste code, just call the function with the altered inputs.
- Keep track of size. When adding or removing, the size should change
- Keep track of your edge cases: empty, 1 item, 2 items

