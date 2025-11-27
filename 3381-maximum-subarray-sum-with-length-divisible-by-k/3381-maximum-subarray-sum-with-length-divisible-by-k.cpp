class Solution {
public:
    long long maxSubarraySum(vector<int>& a, int k) {
        int n = a.size();
        
        vector<long long> ps(n + 1, 0);
        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + a[i];
        }
        
        vector<long long> mps(k, LLONG_MAX);
        long long res = LLONG_MIN;  
        int i = 0;
        
        while (i <= n) {
            int r = i % k;
            if (i >= k) {
                res = max(res, ps[i] - mps[r]);
            }
            mps[r] = min(mps[r], ps[i]);
            i++;
        }
        
        return res == LLONG_MIN ? 0 : res; 
    }
};
