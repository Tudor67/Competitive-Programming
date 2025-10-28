class Solution {
private:
    bool isBeautiful(int num){
        vector<int> countOf(10);
        while(num > 0){
            countOf[num % 10] += 1;
            num /= 10;
        }

        for(int digit = 0; digit <= 9; ++digit){
            if(countOf[digit] != 0 && countOf[digit] != digit){
                return false;
            }
        }
        
        return true;
    }

public:
    int nextBeautifulNumber(int n) {
        for(int num = n + 1; num <= 1224444; ++num){
            if(isBeautiful(num)){
                return num;
            }
        }
        return -1;
    }
};