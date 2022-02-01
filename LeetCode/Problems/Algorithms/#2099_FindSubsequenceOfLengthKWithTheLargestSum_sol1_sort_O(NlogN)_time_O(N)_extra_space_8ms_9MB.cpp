class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        const int N = nums.size();
        
        // Step 1: create v[i] = {nums[i], i}
        //         sort v in decreasing order (of values nums[i])
        //         after sorting: values v[0].first, v[1].first, ..., v[k - 1].first
        //                        will represent the biggest k values of nums
        //                        and v[0].second, v[1].second, ..., v[k - 1].second
        //                        the corresponding indices
        vector<pair<int, int>> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = {nums[i], i};
        }
        
        sort(v.rbegin(), v.rend());
        
        // Step 2: store indices of the k biggest values
        //         sort these indices in increasing order
        vector<int> indices(k);
        for(int i = 0; i < k; ++i){
            indices[i] = v[i].second;
        }
        
        sort(indices.begin(), indices.end());
        
        // Step 3: create subseq[i] = nums[indices[i]]
        vector<int> subseq(k);
        for(int i = 0; i < k; ++i){
            subseq[i] = nums[indices[i]];
        }
        
        return subseq;
    }
};