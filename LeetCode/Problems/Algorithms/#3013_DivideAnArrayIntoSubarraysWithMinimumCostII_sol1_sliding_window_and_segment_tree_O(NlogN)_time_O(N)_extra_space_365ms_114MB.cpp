class SegmentTree{
private:
    const int N;
    const vector<int>& VALUES;
    vector<long long> sum;
    vector<long long> count;

    void add(int node, int l, int r, int pos, int countVal){
        if(l == r){
            count[node] += countVal;
            sum[node] = count[node] * VALUES[r];
        }else{
            int mid = (l + r) / 2;
            if(pos <= mid){
                add(2 * node + 1, l, mid, pos, countVal);
            }else{
                add(2 * node + 2, mid + 1, r, pos, countVal);
            }
            sum[node] = sum[2 * node + 1] + sum[2 * node + 2];
            count[node] = count[2 * node + 1] + count[2 * node + 2];
        }
    }

    long long getSumOfFirstK(int node, int l, int r, int k){
        if(k == 0){
            return 0;
        }
        if(l == r){
             return k * (long long)VALUES[r];
        }
        int mid = (l + r) / 2;
        if(count[2 * node + 1] <= k){
            return sum[2 * node + 1] + getSumOfFirstK(2 * node + 2, mid + 1, r, k - count[2 * node + 1]);
        }
        return getSumOfFirstK(2 * node + 1, l, mid, k);
    }

public:
    SegmentTree(const vector<int>& VALUES): N(VALUES.size()), VALUES(VALUES){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        sum.resize(2 * minLeaves);
        count.resize(2 * minLeaves);
    }

    void add(int pos, int countVal){
        add(0, 0, N - 1, pos, countVal);
    }

    long long getSumOfFirstK(int k){
        return getSumOfFirstK(0, 0, N - 1, k);
    }
};

class Solution {
private:
    int compress(int num, vector<int>& sortedNums){
        return lower_bound(sortedNums.begin(), sortedNums.end(), num) - sortedNums.begin();
    }

public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        sortedNums.resize(unique(sortedNums.begin(), sortedNums.end()) - sortedNums.begin());

        long long minCost = accumulate(nums.begin(), nums.end(), (long long)0);
        SegmentTree tree(sortedNums);
        for(int i = 1; i < N; ++i){
            tree.add(compress(nums[i], sortedNums), 1);
            if(i - dist - 1 >= 1){
                tree.add(compress(nums[i - dist - 1], sortedNums), -1);
            }
            if(i >= k - 1){
                long long cost = nums[0] + tree.getSumOfFirstK(k - 1);
                minCost = min(minCost, cost);
            }
        }

        return minCost;
    }
};