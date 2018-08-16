/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


*/
#include<iostream>
#include<vector>

using namespace std;
using vi=vector<int>;

int max_product(vi &arr){
	int n=arr.size();
	if(n==0)
		return 0;
 	vi pos_product(n);
	vi neg_product(n);
	vi ans(n);
	pos_product[0]=neg_product[0]=ans[0]=arr[0];
	for(int i=1;i<arr.size();i++){
		int pos=pos_product[i-1]*arr[i];
		int neg=neg_product[i-1]*arr[i];
		pos_product[i]=max(max(pos,neg),arr[i]);
		neg_product[i]=min(min(pos,neg),arr[i]);
		ans[i]=max(ans[i-1],pos_product[i]);
	}
	return ans[n-1];
}
// single variables
int max_productR(vi &arr){
	int n=arr.size();
	if(n==0)
		return 0;
 	int pos_product,neg_product,ans;
	
	pos_product=neg_product=ans=arr[0];
	for(int i=1;i<arr.size();i++){
		int pos=pos_product*arr[i];
		int neg=neg_product*arr[i];
		pos_product=max(max(pos,neg),arr[i]);
		neg_product=min(min(pos,neg),arr[i]);
		ans=max(ans,pos_product);
	}
	return ans;
}
int main(){
	vi arr={-2,3,1};
	cout<<max_productR(arr)<<endl;
	return 0;
}
