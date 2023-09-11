class Solution {
public:
    int countSeniors(vector<string>& details) {
        int oldCount = 0;
        for(string& s: details){
            int age = (s[11] - '0') * 10 + (s[12] - '0');
            oldCount += (int)(age > 60);
        }
        return oldCount;
    }
};