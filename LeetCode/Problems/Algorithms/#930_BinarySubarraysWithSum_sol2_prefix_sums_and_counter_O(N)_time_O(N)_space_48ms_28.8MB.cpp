class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        if(A.empty()){
            return 0;
        }
        
        const int N = A.size();
        vector<int> prefSum(N);
        prefSum[0] = A[0];
        for(int i = 1; i < N; ++i){
            prefSum[i] = A[i] + prefSum[i - 1];
        }
        
        int answer = 0;
        vector<int> cnt(2 * N + 1);
        cnt[0] = 1;
        for(int i = 0; i < N; ++i){
            if(prefSum[i] >= S){
                answer += cnt[prefSum[i] - S];
            }
            cnt[prefSum[i]] += 1;
        }
        
        return answer;
    }
};