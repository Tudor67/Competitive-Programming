class Solution {
private:
    const int BASE = 10;

    int getMappedDigit(int num, int pow10, vector<int>& mapping){
        if(num < pow10 && pow10 > 1){
            return 0;
        }
        return mapping[(num / pow10) % 10];
    }

    void countSort(vector<int>& nums, vector<int>& mapping, int lsd,
                   vector<int>& prevIndices, vector<int>& resIndices){
        const int N = nums.size();

        int pow10 = 1;
        for(int i = 1; i <= lsd; ++i){
            pow10 *= 10;
        }

        vector<int> prefCount(BASE);
        for(int num: nums){
            int mappedDigit = getMappedDigit(num, pow10, mapping);
            prefCount[mappedDigit] += 1;
        }

        for(int i = 1; i < BASE; ++i){
            prefCount[i] += prefCount[i - 1];
        }

        for(int i = N - 1; i >= 0; --i){
            int mappedDigit = getMappedDigit(nums[prevIndices[i]], pow10, mapping);
            prefCount[mappedDigit] -= 1;
            resIndices[prefCount[mappedDigit]] = prevIndices[i];
        }
    }

public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        const int N = nums.size();

        vector<int> prevIndices(N);
        vector<int> resIndices(N);
        iota(prevIndices.begin(), prevIndices.end(), 0);
        iota(resIndices.begin(), resIndices.end(), 0);

        for(int lsd = 0; lsd < 9; ++lsd){
            countSort(nums, mapping, lsd, prevIndices, resIndices);
            prevIndices = resIndices;
        }

        vector<int> res(N);
        for(int i = 0; i < N; ++i){
            res[i] = nums[resIndices[i]];
        }

        return res;
    }
};