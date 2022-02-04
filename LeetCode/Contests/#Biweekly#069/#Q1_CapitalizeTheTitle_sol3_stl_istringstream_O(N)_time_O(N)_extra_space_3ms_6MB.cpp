class Solution {
public:
    string capitalizeTitle(string title) {
        const int N = title.length();
        
        istringstream ss(title);
        string word;
        string answer;
        while(ss >> word){
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if((int)word.length() >= 3){
                word[0] = toupper(word[0]);
            }
            answer += word;
            answer += " ";
        }
        
        answer.pop_back();
        
        return answer;
    }
};