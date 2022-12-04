#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
        Node* temp = new Node(data);
        if(root == NULL){
            root = temp;
            return root;
        }
        
        Node* current = root;
        while(true){
            if(temp->data < current->data){
                if(current->left == NULL){
                    current->left = temp;
                    return root;
                }
                current = current->left;
            }
            else{
                if(current->right == NULL){
                    current->right = temp;
                    return root;
                }
                current = current->right;
            }
        }
        
        return root;
    }

};