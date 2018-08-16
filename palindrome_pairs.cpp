#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
using vs=vector<string>;

struct Trie{
        map<char,Trie*>children;
        vector<int>palindromes;
        int idx;
        Trie():idx(-1){}
    };
bool ispalindrome(string word,int i=0){
    int j=word.length()-1;
    if(i>j) return false;
    while(i<j){
        if(word[i]!=word[j])
            return false;
        i++;--j;
    }
    return true;
}
void insert(Trie *root,string word,int idx){
    if(word.length()==0){
        root->palindromes.push_back(idx);
        return;
    }
    Trie *curr=root;
    for(int i=0;i<word.length();i++){
        if(curr->children.find(word[i])==curr->children.end()){
            curr->children[word[i]]=new Trie();
        }
        curr=curr->children[word[i]];
        if(i<word.length()-1 && ispalindrome(word,i+1))
            curr->palindromes.push_back(idx);	
    }
    curr->idx=idx;
}
vector<int> search(Trie *root,string word){
    vector<int>res;
    Trie *curr=root;
    if(ispalindrome(word))
    for(int i:root->palindromes)
        res.push_back(i);
    for(int i=0;i<word.length();i++){
    	if(curr->idx!=-1 && ispalindrome(word,i))
			res.push_back(curr->idx);
		if(curr->children.find(word[i])==curr->children.end())
            return res;
        curr=curr->children[word[i]];
    }
    for(int i:curr->palindromes)
        res.push_back(i);
    if(curr->idx!=-1)
        res.push_back(curr->idx);
    return res;
}
void display(Trie *root){
	cout<<"palindromes: ";
	for(int i:root->palindromes)
			cout<<i<<"--";
	cout<<" idx: "<<root->idx<<"\t";
	for(auto a:root->children){
		cout<<a.first<<endl;
		display(a.second);
	}
}
int main(){
	Trie *root=new Trie();
	int n;
	cin>>n;
	vs word_list(n);
	for(int i=0;i<n;i++){
		cin>>word_list[i];
		string s=word_list[i];
		reverse(s.begin(),s.end());
		insert(root,s,i);	
	}
	vector<vector<int>>res;
	for(int i=0;i<n;i++){
		if(word_list[i]==""){
			for(int j=0;j<n;j++){
				if(j!=i){
					res.push_back({i,j});
				}
			}
		}
		else{
			vector<int >a=search(root,word_list[i]);
			for(int j:a){
				if(j!=i){
					res.push_back({i,j});
				}
			}
		}
		
	}
	for(vector<int> v:res){
		for(int i:v){
			cout<<i<<" ";
		}
		cout<<endl;
	}
	//display();

	return 0;
}
