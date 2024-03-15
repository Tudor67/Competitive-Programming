class Solution {
private:
    vector<long long> computePrefSol(const vector<int>& H){
        const int N = H.size();

        stack<int> st;
        vector<int> prevSmaller(N, -1);
        for(int i = N - 1; i >= 0; --i){
            while(!st.empty() && H[i] < H[st.top()]){
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        vector<long long> prefSol(N);
        for(int i = 0; i < N; ++i){
            int j = prevSmaller[i];
            prefSol[i] = (long long)H[i] * (i - j) + (j == -1 ? 0 : prefSol[j]);
        }

        return prefSol;
    }

public:
    long long maximumSumOfHeights(vector<int>& H) {
        const int N = H.size();

        vector<long long> prefSol = computePrefSol(H);
        vector<long long> suffSol = computePrefSol(vector<int>{H.rbegin(), H.rend()});
        reverse(suffSol.begin(), suffSol.end());

        long long res = 0;
        for(int i = 0; i < N; ++i){
            res = max(res, prefSol[i] + suffSol[i] - H[i]);
        }

        return res;
    }
};