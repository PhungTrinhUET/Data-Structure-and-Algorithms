#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void printList(const list<int>* lst) {
    for (int value : *lst) {
        cout << value << " ";
    }
    cout << endl;
}

int searchKey(const list<int>* lst, int target) {
    int index = 0;
    for (int value : *lst) {
        cout << "Searching at index " << index << ": " << value << endl;
        if (value == target) {
            return index;
        }
        index++;
    }
    return -1; // Target not found
}

int main() {
    list<int>* lst = new list<int>();
    
    // Insert elements into the linked list
    lst->push_back(15);
    lst->push_back(3);
    lst->push_back(9);
    lst->push_back(7);
    lst->push_back(11);
    lst->push_back(1);
    lst->push_back(5);
    lst->push_back(13);
    
    cout << "Original linked list: ";
    printList(lst);

    // Sort the linked list
    lst->sort();
    cout << "Sorted linked list: ";
    printList(lst);

    // Print the new indices of each element after sorting
    cout << "New indices of elements after sorting:" << endl;
    int index = 0;
    for (int value : *lst) {
        cout << "Value: " << value << ", New Index: " << index << endl;
        index++;
    }

    // Search for a key in the sorted linked list
    int target = 7;
    cout << "\nSearching for element " << target << ":" << endl;
    int result = searchKey(lst, target);
    if (result != -1) {
        cout << "Element " << target << " found at index: " << result << endl;
    } else {
        cout << "Element " << target << " not found in the linked list." << endl;
    }

    delete lst;
    return 0;
}
