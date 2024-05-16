class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        const int N = nums.size();

        // Step 1: sort nums and save their original indices
        vector<pair<int, int>> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = {nums[i], i};
        }

        sort(v.begin(), v.end());

        // Step 2: use two pointers approach to find largest groups of elements that can be swapped
        //         sort indices from each group
        //         assign the sorted values to the corresponding sorted indices
        vector<int> res(N);
        
        int i = 0;
        while(i < N){
            int j = i + 1;
            vector<int> values = {v[i].first};
            vector<int> indices = {v[i].second};
            while(j < N && v[j].first - v[j - 1].first <= limit){
                values.push_back(v[j].first);
                indices.push_back(v[j].second);
                j += 1;
            }

            sort(indices.begin(), indices.end());

            for(int k = 0; k < (int)indices.size(); ++k){
                res[indices[k]] = values[k];
            }

            i = j;
        }

        return res;
    }
};