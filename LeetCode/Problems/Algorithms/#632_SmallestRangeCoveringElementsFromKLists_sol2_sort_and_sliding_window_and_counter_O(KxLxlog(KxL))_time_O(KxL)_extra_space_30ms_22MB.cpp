class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        const int K = nums.size();

        vector<pair<int, int>> v;
        for(int i = 0; i < K; ++i){
            for(int num: nums[i]){
                v.push_back({num, i});
            }
        }

        sort(v.begin(), v.end());

        int resStart = v.front().first;
        int resEnd = v.back().first;

        int distinctLists = 0;
        vector<int> freq(K);

        int l = 0;
        for(int r = 0; r < (int)v.size(); ++r){
            distinctLists += (int)(freq[v[r].second] == 0);
            freq[v[r].second] += 1;
            while(freq[v[l].second] >= 2){
                freq[v[l].second] -= 1;
                l += 1;
            }

            if(distinctLists == K){
                int rangeStart = v[l].first;
                int rangeEnd = v[r].first;
                if(resEnd - resStart > rangeEnd - rangeStart){
                    resStart = rangeStart;
                    resEnd = rangeEnd;
                }
            }
        }

        return {resStart, resEnd};
    }
};