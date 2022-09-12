class Solution {
public:
    int minMoves(vector<int>& nums) {
        const long long N = nums.size();
        long long minNum = *min_element(nums.begin(), nums.end());
        long long initialSum = accumulate(nums.begin(), nums.end(), 0LL);
        return initialSum - minNum * N;
    }
};

/*
Let's assume that the answer of the problem is x.
After x moves all nums will be equal.

After x moves all elements will be equal to (minNum + x).
Why (minNum + x)? Because minNum is always included in a move/operation.
At each move we fix the current max num and increase the remaining (N - 1) nums.

After x moves the sum of all nums will be: (minNum + x) * N.
After x moves the sum of all nums will be: initialSum + x * (N - 1).

(minNum + x) * N == initialSum + x * (N - 1);
minNum * N + x * N == initialSum + x * N - x;
x == initialSum - minNum * N;
*/