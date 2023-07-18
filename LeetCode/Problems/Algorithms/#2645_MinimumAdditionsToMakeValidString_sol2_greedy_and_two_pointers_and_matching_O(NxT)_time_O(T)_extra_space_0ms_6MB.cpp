class Solution {
public:
    int addMinimum(string word) {
        const int N = word.length();
        const string TARGET = "abc";
        const int TARGET_LEN = TARGET.length();

        int res = 0;
        int targetIndex = 0;
        for(char c: word){
            while(c != TARGET[targetIndex]){
                targetIndex = (targetIndex + 1) % TARGET_LEN;
                res += 1;
            }
            targetIndex = (targetIndex + 1) % TARGET_LEN;
        }

        res += (TARGET_LEN - targetIndex) % TARGET_LEN;

        return res;
    }
};