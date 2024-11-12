#include <iostream>
using namespace std;

int main() {
    int n, p;

    // Khai báo mảng danh sách
    cout << "Nhập số lượng phần tử của mảng: ";
    cin >> n;
    int arr[n];

    // Nhập các phần tử của mảng
    cout << "Nhập các phần tử của mảng: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Nhập vị trí phần tử cần xóa (lưu ý p là chỉ số từ 0)
    cout << "Nhập vị trí phần tử cần xóa (bắt đầu từ 0): ";
    cin >> p;

    // Kiểm tra xem vị trí có hợp lệ không
    if (p < 0 || p >= n) {
        cout << "Vị trí không hợp lệ!" << endl;
        return 1;
    }

    // Xóa phần tử tại vị trí p
    for (int i = p; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--; // Giảm kích thước mảng

    // In mảng sau khi xóa phần tử
    cout << "Mảng sau khi xóa phần tử tại vị trí " << p << ": ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
