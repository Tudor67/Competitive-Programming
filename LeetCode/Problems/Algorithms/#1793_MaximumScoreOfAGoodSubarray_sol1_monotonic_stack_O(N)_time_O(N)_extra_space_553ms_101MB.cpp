class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const int N = nums.size();
        
        // nextSmaller
        vector<int> nextSmaller(N, N);
        stack<int> st;
        for(int i = N - 1; i >= 0; --i){
            while(!st.empty() && nums[i] <= nums[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                nextSmaller[i] = st.top();
            }
            st.push(i);
        }
        
        // prevSmaller
        while(!st.empty()){
            st.pop();
        }
        
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
        
        // maxScore
        int maxScore = 0;
        for(int i = 0; i < N; ++i){
            int l = prevSmaller[i];
            int r = nextSmaller[i];
            if(l + 1 <= k && k <= r - 1){
                int score = nums[i] * (r - l - 1);
                maxScore = max(maxScore, score);
            }
        }
        
        return maxScore;
    }
};