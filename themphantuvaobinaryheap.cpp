#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    //khai bao du lieu cua node co kieu du lieu int
    int data;
    //khai bao con tro den cay con trai
    Node* left;
    //khai bao con tro den cay con phai
    Node* right;

};
typedef struct Node* Tree;
Tree root;

void Init (Tree &root){   
    //gan node goc ve NULL
    root = NULL;
}

Node* CreateNode (int x){
    //tao node moi
    Node* p = new Node;
    //neu node p duoc cap phat bo nho
    if (p != NULL){
        //gan cay con trai va cay con phai mac dinh bang NULL
        p->left = NULL;
        p->right = NULL;
        //gan data bang x
        p->data = x;
    }
    //tra ve node p
    return p;
}
int InsertNode(Tree &root, Node*p){
    //neu node root khac rong thi thuc hien them vao cay
    if (root != NULL){
        //neu 2 data cua 2 node bang nhau thi ket thuc
        if (root->data==p->data){
            return 0;
        }
        //neu khoa cua root lon hon khoa cua p thi goi de quy trai 
        if (root->data > p->data){
            return InsertNode(root->left, p);
        }
        else{//neu khoa cua root nho hon khoa cua p thi goi de quy phai 
            return InsertNode(root->right,p);
        }
    }else { //truong hop neu node root la rong thi them node p vao node root
        root = p;
    }
}

void Input(Tree &root){
    int n;
    printf ("NHAP SO LUONG NODE CAN THEM: "); 
     for(int i=1; i<=n;i++){
        int x;
        printf ("NHAP DATA CUA NODE %d: ",i); 
        scanf("%d",&x);
        //tao node p co data = x
        Node* p = CreateNode(x);
        //them node p co data x vao trong cay
        InsertNode(root, p);
    }
}

void NLR(Tree root){
    if (root!=NULL){
        //hien thi du lieu cua tung node sau khi duyet
        printf("%d \t",root->data);
        //su dung de quy de duyet tiep cay con trai
        NLR(root->left);
        //su dung de quy de duyet tiep cay con phai
        NLR(root->right);
    }
}

int main(){
    //tao cay voi node goc la root
    Tree root;
    //khoi tao cay
    Init(root);
    //nhap n phan tu vao cay
    Input(root);
    //them mot phan tu moi vao trong cay
    int x = 15;
    Node *p = CreateNode(x);
    InsertNode(root,p);
    //hien thi tat ca du lieu vua them vao cay
    NLR(root);
}