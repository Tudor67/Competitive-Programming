class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        const int N = A.size();
        int answer = 0;
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());
        
        for(int pA = 0; pA < N; ++pA){
            for(int pB = 0; pB < N; ++pB){
                // pA and pB is fixed
                int pC = 0;
                int pD = N - 1;
                while(pC <= N - 1 && pD >= 0){
                    if(A[pA] + B[pB] + C[pC] + D[pD] < 0){
                        pC += 1;
                    }else if(A[pA] + B[pB] + C[pC] + D[pD] > 0){
                        pD -= 1;
                    }else{
                        int lenC = 0;
                        while(pC + lenC <= N - 1 && C[pC] == C[pC + lenC]) lenC += 1;
                        int lenD = 0;
                        while(pD - lenD >= 0 && D[pD] == D[pD - lenD]) lenD += 1;
                        answer += lenC * lenD;
                        pC += lenC;
                        pD -= lenD;
                    }
                }
            }
        }
        
        return answer;
    }
};