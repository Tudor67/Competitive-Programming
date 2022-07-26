class SegmentTree{
private:
    const int N;
    const vector<int> NUMS;
    vector<int> tree;
    
    void buildTree(int node, int l, int r){
        if(l == r){
            tree[node] = r;
        }else{
            int mid = (l + r) / 2;
            buildTree(2 * node + 1, l, mid);
            buildTree(2 * node + 2, mid + 1, r);
            if(NUMS[tree[2 * node + 1]] < NUMS[tree[2 * node + 2]]){
                tree[node] = tree[2 * node + 1];
            }else{
                tree[node] = tree[2 * node + 2];
            }
        }
    }
    
    int getMinValue(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return INT_MAX;
        }
        if(L <= l && r <= R){
            return NUMS[tree[node]];
        }
        int mid = (l + r) / 2;
        return min(getMinValue(2 * node + 1, l, mid, L, R),
                   getMinValue(2 * node + 2, mid + 1, r, L, R));
    }
    
public:
    SegmentTree(const vector<int>& NUMS): N(NUMS.size()), NUMS(NUMS){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
        buildTree(0, 0, N - 1);
    }
    
    int getMinValue(const int& L, const int& R){
        if(L > R){
            return INT_MAX;
        }
        return getMinValue(0, 0, N - 1, L, R);
    }
    
    int getFirstIdxOfMin(const int& L, const int& R){
        int minValue = getMinValue(L, R);
        int l = L;
        int r = R;
        while(l != r){
            int mid = (l + r) / 2;
            if(getMinValue(L, mid) == minValue){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
};

class Solution {
private:
    int solve(vector<int>& nums, const int& L, const int& R, const int& THRESHOLD, SegmentTree& segmentTree){
        if(L > R){
            return -1;
        }
        
        int firstIdxOfMin = segmentTree.getFirstIdxOfMin(L, R);
        long long minNum = nums[firstIdxOfMin];
        if(minNum * (R - L + 1) > THRESHOLD){
            return R - L + 1;
        }
        
        int leftResult = solve(nums, L, firstIdxOfMin - 1, THRESHOLD, segmentTree);
        int rightResult = solve(nums, firstIdxOfMin + 1, R, THRESHOLD, segmentTree);
        return max(leftResult, rightResult);
    }
    
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        const int N = nums.size();
        SegmentTree segmentTree(nums);
        return solve(nums, 0, N - 1, threshold, segmentTree);
    }
};