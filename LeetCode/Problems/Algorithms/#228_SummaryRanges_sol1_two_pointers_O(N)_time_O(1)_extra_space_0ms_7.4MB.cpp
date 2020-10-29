class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        const int N = nums.size();
        vector<string> answer;
        
        for(int l = 0, r = 1; r <= N; ++r){
            if(r == N || nums[r - 1] + 1 != nums[r]){
                string s = to_string(nums[l]);
                if(l < r - 1){
                    s += "->" + to_string(nums[r - 1]);
                }
                answer.push_back(s);
                l = r;
            }
        }
        
        return answer;
    }
};