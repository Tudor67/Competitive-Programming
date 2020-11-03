class SegmentTree{
private:
    int N;
    int MIN_VAL;
    vector<int> maxLen;
    vector<int> maxLenCnt;
    
    void update(int node, int l, int r, const int& POS, const int& MAX_LEN, const int& CNT){
        if(l == r){
            if(maxLen[node] == MAX_LEN){
                maxLenCnt[node] += CNT;
            }else{
                maxLenCnt[node] = CNT;
                maxLen[node] = MAX_LEN;
            }
            return;
        }
        int mid = (l + r) / 2;
        if(POS <= mid){
            update(2 * node + 1, l, mid, POS, MAX_LEN, CNT);
        }else{
            update(2 * node + 2, mid + 1, r, POS, MAX_LEN, CNT);
        }
        maxLen[node] = max(maxLen[2 * node + 1], maxLen[2 * node + 2]);
        maxLenCnt[node] = (maxLen[node] == maxLen[2 * node + 1]) * maxLenCnt[2 * node + 1] +
                          (maxLen[node] == maxLen[2 * node + 2]) * maxLenCnt[2 * node + 2];
    }
    
    int queryMaxLen(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            return maxLen[node];
        }
        int mid = (l + r) / 2;
        return max(queryMaxLen(2 * node + 1, l, mid, L, R),
                   queryMaxLen(2 * node + 2, mid + 1, r, L, R));
    }
    
    int queryMaxLenCnt(int node, int l, int r, const int& L, const int& R, const int& MAX_LEN){
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            return (maxLen[node] == MAX_LEN) * maxLenCnt[node];
        }
        int mid = (l + r) / 2;
        return queryMaxLenCnt(2 * node + 1, l, mid, L, R, MAX_LEN) +
               queryMaxLenCnt(2 * node + 2, mid + 1, r, L, R, MAX_LEN);
    }
    
public:
    SegmentTree(const int& MIN_VAL, const int& MAX_VAL){
        this->MIN_VAL = MIN_VAL;
        this->N = MAX_VAL - MIN_VAL;
        maxLen.resize(4 * N + 5);
        maxLenCnt.resize(4 * N + 5);
    }
    
    void update(const int& POS, const int& MAX_LEN, const int& CNT){
        update(0, 0, N, POS - MIN_VAL, MAX_LEN, CNT);
    }
    
    int queryMaxLen(const int& L, const int& R){
        return queryMaxLen(0, 0, N, L - MIN_VAL, R - MIN_VAL);
    }
    
    int queryMaxLenCnt(const int& L, const int& R, const int& MAX_LEN){
        return queryMaxLenCnt(0, 0, N, L - MIN_VAL, R - MIN_VAL, MAX_LEN);
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        SegmentTree tree(MIN_NUM, MAX_NUM);
        int globalMaxLen = 0;
        for(int num: nums){
            int maxLen = tree.queryMaxLen(MIN_NUM, num - 1);
            int maxLenCnt = tree.queryMaxLenCnt(MIN_NUM, num - 1, maxLen);
            maxLenCnt = max(1, maxLenCnt);
            tree.update(num, maxLen + 1, maxLenCnt);
            globalMaxLen = max(maxLen + 1, globalMaxLen);
        }
        
        return tree.queryMaxLenCnt(MIN_NUM, MAX_NUM, globalMaxLen);
    }
};