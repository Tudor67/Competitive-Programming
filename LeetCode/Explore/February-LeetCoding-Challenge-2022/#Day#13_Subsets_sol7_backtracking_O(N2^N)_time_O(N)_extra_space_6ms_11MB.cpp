class Solution {
private:
    void back(int idx, vector<int>& nums, vector<int>& st, vector<vector<int>>& answer){
        if(idx == -1){
            answer.push_back(st);
        }else{
            back(idx - 1, nums, st, answer);
            st.push_back(nums[idx]);
            back(idx - 1, nums, st, answer);
            st.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> st;
        vector<vector<int>> answer;
        back(N - 1, nums, st, answer);
        
        return answer;
    }
};