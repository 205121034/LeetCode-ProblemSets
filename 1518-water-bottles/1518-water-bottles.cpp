class Solution {
public:
    int numWaterBottles(int full, int xch) {
        int empty = full;
        int ans = full;
        while (empty>=xch) {
            int k = floor(empty/xch);
            ans += k; 
            empty = empty%xch + k;
        }
        return ans;
    }
};