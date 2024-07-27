class Solution {
private:
    int mirror(int pref, int center){
        int res = pref;
        if(center >= 0){
            res = res * 10 + center;
        }
        while(pref > 0){
            res = res * 10 + (pref % 10);
            pref /= 10;
        }
        return res;
    }

    void generateSortedPalindromes(vector<int>& sortedPalindromes){
        sortedPalindromes.clear();
        for(int i = 1; i <= 9; ++i){
            sortedPalindromes.push_back(i);
        }

        for(int i = 1; i <= 9999; ++i){
            sortedPalindromes.push_back(mirror(i, -1));
            for(int center = 0; center <= 9; ++center){
                sortedPalindromes.push_back(mirror(i, center));
            }
        }

        sort(sortedPalindromes.begin(), sortedPalindromes.end());
    }

public:
    long long minimumCost(vector<int>& nums) {
        const int N = nums.size();
        const long long TOTAL_SUM = accumulate(nums.begin(), nums.end(), (long long)0);

        static vector<int> sortedPalindromes;
        if(sortedPalindromes.empty()){
            generateSortedPalindromes(sortedPalindromes);
        }

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        long long res = TOTAL_SUM;
        long long prefSum = 0;
        int i = 0;
        for(long long palindrome: sortedPalindromes){
            while(i < N && sortedNums[i] <= palindrome){
                prefSum += sortedNums[i];
                i += 1;
            }
            long long leftCost = palindrome * i - prefSum;
            long long rightCost = (TOTAL_SUM - prefSum) - palindrome * (N - i);
            res = min(res, leftCost + rightCost);
        }

        return res;
    }
};