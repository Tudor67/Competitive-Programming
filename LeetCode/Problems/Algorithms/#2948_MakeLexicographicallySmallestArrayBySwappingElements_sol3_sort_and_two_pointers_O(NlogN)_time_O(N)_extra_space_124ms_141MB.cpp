class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        const int N = nums.size();

        vector<int> res(N);
        vector<pair<int, int>> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = {nums[i], i};
        }

        sort(v.begin(), v.end());

        int l = 0;
        while(l < N){
            int r = l;
            vector<int> indices = {v[l].second};
            while(r + 1 < N && v[r + 1].first - v[r].first <= limit){
                indices.push_back(v[r + 1].second);
                r += 1;
            }

            sort(indices.begin(), indices.end());

            for(int i = 0; i < (int)indices.size(); ++i){
                res[indices[i]] = v[l + i].first;
            }

            l = r + 1;
        }

        return res;
    }
};