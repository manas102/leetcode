#include<iostream>
#include<vector>

using namespace std;

struct Node{
	int data;
	Node *left,*right;
	Node(int d):data(d),left(NULL),right(NULL){}
};
using vn=vector<Node *>;
using vvn=vector<vn>;
int depth(Node *root){
	if(!root) return 0;
	return max(depth(root->right),depth(root->left))+1;
}
void paths(Node *root,int d,int i,vvn &res,vn &temp){	
	if(!root) return;
	if(d==i && !root->left && !root->right){
		temp.push_back(root);
		res.push_back(temp);
		temp.pop_back();
		return ;
	}

	temp.push_back(root);
	paths(root->left,d,i+1,res,temp);
	paths(root->right,d,i+1,res,temp);
	temp.pop_back();	
}
Node *subtree(Node *root){
	int d=depth(root);
	vvn res;
	vn temp;
	paths(root,d,1,res,temp);
	Node *prev=root;
	for(int i=1;i<res[0].size();i++){
		for(int j=1;j<res.size();j++){
			if(res[j][i]!=res[j-1][i])
		   		return prev;
		}
		prev=res[0][i];
	}
	
	return prev;
}
Node* subtreeR(Node *root){
	if(!root)
	 return root;
	int l=depth(root->left);
	int r=depth(root->right);
	if(l==r) return root;
	if(l>r) subtree(root->left);
	else
	subtree(root->right);
}
int main(){
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->left->right->left=new Node(6);
//	root->right->right=new Node(8);
//	root->right->right->right=new Node(12);
	
	cout<<subtree(root)->data<<endl;
	cout<<subtreeR(root)->data<<endl;
	return 0;
}

