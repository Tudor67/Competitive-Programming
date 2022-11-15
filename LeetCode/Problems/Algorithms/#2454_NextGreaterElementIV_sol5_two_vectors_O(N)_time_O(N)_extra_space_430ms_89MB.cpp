class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> answer(N, -1);
        vector<int> st0;
        vector<int> st1;
        
        for(int i = 0; i < N; ++i){
            while(!st1.empty() && nums[st1.back()] < nums[i]){
                answer[st1.back()] = nums[i];
                st1.pop_back();
            }
            
            int k = 0;
            while(!st0.empty() && nums[st0.back()] < nums[i]){
                st1.push_back(st0.back());
                st0.pop_back();
                k += 1;
            }
            reverse(st1.end() - k, st1.end());
            
            st0.push_back(i);
        }
        
        return answer;
    }
};