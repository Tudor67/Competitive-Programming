class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters.back() <= target){
            return letters[0];
        }
        return *upper_bound(letters.begin(), letters.end(), target);
    }
};