class Solution {
public:
    int countVowelPermutation(int N) {
        const int MAX_CHAR = 'z';
        const unsigned int MODULO = 1e9 + 7;
        
        vector<vector<unsigned int>> count(N + 1, vector<unsigned int>(MAX_CHAR + 1, 0));
        count[1]['a'] = 1;
        count[1]['e'] = 1;
        count[1]['i'] = 1;
        count[1]['o'] = 1;
        count[1]['u'] = 1;
        
        for(int i = 2; i <= N; ++i){
            count[i]['a'] = (count[i - 1]['e'] + count[i - 1]['i'] + count[i - 1]['u']) % MODULO;
            count[i]['e'] = (count[i - 1]['a'] + count[i - 1]['i']) % MODULO;
            count[i]['i'] = (count[i - 1]['e'] + count[i - 1]['o']) % MODULO;
            count[i]['o'] = count[i - 1]['i'];
            count[i]['u'] = (count[i - 1]['o'] + count[i - 1]['i']) % MODULO;
        }
        
        int answer = 0;
        for(char c: {'a', 'e', 'i', 'o', 'u'}){
            answer += count[N][c];
            answer %= MODULO;
        }
        
        return answer;
    }
};