Efficiently Enumerating the Subsets of a Set
============================================

The [paper](https://github.com/jloughry/subset/blob/master/loughry2000.pdf) is
PDF only until I find the LaTeX source code. This is the
[letter](https://github.com/jloughry/subset/blob/master/letter_to_prof_knuth.pdf)
I gave to Don Knuth in Oxford.

Update 20121203.2048:
---------------------

I found the solution to the Grey-code like banker's sequence for *n* = 4.
In decimal it is 0, 1, 3, 2, 6, 4, 12, 8, 10, 11, 9, 13, 5, 7, 15, 14.
In binary, the sequence is 0000, 0001, 0011, 0010, 0110, 0100, 1100, 1000, 1010,
1011, 1001, 1101, 0101, 0111, 1111, 1110.

<table>
	<tr><th>Binary</th><th>Decimal</th><th>Hex</th><th>Bits Set</th><th>Index</th></tr>
	<tr><td>0000</td><td align="right">0</td><td>0</td><td>0</td><td>0</td></tr>
	<tr><td>0001</td><td align="right">1</td><td>1</td><td>1 *</td><td>1</td></tr>
	<tr><td>0011</td><td align="right">3</td><td>3</td><td>2 **</td><td>2</td></tr>
	<tr><td>0010</td><td align="right">2</td><td>2</td><td>1 *</td><td>3</td></tr>
	<tr><td>0110</td><td align="right">6</td><td>6</td><td>2 **</td><td>4</td></tr>
	<tr><td>0100</td><td align="right">4</td><td>4</td><td>1 *</td><td>5</td></tr>
	<tr><td>1100</td><td align="right">12</td><td>C</td><td>2 **</td><td>6</td></tr>
	<tr><td>1000</td><td align="right">8</td><td>8</td><td>1 *</td><td>7</td></tr>
	<tr><td>1010</td><td align="right">10</td><td>A</td><td>2 **</td><td>8</td></tr>
	<tr><td>1011</td><td align="right">11</td><td>B</td><td>3 ***</td><td>9</td></tr>
	<tr><td>1001</td><td align="right">9</td><td>9</td><td>2 **</td><td>A</td></tr>
	<tr><td>1101</td><td align="right">13</td><td>D</td><td>3 ***</td><td>B</td></tr>
	<tr><td>0101</td><td align="right">5</td><td>5</td><td>2 **</td><td>C</td></tr>
	<tr><td>0111</td><td align="right">7</td><td>7</td><td>3 ***</td><td>D</td></tr>
	<tr><td>1111</td><td align="right">15</td><td>F</td><td>4 ****</td><td>E</td></tr>
	<tr><td>1110</td><td align="right">14</td><td>E</td><td>3 ***</td><td>F</td></tr>
</table>

The solution was found by using `dot` to draw a directed graph of all possible
one-bit transitions from the starting state 0000 and backtracking from impossible
situations until a solution was found.  It is not known whether this solution is
unique or whether any solutions exist for *n* > 4.

Update 20140115.1225:
---------------------

Added Eric Burnett as co-author on the paper. I have to finish my thesis before
I can finish this paper.

