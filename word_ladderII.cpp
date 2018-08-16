/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that: 1) 
Only one letter can be changed at a time, 2) Each intermediate word must exist in the dictionary.

For example, given: start = "hit", end = "cog", and dict = ["hot","dot","dog","lot","log"], return:

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]

*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
using ps=pair<string ,int>;
using vs=vector<string>;
bool one_diff(string s1,string s2){
	if(s1.length()!=s2.length()) return false;
	bool diff=false;
	for(int i=0;i<s1.length();i++){
		if(s1[i]!=s2[i]){
			if(diff)
				return false;
			diff=true;
		}
	}
	return true;
}
void print(int i,int *parent,vs &dictionary,vs &t){
	if(i!=-1){
		print(parent[i],parent,dictionary,t);
	}
	if(i!=-1)
		t.push_back(dictionary[i]);
}
vector<vs> shortest_path(vs &dictionary,string start,string end){
	vector<vs>res;
	int n=dictionary.size();
	
	int parent[n];
	for(int i=0;i<n;i++){
		parent[i]=i;
	}
	
	queue<ps>q;
	vector<bool>visited(n);
	q.push({start,-1});
	q.push({"",-1});
	int count=1;
	while(!q.empty()){
		ps p=q.front();q.pop();
		string temp=p.first;
		int idx=p.second;
		if(temp==""){
			if(!q.empty())
				q.push({"",-1});
			count++;
		}else{
			if(temp==end)
			{
					vs t;
					t.push_back(start);
					print(idx,parent,dictionary,t);
					res.push_back(t); 
			}
			for(int i=0;i<n;i++){
				if(!visited[i] && one_diff(temp,dictionary[i])){
					q.push({dictionary[i],i});
					parent[i]=idx;
					visited[i]=true;
				}
			}
		}
		
	}
	return res;
}
int main(){
	string  start,end;
	cin>>start>>end;
	int n;
	cin>>n;
	vs dictionary(n);
	for(int i=0;i<n;i++){
		cin>>dictionary[i];
	}
	vector<vs> v=shortest_path(dictionary,start,end);
	for(vs ss:v){
		for(string s:ss){
			cout<<s<<" ";
		}
		cout<<endl;
	}
	return 0;
}
