class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        const int N = nums.size();

        vector<int> res = nums;
        vector<int> indices(N);
        iota(indices.begin(), indices.end(), 0);

        auto comp = [&](int lhs, int rhs){
            return pair<int, int>{res[lhs], lhs} >
                   pair<int, int>{res[rhs], rhs};
        };

        priority_queue<int, vector<int>, decltype(comp)> minHeap(comp, indices);

        for(int op = 1; op <= k; ++op){
            int i = minHeap.top();
            minHeap.pop();

            res[i] *= multiplier;
            minHeap.push(i);
        }

        return res;
    }
};