class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return 0;

        // dp[i][mod] = length of longest valid subsequence ending at i with last mod value `mod`
        vector<unordered_map<int, int>> dp(n);
        int maxLength = 0;

        for (int i = 0; i < n; ++i) {
            // Try pairing nums[j] with nums[i] for j < i
            for (int j = 0; j < i; ++j) {
                int mod = (nums[i] + nums[j]) % k;

                // If there's already a subsequence ending at j with mod `mod`, extend it
                if (dp[j].count(mod)) {
                    dp[i][mod] = max(dp[i][mod], dp[j][mod] + 1);
                } else {
                    // Otherwise, start a new subsequence of length 2
                    dp[i][mod] = max(dp[i][mod], 2);
                }

                maxLength = max(maxLength, dp[i][mod]);
            }
        }

        return maxLength;
    }
};