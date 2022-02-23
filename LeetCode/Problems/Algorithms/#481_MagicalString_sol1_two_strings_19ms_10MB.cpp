class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        string nextS;
        while((int)s.length() < n){
            int num = 1;
            nextS.clear();
            for(char c: s){
                nextS.append(c - '0', char('0' + num));
                num = 3 - num;
            }
            s = nextS;
        }
        return count(s.begin(), s.begin() + n, '1');
    }
};