#include <iostream>
#include <vector>

using namespace std;

// Hàm chèn phần tử x vào danh sách L tại vị trí p
void insertElement(vector<int>& L, int x, int p) {
    int count = L.size();

    // B1: Kiểm tra vị trí p có hợp lệ hay không
    if (p < 1 || p > count + 1) {
        cout << "Vi tri khong hop le. Xin vui long chon vi tri tu 1 den " << count + 1 << ".\n";
        return;
    }

    // B2: Di chuyển các phần tử từ vị trí p đến cuối danh sách sang phải
    L.push_back(0); // Tăng kích thước danh sách
    for (int i = count; i >= p - 1; --i) {
        L[i + 1] = L[i];
    }

    // B3: Gán giá trị x cho phần tử tại vị trí p
    L[p - 1] = x;

    // B4: Kích thước của danh sách đã được tăng tự động bằng hàm push_back
}

// Hàm in danh sách
void printList(const vector<int>& L) {
    cout << "Danh sach sau khi chen: ";
    for (int elem : L) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    vector<int> L;
    int n, x, p;

    // Nhập số lượng phần tử trong danh sách
    cout << "Nhap so luong phan tu trong danh sach: ";
    cin >> n;

    // Nhập các phần tử vào danh sách
    cout << "Nhap cac phan tu trong danh sach: ";
    for (int i = 0; i < n; ++i) {
        int elem;
        cin >> elem;
        L.push_back(elem);
    }

    // Nhập phần tử cần chèn và vị trí
    cout << "Nhap phan tu can chen: ";
    cin >> x;
    cout << "Nhap vi tri can chen (tu 1 den " << n + 1 << "): ";
    cin >> p;

    // Thực hiện chèn phần tử
    insertElement(L, x, p);

    // In danh sách sau khi chèn
    printList(L);

    return 0;
}
