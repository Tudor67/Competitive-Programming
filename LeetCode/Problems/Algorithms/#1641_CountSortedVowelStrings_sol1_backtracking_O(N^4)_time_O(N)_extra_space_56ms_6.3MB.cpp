class Solution {
private:
    void back(int n, int idx, int& count){
        if(n == 0){
            count += 1;
        }else{
            for(int i = idx; i < 5; ++i){
                back(n - 1, i, count);
            }
        }
    }
    
public:
    int countVowelStrings(int n) {
        int count = 0;
        back(n, 0, count);
        return count;
    }
};