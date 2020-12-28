#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[101][101];
    // int min(int a, int b){return a<b?a:b;}
    int minFallingPathSum(vector<vector<int>>& A) {
        int i, m=A.size(), n=A[0].size();
        for(i=0;i<n;i++)
            dp[m-1][i]=A[m-1][i];
        for(i=m-2;~i;i--)
            for(int j=0;j<n;j++){
                int mn=dp[i+1][j];
                if(j-1>=0)
                    mn=min(mn, dp[i+1][j-1]);
                if(j+1<n)
                    mn=min(mn, dp[i+1][j+1]);
                    
                dp[i][j]=A[i][j]+mn;
            }
        
        int ans=INT_MAX;
        for(i=0;i<n;i++)
            ans = min(ans,dp[0][i]);

        return ans;

        
    }
};
