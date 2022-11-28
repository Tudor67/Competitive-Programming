class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MODULO = 1e9 + 7;
        const int N = arr.size();
        
        // Step 1: nextSmaller[i]: min position greater than i such that arr[i] > arr[nextSmaller[i]]
        stack<int> st;
        vector<int> nextSmaller(N, N);
        for(int i = 0; i < N; ++i){
            while(!st.empty() && arr[st.top()] > arr[i]){
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        // Step 2: prevSmallerOrEqual[i]: max position less than i such that arr[prevSmallerOrEqual[i]] <= arr[i]
        vector<int> prevSmallerOrEqual(N, -1);
        for(int i = 0; i < N; ++i){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()){
                prevSmallerOrEqual[i] = st.top();
            }
            st.push(i);
        }
        
        // Step 3: accumulate contribution for each fixed min value arr[i]
        int res = 0;
        for(int i = 0; i < N; ++i){
            long long count = (i - prevSmallerOrEqual[i]) * (nextSmaller[i] - i);
            long long minNum = arr[i];
            res = (res + count * minNum) % MODULO;
        }
        
        return res;
    }
};