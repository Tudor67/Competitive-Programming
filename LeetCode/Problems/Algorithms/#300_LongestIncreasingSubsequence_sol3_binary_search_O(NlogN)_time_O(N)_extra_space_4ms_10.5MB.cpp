class Solution {
private:
    int myLowerBound(const vector<int>& V, const int& VAL){
        int l = 0;
        int r = V.size();
        while(l != r){
            int mid = (l + r) / 2;
            if(V[mid] < VAL){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for(int num: nums){
            int pos = myLowerBound(v, num);
            if(pos == (int)v.size()){
                v.push_back(num);
            }else{
                v[pos] = num;
            }
        }
        return (int)v.size();
    }
};