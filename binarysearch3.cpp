/**
 * @file linked_list_operations.cpp
 * @brief Tep nay chua cac ham de thuc hien cac thao tac voi danh sach lien ket,
 *        bao gom chen, xoa, tim kiem, va sap xep.
 *
 * Cac thao tac bao gom:
 * - In danh sach lien ket.
 * - Tim kiem mot phan tu.
 * - Chen mot phan tu moi sau gia tri cu the.
 * - Xoa mot phan tu khoi danh sach lien ket.
 */

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

/**
 * @brief In tat ca cac phan tu cua danh sach lien ket.
 * @param lst Con tro toi danh sach lien ket can in.
 */
void printList(const list<int>* lst) {
    for (int value : *lst) {
        cout << value << " ";
    }
    cout << endl;
}

/**
 * @brief Tim kiem gia tri cu the trong danh sach lien ket va tra ve chi so cua no.
 * @param lst Con tro toi danh sach lien ket can tim kiem.
 * @param target Gia tri can tim kiem.
 * @return Chi so cua gia tri neu tim thay, nguoc lai tra ve -1.
 */
int searchKey(const list<int>* lst, int target) {
    int index = 0;
    for (int value : *lst) {
        cout << "Tim kiem tai chi so " << index << ": " << value << endl;
        if (value == target) {
            return index;
        }
        index++;
    }
    return -1; // Khong tim thay gia tri
}

/**
 * @brief Chen mot gia tri moi sau gia tri cu the trong danh sach lien ket.
 * @param lst Con tro toi danh sach lien ket.
 * @param afterValue Gia tri sau do se chen gia tri moi.
 * @param newValue Gia tri moi can chen.
 */
void insertAfterValue(list<int>* lst, int afterValue, int newValue) {
    int index = searchKey(lst, afterValue);
    if (index != -1) {
        cout << "Phan tu " << afterValue << " tim thay, chen gia tri " << newValue << " sau no." << endl;
        auto it = lst->begin();
        advance(it, index + 1);
        lst->insert(it, newValue);
    } else {
        cout << "Phan tu " << afterValue << " khong tim thay trong danh sach lien ket." << endl;
    }
    printList(lst);
}

/**
 * @brief Xoa mot gia tri cu the khoi danh sach lien ket.
 * @param lst Con tro toi danh sach lien ket.
 * @param target Gia tri can xoa.
 */
void deleteValue(list<int>* lst, int target) {
    int index = searchKey(lst, target);
    if (index != -1) {
        cout << "Phan tu " << target << " tim thay, xoa no." << endl;
        auto it = lst->begin();
        advance(it, index);
        lst->erase(it);
    } else {
        cout << "Phan tu " << target << " khong tim thay trong danh sach lien ket." << endl;
    }
    printList(lst);
}

int main() {
    list<int>* lst = new list<int>();
    
    // Chen cac phan tu vao danh sach lien ket
    lst->push_back(15);
    cout << "Danh sach lien ket sau khi chen 15: ";
    printList(lst);
    lst->push_back(3);
    cout << "Danh sach lien ket sau khi chen 3: ";
    printList(lst);
    lst->push_back(9);
    cout << "Danh sach lien ket sau khi chen 9: ";
    printList(lst);
    lst->push_back(7);
    cout << "Danh sach lien ket sau khi chen 7: ";
    printList(lst);
    lst->push_back(11);
    cout << "Danh sach lien ket sau khi chen 11: ";
    printList(lst);
    lst->push_back(1);
    cout << "Danh sach lien ket sau khi chen 1: ";
    printList(lst);
    lst->push_back(5);
    cout << "Danh sach lien ket sau khi chen 5: ";
    printList(lst);
    lst->push_back(13);
    cout << "Danh sach lien ket sau khi chen 13: ";
    printList(lst);
    
    cout << "Danh sach lien ket ban dau: ";
    printList(lst);

    // Sap xep danh sach lien ket
    lst->sort();
    cout << "Danh sach lien ket sau khi sap xep: ";
    printList(lst);

    // In ra chi so moi cua cac phan tu sau khi sap xep
    cout << "Chi so moi cua cac phan tu sau khi sap xep:" << endl;
    int index = 0;
    for (int value : *lst) {
        cout << "Gia tri: " << value << ", Chi so moi: " << index << endl;
        index++;
    }

    // Chen gia tri 6 sau gia tri 15
    cout << "\nChen gia tri 6 sau gia tri 15:" << endl;
    insertAfterValue(lst, 15, 6);

    // Xoa gia tri 9 khoi danh sach lien ket
    cout << "\nXoa gia tri 9 khoi danh sach lien ket:" << endl;
    deleteValue(lst, 9);

    delete lst;
    return 0;
}
