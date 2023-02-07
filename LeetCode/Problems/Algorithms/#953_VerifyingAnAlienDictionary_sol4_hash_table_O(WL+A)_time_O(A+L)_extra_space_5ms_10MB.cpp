class Solution {
private:
    bool isGreater(string str1, string str2, unordered_map<char, int>& indexOf){
        for(char& c: str1){
            c = char('a' + indexOf[c]);
        }

        for(char& c: str2){
            c = char('a' + indexOf[c]);
        }

        return (str1 > str2);
    }

public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> indexOf;
        for(int i = 0; i < (int)order.length(); ++i){
            indexOf[order[i]] = i;
        }

        for(int i = 1; i < (int)words.size(); ++i){
            if(isGreater(words[i - 1], words[i], indexOf)){
                return false;
            }
        }

        return true;
    }
};