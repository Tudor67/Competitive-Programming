class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        const int N = A.size();
        
        vector<int> dp_forward(N);
        vector<int> pref_sum(N + 1);
        vector<int> max_pref_sum(N + 1);
        vector<int> suff_sum(N + 1);
        vector<int> max_suff_sum(N + 1);
        
        dp_forward[0] = A[0];
        pref_sum[0] = A[0];
        max_pref_sum[0] = A[0];
        for(int i = 1; i < N; ++i){
            dp_forward[i] = max(A[i], A[i] + dp_forward[i - 1]);
            pref_sum[i] = A[i] + pref_sum[i - 1];
            max_pref_sum[i] = max(pref_sum[i], max_pref_sum[i - 1]);
        }
        
        suff_sum[N - 1] = A[N - 1];
        max_suff_sum[N - 1] = A[N - 1];
        for(int i = N - 2; i >= 0; --i){
            suff_sum[i] = A[i] + suff_sum[i + 1];
            max_suff_sum[i] = max(suff_sum[i], max_suff_sum[i + 1]);
        }
        
        int answer = A[0];
        for(int i = 0; i <= N - 1; ++i){
            answer = max({max_pref_sum[i] + max_suff_sum[i + 1], dp_forward[i], answer});
        }
        
        return answer;
    }
};