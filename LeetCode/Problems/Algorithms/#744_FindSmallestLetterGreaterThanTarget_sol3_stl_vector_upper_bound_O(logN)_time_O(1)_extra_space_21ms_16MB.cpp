class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters.back() <= target){
            return letters.front();
        }
        return *upper_bound(letters.begin(), letters.end(), target);
    }
};