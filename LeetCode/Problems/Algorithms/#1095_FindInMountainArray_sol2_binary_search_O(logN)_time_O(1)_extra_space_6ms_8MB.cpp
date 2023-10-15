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
    int findInMountainArray(int target, MountainArray& mountainArr) {
        const int N = mountainArr.length();

        // Binary Search on increasing part
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

        if(mountainArr.get(r) == target){
            return r;
        }

        // Binary Search on decreasing part
        l = 0;
        r = N - 1;
        while(l != r){
            int mid = (l + r) / 2;
            int midVal = mountainArr.get(mid);
            int nextMidVal = mountainArr.get(mid + 1);
            if(midVal < nextMidVal){
                l = mid + 1;
            }else{
                if(midVal > target){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }
        }

        if(mountainArr.get(r) == target){
            return r;
        }

        return -1;
    }
};