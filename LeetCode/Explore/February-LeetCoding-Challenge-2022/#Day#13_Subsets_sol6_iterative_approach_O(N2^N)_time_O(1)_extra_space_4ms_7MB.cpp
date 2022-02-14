class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int N = nums.size();
        
        vector<vector<int>> answer;
        answer.push_back({});
        
        for(int num: nums){
            int prevSize = answer.size();
            for(int i = 0; i < prevSize; ++i){
                answer.push_back(answer[i]);
                answer.back().push_back(num);
            }
        }
        
        return answer;
    }
};