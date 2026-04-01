class Solution {
public:
    using int2=pair<int, int>;// (position, idx)
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string& directions) {
        const int n=positions.size();
        int2 robot[n];
        for(int i=0; i<n; i++)// 0-indexed is fine
            robot[i]={positions[i], i};
        sort(robot, robot+n);

        int stack[n], top=-1;
        for(auto& [_, i]: robot){
            if (directions[i]=='R') stack[++top]=i;
            else{
                while(top!=-1 && healths[i]>0){
                    int j=stack[top];
                    int x=healths[j]-healths[i];
                    if (x>0) healths[j]--, healths[i]=0;
                    else if (x<0) healths[j]=0, healths[i]--, top--;
                    else healths[i]=healths[j]=0, top--;
                }
            }
        }
        vector<int> ans;
        for(int x: healths)
            if (x>0) ans.push_back(x);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();