#include <iostream>
#include<bits/stdc++.h>
typedef long long ll;
const int mod = 1e9+7;
using namespace std;
char a[1005][1005];
/*
ll solve(int h,int w,int i,int j){
	if(i<1 or j<1){
		return 0;
	}
	if(i==1 and j==1){
		return 1;
	}
	ll ans = 0;
	if(a[i-1][j] == '.'){
		ans+= solve(h,w,i-1,j);
	}
	if(a[i][j-1] == '.'){
		ans+= solve(h,w,i,j-1);
	}
	return ans;
}
*/
void solve(int h,int w){
	ll dp[h+1][w+1];
	dp[1][1]= 1;
	for(int i=2;i<=w;i++){
		if(dp[1][i-1]!=-1 and a[1][i]=='.'){
			dp[1][i] = 1;
		}
		else{
			dp[1][i] = -1;
		}
	}
	for(int i=2;i<=h;i++){
		if(dp[i-1][1]!=-1 and a[i][1]=='.'){
			dp[i][1] = 1;
		}
		else{
			dp[i][1] = -1;
		}
	}
	for(int i=2;i<=h;i++){
		for(int j=2;j<=w;j++){
			dp[i][j] = 0;
			if(a[i][j] == '.'){
				if(dp[i-1][j]!=-1){
					dp[i][j]= ( dp[i][j] + dp[i-1][j] ) % mod;
				}
				if(dp[i][j-1]!=-1){
					dp[i][j]= ( dp[i][j] + dp[i][j-1] ) % mod;
				}
				dp[i][j] %=mod;
			}
			else{
				dp[i][j]= -1;
			}
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			//cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}
	cout<<dp[h][w];
}
int main(){
	int h,w;
	cin>>h>>w;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin>>a[i][j];
		}
	}
	solve(h,w);
}