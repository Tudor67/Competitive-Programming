class Solution {
public:
    int countVowelPermutation(int N) {
        const int VOWELS_SIZE = 5;
        const unsigned int MODULO = 1e9 + 7;
        
        enum Vowels{
            a, e, i, o, u
        };
        
        vector<vector<unsigned int>> count(N + 1, vector<unsigned int>(VOWELS_SIZE, 0));
        count[1][a] = 1;
        count[1][e] = 1;
        count[1][i] = 1;
        count[1][o] = 1;
        count[1][u] = 1;
        
        for(int step = 2; step <= N; ++step){
            count[step][a] = (count[step - 1][e] + count[step - 1][i] + count[step - 1][u]) % MODULO;
            count[step][e] = (count[step - 1][a] + count[step - 1][i]) % MODULO;
            count[step][i] = (count[step - 1][e] + count[step - 1][o]) % MODULO;
            count[step][o] = count[step - 1][i];
            count[step][u] = (count[step - 1][o] + count[step - 1][i]) % MODULO;
        }
        
        int answer = 0;
        for(int c: {a, e, i, o, u}){
            answer += count[N][c];
            answer %= MODULO;
        }
        
        return answer;
    }
};