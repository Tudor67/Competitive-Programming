class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        const int N = s.length();
        const int M = spaces.size();

        s.resize(N + M, ' ');

        rotate(s.begin(), s.begin() + N, s.end());

        int spaceIndex = 0;
        int i = 0;
        int j = M;
        while(j < M + N){
            if(spaceIndex < M && spaces[spaceIndex] == j - M){
                s[i] = ' ';
                i += 1;
                spaceIndex += 1;
            }
            s[i] = s[j];
            i += 1;
            j += 1;
        }

        return s;
    }
};