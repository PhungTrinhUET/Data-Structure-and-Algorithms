#include<iostream>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i =0; i < n; i++) {
        //i danh dau vi tri bat dau
        int min_index = i;
        for (int j = i; i < n; j++) {
            //xet mang tu i den cuoi
            //tim vi tri cua gia trii nho nhat
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }

        int tmp = a[i];
        a[i] = a[min_index];
        a[min_index] = tmp;
    }
}

int main () {
    
}