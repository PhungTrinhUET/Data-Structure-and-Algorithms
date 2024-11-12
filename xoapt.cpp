#include <iostream>
#include <vector>

using namespace std;

bool add(List *head, int k){
    List *preP;
    if ((isEmpty(head)==true)) return false;
    if(k==1) head = head->headnext; return true;
    for (int i=1;i<k, i++) {
        preP = p
        p = p->next;
        if(p==NULL) return false;
    }
    preP->next=p->next;
    return true;
}