Efficiently Enumerating the Subsets of a Set
============================================

The [paper](https://github.com/jloughry/subset/blob/master/loughry2000.pdf) is
PDF only until I find the LaTeX source code.  This is the
[letter](https://github.com/jloughry/subset/blob/master/letter_to_prof_knuth.pdf)
I gave to Don Knuth in Oxford.

Update 20121203.2048: I found the solution to the Grey-code like banker's sequence for *n* = 4.
In decimal it is 0, 1, 3, 2, 6, 4, 12, 8, 10, 11, 9, 13, 5, 7, 15, 14.  In binary, the sequence
is 0000, 0001, 0011, 0010, 0110, 0100, 1100, 1000, 1010, 1011, 1001, 1101, 0101, 0111, 1111, 1110.

The solution was found by using `dot` to draw a directed graph of all possible one-bit transitions
from the starting state 0000 and backtracking from impossible situations until a solution was
found.  It is not known whether this solution is unique or whether any solutions exist for *n* >
4.

