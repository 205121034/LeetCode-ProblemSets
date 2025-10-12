#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        vector<vector<ll>> powNum(n, vector<ll>(m + 1, 1));
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= m; j++)
                powNum[i][j] = (powNum[i][j - 1] * nums[i]) % MOD;

        // nCk table
        vector<vector<ll>> C(m + 1, vector<ll>(m + 1, 0));
        for (int i = 0; i <= m; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++)
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
        // dp[pos][carry][used][ones]
        static ll dp[55][35][35][35];
        static bool vis[55][35][35][35];
        memset(vis, 0, sizeof(vis));

        function<ll(int,int,int,int)> dfs = [&](int pos, int carry, int used, int ones) -> ll {
            if (pos == n) {
                // process leftover carry bits
                int extra = 0;
                int c = carry;
                while (c) {
                    if (c & 1) extra++;
                    c >>= 1;
                }
                return (used == m && ones + extra == k) ? 1 : 0;
            }
            if (vis[pos][carry][used][ones]) return dp[pos][carry][used][ones];
            vis[pos][carry][used][ones] = 1;
            ll ans = 0;

            for (int cnt = 0; cnt + used <= m; cnt++) {
                int total = carry + cnt;
                int bit = total & 1;  // resulting bit here
                int ncarry = total >> 1;
                int nones = ones + bit;
                ll sub = dfs(pos + 1, ncarry, used + cnt, nones);
                if (!sub) continue;
                // ways to choose cnt occurrences of this index
                ll ways = C[m - used][cnt];
                // multiply by nums[pos]^cnt
                ll prod = powNum[pos][cnt];
                ans = (ans + sub * ways % MOD * prod) % MOD;
            }
            return dp[pos][carry][used][ones] = ans;
        };
        return (int)dfs(0, 0, 0, 0);
    }
};