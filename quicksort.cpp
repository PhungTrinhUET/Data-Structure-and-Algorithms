#include <iostream>
#include <vector>

using namespace std;

// Hàm in mảng từ chỉ số low đến high
void printArray(const vector<int>& arr, int low, int high) {
    for (int i = 0; i < arr.size(); ++i) {
        if (i >= low && i <= high) {
            cout << arr[i];
        } else {
            cout << ".";
        }
        if (i < arr.size() - 1) cout << " ";
    }
    cout << endl;
}

// Hàm phân hoạch và in các bước
int partition(vector<int>& arr, int low, int high, int depth) {
    int pivot = arr[high]; // Chọn pivot là phần tử cuối
    int i = low - 1; // Chỉ số của phần tử nhỏ hơn pivot

    cout << string(depth * 2, ' ') << "Phân hoạch với pivot " << pivot << " từ " << low << " đến " << high << endl;

    for (int j = low; j <= high - 1; ++j) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] <= pivot) {
            i++; // Tăng chỉ số của phần tử nhỏ hơn
            swap(arr[i], arr[j]); // Hoán đổi
            cout << string(depth * 2, ' ') << "Hoán đổi " << arr[i] << " và " << arr[j] << ": ";
            printArray(arr, low, high);
        }
    }
    swap(arr[i + 1], arr[high]); // Đưa pivot về đúng vị trí
    cout << string(depth * 2, ' ') << "Đưa pivot vào vị trí " << i + 1 << ": ";
    printArray(arr, low, high);

    return i + 1; // Trả về chỉ số của pivot
}

// Hàm Quick Sort đệ quy và in các bước
void quickSort(vector<int>& arr, int low, int high, int depth = 0) {
    if (low < high) {
        // pi là chỉ số phân hoạch, arr[pi] đã ở đúng vị trí
        int pi = partition(arr, low, high, depth);

        // Sắp xếp các phần tử trước và sau phân hoạch
        quickSort(arr, low, pi - 1, depth + 1);
        quickSort(arr, pi + 1, high, depth + 1);
    }
}

int main() {
    vector<int> arr = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
    int n = arr.size();

    cout << "Mảng ban đầu: ";
    printArray(arr, 0, n - 1);

    quickSort(arr, 0, n - 1);

    cout << "Mảng sau khi sắp xếp: ";
    printArray(arr, 0, n - 1);

    return 0;
}
