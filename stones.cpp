#include<iostream>
#include<vector>
using namespace std;
void solve(int *a,int n,int k){
	std::vector<int> v(k+1);
	for(int i=0;i<=k;i++){
		v[i] = 0;
	}
	for(int i=0;i<=k;i++){
		for(int j=0;j<n;j++){
			if(a[j]<=i){
				if(i-a[j]==0 or v[i-a[j]]==0){
					v[i] =1;
				}
			}
		}
	}

	for(auto i:v){
		//cout<<i<<" ";
	}

	if(v[k]==1){
		cout<<"First";
	}
	else{
		cout<<"Second";
	}
}
int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	solve(a,n,k);
}