class SegmentTree{
private:
    const int N;
    vector<int> maxLen;
    vector<int> maxLenCount;

    void update(int node, int l, int r, const int POS, const int MAX_LEN, const int MAX_LEN_COUNT){
        if(l == r){
            maxLen[node] = MAX_LEN;
            maxLenCount[node] = MAX_LEN_COUNT;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, MAX_LEN, MAX_LEN_COUNT);
            }else{
                update(2 * node + 2, mid + 1, r, POS, MAX_LEN, MAX_LEN_COUNT);
            }
            maxLen[node] = max(maxLen[2 * node + 1], maxLen[2 * node + 2]);
            maxLenCount[node] = (int)(maxLen[node] == maxLen[2 * node + 1]) * maxLenCount[2 * node + 1] +
                                (int)(maxLen[node] == maxLen[2 * node + 2]) * maxLenCount[2 * node + 2];
        }
    }

    int getMaxLen(int node, int l, int r, const int L, const int R){
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            return maxLen[node];
        }
        int mid = (l + r) / 2;
        return max(getMaxLen(2 * node + 1, l, mid, L, R), 
                   getMaxLen(2 * node + 2, mid + 1, r, L, R));
    }

    int getMaxLenCount(int node, int l, int r, const int L, const int R, const int MAX_LEN){
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            return (int)(maxLen[node] == MAX_LEN) * maxLenCount[node];
        }
        int mid = (l + r) / 2;
        return getMaxLenCount(2 * node + 1, l, mid, L, R, MAX_LEN) +
               getMaxLenCount(2 * node + 2, mid + 1, r, L, R, MAX_LEN);
    }

public:
    SegmentTree(const int N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        maxLen.resize(2 * minLeaves);
        maxLenCount.resize(2 * minLeaves);
    }

    void update(const int POS, const int MAX_LEN, const int MAX_LEN_COUNT){
        update(0, 0, N - 1, POS, MAX_LEN, MAX_LEN_COUNT);
    }

    int getMaxLen(const int L, const int R){
        if(L > R){
            return 0;
        }
        return getMaxLen(0, 0, N - 1, L, R);
    }

    int getMaxLenCount(const int L, const int R){
        if(L > R){
            return 0;
        }
        return getMaxLenCount(0, 0, N - 1, L, R, getMaxLen(L, R));
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        sortedNums.resize(unique(sortedNums.begin(), sortedNums.end()) - sortedNums.begin());

        const int U = sortedNums.size();
        SegmentTree tree(U);
        for(int num: nums){
            int compressedNum = lower_bound(sortedNums.begin(), sortedNums.end(), num) - sortedNums.begin();
            int maxLen = tree.getMaxLen(0, compressedNum - 1) + 1;
            int maxLenCount = max(tree.getMaxLenCount(0, compressedNum - 1), 1);
            if(maxLen == tree.getMaxLen(compressedNum, compressedNum)){
                maxLenCount += tree.getMaxLenCount(compressedNum, compressedNum);
            }
            tree.update(compressedNum, maxLen, maxLenCount);
        }

        return tree.getMaxLenCount(0, U - 1);
    }
};