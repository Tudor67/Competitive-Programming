class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        const int N = s.length();
        const int A = 26;

        int maxGap = -1;
        vector<int> firstPosOf(A, -1);
        for(int i = 0; i < N; ++i){
            if(firstPosOf[s[i] - 'a'] == -1){
                firstPosOf[s[i] - 'a'] = i;
            }else{
                maxGap = max(maxGap, i - firstPosOf[s[i] - 'a'] - 1);
            }
        }

        return maxGap;
    }
};