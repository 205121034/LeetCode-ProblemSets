class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<>());
        long long res = 0, sub = 0, idx = 0;
        while(k--) res += max(0ll, happiness[idx++] - sub++);
        return res;
    }
};