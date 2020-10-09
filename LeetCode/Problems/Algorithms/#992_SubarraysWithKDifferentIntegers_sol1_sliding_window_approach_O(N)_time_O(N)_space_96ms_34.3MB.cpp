class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        const int N = A.size();
        int answer = 0;
        
        vector<int> cnt(N + 1);
        int differentNums = 0;
        for(int p0 = 0, p1 = 0, p2 = 0; p2 < N; ++p2){
            differentNums += (cnt[A[p2]] == 0);
            cnt[A[p2]] += 1;
            if(differentNums > K){
                while(differentNums > K){
                    cnt[A[p1]] -= 1;
                    differentNums -= (cnt[A[p1]] == 0);
                    p1 += 1;
                }
                p0 = p1;
            }
            if(differentNums == K){
                while(differentNums - (cnt[A[p1]] == 1) == K){
                    differentNums -= (cnt[A[p1]] == 1);
                    cnt[A[p1]] -= 1;
                    p1 += 1;
                }
                answer += (p1 - p0 + 1);
            }
        }
        
        return answer;
    }
};