class Solution {
public:
    string countAndSay(int n) {
        string currStr = "1";
        string nextStr;

        for(int step = 1; step <= n - 1; ++step){
            nextStr.clear();
            int cons = 0;
            for(int i = 0; i < (int)currStr.length(); ++i){
                cons += 1;
                if(i + 1 == (int)currStr.length() || currStr[i] != currStr[i + 1]){
                    nextStr += to_string(cons);
                    nextStr += currStr[i];
                    cons = 0;
                }
            }
            currStr.swap(nextStr);
        }

        return currStr;
    }
};