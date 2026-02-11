class SegmentTree {
public:
    /* Segment Tree over array of size n */

    int n;
    int size;
    vector<int> sum;
    vector<int> mn;
    vector<int> mx;

    SegmentTree(int n_) : n(n_), size(4 * n_), sum(size, 0), mn(size, 0), mx(size, 0) {}

    void _pull(int node) {
        /* Helper to recompute information of node by it's children */

        int l = node * 2, r = node * 2 + 1;

        sum[node] = sum[l] + sum[r];
        mn[node] = std::min(mn[l], sum[l] + mn[r]);
        mx[node] = std::max(mx[l], sum[l] + mx[r]);
    }

    void update(int idx, int val) {
        /* Update value by index idx in original array */

        int node = 1, l = 0, r = n - 1;
        vector<int> path;

        while (l != r) {
            path.push_back(node);
            int m = l + (r - l) / 2;
            if (idx <= m) {
                node = node * 2;
                r = m;
            } else {
                node = node * 2 + 1;
                l = m + 1;
            }
        }

        sum[node] = val;
        mn[node] = val;
        mx[node] = val;

        while (!path.empty()) {
            _pull(path.back());
            path.pop_back();
        }
    }

    int find_rightmost_prefix(int target = 0) {
        /* Find rightmost index r with prefixsum(r) = target */

        int node = 1, l = 0, r = n - 1, sum_before = 0;

        auto _exist = [&](int node_, int sum_before_) -> bool {
            return mn[node_] <= target - sum_before_ && target - sum_before_ <= mx[node_];
        };

        if (!_exist(node, sum_before))
            return -1;

        while (l != r) {
            int m = l + (r - l) / 2;
            int lchild = node * 2, rchild = node * 2 + 1;

            // Check right half first
            int sum_before_right = sum[lchild] + sum_before;
            if (_exist(rchild, sum_before_right)) {
                node = rchild;
                l = m + 1;
                sum_before = sum_before_right;
            } else {
                node = lchild;
                r = m;
            }
        }

        return l;
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();

        SegmentTree stree(n);  // SegmentTree over balance array for current l
        unordered_map<int, int> first;  // val -> first occurence idx for current l

        int result = 0;
        for (int l = n - 1; l >= 0; --l) {
            int num = nums[l];

            // If x already had a first occurrence to the right, remove that old marker.
            auto it = first.find(num);
            if (it != first.end())
                stree.update(it->second, 0);

            // Now x becomes first occurrence at l.
            first[num] = l;
            stree.update(l, (num % 2 == 0) ? 1 : -1);

            // Find rightmost r >= l such that sum(w[l..r]) == 0
            int r = stree.find_rightmost_prefix(0);
            if (r >= l)
                result = std::max(result, r - l + 1);
        }

        return result;
    }
};