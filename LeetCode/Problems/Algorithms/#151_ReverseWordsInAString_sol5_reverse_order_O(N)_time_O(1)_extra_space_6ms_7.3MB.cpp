class Solution {
public:
    string reverseWords(string s) {
        const int N = s.length();
        
        string answer;
        int i = N - 1;
        while(i >= 0){
            while(i >= 0 && s[i] == ' '){
                i -= 1;
            }
            int j = i;
            while(i >= 0 && s[i] != ' '){
                i -= 1;
            }
            copy(s.begin() + i + 1, s.begin() + j + 1, back_inserter(answer));
            answer.push_back(' ');
        }
        
        while(answer.back() == ' '){
            answer.pop_back();
        }
        
        return answer;
    }
};