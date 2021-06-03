class Solution {
public:
    int arrayNesting(vector<int>& A) {
        const int N = A.size();
        vector<bool> vis(N, false);
        int answer = 0;
        for(int i = 0; i < N; ++i){
            int cycleSize = 0;
            for(int j = i; !vis[A[j]]; j = A[j]){
                vis[A[j]] = true;
                cycleSize += 1;
            }
            answer = max(cycleSize, answer);
        }
        return answer;
    }
};