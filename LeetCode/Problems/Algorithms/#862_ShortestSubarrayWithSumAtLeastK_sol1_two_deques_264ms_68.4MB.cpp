class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        const int N = A.size();
        int answer = N + 5;
        
        vector<long long> prefix_sum(N);
        long long current_sum = 0;
        deque<int> dq;
        deque<int> increasing_prefix_sum_dq;
        for(int i = 0; i < N; ++i){
            prefix_sum[i] = A[i] + (i >= 1 ? prefix_sum[i - 1] : 0);
            current_sum += A[i];
            
            dq.push_back(i);
            while(!increasing_prefix_sum_dq.empty() && prefix_sum[increasing_prefix_sum_dq.back()] >= prefix_sum[i]){
                increasing_prefix_sum_dq.pop_back();
            }
            increasing_prefix_sum_dq.push_back(i);
            
            if(current_sum <= 0){
                current_sum = 0;
                dq.clear();
                increasing_prefix_sum_dq.clear();
            }else if(current_sum >= K){
                long long sum_to_remove = prefix_sum[increasing_prefix_sum_dq.front()] - (dq.front() >= 1 ? prefix_sum[dq.front() - 1] : 0);
                while(!increasing_prefix_sum_dq.empty() && current_sum - sum_to_remove >= K){
                    while(increasing_prefix_sum_dq.front() != dq.front()){
                        current_sum -= A[dq.front()];
                        dq.pop_front();
                    }
                    current_sum -= A[dq.front()];
                    dq.pop_front();
                    increasing_prefix_sum_dq.pop_front();
                    sum_to_remove = prefix_sum[increasing_prefix_sum_dq.front()] - prefix_sum[dq.front() - 1];
                }
                while(!dq.empty() && current_sum - A[dq.front()] >= K){
                    current_sum -= A[dq.front()];
                    dq.pop_front();
                }
                answer = min((int)dq.size(), answer);
            }
        }
        
        if(answer > N){
            answer = -1;
        }
        
        return answer;
    }
};