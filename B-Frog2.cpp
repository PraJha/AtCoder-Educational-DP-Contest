#include<bits/stdc++.h>
using namespace std;

#define MAX 100005
#define int long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int32_t main(){
	int n, k;
	cin>>n>>k;

	int arr[n];
	for(int i = 0; i < n; i++)cin>>arr[i];

	int dp[n];
	dp[0] = 0;
	dp[1] = abs(arr[1] - arr[0]);

	for(int i = 2; i < n; i++){
		int minAns = INT_MAX;
		for(int j = i - 1; j >= i - k && j >= 0; j --){
			minAns = min(minAns, dp[j] + abs(arr[i] - arr[j]));
		}
		dp[i] = minAns;
	}

	cout<<dp[n - 1];
}