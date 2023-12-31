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
  
### DP
__*Dominos & Covering/Tiling & DP*__
* [790. Domino and Tromino Tiling](https://leetcode.com/problems/domino-and-tromino-tiling/)

__*Digits, Counting numbers less than something*__
* [600. Non-negative Integers without Consecutive Ones (dp on digits, fibonacci, bit manipulation)](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/)
* [1803. Count Pairs With XOR in a Range (bit manipulation, prefix counts, trie)](https://leetcode.com/problems/count-pairs-with-xor-in-a-range/)
* [1397. Find All Good Strings (string matching, dp on digits)](https://leetcode.com/problems/find-all-good-strings/)
* [2719. Count of Integers](https://leetcode.com/problems/count-of-integers/)
  * [Leetcode submission](https://leetcode.com/problems/count-of-integers/submissions/1115270373/)

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

### Math
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

### Geometry
__*Check intersection of two segments (handle collinearity)*__
* [335. Self Crossing](https://leetcode.com/problems/self-crossing/)
  * [LeetCode submission](https://leetcode.com/submissions/detail/773672945/)

### Nice implementation problems
* [715. Range Module (ranges, segments, intersection + merge + split operations)](https://leetcode.com/problems/range-module/)
* [2056. Number of Valid Move Combinations On Chessboard (implementation + simulation + backtracking, difficult to digest the problem statement)](https://leetcode.com/problems/number-of-valid-move-combinations-on-chessboard/)

## Problems with many solutions
* [1658. Minimum Operations to Reduce X to Zero]()
* [1723. Find Minimum Time to Finish All Jobs]()
* [1655. Distribute Repeating Integers]()
* [1631. Path With Minimum Effort (binary search the answer, dsu, dijkstra)]()
* [1675. Minimize Deviation in Array (sliding window, max heap)]()
* [1337. The K Weakest Rows in a Matrix (max heap, nth_element + sort, binary search, buckets)]()]()
* [856. Score of Parentheses (stack, recursion, strings, math)]()
* [581. Shortest Unsorted Continuous Subarray (sort, stack, two pointers approach)]()
* [645. Set Mismatch (sort, hash, int sign as visited mark, math, bit manipulation)]()
* [160. Intersection of Two Linked Lists (int sign as visited mark, two pointers, hash)]()
* [475. Heaters (binary search the answer, lower bound, two pointers)]()
* [718. Maximum Length of Repeated Subarray (dp, binary search, rolling hash, sliding window)]()
* [376. Wiggle Subsequence (dp, segment tree, greedy)]()
* [1562. Find Latest Group of Size M (dsu, stl set upper_bound, propagate segment length to segment end points, sliding window, divide and conquer)]()
* [923. 3Sum With Multiplicity (sort, two pointers, combinatorics, counting, dp)]()
* [1526. Minimum Number of Increments on Subarrays to Form a Target Array (rmq, segment tree, two pointers, observation)]()
* [1687. Delivering Boxes from Storage to Ports (DP, binary search, sliding window)]()
* [850. Rectangle Area II (line sweep, coordinate compression, segment tree)]()
* [391. Perfect Rectangle (line sweep, coordinate compression, xor, segment tree with lazy propagation)]()
* [128. Longest Consecutive Sequence (dsu, memoization, hash table)]()
* [1871. Jump Game VII (dp, queue, two pointers, difference arrays, segment tree)]()
* [1856. Maximum Subarray Min-Product (sort + dsu, max heap, monotonic stack, recursion + segment tree + prefix sum) => similar to largest rectangle in histogram]()
* [658. Find K Closest Elements (binary search, sliding window, heap, two pointers)]()
* [926. Flip String to Monotone Increasing (dp, smart dp, prefix suffix)]()
* [1349. Maximum Students Taking Exam (backtracking, memoization, graphs + greedy, bipartite matching, max flow)]()
* [978. Longest Turbulent Subarray (sliding window, two pointers, dp)]()
* [2002. Maximum Product of the Length of Two Palindromic Subsequences (bit manipulation, submask enumeration, dp, O(4^N) -> O(3^N) -> O(2^N))]()
* [75. Sort Colors (count sort, two pointers, shift trick)]()
* [1923. Longest Common Subpath (binary search the answer, rolling hash, suffix array + lcp with kasai's algorithm, sliding window, monodeque)](https://leetcode.com/problems/longest-common-subpath/)
* [973. K Closest Points to Origin (sort, nth_element, heap, randomized quick select, binary search)](https://leetcode.com/problems/k-closest-points-to-origin/)
* [1508. Range Sum of Sorted Subarray Sums (sort, nth_element, min heap, counter, binary search + sliding window)](https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/)
* [84. Largest Rectangle in Histogram (monostack, segment tree, binary search, divide and conquer)](https://leetcode.com/problems/largest-rectangle-in-histogram/)
* [135. Candy (greedy, sort, count sort, topological sort, left to right and right to left iterations)](https://leetcode.com/problems/candy/)

## Very difficult problems
* [1659. Maximize Grid Happiness]()
* [312. Burst Balloons]()
* [887. Super Egg Drop (memoization + binary search)]()
* [546. Remove Boxes (dp, memoization)]()
* [1787. Make the XOR of All Segments Equal to Zero (dp, bit manipulation, property of xor for sliding window)]()
* [1815. Maximum Number of Groups Getting Fresh Donuts (greedy + dp, memoization, bit manipulation)]()
* [1397. Find All Good Strings (string matching, dp on digits)]()
* [1531. String Compression II (dp)](https://leetcode.com/problems/string-compression-ii/)

## Nice problems
* [910. Smallest Range II (prefix-suffix trick)]()
* [1673. Find the Most Competitive Subsequence (heap, monoque)]()
* [895. Maximum Frequency Stack (stacks)]()
* [1157. Online Majority Element In Subarray (segment tree, binary search, Boyer–Moore majority vote algorithm)]()
* [630. Course Schedule III (greedy + dp + max heap)]()
* [777. Swap Adjacent in LR String (set of positions, three pointers, two pointers and prefix/suffix count)]()
* [850. Rectangle Area II (line sweep, coordinate compression, segment tree)]()
* [391. Perfect Rectangle (line sweep, coordinate compression, xor, segment tree with lazy propagation)]()
* [932. Beautiful Array (divide and conquer)]()
* [330. Patching Array (greedy, brain teaser)]()
* [779. K-th Symbol in Grammar (recursion, brain teaser)]()
* [834. Sum of Distances in Tree (2 dfs, euler tour, memoization)]()
* [214. Shortest Palindrome (string matching, palindromes)]()
* [1977. Number of Ways to Separate Numbers (dp, suffix array, lcp, smart <= compare of two substrings)]()

## Nice people on LeetCode
* https://leetcode.com/Bakerston/
* https://leetcode.com/lzl124631x/
* https://leetcode.com/DBabichev/
* https://leetcode.com/rowe1227/
* https://leetcode.com/lee215/
* https://leetcode.com/votrubac/
* https://leetcode.com/archit91/
* https://leetcode.com/ye15/
* https://leetcode.com/steiner/
* https://leetcode.com/Roka/
* https://leetcode.com/hobiter/
* https://leetcode.com/karutz/
* https://leetcode.com/rock/
* https://leetcode.com/wangzi6147/

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
