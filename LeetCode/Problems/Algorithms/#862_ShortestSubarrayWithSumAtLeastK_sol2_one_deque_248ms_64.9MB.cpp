class Solution {
private:
    long long range_sum(const int& LEFT_IDX, const int& RIGHT_IDX, const vector<long long>& PREF_SUM){
        if(LEFT_IDX <= 0){
            return PREF_SUM[RIGHT_IDX];
        }
        return PREF_SUM[RIGHT_IDX] - PREF_SUM[LEFT_IDX - 1];
    }
    
public:
    int shortestSubarray(vector<int>& A, int K) {
        const int N = A.size();
        int answer = N + 1;
        
        vector<long long> pref_sum(N);
        pref_sum[0] = A[0];
        for(int i = 1; i < N; ++i){
            pref_sum[i] = pref_sum[i - 1] + A[i];
        }
        
        int start_idx = 0;
        long long current_sum = 0;
        deque<int> dq;
        for(int i = 0; i < N; ++i){
            current_sum += A[i];
            while(!dq.empty() && pref_sum[dq.back()] > pref_sum[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(current_sum <= 0){
                current_sum = 0;
                start_idx = i + 1;
                dq.clear();
            }else if(current_sum >= K){
                while(!dq.empty() && current_sum - range_sum(start_idx, dq.front(), pref_sum) >= K){
                    current_sum -= range_sum(start_idx, dq.front(), pref_sum);
                    start_idx = dq.front() + 1;
                    dq.pop_front();
                }
                answer = min(i - start_idx + 1, answer);
            }
        }
        
        if(answer > N){
            answer = -1;
        }
        
        return answer;
    }
};