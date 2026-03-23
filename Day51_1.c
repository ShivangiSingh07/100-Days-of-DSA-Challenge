/*
Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Insert into BST
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Find LCA
Node* findLCA(Node* root, int n1, int n2) {
    if (!root) return nullptr;
    if (n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);
    if (n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);
    return root;
}

int main() {
    int N;
    cin >> N;
    Node* root = nullptr;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    int n1, n2;
    cin >> n1 >> n2;

    Node* lca = findLCA(root, n1, n2);
    if (lca) cout << lca->data << endl;
    return 0;
}
