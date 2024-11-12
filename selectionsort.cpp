/*
- Bước 1:
Dãy ban đầu: [15, 3, 11, 19, 4, 7]
Đánh dấu số đầu tiên là 15.
Tìm số nhỏ nhất trong các số còn lại: 3 là số nhỏ nhất.
Hoán đổi 15 và 3.
Kết quả sau bước 1: [3, 15, 11, 19, 4, 7]
- Bước 2:
Đánh dấu số thứ hai là 15.
Tìm số nhỏ nhất trong các số còn lại: 4 là số nhỏ nhất.
Hoán đổi 15 và 4.
Kết quả sau bước 2: [3, 4, 11, 19, 15, 7]
- Bước 3:
Đánh dấu số thứ ba là 11.
Tìm số nhỏ nhất trong các số còn lại: 7 là số nhỏ nhất.
Hoán đổi 11 và 7.
Kết quả sau bước 3: [3, 4, 7, 19, 15, 11]
- Bước 4:
Đánh dấu số thứ tư là 19.
Tìm số nhỏ nhất trong các số còn lại: 11 là số nhỏ nhất.
Hoán đổi 19 và 11.
Kết quả sau bước 4: [3, 4, 7, 11, 15, 19]
- Bước 5:
Đánh dấu số thứ năm là 15.
Các số còn lại đã sắp xếp xong, không cần hoán đổi.
Kết quả sau bước 5: [3, 4, 7, 11, 15, 19]
*/
#include <iostream>
#include <vector>
using namespace std;

void step1(vector<int>& arr) {
    int minIndex = 0;
    for (int j = 1; j < arr.size(); j++) {
        if (arr[j] < arr<[minIndex]) {
            minIndex = j;
        }
    }
    swap(arr[0], arr[minIndex]);
    cout << "Sau bước 1: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void step2(vector<int>& arr) {
    int minIndex = 1;
    for (int j = 2; j < arr.size(); j++) {
        if (arr[j] < arr[minIndex]) {
            minIndex = j;
        }
    }
    swap(arr[1], arr[minIndex]);
    cout << "Sau bước 2: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void step3(vector<int>& arr) {
    int minIndex = 2;
    for (int j = 3; j < arr.size(); j++) {
        if (arr[j] < arr[minIndex]) {
            minIndex = j;
        }
    }
    swap(arr[2], arr[minIndex]);
    cout << "Sau bước 3: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void step4(vector<int>& arr) {
    int minIndex = 3;
    for (int j = 4; j < arr.size(); j++) {
        if (arr[j] < arr[minIndex]) {
            minIndex = j;
        }
    }
    swap(arr[3], arr[minIndex]);
    cout << "Sau bước 4: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void step5(std::vector<int>& arr) {
    int minIndex = 4;
    for (int j = 5; j < arr.size(); j++) {
        if (arr[j] < arr[minIndex]) {
            minIndex = j;
        }
    }
    swap(arr[4], arr[minIndex]);
    cout << "Sau bước 5: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {15, 3, 11, 19, 4, 7};

    std::cout << "Mảng ban đầu: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    // Thực hiện từng bước của thuật toán
    step1(arr);  // Thực hiện bước 1
    step2(arr);  // Thực hiện bước 2
    step3(arr);  // Thực hiện bước 3
    step4(arr);  // Thực hiện bước 4
    step5(arr);  // Thực hiện bước 5

    cout << "Mảng đã sắp xếp: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}