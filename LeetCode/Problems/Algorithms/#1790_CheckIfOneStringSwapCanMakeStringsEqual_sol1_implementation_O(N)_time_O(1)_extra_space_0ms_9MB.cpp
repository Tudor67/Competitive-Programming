class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        const int N = s1.length();

        vector<int> mismatchIndices;
        for(int i = 0; i < N; ++i){
            if(s1[i] != s2[i]){
                mismatchIndices.push_back(i);
            }
            if((int)mismatchIndices.size() >= 3){
                return false;
            }
        }

        if((int)mismatchIndices.size() == 2){
            int i = mismatchIndices[0];
            int j = mismatchIndices[1];
            return (s1[i] == s2[j] && s1[j] == s2[i]);
        }

        return mismatchIndices.empty();
    }
};