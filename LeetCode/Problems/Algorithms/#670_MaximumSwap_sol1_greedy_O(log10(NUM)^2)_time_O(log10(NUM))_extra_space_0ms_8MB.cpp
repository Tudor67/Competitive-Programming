class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int sLen = s.length();

        for(int i = 0; i < sLen; ++i){
            int indexToSwap = i;
            for(int j = i + 1; j < sLen; ++j){
                if(s[indexToSwap] <= s[j]){
                    indexToSwap = j;
                }
            }

            if(s[i] < s[indexToSwap]){
                swap(s[i], s[indexToSwap]);
                break;
            }
        }

        return stoi(s);
    }
};