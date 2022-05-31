class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        const int N = nums.size();
        
        if(N <= 2){
            return false;
        }
        
        vector<int> prefMin(N);
        prefMin[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefMin[i] = min(prefMin[i - 1], nums[i]);
        }
        
        stack<int> st;
        vector<int> prevGreater(N, -1);
        for(int i = 0; i < N; ++i){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                prevGreater[i] = st.top();
            }
            st.push(i);
        }
        
        for(int i = 1; i < N; ++i){
            if(prevGreater[i] >= 1){
                if(prefMin[prevGreater[i] - 1] < nums[i]){
                    return true;
                }
            }
        }
        
        return false;
    }
};