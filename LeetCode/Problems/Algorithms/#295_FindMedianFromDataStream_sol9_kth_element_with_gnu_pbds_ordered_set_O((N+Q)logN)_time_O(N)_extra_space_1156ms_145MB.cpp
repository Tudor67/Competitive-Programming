#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class MedianFinder {
private:
    ordered_set<pair<int, int>> orderedSet;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int numsSize = orderedSet.size();
        orderedSet.insert({num, numsSize});
    }
    
    double findMedian() {
        int numsSize = orderedSet.size();
        return (orderedSet.find_by_order((numsSize - 1) / 2)->first +
                orderedSet.find_by_order(numsSize / 2)->first) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */