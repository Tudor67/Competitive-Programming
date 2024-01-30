class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        const int N = words.size();
        
        vector<string> res;

        for(const string& WORD: words){
            const int L = WORD.length();
            int startPos = 0;
            while(startPos < L){
                int endPos = startPos;
                while(endPos < L && WORD[endPos] != separator){
                    endPos += 1;
                }
                if(startPos != endPos){
                    res.push_back("");
                    copy(WORD.begin() + startPos, WORD.begin() + endPos, back_inserter(res.back()));
                }
                startPos = endPos + 1;
            }
        }
        
        return res;
    }
};