class SegmentTree{
private:
    const int N;
    vector<int> tree;

    void add(int node, int l, int r, int pos, int val){
        if(l == r){
            tree[node] += val;
        }else{
            int mid = (l + r) / 2;
            if(pos <= mid){
                add(2 * node + 1, l, mid, pos, val);
            }else{
                add(2 * node + 2, mid + 1, r, pos, val);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int getXthElement(int node, int l, int r, int x){
        if(l == r){
            return r;
        }
        int mid = (l + r) / 2;
        if(x <= tree[2 * node + 1]){
            return getXthElement(2 * node + 1, l, mid, x);
        }
        return getXthElement(2 * node + 2, mid + 1, r, x - tree[2 * node + 1]);
    }

public:
    SegmentTree(const int N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
    }

    void add(int pos, int val){
        add(0, 0, N - 1, pos, val);
    }

    int getXthElement(int x){
        return getXthElement(0, 0, N - 1, x);
    }
};

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        const int N = nums.size();
        const int MIN_NUM = *min_element(nums.begin(), nums.end());

        // Step 1: special case when all nums >= 0
        vector<int> res(N - k + 1);
        if(MIN_NUM >= 0){
            return res;
        }

        // Step 2: coordinate compression for input nums
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        sortedNums.resize(unique(sortedNums.begin(), sortedNums.end()) - sortedNums.begin());

        unordered_map<int, int> compressed;
        for(int i = 0; i < (int)sortedNums.size(); ++i){
            compressed[sortedNums[i]] = i;
        }

        // Step 3: sliding window + segment tree on compressed nums
        SegmentTree tree(compressed.size());
        for(int i = 0; i < N; ++i){
            tree.add(compressed[nums[i]], 1);
            if(i >= k){
                tree.add(compressed[nums[i - k]], -1);
            }
            if(i >= k - 1){
                res[i - k + 1] = min(0, sortedNums[tree.getXthElement(x)]);
            }
        }

        return res;
    }
};