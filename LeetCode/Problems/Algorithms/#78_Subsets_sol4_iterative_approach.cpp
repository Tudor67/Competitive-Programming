class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        answer.push_back({});
        for(int num: nums){
            int prev_size = answer.size();
            for(int i = 0; i < prev_size; ++i){
                answer.push_back(answer[i]);
                answer.back().push_back(num);
            }
        }
        return answer;
    }
};