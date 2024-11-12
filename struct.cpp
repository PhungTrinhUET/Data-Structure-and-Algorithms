#include <iostream>
using namespace std;

//Tao mot node bao gom 2 thanh phan lien ket va thanh phan du lieu
struct Node {
    
    int data;
    Node* next;

};
/*
Tao mot node moi:
- Khoi tao gia tri ban dau va tra dia chi ve cho node duoc cap phat
*/

Node*CreateNode(int init_data)
{
    Node*node = new Node;
    node->data = init_data;
    node->next = NULL;
}

/*
Khi co node roi, tao lap 1 list. 
- Do dac tinh cua node la lien ket voi nhau nen 
ta chi can nam duoc thong tin của node dau (head) và not cuoi (tali) 
la co the quan ly duoc danh sach
*/

struct LinkedList

{
    Node* head;
    Node* tail;

};

/*
Khi tao danh sach moi, chung ta chua co phan tu nao ca
-> Vi the ta se gan phan dau va cuoi vao NULL
*/

void CreateList(LinkedList& I)
{
    I.head = NULL;
    I.tail = NULL;
}

/*
2. THEM PHAN TU VAO DANH SACH LIEN KET DON
*/

//2.1 THEM PHAN TU VAO DAU
void AddHead(LinkedList& I, Node* node)

{
    if(I.head == NULL)
{
    I.head = node;
    I.tail = node; 
}
else
{
    node -> next = I.head;
    I.head = node;
}
}

int main(){
    
}
