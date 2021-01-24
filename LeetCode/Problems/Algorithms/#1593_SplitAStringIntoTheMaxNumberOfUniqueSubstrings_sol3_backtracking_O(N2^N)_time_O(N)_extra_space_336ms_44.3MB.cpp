class Solution {
private:
    void back(int prevPos, const string& S, unordered_set<string>& substrings, int& answer){
        if(prevPos == S.length()){
            answer = max((int)substrings.size(), answer);
        }else{
            for(int pos = prevPos; pos < S.length(); ++pos){
                string substring = S.substr(prevPos, pos - prevPos + 1);
                if(!substrings.count(substring)){
                    substrings.insert(substring);
                    back(pos + 1, S, substrings, answer);
                    substrings.erase(substring);
                }
            }
        }
    }
    
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> substrings;
        int answer = 1;
        back(0, s, substrings, answer);
        return answer;
    }
};