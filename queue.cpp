#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    node *next;
};
typedef struct node NODE;

struct queue{
    NODE *front;
    NODE *rear;
};
typedef struct queue QUEUE;

void Init(QUEUE &q){
    //gan front va rear ve NULL
    q.front = NULL;
    q.rear = NULL;
}

NODE* CreateNode (int x) {
    NODE *p;
    p = new NODE;
    //neu p = NULL thi ko du bo nho cap phat
    if (p==NULL) {
        printf ("KHONG DU BO NHO!");
        return NULL;
    }
    //gan data bang X
    p->data=x;
    //gan con tro next bang NULL
    p->next=NULL;
    //tra ve node p
    return p;
}

int IsEmpty(QUEUE q){
    //neu front bang NULL thi queue rong
    if (q.front == NULL){
        return 1;
    }
    //nguoc lai tra ve 0
    return 0;
}

void Add (QUEUE &q, NODE *NewNode){
    //neu hang doi rong thi them node moi vao ca dau va cuoi hang doi
    if(q.front == NULL){
        q.front = NewNode;
        q.rear = NewNode;
    }
    else{//nguoc lai them cuoi hang doi
        //dat con tro next cua phan tu cuoi ve NewNode
        q.rear->next = NewNode;
        //gan lai phan tu cuoi cua danh sach
        q.rear = NewNode;
    }
}

int Remove(QUEUE &q){
    int x;
    NODE *p = NULL;
    //neu queue khong rong thuc hien lay phan tu dau queue
    if (!IsEmpty(q)){
        //gan node p bang phan tu dau tien cua queue
        p = q.front;
        //gan du lieu cua node p vao x
        x = p->data;
        //xoa di node dau tien cua queue
        q.front = q.front->next;
        delete p;
        //neu front bang NULL thi gan luon rear bang NULL
        if (q.front==NULL){
            q.rear = NULL;
        }
    }
    //tra ve du lieu x vua lay ra
    return x;
}

void Input(QUEUE &q, int n){
    //duyet N lan
    for(int i = 0; i< n; i++){
        //nhap phan tu vao bien x
        int x;
        printf("Nhap phan tu thu %d: ",i);
        scanf("%d", &x);
        //tao node p co du lieu la x
        NODE *p;
        p = CreateNode(x);
        //them node p vao queue
        Add(q,p);
    }
}

void Output(QUEUE q){
    //duyet tu dau den cuoi hang doi
    for(NODE *p = q.front; p!= NULL; p=p->next){
        //hien thi data cua cac node
        printf("%d \t",p->data);
    }
}

int main(){
    //tao moi queue
    QUEUE q;
    //khoi tao queue
    Init(q);
    //nhap n phan tu vao queue
    int n;
    printf("NHAP N: ");
    scanf("%d", &n);
    Input(q,n);
    //hien thi phan tu trong queue
    printf("CAC PHAN TU TRONG HANG DOI LA\n");
    Output(q);
    //them mot node co du lieu bang 66 vao hang doi
    int x = 66;
    NODE *p = CreateNode(x);
    Add(q,p);
    printf("\nHANG DOI SAU KHI THEM NODE %d \n",x);
    Output(q);
    //thuc hien lay phan tu trong hang doi ra
    int k = Remove(q);
    printf("\nHANG DOI SAU KHI REMOVE %d \n",k);
    Output(q);
}