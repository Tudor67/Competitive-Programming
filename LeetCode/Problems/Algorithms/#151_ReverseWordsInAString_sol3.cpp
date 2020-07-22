class Solution {
public:
    string reverseWords(string s) {
        string answer;
        string word;
        reverse(s.begin(), s.end());
        for(int i = 0; i <= s.size(); ++i){
            if(i == s.size() || s[i] == ' '){
                if(!word.empty()){
                    reverse(word.begin(), word.end());
                    answer += word;
                    answer += " ";
                    word = "";
                }
            }else{
                word += s[i];
            }
        }
        if(!answer.empty() && answer.back() == ' '){
            answer.pop_back();
        }
        return answer;
    }
};