#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_set>
#include <climits>

class Solution {
public:
    int maxSum(std::vector<int>& nums) {
        int max_val = INT_MIN;
        bool all_neg = true;

        for (int num : nums) {
            if (num > 0) {
                all_neg = false;
                break;
            }
            max_val = std::max(max_val, num);
        }
        if (all_neg) {
            return max_val;
        }
        std::unordered_set<int> positive_set;
        for (int num : nums) {
            if (num > 0) {
                positive_set.insert(num);
            }
        }
        int sum = 0;
        for (int val : positive_set) {
            sum += val;
        }
        return sum;
    }
};