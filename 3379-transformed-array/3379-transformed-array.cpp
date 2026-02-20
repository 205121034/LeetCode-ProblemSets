class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
 


    vector<int> res(nums.size());
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        if (nums[i] > 0) {
            int idx = (i + nums[i]) % n;
            res[i] = nums[idx];
        } else if (nums[i] < 0) {
            int idx = (i + nums[i]) % n;
            if (idx < 0) idx += n; // Correct for negative modulo
            res[i] = nums[idx];
        } else {
            res[i] = nums[i];
        }
    }

    return res;
}

    
};