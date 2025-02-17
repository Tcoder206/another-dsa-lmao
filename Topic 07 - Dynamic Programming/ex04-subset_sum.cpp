#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, k, a[100]; cin >> n >> k;
    int dp[n + 1][k + 1];
    for(int i = 0; i < n; i++) cin >> a[i];
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) dp[i][0] = 0;
    for(int j = 1; j <= k; j++) dp[0][j] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(j >= a[i - 1]) dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j];
        }
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[n][k] << endl;
    return 0;
}