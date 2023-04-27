#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include "ExpressionManager.h"
#include "Queue.h"

using namespace std;

int main() {

  int choice;
  
  cout << "Would you like to test the Queue(enter 0) or would you like to test Infix to Postfix conversion(enter 1)?" << endl;
  cin >> choice;
  if (choice == 1){

    std::string expression;
    // Read an infix expression from the user
    cout << "Enter an infix expression: ";
    cin >> expression;
    
    
    // Check if the expression has balanced parentheses
    if (!hasBalancedParentheses(expression)) {
        cout << "Invalid Expression: Unmatched Parentheses" << endl;
        return 0;
    }

    // Convert the infix expression to postfix expression
    string postfix = infixToPostfix(expression);
    // Display the postfix expression
    cout << "Postfix expression: " << postfix << endl;

    return 0;
  }else if(choice == 0){
    int size, item;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size);

    cout << "Enter " << size << " items to enqueue:\n";
    for (int i = 0; i < size; i++) {
        cin >> item;
        q.enqueue(item);
    }

    cout << "Front element: " << q.peek() << endl;
    cout << "Queue size: " << q.size() << endl;

    cout << "Dequeue how many items? ";
    int numToDequeue;
    cin >> numToDequeue;
    for (int i = 0; i < numToDequeue; i++) {
        cout << q.dequeue() << " dequeued from queue\n";
    }

    cout << "Front element: " << q.peek() << endl;
    cout << "Queue size: " << q.size() << endl;

    cout << "Enter an item to enqueue: ";
    cin >> item;
    q.enqueue(item);
    cout << "Front element: " << q.peek() << endl;
    cout << "Queue size: " << q.size() << endl;

    if (q.isEmpty())
        cout << "Queue is empty\n";
    else
        cout << "Queue is not empty\n";
    return 0;
  }
}
    

