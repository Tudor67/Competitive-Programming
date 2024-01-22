class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int N = arr.size();
        const int MODULO = 1e9 + 7;

        stack<int> st;
        vector<int> nextSmallerOrEqual(N, N);
        for(int i = 0; i < N; ++i){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                nextSmallerOrEqual[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        vector<int> prevSmaller(N, -1);
        for(int i = N - 1; i >= 0; --i){
            while(!st.empty() && arr[i] < arr[st.top()]){
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int res = 0;
        for(int i = 0; i < N; ++i){
            int l = prevSmaller[i];
            int r = nextSmallerOrEqual[i];
            long long leftCount = i - l;
            long long rightCount = r - i;
            long long fixedMin = arr[i];
            long long contrib = (leftCount * rightCount % MODULO) * fixedMin % MODULO;
            res = (res + contrib) % MODULO;
        }

        return res;
    }
};