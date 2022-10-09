class SegmentTree{
private:
    const int N;
    vector<int> tree;
    
    void buildTree(int node, int l, int r, const vector<int>& NUMS){
        if(l == r){
            tree[node] = NUMS[r];
        }else{
            int mid = (l + r) / 2;
            buildTree(2 * node + 1, l, mid, NUMS);
            buildTree(2 * node + 2, mid + 1, r, NUMS);
            tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
        }
    }
    
    int query(int node, int l, int r, const int& L, const int& R){
        if(R < l || r < L){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return query(2 * node + 1, l, mid, L, R) |
               query(2 * node + 2, mid + 1, r, L, R);
    }
    
public:
    SegmentTree(const vector<int>& NUMS): N(NUMS.size()){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
        buildTree(0, 0, N - 1, NUMS);
    }
    
    int query(const int& L, const int& R){
        if(L > R){
            return 0;
        }
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> answer(N);
        SegmentTree tree(nums);
        
        int j = 0;
        for(int i = 0; i < N; ++i){
            j = max(j, i);
            while(j < N && tree.query(i, j) < tree.query(i, N - 1)){
                j += 1;
            }
            answer[i] = j - i + 1;
        }
        
        return answer;
    }
};