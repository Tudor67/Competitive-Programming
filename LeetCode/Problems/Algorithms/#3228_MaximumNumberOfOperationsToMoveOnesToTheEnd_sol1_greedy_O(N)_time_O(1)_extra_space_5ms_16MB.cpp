class Solution {
public:
    int maxOperations(string s) {
        const int N = s.length();

        int totalOps = 0;

        int i = N - 1;
        int rightGroups1 = (s.back() == '0' ? 1 : 0);
        while(i >= 0){
            while(i >= 0 && s[i] == '0'){
                i -= 1;
            }
            while(i >= 0 && s[i] == '1'){
                totalOps += rightGroups1;
                i -= 1;
            }
            rightGroups1 += 1;
        }

        return totalOps;
    }
};