class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        const int N = g.size();
        const int M = s.size();

        int res = 0;
        multiset<int> sMultiset(s.begin(), s.end());

        for(int greedFactor: g){
            multiset<int>::iterator it = sMultiset.lower_bound(greedFactor);
            if(it != sMultiset.end()){
                sMultiset.erase(it);
                res += 1;
            }
        }

        return res;
    }
};