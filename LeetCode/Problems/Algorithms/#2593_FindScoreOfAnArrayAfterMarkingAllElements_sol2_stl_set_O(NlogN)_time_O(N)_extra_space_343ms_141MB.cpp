class Solution {
public:
    long long findScore(vector<int>& nums) {
        const int N = nums.size();

        set<pair<int, int>> s;
        for(int i = 0; i < N; ++i){
            s.insert({nums[i], i});
        }

        long long score = 0;
        while(!s.empty()){
            int i = s.begin()->second;
            s.erase(s.begin());

            score += nums[i];

            if(i - 1 >= 0){
                s.erase({nums[i - 1], i - 1});
            }
            if(i + 1 < N){
                s.erase({nums[i + 1], i + 1});
            }
        }

        return score;
    }
};