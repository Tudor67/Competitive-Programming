# LeetCode
Profile: [Tudor67](https://leetcode.com/tudor67/)

## Posts
* Trie and Aho-Corasick
  - [1032. Stream of Characters](https://leetcode.com/problems/stream-of-characters/): [\[C++\] Trie and Aho-Corasick solutions](https://leetcode.com/problems/stream-of-characters/discuss/1611622/c-trie-and-aho-corasick-solutions)

* Binary search
  - [2071. Maximum Number of Tasks You Can Assign](https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/): [\[C++\] Binary search the answer](https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/discuss/1596318/c-binary-search-the-answer)

* Brain teaser
  - [1927. Sum Game](https://leetcode.com/problems/sum-game/): [\[C++\] Brain Teaser](https://leetcode.com/problems/sum-game/discuss/1572494/C%2B%2B-Brain-Teaser)

* Bottom-up dp
  - [96. Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/): [\[C++\] Bottom-Up DP & Catalan Numbers](https://leetcode.com/problems/unique-binary-search-trees/discuss/1566498/c-bottom-up-dp-catalan-numbers)

* Top-down dp
  - [980. Unique Paths III](https://leetcode.com/problems/unique-paths-iii/): [\[C++\] O(RC * 2^(RC)) Top-Down DP (Memoization)](https://leetcode.com/problems/unique-paths-iii/discuss/1555177/c-orc-2rc-top-down-dp-memoization)

* Analysis
  - [2589. Minimum Time to Complete All Tasks](https://leetcode.com/problems/minimum-time-to-complete-all-tasks/): [Small Test Case for Wrong Greedy Approach](https://leetcode.com/problems/minimum-time-to-complete-all-tasks/solutions/3454369/small-test-case-for-wrong-greedy-approach/)

## Notes
### Sorting
* [912. Sort an Array](https://leetcode.com/problems/sort-an-array/)
  * [LeetCode submission (heap sort)](https://leetcode.com/submissions/detail/732469924/)
  * [LeetCode submission (merge sort)](https://leetcode.com/submissions/detail/732480232/)
  * [LeetCode submission (quick sort with randomized pivot)](https://leetcode.com/submissions/detail/732493419/)
  * [LeetCode submission (count sort)](https://leetcode.com/submissions/detail/732498605/)
  
### Kth Order Statistic (nth_element)
* [324. Wiggle Sort II](https://leetcode.com/problems/wiggle-sort-ii/)
  * [LeetCode submission](https://leetcode.com/submissions/detail/771104059/)
  
### Binary Search
__*Unusual binary search problems*__
* [658. Find K Closest Elements (binary search, sliding window, heap, two pointers)](https://leetcode.com/problems/find-k-closest-elements/)
* [2071. Maximum Number of Tasks You Can Assign (binary search the answer, difficult greedy check function isValid)](https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/)
* [1923. Longest Common Subpath (binary search the answer, suffix array + lcp with kasai's algorithm, rolling hash)](https://leetcode.com/problems/longest-common-subpath/)
* [2141. Maximum Running Time of N Computers (binary search the answer)](https://leetcode.com/problems/maximum-running-time-of-n-computers/)

### Sliding Window
* [2106. Maximum Fruits Harvested After at Most K Steps](https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/)
  * [Leetcode submission (sliding window)](https://leetcode.com/submissions/detail/622778174/)
  * [Leetcode submission (binary search)](https://leetcode.com/submissions/detail/622762745/)
  
### Heaps
* [1834. Single-Threaded CPU](https://leetcode.com/problems/single-threaded-cpu/)
  * [Heap with lambda comparator]()
  * [Heap with struct comparator]()
  
* [1424. Diagonal Traverse II](https://leetcode.com/problems/diagonal-traverse-ii/)
  * [Heap with lambda comparator]()
  * [Heap with struct comparator]()
  * [Heap with compare method]()

### Strings
__*Palindromes*__
* [2967. Minimum Cost to Make Array Equalindromic](https://leetcode.com/problems/minimum-cost-to-make-array-equalindromic/description/)
  * [Sort + Prefix Sum + Generate All Palindromes](https://leetcode.com/problems/minimum-cost-to-make-array-equalindromic/submissions/1287475163/)
  * [Sort + Median Palindrome](https://leetcode.com/problems/minimum-cost-to-make-array-equalindromic/submissions/1334534162/)
* [564. Find the Closest Palindrome](https://leetcode.com/problems/find-the-closest-palindrome/description/)
  * [Strings](https://leetcode.com/problems/find-the-closest-palindrome/submissions/1366827900/)
  * [Binary Search](https://leetcode.com/problems/find-the-closest-palindrome/submissions/1367140057/)

__*Lexicographically minimal string rotation*__
* [899. Orderly Queue](https://leetcode.com/problems/orderly-queue/)
  * [O(NlogN) time, O(N) extra-space: Binary search + hashes + modular multiplicative inverse](https://github.com/Tudor67/Competitive-Programming/blob/master/LeetCode/Problems/Algorithms/%23899_OrderlyQueue_sol4_binary_search_and_hashing_O(NlogN)_time_O(N)_extra_space.cpp)
  * [O(N) time, O(N) extra-space: Duval's algorithm](https://github.com/Tudor67/Competitive-Programming/blob/master/LeetCode/Problems/Algorithms/%23899_OrderlyQueue_sol5_duval_algorithm_O(NlogN)_time_O(N)_extra_space.cpp)

__*Suffix array*__
* [1044. Longest Duplicate Substring](https://leetcode.com/problems/longest-duplicate-substring/):
  * [O(N(logN)^2) time, O(NlogN) extra-space: LCP](https://github.com/Tudor67/Competitive-Programming/tree/master/LeetCode/Problems/Algorithms#1044_LongestDuplicateSubstring_sol4_suffix_array_and_lcp_O(N(logN)^2)_time_O(NlogN)_extra_space_864ms_35MB.cpp)
  * [O(N(logN)^2) time, O(N) extra-space: LCP with Kasai's algorithm](https://github.com/Tudor67/Competitive-Programming/tree/master/LeetCode/Problems/Algorithms#1044_LongestDuplicateSubstring_sol5_suffix_array_and_lcp_with_kasai_algorithm_O(N(logN)^2)_time_O(N)_extra_space_768ms_18MB.cpp)
  * O(N(logN)^2) time, O(N) extra-space: LCP with Kasai's algorithm
    * [Leetcode submission 1](https://leetcode.com/submissions/detail/599425225/)
    * [Leetcode submission 2](https://leetcode.com/submissions/detail/599502373/)

__*Trie*__
* [1032. Stream of Characters](https://leetcode.com/problems/stream-of-characters/):
  * [Leetcode submission](https://leetcode.com/submissions/detail/596981365/)

__*Aho-Corasick*__
* [1032. Stream of Characters](https://leetcode.com/problems/stream-of-characters/):
  * [Leetcode submission](https://leetcode.com/submissions/detail/597320684/)
  
__*Manacher's Algorithm*__
* [2472. Maximum Number of Non-overlapping Palindrome Substrings](https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/description/)
  * [Leetcode submission](https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/submissions/855743355/)

### Range Queries
__*Merge Sort Tree*__
* [2080. Range Frequency Queries](https://leetcode.com/problems/range-frequency-queries/)
  * [Implementation with vector\<vector\<int\>\>](https://github.com/Tudor67/Competitive-Programming/tree/master/LeetCode/Problems/Algorithms#2080_RangeFrequencyQueries_sol4_merge_sort_tree_1741ms_382MB.cpp)
  * [Implementation with vector\<int\> and start indices](https://github.com/Tudor67/Competitive-Programming/tree/master/LeetCode/Problems/Algorithms#2080_RangeFrequencyQueries_sol5_merge_sort_tree_1672ms_285MB.cpp)
* [315. Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)
* [2250. Count Number of Rectangles Containing Each Point](https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/)
  * [Leetcode submission, TLE, Implementation with vector\<vector\<int\>\>](https://leetcode.com/submissions/detail/760001627/)

__*2D Queries*__
  * [2736. Maximum Sum Queries](https://leetcode.com/problems/maximum-sum-queries/)
    * [Implementation with Sweep Line + Segment Tree](https://github.com/Tudor67/Competitive-Programming/blob/master/LeetCode/Problems/Algorithms/%232736_MaximumSumQueries_sol1_sweep_line_and_segment_tree_O(NlogN%2BQlogQ%2BQlogN)_time_O(N%2BQ)_extra_space_389ms_188MB.cpp)

__*Dynamic Segment Tree*__
* [1348. Tweet Counts Per Frequency](https://leetcode.com/problems/tweet-counts-per-frequency/)
  * [Leetcode submission](https://leetcode.com/submissions/detail/624748522/)

__*Segment Tree with Lazy Propagation*__
* [218. The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/)
  * [Leetcode submission, Maximize Range, lazy vector and tree vector](https://leetcode.com/submissions/detail/813783931/)
  
__*Special Segment Tree to Maximize a Range*__
* [218. The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/)
  * [Leetcode submission, Maximize Range, only lazy vector](https://leetcode.com/submissions/detail/814180774/)
  
__*Monotonic Stack*__
* [84. Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)
  * [PrevSmaller and NextSmaller in O(N)](https://github.com/Tudor67/Competitive-Programming/tree/master/LeetCode/Problems/Algorithms#84_LargestRectangleInHistogram_sol4_monostack_O(N)_time_O(N)_extra_space_20ms_15.1MB.cpp)
* [1793. Maximum Score of a Good Subarray](https://leetcode.com/problems/maximum-score-of-a-good-subarray/)
  * [PrevSmaller and NextSmaller in O(N)](https://github.com/Tudor67/Competitive-Programming/blob/master/LeetCode/Problems/Algorithms/%231793_MaximumScoreOfAGoodSubarray_sol1_monotonic_stack_O(N)_time_O(N)_extra_space_553ms_101MB.cpp)

__*SQRT decomposition*__
* [307. Range Sum Query - Mutable (standard sqrt decomposition with updates on single elements, not ranges)](https://leetcode.com/problems/range-sum-query-mutable/)
  * [Leetcode submission](https://leetcode.com/submissions/detail/761489724/)
* [699. Falling Squares (sqrt decomposition with updates on ranges)](https://leetcode.com/problems/falling-squares/)

__*Mo's Algorithm*__
* [1630. Arithmetic Subarrays](https://leetcode.com/problems/arithmetic-subarrays/)
  * [Leetcode submission](https://leetcode.com/problems/arithmetic-subarrays/submissions/1105619572/)

__*Coordinate compression*__
* [699. Falling Squares (coordinate compression, segment tree with lazy propagation)](https://leetcode.com/problems/falling-squares/)
* [850. Rectangle Area II (line sweep, coordinate compression, segment tree)](https://leetcode.com/problems/rectangle-area-ii/)
* [1964. Find the Longest Valid Obstacle Course at Each Position (coordinate compression, segment tree)](https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/)
  * [Leetcode submission](https://leetcode.com/submissions/detail/621830593/)

__*Sparse Table*__
* [1483. Kth Ancestor of a Tree Node](https://leetcode.com/problems/kth-ancestor-of-a-tree-node/)
  * [Leetcode submission](https://leetcode.com/submissions/detail/620427452/)

### Subsequences
__*Longest Increasing Subsequence*__
* [300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)
* [1964. Find the Longest Valid Obstacle Course at Each Position](https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/)
  * [Leetcode submission (binary search implementation)](https://leetcode.com/submissions/detail/621849479/)
* [2111. Minimum Operations to Make the Array K-Increasing](https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/)
  * [Leetcode submission (binary search implementation)](https://leetcode.com/submissions/detail/622602059/)
* [1713. Minimum Operations to Make a Subsequence](https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/)
  * [Leetcode submission (segment tree)](https://leetcode.com/submissions/detail/623335835/)
  * [Leetcode submission (binary search)](https://leetcode.com/submissions/detail/623340907/)
  * [Leetcode submission (binary search)](https://leetcode.com/submissions/detail/623352595/)

### Greedy
__*Select most frequent elements*__
* [1753. Maximum Score From Removing Stones](https://leetcode.com/problems/maximum-score-from-removing-stones/)
  * [Sort frequencies](https://leetcode.com/problems/maximum-score-from-removing-stones/submissions/716809022/)
* [2856. Minimum Array Length After Pair Removals](https://leetcode.com/problems/minimum-array-length-after-pair-removals/)
  * [Max Heap, O(NlogN)](https://leetcode.com/problems/minimum-array-length-after-pair-removals/submissions/1192983137/)
  * [Find most frequent element, O(N)](https://leetcode.com/problems/minimum-array-length-after-pair-removals/submissions/1193012678/)
  
### DP
__*Dominos & Covering/Tiling & DP*__
* [790. Domino and Tromino Tiling](https://leetcode.com/problems/domino-and-tromino-tiling/)

__*Digits, Counting numbers less than something*__
* [600. Non-negative Integers without Consecutive Ones (dp on digits, fibonacci, bit manipulation)](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/)
* [1803. Count Pairs With XOR in a Range (bit manipulation, prefix counts, trie)](https://leetcode.com/problems/count-pairs-with-xor-in-a-range/)
* [1397. Find All Good Strings (string matching, dp on digits)](https://leetcode.com/problems/find-all-good-strings/)
* [2719. Count of Integers](https://leetcode.com/problems/count-of-integers/)
  * [Leetcode submission](https://leetcode.com/problems/count-of-integers/submissions/1115270373/)
* [2999. Count the Number of Powerful Integers](https://leetcode.com/problems/count-the-number-of-powerful-integers/)
  * [Leetcode submission](https://leetcode.com/problems/count-the-number-of-powerful-integers/submissions/1376980357/)
* [2801. Count Stepping Numbers in Range](https://leetcode.com/problems/count-stepping-numbers-in-range/)
  * [LeetCode submission](https://leetcode.com/problems/count-stepping-numbers-in-range/submissions/1161446979/)
* [2827. Number of Beautiful Integers in the Range](https://leetcode.com/problems/number-of-beautiful-integers-in-the-range/)
  * [LeetCode submission](https://leetcode.com/problems/number-of-beautiful-integers-in-the-range/submissions/1175478521/)

__*Nice DP problems*__
* [1463. Cherry Pickup II](https://leetcode.com/problems/cherry-pickup-ii/)
* [312. Burst Balloons](https://leetcode.com/problems/burst-balloons/)
* [600. Non-negative Integers without Consecutive Ones (dp on digits, fibonacci)](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/)
* [1494. Parallel Courses II (dp with submask enumeration or combinations)](https://leetcode.com/problems/parallel-courses-ii/)
* [805. Split Array With Same Average (knapsack + bitmasks)](https://leetcode.com/problems/split-array-with-same-average/)

__*Memoization*__
* [1659. Maximize Grid Happiness](https://leetcode.com/problems/maximize-grid-happiness/)
* [312. Burst Balloons](https://leetcode.com/problems/burst-balloons/)
* [698. Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/)
* [377. Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/)

### Graphs
* [1192. Critical Connections in a Network](https://leetcode.com/problems/critical-connections-in-a-network/)
  * [DFS solution](https://github.com/Tudor67/Competitive-Programming/blob/master/LeetCode/Problems/Algorithms/%231192_CriticalConnectionsInANetwork_sol1_dfs_O(E)_time_O(E)_extra_space_492ms_164.2MB.cpp)

__*Topological Sort*__
* [210. Course Schedule II](https://leetcode.com/problems/course-schedule-ii/)
  * [Topological sort with queue](https://github.com/Tudor67/Competitive-Programming/tree/master/LeetCode/Problems/Algorithms#210_CourseScheduleII_sol7_topological_sort_with_queue_O(V+E)_time_O(V+E)_extra_space_16ms_13.3MB.cpp)
  * [Topological sort with dfs](https://github.com/Tudor67/Competitive-Programming/tree/master/LeetCode/Problems/Algorithms#210_CourseScheduleII_sol8_topological_sort_with_dfs_O(V+E)_time_O(V+E)_extra_space_20ms_14.2MB.cpp)

__*Minimum Spanning Tree*__
* [1584. Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/)
  * [Kruskal's Algorithm](https://leetcode.com/submissions/detail/687818535/)
  * [Prim's Algorithm](https://leetcode.com/submissions/detail/687817611/)
  * [Prim's Algorithm for dense graphs](https://leetcode.com/submissions/detail/687828313/)
  
__*0-1 BFS (Dijkstra's algorithm in a binary weight graph)*__
* [1368. Minimum Cost to Make at Least One Valid Path in a Grid](https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/)
* [2290. Minimum Obstacle Removal to Reach Corner](https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/)
* [2812. Find the Safest Path in a Grid](https://leetcode.com/problems/find-the-safest-path-in-a-grid/)

__*Eulerian Path (Hierholzer's Algorithm)*__
* [332. Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/)
  * [Recursive DFS + STL list](https://github.com/Tudor67/Competitive-Programming/blob/master/LeetCode/Problems/Algorithms/%23332_ReconstructItinerary_sol4_eulerian_path_with_recursive_dfs_and_stl_list_O(LxTlogT)_time_O(LxT)_extra_space_17ms_15MB.cpp)
  * [Iterative DFS + STL list](https://github.com/Tudor67/Competitive-Programming/blob/master/LeetCode/Problems/Algorithms/%23332_ReconstructItinerary_sol5_eulerian_path_with_iterative_dfs_and_stl_list_O(LxTlogT)_time_O(LxT)_extra_space_24ms_15MB.cpp)
  * [Recursive DFS](https://github.com/Tudor67/Competitive-Programming/blob/master/LeetCode/Problems/Algorithms/%23332_ReconstructItinerary_sol6_eulerian_path_with_recursive_dfs_O(LxTlogT)_time_O(LxT)_extra_space_21ms_15MB.cpp)
  * [Iterative DFS](https://github.com/Tudor67/Competitive-Programming/blob/master/LeetCode/Problems/Algorithms/%23332_ReconstructItinerary_sol7_eulerian_path_with_iterative_dfs_O(LxTlogT)_time_O(LxT)_extra_space_26ms_15MB.cpp)

### Trees
__*Morris Inorder Traversal*__
* [98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)
  * [Leetcode submission](https://leetcode.com/submissions/detail/771007420/)

__*Iterative Postorder Traversal*__
* [2265. Count Nodes Equal to Average of Subtree](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/)
  * [Leetcode submission](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/submissions/1090094868/)
* [543. Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/description/)
  * [Leetcode submission](https://leetcode.com/problems/diameter-of-binary-tree/submissions/1187974625/)
* [1325. Delete Leaves With a Given Value](https://leetcode.com/problems/delete-leaves-with-a-given-value/description/)
  * [Leetcode submission](https://leetcode.com/problems/delete-leaves-with-a-given-value/submissions/1260607155/)
* [145. Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/description/)
  * [Iterative Postorder Traversal with `addLeftPath(..)`](https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/1368216520/)
  * [Iterative Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/1369236407/)
  * [Morris Reversed Preorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/1368236086/)
* [590. N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/)
  * [Iterative Reversed Preorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal/submissions/1369119590/)
  * [Iterative Postorder Traversal with `addLeftPath(..)`](https://leetcode.com/problems/n-ary-tree-postorder-traversal/submissions/1369164749/)
  * [Iterative Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal/submissions/1369206795/)

__*LCA*__
* [2846. Minimum Edge Weight Equilibrium Queries in a Tree](https://leetcode.com/problems/minimum-edge-weight-equilibrium-queries-in-a-tree/description/)
  * [Counter + LCA + Euler Tour + Segment Tree](https://leetcode.com/problems/minimum-edge-weight-equilibrium-queries-in-a-tree/submissions/1188074810/)
  * [Counter + LCA + Binary Lifting + Sparse Table](https://leetcode.com/problems/minimum-edge-weight-equilibrium-queries-in-a-tree/submissions/1188103242/)
  * [Counter + LCA + Tarjan's Offline Algorithm + DSU](https://leetcode.com/problems/minimum-edge-weight-equilibrium-queries-in-a-tree/submissions/1188149919/)
  
__*Nice Tree Problems*__
* [2791. Count Paths That Can Form a Palindrome in a Tree](https://leetcode.com/problems/count-paths-that-can-form-a-palindrome-in-a-tree/)
  * [LeetCode submission](https://leetcode.com/problems/count-paths-that-can-form-a-palindrome-in-a-tree/submissions/1161300986/)
  
__*Re-rooting*__
* [2858. Minimum Edge Reversals So Every Node Is Reachable](https://leetcode.com/problems/minimum-edge-reversals-so-every-node-is-reachable/)
  * [Re-Rooting with DFS](https://leetcode.com/problems/minimum-edge-reversals-so-every-node-is-reachable/submissions/1194022663/)
  * [Re-Rooting with BFS](https://leetcode.com/problems/minimum-edge-reversals-so-every-node-is-reachable/submissions/1194040359/)
* [310. Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/description/)
  * [Re-Rooting](https://leetcode.com/problems/minimum-height-trees/submissions/1240227399/)
* [834. Sum of Distances in Tree](https://leetcode.com/problems/sum-of-distances-in-tree/description/)
  * [Re-Rooting](https://leetcode.com/problems/sum-of-distances-in-tree/submissions/1244452654/)
  
### Nice implementation problems
* [715. Range Module (ranges, segments, intersection + merge + split operations)](https://leetcode.com/problems/range-module/)
* [2056. Number of Valid Move Combinations On Chessboard (implementation + simulation + backtracking, difficult to digest the problem statement)](https://leetcode.com/problems/number-of-valid-move-combinations-on-chessboard/)

### Geometry
__*Check intersection of two segments (handle collinearity)*__
* [335. Self Crossing](https://leetcode.com/problems/self-crossing/)
  * [LeetCode submission](https://leetcode.com/submissions/detail/773672945/)
  
### Math
__*Inclusion-Exclusion Principle*__
* [2929. Distribute Candies Among Children II](https://leetcode.com/problems/distribute-candies-among-children-ii/description/)
  * [Leetcode submission](https://leetcode.com/problems/distribute-candies-among-children-ii/submissions/1224312563/)
* [2930. Number of Strings Which Can Be Rearranged to Contain Substring](https://leetcode.com/problems/number-of-strings-which-can-be-rearranged-to-contain-substring/description/)
  * [Leetcode submission](https://leetcode.com/problems/number-of-strings-which-can-be-rearranged-to-contain-substring/submissions/1227043176/)

__*Combinations with repetition*__
* [1641. Count Sorted Vowel Strings](https://leetcode.com/problems/count-sorted-vowel-strings/)

__*Permutations with repetition*__
* [1467. Probability of a Two Boxes Having The Same Number of Distinct Balls](https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/)

__*Transformation matrices*__
* [1680. Concatenation of Consecutive Binary Numbers](https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/)
  * [Leetcode submission](https://leetcode.com/submissions/detail/448688529/)

__*Matrix binary exponentiation*__
* [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
* [1680. Concatenation of Consecutive Binary Numbers](https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/)
  * [Leetcode submission](https://leetcode.com/submissions/detail/448688529/)

__*Sieve of Eratosthenes*__  
Nice explanation at https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html
* [204. Count Primes](https://leetcode.com/problems/count-primes/)
  * O(Nlog(log(N))) time, O(N) extra-space, standard implementation
  * O(Nlog(log(sqrt(N)) time, O(N) extra-space, implementation with optimizations
  * O(Nlog(log(sqrt(N)) time, O(sqrt(N)) extra-space, segmented sieve, implementation with sqrt blocks
  * O(N) time, O(N) extra-space, implementation with factorization of all numbers

__*Prime numbers*__  
[Prime gap](https://en.wikipedia.org/wiki/Prime_gap):
Difference between two successive prime numbers is relatively small (compared to their values)
  
[The sum of the reciprocals of the primes](https://en.wikipedia.org/wiki/Divergence_of_the_sum_of_the_reciprocals_of_the_primes):
1/p1 + 1/p2 + 1/p3 + ... + 1/pk ~ log(log(N)), where pk is the closest prime <= N and [p1, p2, p3, ... , pk] are the first k primes [2, 3, 5, ... , pk]
  
[Prime-counting function](https://en.wikipedia.org/wiki/Prime-counting_function):
The number of prime numbers less or equal to N, denoted by pi(N):
pi(N) ~ N / ln(N), when N increases the error decreases (i.e., the aproximation is better for large values of N)

[Prime number theorem](https://en.wikipedia.org/wiki/Prime_number_theorem):
The mth prime prime number pm ~ mlog(m)

[Prime Sums](https://mathworld.wolfram.com/PrimeSums.html):
The sum of the first M primes: p1 + p2 + p3 + ... + pM ~ (1/2) * M^2 * ln(M)
The sum of the primes less or equal to N: p1 + p2 + p3 + ... + pk ~ (1/2) * N^2 * (1/ln(N)), where pk <= N

## Questions related to Time/Space complexity
* [38. Count and Say: O(2^N) time? because the length at each step can grow twice (in worst case)?]()
* [39. Combination Sum]()
* [1367. Linked List in Binary Tree]()
* [397. Integer Replacement: O(logN)?]()
* [756. Pyramid Transition Matrix]()
  - A is alphabet size, N is bottom.length()
  - without caching: Time O(NA^(N^2)) or O(A^(N^2)), Space O(N^3) or O(N^2) depending on implementation (with/without global variables)
  - with caching:    Time O(NA^N), Space O(N(N+A^N))
  - look at my implementations (I use strings, not bit masks)
* [1562. Find Latest Group of Size M]()
   - Time complexity of recursive approach
* [95. Unique Binary Search Trees II]()
   - Time and space complexity (sum of catalan numbers? for space, should we multiply with n = number of nodes in a tree?)

## Bugs, Warnings and implementation problems
__*Warning (11-Dec-2023) for my old implementations of: Segment Tree with Lazy Propagation*__
  * Possible bug in implementation of `propagate(node)`:
    * `if(2 * node < (int)lazy.size())` and `if(2 * node < (int)tree.size())` are bad;
	* use `if(l != r)` instead (to check if the current node is a leaf, l and r represent the limits of the current range).