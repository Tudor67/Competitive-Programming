class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        const int K = nums.size();

        set<tuple<int, int, int>> s;
        for(int i = 0; i < K; ++i){
            s.insert({nums[i][0], i, 0});
        }

        int resStart = get<0>(*s.begin());
        int resEnd = get<0>(*s.rbegin());

        while((int)s.size() == K){
            int rangeStart = get<0>(*s.begin());
            int rangeEnd = get<0>(*s.rbegin());
            if(resEnd - resStart > rangeEnd - rangeStart){
                resStart = rangeStart;
                resEnd = rangeEnd;
            }

            int i = get<1>(*s.begin());
            int j = get<2>(*s.begin());
            s.erase(s.begin());

            if(j + 1 < (int)nums[i].size()){
                s.insert({nums[i][j + 1], i, j + 1});
            }
        }

        return {resStart, resEnd};
    }
};