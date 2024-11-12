#include <iostream>
using namespace std;
/*
swap(): Hàm này để hoán đổi hai giá trị.
partition(): Hàm này thực hiện việc chọn phần tử chốt và phân chia mảng thành hai phần.
quickSort(): Hàm chính của thuật toán QuickSort được triển khai theo cách truyền thống với đệ quy để sắp xếp mảng.
printArray(): Hàm in mảng ra màn hình.
*/
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Chọn phần tử chốt là phần tử cuối
    int i = low - 1;        // Đặt con trỏ i ở vị trí trước đầu mảng

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {  // Nếu phần tử hiện tại nhỏ hơn hoặc bằng chốt
            i++;
            swap(arr[i], arr[j]);  // Hoán đổi phần tử
        }
    }
    swap(arr[i + 1], arr[high]);  // Đưa chốt về vị trí chính xác
    return i + 1;  // Trả về chỉ số của chốt
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {  // Điều kiện dừng
        int pi = partition(arr, low, high);  // Phân đoạn mảng

        quickSort(arr, low, pi - 1);  // Sắp xếp phần tử bên trái chốt
        quickSort(arr, pi + 1, high); // Sắp xếp phần tử bên phải chốt
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {2, 5, 4, 3, 1, 9, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mảng trước khi sắp xếp: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Mảng sau khi sắp xếp: ";
    printArray(arr, n);

    return 0;
}
