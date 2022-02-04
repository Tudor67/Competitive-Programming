class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        const int N = words.size();
        
        int answer = 0;
        vector<vector<int>> count(26, vector<int>(26));
        for(const string& WORD: words){
            int a = WORD[0] - 'a';
            int b = WORD[1] - 'a';
            count[a][b] += 1;
            if((a == b && count[b][a] >= 2) || (a != b && count[b][a] >= 1)){
                answer += 4;
                count[a][b] -= 1;
                count[b][a] -= 1;
            }
        }
        
        for(int a = 0; a < (int)count.size(); ++a){
            if(count[a][a] > 0){
                answer += 2;
                break;
            }
        }
        
        return answer;
    }
};