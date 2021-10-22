class Solution {
public:
    string reverseWords(string s) {
        const int N = s.length();
        
        string answer;
        string word;
        istringstream ss(s);
        while(ss >> word){
            copy(word.rbegin(), word.rend(), back_inserter(answer));
            answer += ' ';
        }
        
        answer.pop_back();
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};