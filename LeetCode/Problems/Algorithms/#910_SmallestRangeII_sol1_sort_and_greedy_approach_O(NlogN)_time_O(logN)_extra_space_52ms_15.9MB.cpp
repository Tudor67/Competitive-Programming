class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        const int N = A.size();
        sort(A.begin(), A.end());
        
        int answer = A[N - 1] - A[0];
        for(int i = 0; i < N - 1; ++i){
            int minVal = min(A[0] + K, A[i + 1] - K);
            int maxVal = max(A[i] + K, A[N - 1] - K);
            answer = min(maxVal - minVal, answer);
        }
        
        return answer;
    }
};