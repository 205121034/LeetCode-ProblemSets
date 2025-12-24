class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for(auto a : apple) sum += a;
        sort(capacity.begin(), capacity.end(), greater<>());
        
        int ans = 0;
        for(auto c : capacity){
            sum -= c;
            ans += 1;
            if(sum <= 0) break;
        }
        return ans;
    }
};