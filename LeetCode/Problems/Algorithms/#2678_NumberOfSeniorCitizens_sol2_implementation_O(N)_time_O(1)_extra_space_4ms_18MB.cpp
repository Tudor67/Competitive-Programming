class Solution {
public:
    int countSeniors(vector<string>& details) {
        int seniors = 0;
        for(const string& S: details){
            int age = (S[11] - '0') * 10 + (S[12] - '0');
            if(age > 60){
                seniors += 1;
            }
        }
        return seniors;
    }
};