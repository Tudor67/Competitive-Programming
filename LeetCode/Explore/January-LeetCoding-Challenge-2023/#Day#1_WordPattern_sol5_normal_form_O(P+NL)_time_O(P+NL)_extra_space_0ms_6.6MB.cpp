class Solution {
private:
    template<typename T>
    string getNormForm(const vector<T>& V){
        string normForm;
        unordered_map<T, int> indexOf;
        for(const T& elem: V){
            if(!indexOf.count(elem)){
                int index = indexOf.size();
                indexOf[elem] = index;
            }
            normForm += to_string(indexOf[elem]) + "#";
        }
        return normForm;
    }

public:
    bool wordPattern(string pattern, string s) {
        vector<char> patternChars(pattern.begin(), pattern.end());
        
        vector<string> words;
        int startPos = 0;
        for(int pos = 0; pos <= (int)s.length(); ++pos){
            if(pos == (int)s.length() || s[pos] == ' '){
                words.push_back(s.substr(startPos, pos - startPos));
                startPos = pos + 1;
            }
        }

        return getNormForm(patternChars) == getNormForm(words);
    }
};