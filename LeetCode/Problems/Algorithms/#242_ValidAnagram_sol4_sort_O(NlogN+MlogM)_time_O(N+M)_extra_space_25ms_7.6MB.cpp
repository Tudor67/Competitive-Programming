class Solution {
public:
    bool isAnagram(string s, string t) {
        string sortedS(s);
        string sortedT(t);
        
        sort(sortedS.begin(), sortedS.end());
        sort(sortedT.begin(), sortedT.end());
        
        return (sortedS == sortedT);
    }
};