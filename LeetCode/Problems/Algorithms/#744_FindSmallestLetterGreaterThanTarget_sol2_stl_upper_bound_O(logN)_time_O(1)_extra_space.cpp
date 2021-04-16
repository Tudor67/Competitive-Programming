class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters.back() <= target){
            return letters.front();
        }
        vector<char>::iterator it = upper_bound(letters.begin(), letters.end(), target);
        return *it;
    }
};