#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
#include <algorithm>
#include <queue>

struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
    Node* root;

    BinaryTree() : root(nullptr)
    {
        
    }

    void insert(int key)
    {
        root = insertRec(root, key);
    }

    void remove(int key)
    {
        root = removeRec(root, key);
    }

    Node* search(int key)
    {
        return searchRec(root, key);
    }

    int findMax()
    {
        Node* current = root;
        while (current && current->right)
            current = current->right;
        return current ? current->key : -1;
    }

    void inorder()
    {
        inorderRec(root);
        std::cout << "\n";
    }

    void preorder()
    {
        preorderRec(root);
        std::cout << "\n";
    }

    void postorder()
    {
        postorderRec(root);
        std::cout << "\n";
    }

    void balance()
    {
        int size = 0;
        storeInorder(root, nullptr, size);
        Node** arr = new Node*[size];
        int i = 0;
        storeInorder(root, arr, i);
        root = buildBalancedTree(arr, 0, size - 1);
        delete[] arr;
    }
    
    void printHorizontal()
    {
        printHorizontalRec(root, 0);
    }

    void printHorizontalRec(Node* node, int depth)
    {
        if (!node) return;
        printHorizontalRec(node->right, depth + 1);

        for (int i = 0; i < depth; ++i)
            std::cout << "    ";  // Отступ
        std::cout << node->key << "\n";

        printHorizontalRec(node->left, depth + 1);
    }
    
    void printVertical()
    {
        if (!root) return;
        std::queue<std::pair<Node*, int>> q;
        q.push({root, 0});
        int currentLevel = 0;

        while (!q.empty())
        {
            auto [node, level] = q.front();
            q.pop();

            if (level != currentLevel)
            {
                std::cout << "\n";
                currentLevel = level;
            }

            std::cout << node->key << " ";

            if (node->left) q.push({node->left, level + 1});
            if (node->right) q.push({node->right, level + 1});
        }
        std::cout << "\n";
    }

private:
    Node* insertRec(Node* node, int key)
    {
        if (!node) return new Node(key);
        if (key < node->key)
            node->left = insertRec(node->left, key);
        else if (key > node->key)
            node->right = insertRec(node->right, key);
        return node;
    }

    Node* removeRec(Node* root, int key)
    {
        if (!root) return root;
        if (key < root->key)
            root->left = removeRec(root->left, key);
        else if (key > root->key)
            root->right = removeRec(root->right, key);
        else {
            if (!root->left)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = removeRec(root->right, temp->key);
        }
        return root;
    }

    Node* minValueNode(Node* node)
    {
        Node* current = node;
        while (current && current->left)
            current = current->left;
        return current;
    }

    Node* searchRec(Node* node, int key)
    {
        if (!node || node->key == key)
            return node;
        if (key < node->key)
            return searchRec(node->left, key);
        return searchRec(node->right, key);
    }

    void inorderRec(Node* root)
    {
        if (!root) return;
        inorderRec(root->left);
        std::cout << root->key << " ";
        inorderRec(root->right);
    }

    void preorderRec(Node* root)
    {
        if (!root) return;
        std::cout << root->key << " ";
        preorderRec(root->left);
        preorderRec(root->right);
    }

    void postorderRec(Node* root)
    {
        if (!root) return;
        postorderRec(root->left);
        postorderRec(root->right);
        std::cout << root->key << " ";
    }

    void storeInorder(Node* node, Node** arr, int& index)
    {
        if (!node) return;
        storeInorder(node->left, arr, index);
        if (arr) arr[index] = node;
        ++index;
        storeInorder(node->right, arr, index);
    }

    Node* buildBalancedTree(Node** arr, int start, int end)
    {
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        Node* node = arr[mid];
        node->left = buildBalancedTree(arr, start, mid - 1);
        node->right = buildBalancedTree(arr, mid + 1, end);
        return node;
    }
};

#endif
