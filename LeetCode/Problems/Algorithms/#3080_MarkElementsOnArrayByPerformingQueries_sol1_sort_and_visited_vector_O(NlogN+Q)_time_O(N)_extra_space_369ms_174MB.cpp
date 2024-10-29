class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        const int N = nums.size();
        const int Q = queries.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
            [&](int lhs, int rhs){
                return (pair<int, int>{nums[lhs], lhs} >
                        pair<int, int>{nums[rhs], rhs});
             });

        vector<long long> res(Q);
        vector<bool> vis(N, false);
        long long sum = accumulate(nums.begin(), nums.end(), (long long)0);
        for(int qIndex = 0; qIndex < Q; ++qIndex){
            int index = queries[qIndex][0];
            int k = queries[qIndex][1];

            if(!vis[index]){
                vis[index] = true;
                sum -= nums[index];
            }

            while(!p.empty() && k >= 1){
                int i = p.back();
                p.pop_back();
                
                if(!vis[i]){
                    vis[i] = true;
                    sum -= nums[i];
                    k -= 1;
                }
            }

            res[qIndex] = sum;
        }

        return res;
    }
};