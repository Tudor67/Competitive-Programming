// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        // The main idea to generate something close to a uniform distribution:
        // r = (rand7() + rand7() + rand7() + rand7() + rand7())
        // r is a random number between 5 and 35
        // (r % 10) is a random digit in the range [0, 9],
        //          because each digit occurs 3 times except digit 5 (which occurs 4 times)
        // So, the probability of a generated digit is 3 / (35 - 5 + 1) = 3 / 31,
        //     except digit 5 which has a probability equal to 4 / 31
        // ---------------------------------------------------------------
        // |           |    |    |    |    |    |  5 |  6 |  7 |  8 |  9 |
        // |     r     | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 |
        // |           | 20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 |
        // |           | 30 | 31 | 32 | 33 | 34 | 35 |    |    |    |    |
        // |--------------------------------------------------------------
        // | (r % 10)  |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |
        // | frequency |  3 |  3 |  3 |  3 |  3 |  4 |  3 |  3 |  3 |  3 |
        // ---------------------------------------------------------------
        // 1 + (r % 10) is a random digit in the range [1, 10]
        
        int r = rand7() + rand7() + rand7() + rand7() + rand7();
        return 1 + (r % 10);
    }
};