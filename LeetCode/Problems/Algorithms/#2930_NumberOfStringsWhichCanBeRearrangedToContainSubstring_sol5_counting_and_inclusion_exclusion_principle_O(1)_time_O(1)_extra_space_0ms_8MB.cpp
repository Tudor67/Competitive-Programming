class Solution {
private:
    long long fastPow(long long a, long long n, const long long MODULO){
        long long res = 1;
        while(n > 0){
            if(n & 1){
                res = (res * a) % MODULO;
            }
            a = (a * a) % MODULO;
            n >>= 1;
        }
        return res;
    }

public:
    int stringCount(int N) {
        const long long MODULO = 1e9 + 7;
        long long totalCount = fastPow(26, N, MODULO);
        long long badCount = (3 * fastPow(25, N, MODULO) + N * fastPow(25, N - 1, MODULO)
                              - 3 * fastPow(24, N, MODULO) - 2 * N * fastPow(24, N - 1, MODULO)
                              + fastPow(23, N, MODULO) + N * fastPow(23, N - 1, MODULO)) % MODULO;
        return (totalCount - badCount + MODULO) % MODULO;
    }
};

/*
Notation:
N = s.length();
A = 26 (the alphabet size, i.e., the number of lowercase English characters);
#GoodStringsCount = the number of good strings of length N;
#BadStringsCount = the number of bad strings of length N;
#TotalStringsCount = the total number of strings of length N;

#GoodStringsCount + #BadStringsCount = #TotalStringsCount
#GoodStringsCount = #TotalStringsCount - #BadStringsCount

#TotalStringsCount = 26 * 26 * ... * 26 = 26 ^ N;
#BadStringsCount = |{strings with eCount <= 1} U {strings with lCount == 0} U {strings with tCount == 0}|;

Inclusion - Exclusion Principle
Let's simplify the notations:
A = {strings with eCount <= 1};
B = {strings with lCount == 0};
C = {strings with tCount == 0};
So, #BadStringsCount = |A U B U C|;

Using inclusion-exclusion principle, we can compute the number of bad strings in the following way:
#BadStringsCount = |A U B U C| = |A| + |B| + |C| - |A & B| - |A & C| - |B & C| + |A & B & C|;

|A| = |{strings with eCount <= 1}|
    = |{strings with eCount == 0}| + |{strings with eCount == 1}|
    = 25 ^ N + N * 25 ^ (N - 1);
    (total number of strings without character 'e' <=> alphabet size = A - 1 = 26 - 1 = 25
     and
     total number of strings when we use only one `e` and put it at position 1 or position 2 or ... position N)

|B| = |{strings with lCount == 0}|
    = 25 ^ N; (total number of strings without character 'l' <=> alphabet size = A - 1 = 26 - 1 = 25)

|C| = |{strings with tCount == 0}|
    = 25 ^ N; (total number of strings without character 't' <=> alphabet size = A - 1 = 26 - 1 = 25)

|A & B| = 24 ^ N + N * 24 ^ (N - 1); (the same idea as |A| but without character 'l')

|A & C| = 24 ^ N + N * 24 ^ (N - 1); (the same idea as |A| but without character 't')

|B & C| = 24 ^ N; (total number of strings without characters {'l', 't'} <=> alphabet size = A - 2 = 26 - 2 = 24)

|A & B & C| = 23 ^ N + N * 23 ^ (N - 1);

So, #BadStringsCount = |A| + |B| + |C|
                     - |A & B| - |A & C| - |B & C|
                     + |A & B & C|
                     
                     = 25 ^ N + N * 25 ^ (N - 1) + 25 ^ N + 25 ^ N
                     - 24 ^ N - N * 24 ^ (N - 1) - 24 ^ N - N * 24 ^ (N - 1) - 24 ^ N
                     + 23 ^ N + N * 23 ^ (N - 1)

                     = 3 * 25 ^ N + N * 25 ^ (N - 1)
                     - 3 * 24 ^ N - 2 * N * 24 ^ (N - 1)
                     + 23 ^ N + N * 23 ^ (N - 1).
*/