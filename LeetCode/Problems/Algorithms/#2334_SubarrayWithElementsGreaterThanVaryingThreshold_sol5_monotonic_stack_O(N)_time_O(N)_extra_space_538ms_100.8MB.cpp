class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        const int N = nums.size();
        
        // prev smaller
        stack<int> st;
        vector<int> prevSmaller(N, -1);
        for(int i = 0; i < N; ++i){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                prevSmaller[i] = st.top();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        // next smaller
        vector<int> nextSmaller(N, N);
        for(int i = N - 1; i >= 0; --i){
            while(!st.empty() && nums[i] <= nums[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                nextSmaller[i] = st.top();
            }
            st.push(i);
        }
        
        // answer
        for(int i = 0; i < N; ++i){
            long long minNum = nums[i];
            long long k = nextSmaller[i] - prevSmaller[i] - 1;
            if(minNum * k > threshold){
                return k;
            }
        }
        
        return -1;
    }
};