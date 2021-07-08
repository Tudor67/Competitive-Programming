class Solution {
public:
    int countVowelPermutation(int N) {
        const int MAX_CHAR = 'z';
        const unsigned int MODULO = 1e9 + 7;
        
        vector<vector<unsigned int>> count(2, vector<unsigned int>(MAX_CHAR + 1, 0));
        count[1]['a'] = 1;
        count[1]['e'] = 1;
        count[1]['i'] = 1;
        count[1]['o'] = 1;
        count[1]['u'] = 1;
        
        for(int i = 2; i <= N; ++i){
            count[i % 2]['a'] = (count[(i - 1) % 2]['e'] + count[(i - 1) % 2]['i'] + count[(i - 1) % 2]['u']) % MODULO;
            count[i % 2]['e'] = (count[(i - 1) % 2]['a'] + count[(i - 1) % 2]['i']) % MODULO;
            count[i % 2]['i'] = (count[(i - 1) % 2]['e'] + count[(i - 1) % 2]['o']) % MODULO;
            count[i % 2]['o'] = count[(i - 1) % 2]['i'];
            count[i % 2]['u'] = (count[(i - 1) % 2]['o'] + count[(i - 1) % 2]['i']) % MODULO;
        }
        
        int answer = 0;
        for(char c: {'a', 'e', 'i', 'o', 'u'}){
            answer += count[N % 2][c];
            answer %= MODULO;
        }
        
        return answer;
    }
};