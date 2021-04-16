class Solution {
private:
    static int f(const string& S){
        int minElem = *min_element(S.begin(), S.end());
        int minElemCount = count(S.begin(), S.end(), minElem);
        return minElemCount;
    }
    
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        const int Q = queries.size();
        const int W = words.size();
        const int L = 10;
        
        vector<int> count(L + 2, 0);
        for(int i = 0; i < W; ++i){
            int fw = f(words[i]);
            count[fw] += 1;
        }
        
        vector<int> sufCount(L + 2, 0);
        for(int i = L; i >= 1; --i){
            sufCount[i] = count[i] + sufCount[i + 1];
        }
        
        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            int fq = f(queries[i]);
            answer[i] = sufCount[fq + 1];
        }
        
        return answer;
    }
};