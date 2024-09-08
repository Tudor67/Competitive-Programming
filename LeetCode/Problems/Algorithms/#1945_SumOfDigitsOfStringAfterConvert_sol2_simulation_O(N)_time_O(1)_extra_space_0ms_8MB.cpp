class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for(char c: s){
            int index = c - 'a' + 1;
            sum += (index / 10) + (index % 10);
        }

        for(int step = 2; step <= k && sum >= 10; ++step){
            int nextSum = 0;
            for(int x = sum; x > 0; x /= 10){
                nextSum += (x % 10);
            }
            sum = nextSum;
        }

        return sum;
    }
};