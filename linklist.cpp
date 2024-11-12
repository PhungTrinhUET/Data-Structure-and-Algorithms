#include <iostream>
using namespace std;

/*
1. Tao node
- Danh sach lien ket don duoc tao tu nhieu node -> di tu node truoc
- Mot node gom 2 thanh phan:
     + Du lieu
     + Thanh phan lien ket
*/
struct Node
{
    int data;
    Node* next;
};

/*
2. Tao mot node moi
*/

Node* CreateNode(int init_data)
{
    Node* node = new Node;
    node -> data = init_data;
    node -> next = NULL;
    return node;
}

struct LinkedList
{
    Node* head;
    Node* tail;
};

void CreateList(LinkedList& 1)
{
    l.head = NULL;
    l.tail = NULL;
}