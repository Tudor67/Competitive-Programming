class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        const int N = A.size();
        int answer = N + 1;
        
        vector<long long> pref_sum(N + 1, 0);
        for(int i = 1; i <= N; ++i){
            pref_sum[i] = pref_sum[i - 1] + A[i - 1];
        }
        
        deque<int> dq;
        for(int i = 0; i <= N; ++i){
            while(!dq.empty() && pref_sum[dq.back()] >= pref_sum[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            
            while(!dq.empty() && pref_sum[i] - pref_sum[dq.front()] >= K){
                answer = min(i - dq.front(), answer);
                dq.pop_front();
            }
        }
        
        if(answer > N){
            answer = -1;
        }
        
        return answer;
    }
};