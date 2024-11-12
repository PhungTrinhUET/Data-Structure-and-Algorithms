#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void printList(const list<int>& lst) {
    for (int value : lst) {
        cout << value << " ";
    }
    cout << endl;
}

int searchKey(const list<int>& lst, int target) {
    int index = 0;
    for (int value : lst) {
        if (value == target) {
            return index;
        }
        index++;
    }
    return -1; // Target not found
}

int main() {
    list<int> lst = {15, 3, 9, 7, 11, 1, 5, 13};
    
    cout << "Original list: ";
    printList(lst);

    // Sort the list
    lst.sort();
    cout << "Sorted list: ";
    printList(lst);

    // Print the new indices of each element after sorting
    cout << "New indices of elements after sorting:" << endl;
    int index = 0;
    for (int value : lst) {
        cout << "Value: " << value << ", New Index: " << index << endl;
        index++;
    }

    // Search for a key in the sorted list
    int target = 7;
    int result = searchKey(lst, target);
    if (result != -1) {
        cout << "Element " << target << " found at index: " << result << endl;
    } else {
        cout << "Element " << target << " not found in the list." << endl;
    }

    return 0;
}