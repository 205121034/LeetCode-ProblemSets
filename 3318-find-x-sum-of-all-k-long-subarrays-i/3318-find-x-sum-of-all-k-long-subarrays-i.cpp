class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<long long> result;
        
        // Iterate through all k-length subarrays
        for (int i = 0; i <= (int)nums.size() - k; i++) {
            // Count frequencies in current subarray
            unordered_map<int, int> freq;
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }
            
            // Create pairs of (element, frequency) and sort by:
            // 1. Frequency (descending)
            // 2. Element value (descending) if frequency is same
            vector<pair<int, int>> pairs;
            for (auto& p : freq) {
                pairs.push_back({p.first, p.second});
            }
            
            sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.second != b.second) {
                    return a.second > b.second;  // Higher frequency first
                }
                return a.first > b.first;  // If same frequency, higher element value first
            });
            
            // Sum the top x elements
            long long sum = 0;
            for (int j = 0; j < min(x, (int)pairs.size()); j++) {
                sum += (long long)pairs[j].first * pairs[j].second;
            }
            
            result.push_back(sum);
        }
        
        return result;
    }
};