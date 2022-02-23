class Solution {
private:
    void computeRepr(const string& S, vector<pair<char, int>>& sRepr){
        sRepr.clear();
        for(char c: S){
            if(sRepr.empty() || sRepr.back().first != c){
                sRepr.emplace_back(c, 1);
            }else{
                sRepr.back().second += 1;
            }
        }
    }
    
    bool isValidRepr(vector<pair<char, int>>& sRepr, vector<pair<char, int>>& wordRepr){
        if(sRepr.size() != wordRepr.size()){
            return false;
        }
        const int M = sRepr.size();
        for(int i = 0; i < M; ++i){
            if(sRepr[i].first != wordRepr[i].first ||
               sRepr[i].second < wordRepr[i].second ||
               (sRepr[i].second == 2 && wordRepr[i].second == 1)){
                return false;
            }
        }
        return true;
    }
    
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<pair<char, int>> sRepr;
        computeRepr(s, sRepr);
        
        int answer = 0;
        vector<pair<char, int>> wordRepr;
        for(const string& WORD: words){
            computeRepr(WORD, wordRepr);
            if(isValidRepr(sRepr, wordRepr)){
                answer += 1;
            }
        }
        
        return answer;
    }
};