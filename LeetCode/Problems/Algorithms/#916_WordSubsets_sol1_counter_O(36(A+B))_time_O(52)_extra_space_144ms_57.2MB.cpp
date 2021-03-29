class Solution {
private:
    void computeCharCount(const string& WORD, vector<int>& count){
        fill(count.begin(), count.end(), 0);
        for(char c: WORD){
            count[c - 'a'] += 1;
        }
    }
    
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> countB(26, 0);
        vector<int> countW(26, 0);
        for(const string& WORD: B){
            computeCharCount(WORD, countW);
            for(int i = 0; i < (int)countW.size(); ++i){
                countB[i] = max(countW[i], countB[i]);
            }
        }
        
        vector<string> answer;
        for(const string& WORD: A){
            computeCharCount(WORD, countW);
            bool isSubset = true;
            for(int i = 0; i < (int)countW.size(); ++i){
                if(countW[i] < countB[i]){
                    isSubset = false;
                }
            }
            if(isSubset){
                answer.push_back(WORD);
            }
        }
        
        return answer;
    }
};