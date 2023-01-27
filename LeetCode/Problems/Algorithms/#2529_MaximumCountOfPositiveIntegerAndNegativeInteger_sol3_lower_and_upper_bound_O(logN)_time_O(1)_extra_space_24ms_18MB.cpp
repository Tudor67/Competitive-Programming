class Solution {
private:
    int lowerBound(vector<int>& v, const int& VAL){
        const int N = v.size();
        int l = 0;
        int r = N;
        while(l != r){
            int mid = (l + r) / 2;
            if(v[mid] < VAL){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }

    int upperBound(vector<int>& v, const int& VAL){
        const int N = v.size();
        int l = 0;
        int r = N;
        while(l != r){
            int mid = (l + r) / 2;
            if(v[mid] <= VAL){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }

public:
    int maximumCount(vector<int>& nums) {
        const int N = nums.size();
        int pos = lowerBound(nums, 0);
        int neg = N - upperBound(nums, 0);
        return max(pos, neg);
    }
};