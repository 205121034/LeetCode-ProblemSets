
class Solution {
public:
    int minCost(string& colors, vector<int>& neededTime) {
        int l=0, r;
        const int n=colors.size();
        int removes=0;
        for (r = 1; r < n; r++) {
            if (colors[r]!=colors[l]) {
                removes += accumulate(neededTime.begin()+l, 
                neededTime.begin()+r, 0) 
                -*max_element(neededTime.begin()+l, neededTime.begin()+r);
                l=r;
            }
        }

        removes+=accumulate(neededTime.begin()+l, neededTime.end(), 0) 
        - *max_element(neededTime.begin()+l, neededTime.end());
        return  removes;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();