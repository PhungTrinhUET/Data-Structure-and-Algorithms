#include<iostream>
using namespace std;

class Node {
    public:
    int data; // gia tri du lieu cua nut
    Node* left; // con tro toi nut con trái
    Node* right; // con tro toi nut con phải

    // khoi tao constructor
    Node(int value): data(value), left(nullptr), right(nullptr) {}
};

int main() {
    //Tao nut goc
    Node* root = new Node(10);

    //Them nut con trái va con phải
    root->left = new Node(5);
    root->right = new Node(15);

    //Them cac nut con
    root->left->left = new Node(3);
    root->left->left = new Node(7);

    return 0;
}