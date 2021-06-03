class Solution {
private:
    bool sameValues(vector<int>& arr, int l1, int r1, int l2, int r2){
        const int N = arr.size();
        if(N < max(r1, r2)){
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
        for(int k = 0; k <= r1 - l1; ++k){
            if(arr[l1 + k] != arr[l2 + k]){
                return false;
            }
        }
        return true;
    }
    
    int countSuffixZeros(vector<int>& arr){
        const int N = arr.size();
        int sufZeros = 0;
        for(int i = N - 1; i >= 0; --i){
            if(arr[i] == 0){
                sufZeros += 1;
            }else{
                break;
            }
        }
        return sufZeros;
    }
    
    int getPosOfKthVal(vector<int>& arr, const int& K, const int& VAL){
        const int N = arr.size();
        int count = 0;
        for(int i = 0; i < arr.size(); ++i){
            count += (arr[i] == VAL);
            if(count == K){
                return i;
            }
        }
        return -1;
    }
    
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        const int N = arr.size();
        const int ONES = count(arr.begin(), arr.end(), 1);
        
        vector<int> answer = {-1, -1};
        
        if(ONES == 0){
            answer = {0, N - 1};
        }else if(ONES % 3 == 0){
            // Split into [ left part | mid part | right part ]
            const int SUFFIX_ZEROS = countSuffixZeros(arr);
            
            int lStart = 0;
            int lEnd = getPosOfKthVal(arr, ONES / 3, 1) + SUFFIX_ZEROS;
            int midStart = lEnd + 1;
            int midEnd = getPosOfKthVal(arr, 2 * ONES / 3, 1) + SUFFIX_ZEROS;
            int rStart = midEnd + 1;
            int rEnd = N - 1;
            
            if(sameValues(arr, lStart, lEnd, midStart, midEnd) && 
               sameValues(arr, midStart, midEnd, rStart, rEnd)){
                answer = {lEnd, rStart};
            }
        }
        
        return answer;
    }
};