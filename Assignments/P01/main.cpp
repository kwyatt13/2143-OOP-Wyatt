///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Kyler Wyatt
// Email:            kylco13@gmail.com
// Label:            P01
// Title:            Array Based Stack Example
// Course:           2143
// Semester:         Fall 2020
//
// Description:
//       Example implementation of an array based stack that holds integers.
//
// Usage:
//       Stack S1; // creates instance of stack
//       push 45   // pushes 45 onto the stack (from file)
//       pop       // pops the top off of the stack (from file)
//
// Files:            
//       input.txt (input file)
//       output.txt (output file)
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/**
 * Stack
 * 
 * Description:
 *      Integer array based stack implementation
 * 
 * Public Methods:
 *      - Stack()
 *      - Stack(int)
 *      - void Push()
 *      - int Pop()
 *      - bool empty()
 *      - bool full()
 *      - void Print()
 * 
 * Private Methods:
 *      - None
 * 
 * Usage: 
 * 
 *  Stack S;
 *  S.Push(80);
 *  S.Push(90);
 *  S.Print();
 *  int x = S.Pop();
 *      
 */
class Stack {
private:
    int *S;       //array pointer
    int capacity; //max stack size
    int top;      //current top (index)
    int size;     //current num items
    int StartingSize;   // initial capacity of array
    int MaxSize = 0;    // largest capacity of array
    int LastSize;       // final capacity of array
    int DoubledAlready = 0;
public:
    /**
     * Stack:
     *    Constructor.
     * Params:
     *    void
     * 
     * Returns:
     *     Void
     */
    Stack() {
        capacity = 10;          // set array size
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
        StartingSize = capacity; // saves starting size of array
    }

    /**
     * Stack:
     *    Constructor.
     * Params:
     *    int : capacity
     * 
     * Returns:
     *     Void
     */
    Stack(int cap) {
        capacity = cap;         // set array size      
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
        StartingSize = capacity; // saves starting size of array
    }

    /**
     * Push:
     *    Push item onto stack.
     * Params:
     *    int : data
     * 
     * Returns:
     *     Void
     */
    void Push(int data) {
        if (Full())                                      // Stack size is full
        {
          int* newStack = new int[capacity * 2];       // New stack with doubled size
          for (int i = 0; i < capacity; i++)
          {
              newStack[i] = S[i];                      // Fill new stack with current values
          }
          delete[] S;                                  // Delete previous stack
          S = newStack;                                // Point to new stack
          cout << "+ : " << capacity << " -> " << capacity * 2 << endl;
          capacity *= 2;                               // Double capacity for new stack size
          if (capacity > MaxSize){                     // saves largest capacity as MaxSize
            MaxSize = capacity;
          }
          DoubledAlready++;
        }
        
        top++;              // move top of stack up
        size++;             // increment size
        S[top] = data;      // add item to array

    }

    /**
     * Pop:
     *    remove item from stack.
     * Params:
     *    void
     * 
     * Returns:
     *     int
     */
    int Pop() {
        if (Empty()){
        cout << "Error, stack is empty!" << endl;
        return -1;
        }
        int data = S[top];  // pull item from stack
        top--;              // shrink the stack
        size--;             // update our size

        if((DoubledAlready > 0) && (size < capacity/2)) // Shrink array if the number of value is less than half the size of the array
        {
        int* newStack = new int[capacity / 2];       // New stack with half previous size
        for (int i = 0; i < capacity/2; i++)
        {
            newStack[i] = S[i];                      // Fill new stack with current values
        }
        delete[] S;                                  // Delete previous stack
        S = newStack;                                // Point to new stack
        cout << "- : " << capacity << " -> " << capacity / 2 << endl;
        capacity /= 2;                               // Current capacity is half the size of before
        }
        return data;        // send item back
    }

    /**
     * Empty:
     *    is the stack empty?
     * Params:
     *    void
     * 
     * Returns:
     *     bool : true == stack is empty
     */
    bool Empty() {
        //return size == 0;
        return top == -1;
    }

    /**
     * Full:
     *    is the stack full?
     * Params:
     *    void
     * 
     * Returns:
     *     bool : true == stack is full
     */
    bool Full() {
        return top == capacity - 1;
    }

    /**
     * Print:
     *    Used so we can inspect our stack.
     * Params:
     *    void
     * 
     * Returns:
     *     void
     */    
    void Print() {
        for (int i = top; i >= 0; i--) {
            cout << S[i] << endl;
        }
    }

    /**
     * Overloaded ostream <<
     *    Lets us print a stack using cout
     * Params:
     *    ostream &os   : instance of ostream passed in by reference
     *    const Stack   : instance of stack passed in using const so 
     *                    it cannot be changed
     * 
     * Returns:
     *     ostream 
     */
    friend ostream &operator<<(ostream &os, const Stack s) {
        os << "Overloaded!!" << endl;
        for (int i = s.top; i >= 0; i--) {
            os << s.S[i] << endl;
        }
        return os;
    }

        /**
     * getStartingSize:
     *    Returns the starting size of array
     * Params:
     *    void
     *
     * Returns:
     *     int StartingSize
     */
    int getStartingSize()
    {
        return StartingSize;     // Return starting size of array
    }

        /**
     * getMaxSize:
     *    Returns the largest size of array
     * Params:
     *    void
     *
     * Returns:
     *     int MaxSize
     */
    int getMaxSize()
    {
        return MaxSize;     // Return largest size of array
    }

            /**
     * getLastSize:
     *    Returns the final size of array
     * Params:
     *    void
     *
     * Returns:
     *     int LastSize
     */
    int getLastSize()
    {
        return capacity;     // Return final size of array
    }
};

int main() {
    ifstream infile;
    infile.open ("input.txt");          //input and output files
    ofstream outfile;
    outfile.open ("output.txt");
    cout << "Name: Kyler Wyatt\n"       // prints student information to screen
         << "Program: P01\n"
         << "Date: 15 Sep 2020\n";
    string variable;
    int number;
    Stack S1;           // calls default constructor
    while (infile >> variable){
      if (variable == "pop"){
        S1.Pop();
      }
      else if (variable == "push"){
        infile >> number;
        S1.Push(number);
      }
    }
    cout << "\nFinal Contents of Array:\n";
    cout << S1 << endl;

    outfile << "Name: Kyler Wyatt\n"       // prints student information to output file
            << "Program: P01\n"
            << "Date: 15 Sep 2020\n";
    
    outfile << "Start Size: " << S1.getStartingSize() << endl;
    outfile << "Max Size: " << S1.getMaxSize() << endl;
    outfile << "Final Size: " << S1.getLastSize();

    infile.close();
    outfile.close();
    return 0;
}
