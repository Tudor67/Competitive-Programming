class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        const int R = ransomNote.length();
        const int M = magazine.length();
        
        string sortedRansomNote = ransomNote;
        string sortedMagazine = magazine;
        
        sort(sortedRansomNote.begin(), sortedRansomNote.end());
        sort(sortedMagazine.begin(), sortedMagazine.end());
        
        int i = 0;
        for(int j = 0; j < M; ++j){
            if(i < R && sortedRansomNote[i] == sortedMagazine[j]){
                i += 1;
            }
        }
        
        return (i == R);
    }
};