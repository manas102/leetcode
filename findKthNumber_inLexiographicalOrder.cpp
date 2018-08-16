#include<iostream>

using namespace std;
int findGap(int n,int p,int q){
	int g=0;
	while(p<=n){
		g+=max(0,min(n+1,q)-p);
		p*=10;
		q*=10;
	}
	return g;
}
int findKthNumber(int n, int k) {
    int ans = 1;
    --k;
    while (k > 0) {
       	int gap=findGap(n,ans,ans+1);	
        if (gap <= k) {
            ++ans;
            k -= gap;
        } else {
            ans *= 10;
        	--k; 
        }
    }
    return ans;
}
int main(){
	int n,k;
	cin>>n>>k;
	cout<<findKthNumber(n,k)<<endl;
	return 0;
}
