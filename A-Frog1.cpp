#include<bits/stdc++.h>
using namespace std;

#define MAX 100005
#define int long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int32_t main(){
	int n;
	cin>>n;

	int arr[n];
	for(int i = 0; i < n; i++)cin>>arr[i];

	int dp[n];
	dp[0] = 0;
	dp[1] = abs(arr[1] - arr[0]);

	for(int j = 2; j < n; j++){
		//Jump from j - 1
		int temp1 = dp[j - 1] + abs(arr[j] - arr[j - 1]);

		//jump from j - 2
		int temp2 = dp[j - 2] + abs(arr[j] - arr[j - 2]);	
		
		dp[j] = min(temp1, temp2);	
	}

	cout<<dp[n - 1];
}