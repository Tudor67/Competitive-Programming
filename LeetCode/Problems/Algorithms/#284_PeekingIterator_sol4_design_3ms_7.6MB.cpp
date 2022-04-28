/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *      struct Data;
 *      Data* data;
 *  public:
 *      Iterator(const vector<int>& nums);
 *      Iterator(const Iterator& iter);
 *
 *      // Returns the next element in the iteration.
 *      int next();
 *
 *      // Returns true if the iteration has more elements.
 *      bool hasNext() const;
 *  };
 */

class PeekingIterator : public Iterator {
private:
    vector<int> cache;
    
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        cache.resize(1);
        cache[0] = Iterator::next();
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return cache[0];
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int temp = cache[0];
        if(Iterator::hasNext()){
            cache[0] = Iterator::next();
        }else{
            cache.clear();
        }
        return temp;
    }
    
    bool hasNext() const {
        return !cache.empty();
    }
};