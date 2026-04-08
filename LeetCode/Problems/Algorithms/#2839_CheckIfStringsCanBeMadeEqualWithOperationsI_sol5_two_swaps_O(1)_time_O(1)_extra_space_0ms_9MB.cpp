class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1[0] != s2[0]){
            swap(s1[0], s1[2]);
        }
        if(s1[1] != s2[1]){
            swap(s1[1], s1[3]);
        }
        return (s1 == s2);
    }
};