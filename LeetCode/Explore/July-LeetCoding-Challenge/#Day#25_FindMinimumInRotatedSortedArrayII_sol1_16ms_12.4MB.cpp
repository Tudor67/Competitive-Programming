class Solution {
private:
    int binary_search_min(const vector<int>& NUMS, const int& L, const int& R){
        int l = L;
        int r = R;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(NUMS[l] <= NUMS[mid]){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        int idx = r + 1;
        if(idx > R){
            idx = L;
        }
        return NUMS[idx];
    }
    
    int search_min(const vector<int>& NUMS, const int& L, const int& R, bool& search){
        if(!search){
            return INT_MAX;
        }
        
        if(L > R){
            return INT_MAX;
        }
        
        if(L == R){
            return NUMS[R];
        }
        
        if(NUMS[L] == NUMS[R]){
            return min(search_min(NUMS, L, (L + R) / 2, search),
                       search_min(NUMS, (L + R) / 2 + 1, R, search));
        }
        
        search = false;
        int min1 = binary_search_min(NUMS, 0, L);
        int min2 = binary_search_min(NUMS, L, R);
        int min3 = binary_search_min(NUMS, R, (int)NUMS.size() - 1);
        return min({min1, min2, min3});
    }
    
public:
    int findMin(vector<int>& nums) {
        bool search = true;
        return search_min(nums, 0, (int)nums.size() - 1, search);
    }
};