class Solution {
public:
    long long maximumSumOfHeights(vector<int>& H) {
        const int N = H.size();

        // Step 1: use monotonic stacks to compute
        //         prevSmaller[i]: closest index j such that (H[j] < H[i]) and (j < i)
        //         nextSmaller[i]: closest index j such that (H[i] > H[j]) and (i < j)
        stack<int> st;
        vector<int> prevSmaller(N, -1);
        for(int i = N - 1; i >= 0; --i){
            while(!st.empty() && H[i] < H[st.top()]){
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        vector<int> nextSmaller(N, N);
        for(int i = 0; i < N; ++i){
            while(!st.empty() && H[st.top()] > H[i]){
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // Step 2: use prevSmaller[i] and nextSmaller[i] to compute
        //         prefSum[i]: max sum (heights[0] + heights[1] + ... + heights[i])
        //                     such that heights[0] <= heights[1] <= ... <= heights[i]
        //                           and heights[j] <= H[j] for all (j <= i)
        //         suffSum[i]: max sum (heights[i] + heights[i + 1] + ... + heights[N - 1])
        //                     such that heights[i] >= heights[i + 1] >= ... >= heights[N - 1]
        //                           and heights[j] <= H[j] for all (i <= j)
        vector<long long> prefSum(N);
        for(int i = 0; i < N; ++i){
            int j = prevSmaller[i];
            prefSum[i] = (long long)H[i] * (i - j) + (j == -1 ? 0 : prefSum[j]);
        }

        vector<long long> suffSum(N + 1);
        for(int i = N - 1; i >= 0; --i){
            int j = nextSmaller[i];
            suffSum[i] = (long long)H[i] * (j - i) + suffSum[j];
        }

        // Step 3: res[i] = prefSum[i] + suffSum[i] - H[i]
        //         the final result is the max res[i]
        long long res = 0;
        for(int i = 0; i < N; ++i){
            res = max(res, prefSum[i] + suffSum[i] - H[i]);
        }

        return res;
    }
};