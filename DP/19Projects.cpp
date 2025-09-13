#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>>a(n, vector<int>(3));
    for(int i = 0; i < n; ++i) {
        for(int j{0}; j<3; ++j){
            cin>>a[i][j];
        }
    }

    sort(a.begin(), a.end(), cmp);

    // dp[i] = max weight using first i intervals
    vector<long long>dp(n, 0);
    dp[0]=a[0][2];

    for(int i=1; i<n; ++i) {
        long long take = a[i][2];

        int l=-1; int r=i-1;
        while(l<r) {
            int mid=(l+r+1)/2;
            if(a[mid][1] < a[i][0]) {
                l=mid;
            }
            else r=mid-1;
        }

        if(l!=-1) take+=dp[l];

        dp[i]=max(dp[i-1], take);
    }

    cout<<dp[n-1]<<endl;
}
