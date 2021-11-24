class SegmentTree{
private:
    const int N;
    vector<int> tree;
    
    void update(int node, int l, int r, const int& POS, const int& VAL){
        if(l == r){
            tree[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
    
    int query(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return query(2 * node + 1, l, mid, L, R) +
               query(2 * node + 2, mid + 1, r, L, R);
    }
    
public:
    SegmentTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.assign(2 * minLeaves, 0);
    }
    
    void update(const int& POS, const int& VAL){
        update(0, 0, N - 1, POS, VAL);
    }
    
    int query(const int& L, const int& R){
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int N = nums.size();
        
        // value compression
        vector<int> sortedNums2(2 * N);
        for(int i = 0; i < N; ++i){
            sortedNums2[i] = nums[i];
            sortedNums2[i + N] = nums[i] + N - 1;
        }
        
        sort(sortedNums2.begin(), sortedNums2.end());
        
        unordered_map<int, int> compressed;
        int val = 0;
        compressed[sortedNums2[0]] = 0;
        for(int i = 1; i < 2 * N; ++i){
            if(sortedNums2[i - 1] != sortedNums2[i]){
                compressed[sortedNums2[i]] = ++val;
            }
        }
        
        // segment tree on compressed values
        const int M = compressed.size();
        SegmentTree segmentTree(M);
        for(int num: nums){
            segmentTree.update(compressed[num], 1);
        }
        
        int answer = N - 1;
        for(int num: nums){
            int minNum = num;
            int maxNum = minNum + N - 1;
            int cost = N - segmentTree.query(compressed[minNum], compressed[maxNum]);
            answer = min(answer, cost);
        }
        
        return answer;
    }
};