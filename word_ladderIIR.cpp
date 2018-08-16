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
#include<unordered_set>
#include<algorithm>

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
void print(vs &v){
	for(string s:v){
		cout<<s<<"--";
	}
	cout<<endl;
}
void shortestPath(vs &dictionary,string start,string end,vs &v,unordered_set<string>&s,vector<vs> &res,int &mini){
	s.insert(start);
	v.push_back(start);
	if(start==end){
	//	print(v);
		res.push_back(v);
		int n=v.size();
		mini=min(n,mini);
	}
	for(int i=0;i<dictionary.size();i++){
		if(s.find(dictionary[i])==s.end() && one_diff(dictionary[i],start)){
			shortestPath(dictionary,dictionary[i],end,v,s,res,mini);
		}
	}
	s.erase(s.find(start));
	v.pop_back();	
}
vector<vs> paths(vs &dictionary,string start,string end){
	vector<vs>res;
	vs temp;
	unordered_set<string>m;
	int mini=INT_MAX;
	shortestPath(dictionary,start,end,temp,m,res,mini);
	vector<vs>ans;
	for(vs v:res){
		if(v.size()==mini)
			ans.push_back(v);
	}
	return ans;
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
	vector<vs>v=paths(dictionary,start,end);
	for(vs ss:v){
		for(string s:ss){
			cout<<s<<" ";
		}
		cout<<endl;
	}
	return 0;
}
