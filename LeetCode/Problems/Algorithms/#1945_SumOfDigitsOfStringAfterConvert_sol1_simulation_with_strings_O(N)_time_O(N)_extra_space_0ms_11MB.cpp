class Solution {
public:
    int getLucky(string s, int k) {
        string resStr;
        for(char c: s){
            resStr += to_string(c - 'a' + 1);
        }

        for(int step = 1; step <= k && (int)resStr.length() >= 2; ++step){
            int sum = 0;
            for(char c: resStr){
                sum += (c - '0');
            }
            resStr = to_string(sum);
        }

        return stoi(resStr);
    }
};