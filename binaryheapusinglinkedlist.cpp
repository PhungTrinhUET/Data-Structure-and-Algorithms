// C++ code to implement Priority Queue 
// using Linked List 
#include <bits/stdc++.h> 
using namespace std; 

// Node 
struct Node 
{ 
    int data; 

    // Lower values indicate 
    // higher priority 
    int priority; 

    Node* next; 
    Node (int x, int p)
    {
       data = x;
       priority = p;
       next = NULL;
    }  
}; 

// Return the value at head 
int peek(Node* head) 
{ 
    return head->data; 
} 

// Removes the element with the 
// highest priority from the list 
Node* pop(Node* head) 
{ 
    Node* temp = head; 
    head = head->next; 
    delete temp;
    return head;
} 

// Function to push according to priority 
Node* push(Node* head, int d, int p) 
{ 
    Node* start = head; 

    // Create new Node 
    Node* temp = new Node(d, p); 

    // Special Case: The head of list has 
    // lesser priority than new node. So 
    // insert newnode before head node 
    // and change head node. 
    if (head == NULL || head->priority > p) 
    { 
        
        // Insert New Node before head 
        temp->next = head; 
        head = temp; 
    } 
    else
    { 
        
        // Traverse the list and find a 
        // position to insert new node 
        while (start->next != NULL && 
            start->next->priority < p) 
        { 
            start = start->next; 
        } 

        // Either at the ends of the list 
        // or at required position 
        temp->next = start->next; 
        start->next = temp; 
    } 
    return head;
} 

// Function to check is list is empty 
int isEmpty(Node* head) 
{ 
    return (head == NULL); 
} 

// Driver code 
int main() 
{ 
    
    // Create a Priority Queue 
    // 7->4->5->6 
    Node* pq = new Node(4, 1); 
    
    pq = push(pq, 5, 2); 
    pq = push(pq, 6, 3); 
    pq = push(pq, 7, 0); 

    while (!isEmpty(pq)) 
    { 
        cout << " " << peek(pq); 
        pq = pop(pq); 
    } 
    return 0; 
} 

// This code is contributed by shivanisinghss2110 
