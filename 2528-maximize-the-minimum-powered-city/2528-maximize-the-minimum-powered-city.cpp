// C-array version
using int2=pair<int, int>; // (pos, old_value)
int2 recover[100000];
class Solution {
public:
    static bool check(long long minPower, int* st, int r, long long k, int n) {
        // power for 1st window
        long long power=reduce(st, st+r+1, 0LL);
        int rz=1;
        for (int i=0; i<n; i++) {
            if (power<minPower) {
                long long need=minPower-power;
                if (need>k){
                    for (int j=0; j<rz; j++){ 
                        auto& [k, x]=recover[j];
                        st[k]=x;
                    }
                    return 0;
                }
                k-=need;
                int pos=min(n-1, i+r);
                if( pos!=n-1){
                    recover[rz++]={pos, st[pos]};
                    st[pos]+=need;
                }
                power+=need;
            }

            if (i>=r)// move left end of window
                power-=st[i-r];
            if (i+r+1<n) // move right end of window
                power+=st[i+r+1];
        }

        for (int j=0; j<rz; j++){ 
            auto& [k, x]=recover[j];
            st[k]=x;
        }
        return 1;
    }

    static long long maxPower(vector<int>& stations, int r, long long k) {
        const int n=stations.size();
        int* st=stations.data();
        recover[0]={n-1, st[n-1]};
        auto [m, M]=minmax_element(st, st+n);
        long long left=*m, right=*M*(2LL*r+1LL)+k;
        long long ans=0;

        while (left<=right) {
            long long mid=left+(right-left)/2;
            if (check(mid, st, r, k, n)) {
                ans=mid;
                left=mid+1;
            } 
            else 
                right=mid-1;
        }
        return ans;
    }
};