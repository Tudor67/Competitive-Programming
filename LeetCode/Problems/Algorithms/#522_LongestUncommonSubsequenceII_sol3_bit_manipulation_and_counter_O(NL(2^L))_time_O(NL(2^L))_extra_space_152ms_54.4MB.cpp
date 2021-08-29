class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        const int N = strs.size();
        
        unordered_map<string, int> count;
        unordered_set<string> subseqSet;
        for(const string& S: strs){
            const int L = S.length();
            const int FULL_MASK = (1 << L) - 1;
            
            subseqSet.clear();
            for(int mask = 1; mask <= FULL_MASK; ++mask){
                string subseq;
                for(int bit = 0; bit < L; ++bit){
                    if((mask >> bit) & 1){
                        subseq += S[bit];
                    }
                }
                subseqSet.insert(subseq);
            }
            
            for(const string& UNIQUE_SUBSEQ: subseqSet){
                count[UNIQUE_SUBSEQ] += 1;
            }
        }
        
        int answer = -1;
        for(const pair<string, int>& P: count){
            const string& S = P.first;
            const int S_LENGTH = S.length();
            const int S_COUNT = P.second;
            if(S_COUNT == 1){
                answer = max(answer, S_LENGTH);
            }
        }
        
        return answer;
    }
};