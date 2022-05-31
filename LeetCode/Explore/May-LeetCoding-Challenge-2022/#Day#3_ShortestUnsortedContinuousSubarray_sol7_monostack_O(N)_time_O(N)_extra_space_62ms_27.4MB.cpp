class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const int N = nums.size();
        
        stack<int> st;
        
        int l = N;
        for(int i = 0; i < N; ++i){
            while(!st.empty() && nums[st.top()] > nums[i]){
                l = min(l, st.top());
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        int r = 0;
        for(int i = N - 1; i >= 0; --i){
            while(!st.empty() && nums[i] > nums[st.top()]){
                r = max(r, st.top());
                st.pop();
            }
            st.push(i);
        }
        
        int res = r - l + 1;
        if(res <= 1){
            res = 0;
        }
        
        return res;
        
    }
};