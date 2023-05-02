class Solution {
public:
    long long findScore(vector<int>& nums) {
        const int N = nums.size();

        vector<pair<int, int>> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = {nums[i], i};
        }

        sort(v.begin(), v.end());

        long long score = 0;
        vector<bool> marked(N, false);
        
        for(int i = 0; i < N; ++i){
            int index = v[i].second;

            if(!marked[index]){
                score += nums[index];
                
                marked[index] = true;
                marked[max(0, index - 1)] = true;
                marked[min(N - 1, index + 1)] = true;
            }
        }

        return score;
    }
};