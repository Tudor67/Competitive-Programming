class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        const int N = words.size();

        string res(N, '#');
        for(int i = 0; i < N; ++i){
            int sum = 0;
            for(char c: words[i]){
                sum += weights[c - 'a'];
                sum %= 26;
            }
            res[i] = char('z' - sum);
        }

        return res;
    }
};