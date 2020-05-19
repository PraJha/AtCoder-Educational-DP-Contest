#include<bits/stdc++.h>
using namespace std;

#define MAX 100005
#define int long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int dp[101][100005];

int helper(int weight[], int value[], int n, int maxWeight, int index, int weightTillNow){
	if(index == n){
		return 0;
	}
	if(dp[index][weightTillNow] != -1){
		return dp[index][weightTillNow];
	}
	int ans1 = 0, ans2 = 0;
	if(weightTillNow + weight[index] <= maxWeight){
		ans1 = value[index] + helper(weight, value, n, maxWeight, index + 1, weightTillNow + weight[index]);
	}
	ans2 = helper(weight, value, n, maxWeight, index + 1, weightTillNow);

	dp[index][weightTillNow] = max(ans1, ans2);
	return max(ans1, ans2);
}

int32_t main(){
	int N, W;
	cin>>N>>W;

	//Initialize DP Array with value -1.
	for(int i = 0; i < 101; i++){
		for(int j = 0; j < 100005; j++)dp[i][j] = -1;
	}

	int weight[N], value[N];
	for(int i = 0; i < N; i ++){
		cin>>weight[i]>>value[i];
	}	

	//cout<<helper(weight, value, N, W, 0, 0);//Memoization
    int K[N + 1][W + 1]; 
  
    // Build table K[][] in bottom up manner 
    for (int i = 0; i <= N; i++) { 
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {//Base Case
                K[i][w] = 0; 
            }
            else if (weight[i - 1] <= w){ 
            	int include = value[i - 1] + K[i - 1][w - weight[i - 1]], exclude = K[i - 1][w];
                K[i][w] = max(include, exclude); 
            }
            else{
                K[i][w] = K[i - 1][w]; 
            }
        } 
    } 
  	cout<<K[N][W];
}