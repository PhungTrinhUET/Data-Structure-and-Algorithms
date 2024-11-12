#include <iostream>
using namespace std;
 
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
   
    int L[n1], R[n2];//tạo 2 mảng tạm thời để chứa các phần tử sau khi chia
   
    // Copy dữ liệu sang các mảng tạm 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
   
    // khởi tạo các giá trị ban đầu
    i = 0; 
    j = 0; 
    k = l; 
  
    //gộp hai mảng tạm thời vào mảng arr
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
   
    // Copy các phần tử còn lại của mảng L vào arr nếu có 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
   
    // Copy các phần tử còn lại của mảng R vào arr nếu có 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
   
// l là chỉ số trái và r là chỉ số phải của mảng cần được sắp xếp 
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        // Gọi hàm đệ quy tiếp tục chia đôi từng nửa mảng
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
   
        merge(arr, l, m, r);
    }
}
 
void printArr(int arr[], int N)
{
   int i;
   for (i = 0; i < N; i++)
   {
       cout<<arr[i]<<"\t";
   }
}
 
int main(void) {
  int n;
    do{
        cout<<"\nNhập vào số lượng phần tử có trong mảng: ";
        cin>>n;
    }while(n <= 0);
      
    int a[n];
      
    for(int i = 0;i < n;i++){
        cout<<"a["<<i<<"] = ";
       cin>>a[i];
    };
  
    mergeSort(a,0, n-1);
  
    cout<<"Mảng sau khi được sắp xếp: \n";
    printArr(a, n);
  
    cout<<"\n---------------------------------------\n";
    cout<<"Chương trình này được đăng tại codehow.net";
}