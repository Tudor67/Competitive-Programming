class Solution {
private:
    unordered_map<int, int> pairSumCounter(const vector<int>& A, const vector<int>& B){
        unordered_map<int, int> sumCounter;
        for(int i = 0; i < A.size(); ++i){
            for(int j = 0; j < B.size(); ++j){
                sumCounter[A[i] + B[j]] += 1;
            }
        }
        return sumCounter;
    }
    
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> abSumCounter = pairSumCounter(A, B);
        unordered_map<int, int> cdSumCounter = pairSumCounter(C, D);
        
        int answer = 0;
        for(const pair<int, int>& P: abSumCounter){
            int abSum = P.first;
            int abSumCount = P.second;
            int cdSum = -abSum;
            int cdSumCount = (cdSumCounter.count(cdSum) ? cdSumCounter[cdSum] : 0);
            answer += abSumCount * cdSumCount;
        }
        
        return answer;
    }
};