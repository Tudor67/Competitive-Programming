class Solution {
private:
    bool sameValues(vector<int>& arr, int l1, int r1, int l2, int r2){
        if(r1 >= l2){
            return false;
        }
        
        while(r1 - l1 < r2 - l2){
            if(arr[l2] == 0){
                l2 += 1;
            }else{
                return false;
            }
        }
        
        while(r1 - l1 > r2 - l2){
            if(arr[l1] == 0){
                l1 += 1;
            }else{
                return false;
            }
        }
        
        const int LEN = r1 - l1 + 1;
        for(int k = 0; k <= LEN - 1; ++k){
            if(arr[l1 + k] != arr[l2 + k]){
                return false;
            }
        }
        
        return true;
    }
    
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        const int N = arr.size();
        const int ONES = count(arr.begin(), arr.end(), 1);
        
        if(ONES == 0){
            return {0, N - 1};
        }else if(ONES % 3 == 0){
            // Split into [ left part | mid part | right part ] 
            // right part
            int r = N - 1;
            int rCountOnes = 0;
            int rSufZeros = 0;
            while(rCountOnes < ONES / 3){
                rCountOnes += arr[r];
                rSufZeros += (arr[r] == 0) * (rCountOnes == 0);
                r -= 1;
            }
            r += 1;
            
            const int NUM_LEN = N - r;
            
            // left part
            int l = 0;
            int lCountOnes = 0;
            while(l <= r - 2 && lCountOnes < ONES / 3){
                lCountOnes += arr[l];
                l += 1;
            }
            l += rSufZeros;
            l -= 1;
            
            if(sameValues(arr, 0, l, r, N - 1)){
                // mid part
                int mid = l + 1;
                while(mid <= r - 1 && arr[mid] == 0){
                    mid += 1;
                }
                if(sameValues(arr, mid, mid + NUM_LEN - 1, r, N - 1)){
                    return {l, mid + NUM_LEN};
                }
            }
        }
        
        return {-1, -1};
    }
};