class Solution {
public:
    int numberOfSubstrings(string s) {
        const int N = s.length();
        const int INF = 1e9;

        int validSubstrings = 0;

        int a = INF;
        int b = INF;
        int c = INF;
        for(int i = N - 1; i >= 0; --i){
            if(s[i] == 'a'){
                a = i;
            }else if(s[i] == 'b'){
                b = i;
            }else if(s[i] == 'c'){
                c = i;
            }

            int j = max({a, b, c});
            if(j != INF){
                validSubstrings += (N - j);
            }
        }

        return validSubstrings;
    }
};