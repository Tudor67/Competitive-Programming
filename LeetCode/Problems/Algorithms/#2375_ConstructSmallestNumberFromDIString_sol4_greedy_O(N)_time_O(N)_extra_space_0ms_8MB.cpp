class Solution {
public:
    string smallestNumber(string pattern) {
        const int N = pattern.length();

        string res(1, '1');
        int decOps = 0;

        for(int i = 0; i < N; ++i){
            res.push_back('2' + i);

            if(pattern[i] == 'D'){
                decOps += 1;
            }

            if(pattern[i] == 'D' && (i + 1 == N || pattern[i + 1] == 'I')){
                reverse(res.end() - decOps - 1, res.end());
                decOps = 0;
            }
        }

        return res;
    }
};