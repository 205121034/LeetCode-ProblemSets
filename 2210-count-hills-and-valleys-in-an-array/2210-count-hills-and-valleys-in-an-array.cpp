class Solution {
public:
    int countHillValley(vector<int>& nums) {
        const int n=nums.size();
        int cnt=0;
        bool diff[2]={0, 0};
        for(int i=1; i<n; i++){
            if (nums[i-1]==nums[i]) continue;
            bool bigger=nums[i]>nums[i-1];
            diff[bigger]=1;
            cnt+=diff[bigger] && diff[!bigger];
            diff[!bigger]=0;
        }
        return cnt;
    }
};