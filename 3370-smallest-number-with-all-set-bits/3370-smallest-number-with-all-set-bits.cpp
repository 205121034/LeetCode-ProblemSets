class Solution {
public:
    int smallestNumber(int n) {
        int bitCount = 0;
        while ((1 << bitCount) <= n) {
            bitCount++;
        }

        int ans = (1 << bitCount) - 1;

        if (ans < n) {
            bitCount++;
            ans = (1 << bitCount) - 1;
        }

        return ans;
    }
};