class Solution {
public:
    vector<int> partitionLabels(string s) {
        const int N = s.length();

        unordered_map<char, int> maxIndexOf;
        for(int i = 0; i < N; ++i){
            maxIndexOf[s[i]] = i;
        }

        vector<int> res;
        int partStartIndex = 0;
        int partMaxIndex = 0;
        for(int i = 0; i < N; ++i){
            partMaxIndex = max(partMaxIndex, maxIndexOf[s[i]]);
            if(partMaxIndex == i){
                res.push_back(partMaxIndex - partStartIndex + 1);
                partStartIndex = i + 1;
            }
        }

        return res;
    }
};