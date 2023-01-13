class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        const int N = words.size();

        vector<string> rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        unordered_map<char, int> rowIndexOf;
        for(int i = 0; i < (int)rows.size(); ++i){
            for(char c: rows[i]){
                rowIndexOf[tolower(c)] = i;
            }
        }

        vector<string> res;
        unordered_set<int> rowIndicesSet;
        for(const string& WORD: words){
            rowIndicesSet.clear();
            for(char c: WORD){
                rowIndicesSet.insert(rowIndexOf[tolower(c)]);
            }
            if((int)rowIndicesSet.size() == 1){
                res.push_back(WORD);
            }
        }

        return res;
    }
};