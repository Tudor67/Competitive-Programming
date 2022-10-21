class Solution {
public:
    string countAndSay(int n) {
        string prevStr = "1";
        string str = "1";
        
        for(int i = 2; i <= n; ++i){
            str.clear();
            int count = 0;
            for(int j = 0; j < (int)prevStr.length(); ++j){
                count += 1;
                if(j == (int)prevStr.length() - 1 || prevStr[j] != prevStr[j + 1]){
                    str += to_string(count);
                    str += prevStr[j];
                    count = 0;
                }
            }
            prevStr = str;
        }
        
        return str;
    }
};