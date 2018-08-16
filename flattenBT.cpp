//left view of binary tree using levelorder traversal
#include<iostream>


using namespace std;

struct Node{
	int data;
	Node* left,*right;
	Node(int d){
		this->data=d;
		this->left=NULL;
		this->right=NULL;
	}
};
Node * flatten(Node *root){
	if(!root) return root;

	Node *a=root;
	Node *temp=a->right;
	a->right=flatten(a->left);
	a->left=NULL;
	while(a->right)
		a=a->right;
	a->right=flatten(temp);
	a->left=NULL;
	 	while(a->right)
	 	 a=a->right;
	return root;
}
void print(Node *root){
	if(!root) return ;
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}
int main(){
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(5);
	root->left->left=new Node(3);
	root->left->right=new Node(4);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	Node *temp=flatten(root);
	print(temp);

	return 0;
}
