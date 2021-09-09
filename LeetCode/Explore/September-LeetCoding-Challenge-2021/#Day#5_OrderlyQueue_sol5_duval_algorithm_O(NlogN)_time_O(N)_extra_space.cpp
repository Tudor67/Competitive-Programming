class MinimalStringRotationAlgorithm{
public:
    int minimalRotationIdx(const string& S){
        const int N = S.length();
        const string SS = S + S;
        
        int startIdx = 0;
        int i = 0;
        int j = 1;
        while(j < 2 * N){
            if(SS[i] == SS[j]){
                i += 1;
                j += 1;
            }else if(SS[i] < SS[j]){
                i = startIdx;
                j += 1;
            }else{
                startIdx += (j - i);
                i = startIdx;
                j += 1;
            }
        }
        
        return startIdx % N;
    }
};

class Solution {
public:
    string orderlyQueue(string s, int k) {
        string smallestS;
        if(k == 1){
            int minIdx = MinimalStringRotationAlgorithm().minimalRotationIdx(s);
            smallestS = s.substr(minIdx) + s.substr(0, minIdx);
        }else{
            smallestS = s;
            sort(smallestS.begin(), smallestS.end());
        }
        return smallestS;
    }
};