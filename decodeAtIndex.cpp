/*
n encoded string S is given.  To find and write the decoded string to a tape, the encoded string is read one character at a time and the following steps are taken:

    If the character read is a letter, that letter is written onto the tape.
    If the character read is a digit (say d), the entire current tape is repeatedly written d-1 more times in total.

Now for some encoded string S, and an index K, find and return the K-th letter (1 indexed) in the decoded string.

 

Example 1:

Input: S = "leet2code3", K = 10
Output: "o"
Explanation: 
The decoded string is "leetleetcodeleetleetcodeleetleetcode".
The 10th letter in the string is "o".

*/
#include<iostream>

using namespace std;
string decodeAtIndex(string S, int K) {
	char c;
	long long i=0,count=0,temp;
	while(S[i]!='\0'){
		if(isdigit(S[i])){
			temp=count;
			count=temp*(S[i]-'0');
			if(count==K)
			 return string(1,c);
			if(count>K){
				K%=temp;
				if(K==0)
				 	return string(1,c);
				return decodeAtIndex(S.substr(0,i),K);
			}
			i++;
		}
		else{
			c=S[i];
			count++;
			i++;
				if(count==K){
				return string(1,c);
			}
		}
	}
	return "";
}

//string decodeAtIndex(string &S, int K, long long len = 0) {
//  for (auto i = 0; i < S.size(); ++i) {
//    if (isalpha(S[i])) {
//      if (++len == K) return string(1, S[i]);
//    }
//    else {
//      if (len * (S[i] - '0') >= K) return decodeAtIndex(S, K % len == 0 ? len : K % len);
//      len *= S[i] - '0';
//    }
//  }
//}
int main(){
	string s="ajx37nyx97niysdrzice4petvcvmcgqn282zicpbx6okybw93vhk782unctdbgmcjmbqn25rorktmu5ig2qn2y4xagtru2nehmsp";
	cout<<decodeAtIndex(s,976159153)<<endl;
	return 0;
}
