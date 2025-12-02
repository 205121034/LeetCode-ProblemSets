class Solution {
public:
    static const long long MOD = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long, long long> cnt;
        cnt.reserve(points.size() * 2);
        for (auto &p : points) {
            long long y = p[1];
            cnt[y]++;
        }

        vector<long long> C;  
        for (auto &p : cnt) {
            long long v = p.second;
            if (v >= 2) {
                long long c = (v * (v - 1) / 2) % MOD;
                C.push_back(c);
            }
        }

        if (C.size() < 2) return 0;

        long long total = 0;
        long long prefix = 0;

        for (long long c : C) {
            total = (total + (prefix * c) % MOD) % MOD;
            prefix = (prefix + c) % MOD;
        }

        return total % MOD;
    }
};