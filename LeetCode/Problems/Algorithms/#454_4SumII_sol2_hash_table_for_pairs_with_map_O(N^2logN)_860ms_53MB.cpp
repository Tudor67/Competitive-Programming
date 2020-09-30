class Solution {
private:
    map<int, int> countPairSums(const vector<int>& A, const vector<int>& B){
        map<int, int> cnt;
        for(int i = 0; i < A.size(); ++i){
            for(int j = 0; j < B.size(); ++j){
                cnt[A[i] + B[j]] += 1;
            }
        }
        return cnt;
    }
    
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> cntAB = countPairSums(A, B);
        map<int, int> cntCD = countPairSums(C, D);
        
        int answer = 0;
        for(const pair<int, int>& P: cntAB){
            int sumAB = P.first;
            int cntSumAB = P.second;
            if(cntCD.count(-sumAB)){
                int cntSumCD = cntCD[-sumAB];
                answer += cntSumAB * cntSumCD;
            }
        }
        
        return answer;
    }
};