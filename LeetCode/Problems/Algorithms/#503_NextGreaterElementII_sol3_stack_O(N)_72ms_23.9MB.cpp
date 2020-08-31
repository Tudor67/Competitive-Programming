class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int N = nums.size();
        vector<int> next_greater(N, -1);
        
        stack<int> st;
        for(int i = 2 * N - 1; i >= 0; --i){
            while(!st.empty() && nums[i % N] >= st.top()){
                st.pop();
            }
            if(!st.empty() && nums[i % N] < st.top()){
                next_greater[i % N] = st.top();
            }
            st.push(nums[i % N]);
        }
        
        return next_greater;
    }
};