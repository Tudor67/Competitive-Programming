class Solution {
public:
    int numberOfArrays(vector<int>& d, int lower, int upper) {
        const int N = d.size();
        
        long long elem = 0;
        long long minElem = 0;
        long long maxElem = 0;
        for(int i = 0; i < N; ++i){
            elem += d[i];
            minElem = min(minElem, elem);
            maxElem = max(maxElem, elem);
        }
        
        long long shift = lower - minElem;
        minElem += shift;
        maxElem += shift;
        
        long long answer = max(upper - maxElem + 1, 0LL);
        
        return answer;
    }
};