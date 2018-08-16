#include<iostream>
#include<vector>

using namespace std;
int count(string s){
	int l=s.length();
	if(l==0) return 0;
	vector<int> v;
	int temp=s[0];
	int count=0;
	for(int i=0;i<l;i++){
		if(temp==s[i]){
			count++;
		}else{
			v.push_back(count);
			count=1;
			temp=s[i];
		}
	}
	v.push_back(count);
	int res=0;
	for(int i=1;i<v.size();i++){
		res+=min(v[i],v[i-1]);
	}
	return res;
}
int main(){
	string s;
	cin>>s;
	cout<<count(s)<<endl;
	return 0;
}
