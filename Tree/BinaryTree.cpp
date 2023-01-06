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
        return; //if the current node is null -> print nothing
    }

    preOrder(p->left); 
    cout << p->data << " ";
    preOrder(p->right);
}

void postOrder(Node* p){
    if(p == nullptr){
        return; //if the current node is null -> print nothing
    }

    preOrder(p->left); 
    preOrder(p->right);
    cout << p->data << " ";
}

int numberOfLeafNode(Node* root){
    if(root == nullptr) return 0;
    if(root->left == nullptr && root->right == nullptr) return 1;
    return numberOfLeafNode(root->left) + numberOfLeafNode(root->right);

}

int numberOfNode(Node* root){
    if(root == nullptr) return 0;
    else return 1 + numberOfNode(root->left) + numberOfNode(root->right);
}

int numberOfInternalNode(Node* root){
    if(root == nullptr) return 0;
    if(root->left == nullptr && root->right == nullptr) return 0;
    return 1 + numberOfInternalNode(root->left) + numberOfInternalNode(root->right);
}

int heightOfTree(Node* root){
    if(root == nullptr) return 0;
    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}

int main(){
    insertData(); //creat the tree
    // preOrder(root);
    cout << numberOfNode(root) << endl;
    cout << numberOfLeafNode(root) << endl;
    cout << numberOfInternalNode(root) << endl;
    cout << heightOfTree(root) << endl;
}
