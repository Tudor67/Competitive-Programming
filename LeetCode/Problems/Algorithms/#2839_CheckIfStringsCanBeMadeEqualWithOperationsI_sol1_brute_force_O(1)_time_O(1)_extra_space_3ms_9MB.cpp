class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int mask = 0; mask <= 3; ++mask){
            string str = s1;
            if((mask >> 0) & 1){
                swap(str[0], str[2]);
            }
            if((mask >> 1) & 1){
                swap(str[1], str[3]);
            }
            if(str == s2){
                return true;
            }
        }
        return false;
    }
};