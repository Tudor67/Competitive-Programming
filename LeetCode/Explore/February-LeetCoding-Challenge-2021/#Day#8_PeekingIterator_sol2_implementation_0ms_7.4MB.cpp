/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *      struct Data;
 *      Data* data;
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
    bool advance;
    int nextElem;
    
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        this->advance = true;
        this->nextElem = 0;
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if(advance){
            nextElem = Iterator::next();
            advance = false;
        }
        return nextElem;
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if(advance){
            nextElem = Iterator::next();
        }
        advance = true;
        return nextElem;
    }
    
    bool hasNext() const {
        return (!advance || Iterator::hasNext());
    }
};