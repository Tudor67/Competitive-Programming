class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int sLen = s.length();

        vector<int> indexOfSuffixMax(sLen);
        indexOfSuffixMax[sLen - 1] = sLen - 1;
        for(int i = sLen - 2; i >= 0; --i){
            if(s[i] > s[indexOfSuffixMax[i + 1]]){
                indexOfSuffixMax[i] = i;
            }else{
                indexOfSuffixMax[i] = indexOfSuffixMax[i + 1];
            }
        }

        for(int i = 0; i + 1 < sLen; ++i){
            if(s[i] < s[indexOfSuffixMax[i + 1]]){
                swap(s[i], s[indexOfSuffixMax[i + 1]]);
                break;
            }
        }

        return stoi(s);
    }
};