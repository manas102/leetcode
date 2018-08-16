#include<iostream>

using namespace std;

int solve(string s,int &i,int n){
	int res=0;
	while(i<n){
		if(s[i]==')')
		 	return res;
		if(s[i+1]==')'){
			res+=1;
			i+=2;	
		}
		else{
			i=i+1;
			res+=2*solve(s,i,n);	
			i++;
		}		
	}
	return res;
}
int main(){
	string s="(()(()))";
//	cin>>s;
	int i=0;
	cout<<solve(s,i,s.length())<<endl;
	return 0;
}
