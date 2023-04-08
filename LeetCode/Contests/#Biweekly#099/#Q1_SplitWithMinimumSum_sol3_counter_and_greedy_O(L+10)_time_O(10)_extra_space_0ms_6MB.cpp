class Solution {
public:
    int splitNum(int num) {
        vector<int> count(10);
        while(num > 0){
            count[num % 10] += 1;
            num /= 10;
        }

        vector<int> newNums(2);
        int index = 0;
        for(int digit = 1; digit <= 9; ++digit){
            while(count[digit] >= 1){
                newNums[index] = newNums[index] * 10 + digit;
                index ^= 1;
                count[digit] -= 1;
            }
        }

        return newNums[0] + newNums[1];
    }
};