#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* next;
};

// -----------------------------
// Tạo node mới
Node* NewNode(int k) {
    Node* newNode = new Node;
    newNode->value = k;
    newNode->next = NULL;
    return newNode;
}

// -----------------------------
// Kiểm tra phần tử đã tồn tại
bool Exists(Node* head, int k) {
    while (head != NULL) {
        if (head->value == k) return true;
        head = head->next;
    }
    return false;
}

// -----------------------------
// Thêm vào cuối
void AddLast(Node*& head, int k) {
    if (head == NULL) {
        head = NewNode(k);
        return;
    }
    Node* cur = head;
    while (cur->next != NULL) cur = cur->next;
    cur->next = NewNode(k);
}

// -----------------------------
// Thêm vào đầu
void AddFirst(Node*& head, int k) {
    Node* newNode = NewNode(k);
    newNode->next = head;
    head = newNode;
}

// -----------------------------
// Thêm sau phần tử v
void AddAfter(Node*& head, int u, int v) {
    Node* cur = head;
    while (cur != NULL && cur->value != v) cur = cur->next;
    if (cur == NULL) return; // v không tồn tại
    Node* newNode = NewNode(u);
    newNode->next = cur->next;
    cur->next = newNode;
}

// -----------------------------
// Thêm trước phần tử v
void AddBefore(Node*& head, int u, int v) {
    if (head == NULL) return;
    if (head->value == v) { // chèn trước head
        AddFirst(head, u);
        return;
    }
    Node* cur = head;
    while (cur->next != NULL && cur->next->value != v)
        cur = cur->next;
    if (cur->next == NULL) return; // không tìm thấy v
    Node* newNode = NewNode(u);
    newNode->next = cur->next;
    cur->next = newNode;
}

// -----------------------------
// Xóa phần tử có giá trị v
void Remove(Node*& head, int v) {
    if (head == NULL) return;
    if (head->value == v) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return;
    }
    Node* cur = head;
    while (cur->next != NULL && cur->next->value != v)
        cur = cur->next;
    if (cur->next == NULL) return;
    Node* tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
}

// -----------------------------
// Đảo ngược danh sách
void Reverse(Node*& head) {
    Node* prev = NULL;
    Node* cur = head;
    Node* next = NULL;
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

// -----------------------------
// In danh sách
void Print(Node* head) {
    while (head != NULL) {
        cout << head->value;
        if (head->next != NULL) cout << " ";
        head = head->next;
    }
    cout << "\n";
}

// -----------------------------
// MAIN
int main() {
    int n;
    cin >> n;

    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        AddLast(head, x);
    }

    while (true) {
        string cmd;
        cin >> cmd;
        if (cmd == "#") break;

        if (cmd == "addlast") {
            int k; cin >> k;
            if (!Exists(head, k)) AddLast(head, k);
        } 
        else if (cmd == "addfirst") {
            int k; cin >> k;
            if (!Exists(head, k)) AddFirst(head, k);
        } 
        else if (cmd == "addafter") {
            int u, v; cin >> u >> v;
            if (!Exists(head, u) && Exists(head, v)) AddAfter(head, u, v);
        } 
        else if (cmd == "addbefore") {
            int u, v; cin >> u >> v;
            if (!Exists(head, u) && Exists(head, v)) AddBefore(head, u, v);
        } 
        else if (cmd == "remove") {
            int k; cin >> k;
            if (Exists(head, k)) Remove(head, k);
        } 
        else if (cmd == "reverse") {
            Reverse(head);
        }
    }

    Print(head);
    return 0;
}
