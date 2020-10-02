#include <iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
/*
ll solve_brute(int n,int W,ll *w,ll *v){
  if(n==0 or w==0){
    return 0;
  }
  // select the nth item if weight less than total weight
  ll choice_1 = 0,choice_2 = 0;
  if(w[n]<=W){
    choice_1 = v[n] + solve(n-1,W-w[n],w,v);
  }
  choice_2 = solve(n-1,W,w,v);
  ll ans = max(choice_1,choice_2);
  return ans;
}
*/
void solve(int n,int W,ll *w,ll *v){
  ll dp[n+1][W+1];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=W;j++){
      dp[i][j] = 0;
    }
  }
  for(int i=0;i<=n;i++){
    
    for(int j=0;j<=W;j++){
      ll case_1= INT_MIN,case_2= INT_MIN;
      if(i<=0 or j<=0){
        dp[i][j] = 0;
        continue;
      }
      // case 1: include
      if(w[i]<=j){
        case_1 = v[i] + dp[i-1][j - w[i]];
      }
      // case 2 : exclude
      case_2 = dp[i-1][j];
      dp[i][j] = max(case_1,case_2);
    }
  }
  cout<<dp[n][W];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=W;j++){
      //cout<<dp[i][j]<<" ";
    }
    //cout<<endl;
  }
}
int main() {
  int n,W;
  cin>>n>>W;
  ll w[n+1];
  ll v[n+1];
  ll max_weight= INT_MIN;
  for(int i=1;i<=n;i++){
    cin>>w[i]>>v[i];
  }
  ll ans;
  solve(n,W,w,v);
}