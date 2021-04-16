/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        const int N = mountainArr.length();
        
        // binary search on A[0] < A[1] < ... < A[i - 1] < A[i]
        int l = 0;
        int r = N - 1;
        while(l != r){
            int mid = (l + r) / 2;
            int midVal = mountainArr.get(mid);
            int nextMidVal = mountainArr.get(mid + 1);
            if(midVal < nextMidVal){
                if(midVal < target){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }else{
                r = mid;
            }
        }
        int pos1 = r;
        
        // binary search on A[i] > A[i + 1] > ... > A[A.length() - 1]
        l = 0;
        r = N - 1;
        while(l != r){
            int mid = (l + r + 1) / 2;
            int prevMidVal = mountainArr.get(mid - 1);
            int midVal = mountainArr.get(mid);
            if(prevMidVal < midVal){
                l = mid;
            }else{
                if(target > midVal){
                    r = mid - 1;
                }else{
                    l = mid;
                }
            }
        }
        int pos2 = r;
        
        // update answer
        int answer = -1;
        if(mountainArr.get(pos1) == target){
            answer = pos1;
        }else if(mountainArr.get(pos2) == target){
            answer = pos2;
        }
        
        return answer;
    }
};