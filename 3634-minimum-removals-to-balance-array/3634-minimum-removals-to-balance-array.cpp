class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int min_rem = n;
        int r = 0;
        int l = 0;
        while (l < n) {
            while (r < n) {
                bool ok = (long long)nums[r] <= (long long)nums[l] * k;
                r = ok ? r + 1 : r;
                if (!ok) break;
            }
            min_rem = min_rem < (n - (r - l)) ? min_rem : (n - (r - l));
            ++l;
        }
        return min_rem;
    }
};