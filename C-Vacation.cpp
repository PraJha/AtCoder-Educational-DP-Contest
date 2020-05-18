#include<bits/stdc++.h>
using namespace std;

#define MAX 100005
#define int long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int dp[3][100005];

//Memoization
int helper(int arr[][100005], int n, int prevOption, int index){
	if(index == n){
		return 0;
	}
	if(prevOption != -1 && dp[prevOption][index] != -1){
		return dp[prevOption][index];
	}

	int tempAns1 = INT_MIN, tempAns2 = INT_MIN, tempAns3 = INT_MIN;
	if(prevOption == -1){
		tempAns1 = arr[0][index] + helper(arr, n, 0, index + 1);
		tempAns2 = arr[1][index] + helper(arr, n, 1, index + 1);
		tempAns3 = arr[2][index] + helper(arr, n, 2, index + 1);
	}

	if(prevOption == 0){
		tempAns1 = arr[1][index] + helper(arr, n, 1, index + 1);
		tempAns2 = arr[2][index] + helper(arr, n, 2, index + 1);
	}
	if(prevOption == 1){
		tempAns1 = arr[0][index] + helper(arr, n, 0, index + 1);
		tempAns2 = arr[2][index] + helper(arr, n, 2, index + 1);
	}
	if(prevOption == 2){
		tempAns1 = arr[0][index] + helper(arr, n, 0, index + 1);
		tempAns2 = arr[1][index] + helper(arr, n, 1, index + 1);
	}
	if(prevOption != -1){
		dp[prevOption][index] = max(tempAns1, max(tempAns2, tempAns3));
	}
	return max(tempAns1, max(tempAns2, tempAns3));
}

int32_t main(){
	//Initialize DP array with -1.
	for(int i = 0; i < 100005; i++){
		dp[0][i] = -1;
		dp[1][i] = -1;
		dp[2][i] = -1;
	}
	int n;
	cin>>n;
	int arr[3][100005];

	for(int i = 0; i < n; i++){
		cin>>arr[0][i]>>arr[1][i]>>arr[2][i];
	}

	// cout<<helper(arr, n, -1, 0); Memoization Method

	int tabDp[3][100005];
	/* tabDp[i][j] represents maximum if we choose activity i till index j. */

	tabDp[0][0] = arr[0][0];
	tabDp[1][0] = arr[1][0];
	tabDp[2][0] = arr[2][0];

	for(int i = 1; i < n; i++){
		tabDp[0][i] = arr[0][i] + max(tabDp[1][i - 1], tabDp[2][i - 1]);
		tabDp[1][i] = arr[1][i] + max(tabDp[0][i - 1], tabDp[2][i - 1]);
		tabDp[2][i] = arr[2][i] + max(tabDp[1][i - 1], tabDp[0][i - 1]);
	}

	int ans = max(tabDp[0][n - 1], max(tabDp[1][n - 1], tabDp[2][n - 1]));//Maximum of all three options we choose.

	cout<<ans;
}