//
//  main.cpp
//  searchTreeProblem11
//
//  Created by Anton on 2/18/18.
//  Copyright © 2018 Anton. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

class Tree
{
    private:
    struct Node {
        int key;
        Node* left;
        Node* right;
    };
    Node* root;
    
    //Global variable for solution
    int nodeMaxHeight = 0;
    int rootDeleted = 0;
    int result = 0;
    
    Node* insert(Node* node, int data) {
        if (!node) {
            node = new Node;
            node->key = data;
            node->left = node->right = NULL;
        }
        if (data < node->key)
        node->left = insert(node->left, data);
        else if (data > node->key)
        node->right = insert(node->right, data);
        return node;
    }
    void preOrderTrabersal(Node* node) {
        if (!node)
        return;
        std::cout << node->key << std::endl;
        preOrderTrabersal(node->left);
        preOrderTrabersal(node->right);
    }
    Node* deleteRecursively(Node* node, int data) {
        if (!node)
        return NULL;
        if (data < node->key) {
            node->left = deleteRecursively(node->left, data);
            return node;
        }
        else if (data > node->key) {
            node->right = deleteRecursively(node->right, data);
            return node;
        }
        if (!node->left)
        return node->right;
        else if (!node->right)
        return node->left;
        else {
            int minKey = findMin(node->right)->key;
            node->key = minKey;
            node->right = deleteRecursively(node->right, minKey);
        }
        return node;
    }
    Node* findMin(Node* node) {
        if (node->left)
        return findMin(node->left);
        return node;
    }
    
    //Solution task
    int height(Node* node) {
        if (!node)
        return 0;
        else if (!node->left && !node->right)
        return 0;
        return std::max(height(node->left), height(node->right)) + 1;
    }
    int msl(Node* node) {
        if (!node)
        return 0;
        else if (!node->left && !node->right)
        return 0;
        int h = height(node->left) + height(node->right);
        if (!node->left or !node->right)
        return h + 1;
        return h + 2;
    }
    void postOrderTraversal(Node* node) {
        if (!node)
        return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        int m = msl(node);
        if (nodeMaxHeight < m)
        nodeMaxHeight = m;
    }
    void inOrderTraversal(Node* node) {
        if (!node)
        return;
        inOrderTraversal(node->left);
        if (rootDeleted == 0)
        if (msl(node) == nodeMaxHeight) {
            rootDeleted = 1;
            result = node->key;
        }
        inOrderTraversal(node->right);
    }
    public:
    Tree() {
        root = NULL;
    }
    void insert(int x) {
        root = insert(root, x);
    }
    void solution() {
        this->postOrderTraversal(root);
        this->inOrderTraversal(root);
        root = deleteRecursively(root, result);
        this->preOrderTrabersal(root);
    }
};

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    Tree tree;
    int x = 0;
    while (std::cin >> x) {
        tree.insert(x);
    }
    tree.solution();
    return 0;
}
