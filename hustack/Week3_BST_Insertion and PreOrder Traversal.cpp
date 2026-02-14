#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int value;
};

Node* NewNode(int k){
    Node* newNode = new Node;
    newNode -> value = k;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void Insert(Node*& head, int k){
    if (head == NULL) {
        head = NewNode(k);
        return;
    }

    if (k > head->value){
        Insert(head -> right, k);
    } else if (k < head-> value){
        Insert(head -> left, k);
    }
}

void PreOrder(Node* head){
    if (head == NULL) return;

    cout << head -> value << " ";
    PreOrder(head -> left);
    PreOrder(head -> right);
}

int main(){
    Node* head = NULL;

    while (true) {
        string in;
        cin >> in;
        int k;
        if (in == "#") break;
        if (in == "insert"){
            int k;
            cin >> k;
            Insert(head, k);
        }
    }

    PreOrder(head);

    return 0;
}