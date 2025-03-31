class Solution {
public:
    vector<int> partitionLabels(string s) {
        const int N = s.length();
        const int A = 26;
        const int FIRST_CHAR = 'a';

        vector<int> maxIndexOf(A);
        for(int i = 0; i < N; ++i){
            maxIndexOf[s[i] - FIRST_CHAR] = i;
        }

        vector<int> res;
        int partStartIndex = 0;
        int partMaxIndex = 0;
        for(int i = 0; i < N; ++i){
            partMaxIndex = max(partMaxIndex, maxIndexOf[s[i] - FIRST_CHAR]);
            if(partMaxIndex == i){
                res.push_back(partMaxIndex - partStartIndex + 1);
                partStartIndex = i + 1;
            }
        }

        return res;
    }
};