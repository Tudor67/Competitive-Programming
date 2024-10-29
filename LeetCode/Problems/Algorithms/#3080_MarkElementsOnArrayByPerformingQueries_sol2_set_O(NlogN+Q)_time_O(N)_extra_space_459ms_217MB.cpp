class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        const int N = nums.size();
        const int Q = queries.size();

        set<pair<int, int>> s;
        for(int i = 0; i < N; ++i){
            s.insert({nums[i], i});
        }

        vector<long long> res(Q);
        long long sum = accumulate(nums.begin(), nums.end(), (long long)0);
        for(int qIndex = 0; qIndex < Q; ++qIndex){
            int index = queries[qIndex][0];
            int k = queries[qIndex][1];

            if(s.count({nums[index], index})){
                s.erase({nums[index], index});
                sum -= nums[index];
            }

            while(!s.empty() && k >= 1){
                k -= 1;
                sum -= s.begin()->first;
                s.erase(s.begin());
            }

            res[qIndex] = sum;
        }

        return res;
    }
};