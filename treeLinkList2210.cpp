#include <iostream>
#include <limits>

struct Node {
    char key;
    int value;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Thêm một node vào cuối danh sách
    void append(char key, int value) {
        Node* newNode = new Node{key, value, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Duyệt và in danh sách
    void display() {
        Node* temp = head;
        std::cout << "Linked List:\n";
        while (temp) {
            std::cout << "Key: " << temp->key << ", Value: " << temp->value << "\n";
            temp = temp->next;
        }
    }

    // Tìm min và max giá trị
    void findMinMax() {
        if (!head) {
            std::cout << "Danh sách rỗng.\n";
            return;
        }
        int min = head->value;
        int max = head->value;
        Node* temp = head;
        while (temp) {
            if (temp->value < min)
                min = temp->value;
            if (temp->value > max)
                max = temp->value;
            temp = temp->next;
        }
        std::cout << "Min: " << min << "\n";
        std::cout << "Max: " << max << "\n";
    }

    // Tìm floor và ceiling cho một giá trị cho trước
    void findFloorCeiling(int target) {
        if (!head) {
            std::cout << "Danh sách rỗng.\n";
            return;
        }
        int floor = std::numeric_limits<int>::min();
        int ceiling = std::numeric_limits<int>::max();
        Node* temp = head;
        while (temp) {
            if (temp->value <= target && temp->value > floor)
                floor = temp->value;
            if (temp->value >= target && temp->value < ceiling)
                ceiling = temp->value;
            temp = temp->next;
        }
        if (floor == std::numeric_limits<int>::min())
            std::cout << "Không có floor cho giá trị " << target << ".\n";
        else
            std::cout << "Floor của " << target << ": " << floor << "\n";
        if (ceiling == std::numeric_limits<int>::max())
            std::cout << "Không có ceiling cho giá trị " << target << ".\n";
        else
            std::cout << "Ceiling của " << target << ": " << ceiling << "\n";
    }

    // Chèn một node sau một key cho trước
    void insertAfter(char key, char newKey, int newValue) {
        Node* temp = head;
        while (temp && temp->key != key)
            temp = temp->next;
        if (!temp) {
            std::cout << "Không tìm thấy key " << key << ".\n";
            return;
        }
        Node* newNode = new Node{newKey, newValue, temp->next};
        temp->next = newNode;
        std::cout << "Đã chèn key " << newKey << " sau key " << key << ".\n";
    }

    // Xóa một node với key cho trước
    void deleteNode(char key) {
        if (!head) {
            std::cout << "Danh sách rỗng.\n";
            return;
        }
        if (head->key == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            std::cout << "Đã xóa key " << key << ".\n";
            return;
        }
        Node* current = head;
        Node* prev = nullptr;
        while (current && current->key != key) {
            prev = current;
            current = current->next;
        }
        if (!current) {
            std::cout << "Không tìm thấy key " << key << ".\n";
            return;
        }
        prev->next = current->next;
        delete current;
        std::cout << "Đã xóa key " << key << ".\n";
    }
};

int main() {
    LinkedList list;
    int n;
    std::cout << "Nhập số lượng phần tử (tối đa 10): ";
    std::cin >> n;
    if (n > 10) n = 10;

    // Nhập dữ liệu cho linked list
    for (int i = 0; i < n; ++i) {
        char key;
        int value;
        std::cout << "Nhập key (char) cho phần tử " << i + 1 << ": ";
        std::cin >> key;
        std::cout << "Nhập value (int) cho phần tử " << i + 1 << ": ";
        std::cin >> value;
        list.append(key, value);
    }

    // Duyệt và in danh sách
    list.display();

    // Tìm min và max
    list.findMinMax();

    // Tìm floor và ceiling
    int target;
    std::cout << "Nhập giá trị để tìm floor và ceiling: ";
    std::cin >> target;
    list.findFloorCeiling(target);

    // Thực hiện chèn và xóa
    char chon;
    do {
        std::cout << "\nChọn thao tác:\n";
        std::cout << "1. Chèn phần tử\n";
        std::cout << "2. Xóa phần tử\n";
        std::cout << "3. Thoát\n";
        std::cout << "Lựa chọn của bạn: ";
        std::cin >> chon;
        if (chon == '1') {
            char key, newKey;
            int newValue;
            std::cout << "Nhập key sau đó chèn: ";
            std::cin >> key;
            std::cout << "Nhập key mới: ";
            std::cin >> newKey;
            std::cout << "Nhập value mới: ";
            std::cin >> newValue;
            list.insertAfter(key, newKey, newValue);
            list.display();
        } else if (chon == '2') {
            char key;
            std::cout << "Nhập key cần xóa: ";
            std::cin >> key;
            list.deleteNode(key);
            list.display();
        } else if (chon != '3') {
            std::cout << "Lựa chọn không hợp lệ.\n";
        }
    } while (chon != '3');

    return 0;
}
