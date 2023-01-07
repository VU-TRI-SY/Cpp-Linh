#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

Node* root = nullptr;

void insertData(){
    root = new Node(1);
    //insert children of root
    root->left = new Node(2);
    root->right = new Node(3);
    //insert children of Node 2
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    //insert children of Node 3
    root->right->left = new Node(6);
    //insert children of Node 4
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(8);
    //insert children of Node 5
    root->left->right->right = new Node(9);
    //insert children of Node 7
    root->left->left->left->left = new Node(10);
}

void preOrder(Node* p){
    if(p == nullptr){
        return; //if the current node is null -> print nothing
    }

    cout << p->data << " ";
    preOrder(p->left); //apply the preOrder function for the left sub tree of p
    preOrder(p->right);
}

void inOrder(Node* p){
    if(p == nullptr){
        return; 
    }

    inOrder(p->left); 
    cout << p->data << " ";
    inOrder(p->right);
}

void postOrder(Node* p){
    if(p == nullptr){
        return; 
    }

    postOrder(p->left); 
    postOrder(p->right);
    cout << p->data << " ";
}

int numberOfLeafNode(Node* p){ //tree: non-linear data structure ---> recursive
    //p is the current node in tree
    //base case
    if(p == nullptr)
        return 0;

    if(p->left == nullptr && p->right == nullptr){
        cout << "Leaf node: " << p->data << endl;
        return 1;
    }

    //formula: Number leaf nodes of current Node = NOLN(left) + NOLN(right)
    return numberOfLeafNode(p->left) + numberOfLeafNode(p->right);
}

int numberOfNode(Node* p){
    if(p == nullptr)
        return 0;

    //Number of Nodes of current Node = numberOfNode(left) + numberOfNode(right) + 1(current Node is a node)
    return numberOfNode(p->left) + numberOfNode(p->right) + 1;
}

int numberOfInternalNode(Node* p){
    if(p == nullptr) return 0;
    if(p->left == nullptr && p->right == nullptr) return 0; //p is leaf node

    //p is a internal node
    return 1 + numberOfInternalNode(p->left) + numberOfInternalNode(p->right);
    //retrun numberOfNode(root) - numberOfLeafNode(root);
}

int heightOfTree(Node* p){ //find the highest of the tree
    if(p == nullptr) return 0;
    return 1 + max(heightOfTree(p->left), heightOfTree(p->right));
}

int main(){
    insertData();
    cout << heightOfTree(root) << endl;
}
