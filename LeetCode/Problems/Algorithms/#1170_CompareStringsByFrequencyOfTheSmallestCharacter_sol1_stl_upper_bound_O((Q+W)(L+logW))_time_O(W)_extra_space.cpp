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
        
        vector<int> fw(W);
        transform(words.begin(), words.end(), fw.begin(), f);
        
        sort(fw.begin(), fw.end());
        
        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            int fq = f(queries[i]);
            answer[i] = fw.end() - upper_bound(fw.begin(), fw.end(), fq);
        }
        
        return answer;
    }
};