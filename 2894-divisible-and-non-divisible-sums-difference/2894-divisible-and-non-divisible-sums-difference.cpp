class Solution {
public:
    int differenceOfSums(int n, int m) {
        vector<int>v(n+1);
        int sum = 0;
        for(int i=m;i<=n;i+=m){
            v[i] = 1;
        }
        for(int i=0;i<=n;i++){
            if(v[i]) sum -= i;
            else sum += i;
        }
        return sum;
    }
};