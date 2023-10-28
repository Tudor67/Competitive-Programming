class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const int N = nums.size();

        // Step 1: compute nextSmaller[i] with a mono-stack
        stack<int> st;
        vector<int> nextSmaller(N, N);
        for(int i = 0; i < N; ++i){
            while(!st.empty() && nums[st.top()] > nums[i]){
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        // Step 2: compute prevSmaller[i] with a mono-stack
        vector<int> prevSmaller(N, -1);
        for(int i = N - 1; i >= 0; --i){
            while(!st.empty() && nums[i] < nums[st.top()]){
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // Step 3: compute the score for each valid range [prevSmaller[i] + 1, nextSmaller[i] - 1]
        //                                                when we fix the minNum = nums[i]
        //         and update the result
        int res = 0;
        for(int i = 0; i < N; ++i){
            int l = prevSmaller[i] + 1;
            int r = nextSmaller[i] - 1;
            if(l <= k && k <= r){
                int minNum = nums[i];
                int len = (r - l + 1);
                int score = minNum * len;
                res = max(res, score);
            }
        }

        return res;
    }
};