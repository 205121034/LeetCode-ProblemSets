class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> dp(1 << 17, 0);
        dp[0] = 1;
        int maxOr = 0;

        for (int num : nums) {
            for (int i = maxOr; i >= 0; --i) {
                dp[i | num] += dp[i];
            }
            maxOr |= num;
        }

        return dp[maxOr];
    }
};