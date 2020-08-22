class Solution {
public:
    string toGoatLatin(string S) {
        const set<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};
        string answer;
        
        S += " ";
        int word_cnt = 0;
        for(int i = 0, j = 0; j < S.length(); ++j){
            if(S[j] == ' '){
                word_cnt += 1;
                if(VOWELS.count(tolower(S[i]))){
                    answer += S.substr(i, j - i);
                }else{
                    answer += S.substr(i + 1, j - i - 1);
                    answer += S[i];
                }
                answer += "ma";
                answer += string(word_cnt, 'a');
                answer += " ";
                i = j + 1;
            }
        }
        answer.pop_back();
        
        return answer;
    }
};