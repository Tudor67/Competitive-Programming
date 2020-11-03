class SegmentTree{
private:
    const int N;
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
    SegmentTree(const int& N): N(N){
        maxLen.resize(4 * N + 5);
        maxLenCnt.resize(4 * N + 5);
    }
    
    void update(const int& POS, const int& MAX_LEN, const int& CNT){
        update(0, 1, N, POS, MAX_LEN, CNT);
    }
    
    int queryMaxLen(const int& L, const int& R){
        return queryMaxLen(0, 1, N, L, R);
    }
    
    int queryMaxLenCnt(const int& L, const int& R, const int& MAX_LEN){
        return queryMaxLenCnt(0, 1, N, L, R, MAX_LEN);
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        
        // value compression
        vector<pair<int, int>> numPos(nums.size());
        for(int i = 0; i < numPos.size(); ++i){
            numPos[i].first = nums[i];
        }
        
        sort(numPos.begin(), numPos.end());
        
        numPos[0].second = 1;
        for(int i = 1; i < numPos.size(); ++i){
            if(numPos[i - 1].first == numPos[i].first){
                numPos[i].second = numPos[i - 1].second;
            }else{
                numPos[i].second = 1 + numPos[i - 1].second;
            }
        }
        
        const int MAX_COMPRESSED_NUM = numPos.back().second;
        map<int, int> compressedVal;
        for(int i = 0; i < numPos.size(); ++i){
            compressedVal[numPos[i].first] = numPos[i].second;
        }
        
        // segment tree on compressed values
        SegmentTree tree(MAX_COMPRESSED_NUM);
        int globalMaxLen = 0;
        for(int initialNum: nums){
            int compressedNum = compressedVal[initialNum];
            int maxLen = tree.queryMaxLen(1, compressedNum - 1);
            int maxLenCnt = tree.queryMaxLenCnt(1, compressedNum - 1, maxLen);
            maxLenCnt = max(1, maxLenCnt);
            tree.update(compressedNum, maxLen + 1, maxLenCnt);
            globalMaxLen = max(maxLen + 1, globalMaxLen);
        }
        
        return tree.queryMaxLenCnt(1, MAX_COMPRESSED_NUM, globalMaxLen);
    }
};