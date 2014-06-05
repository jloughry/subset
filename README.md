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

<p>
<table>
	<tr><th>Binary</th><th>Dec (Hex)</th><th>Bits Set</th><th>Index</th></tr>
	<tr><td>0000</td><td align="right">0 (0)</td><td>&nbsp;</td><td>0</td></tr>
	<tr><td>0001</td><td align="right">1 (1)</td><td>*</td><td>1</td></tr>
	<tr><td>0011</td><td align="right">3 (3)</td><td>**</td><td>2</td></tr>
	<tr><td>0010</td><td align="right">2 (2)</td><td>*</td><td>3</td></tr>
	<tr><td>0110</td><td align="right">6 (6)</td><td>**</td><td>4</td></tr>
	<tr><td>0100</td><td align="right">4 (4)</td><td>*</td><td>5</td></tr>
	<tr><td>1100</td><td align="right">12 (C)</td><td>**</td><td>6</td></tr>
	<tr><td>1000</td><td align="right">8 (8)</td><td>*</td><td>7</td></tr>
	<tr><td>1010</td><td align="right">10 (A)</td><td>**</td><td>8</td></tr>
	<tr><td>1011</td><td align="right">11 (B)</td><td>***</td><td>9</td></tr>
	<tr><td>1001</td><td align="right">9 (9)</td><td>**</td><td>A</td></tr>
	<tr><td>1101</td><td align="right">13 (D)</td><td>***</td><td>B</td></tr>
	<tr><td>0101</td><td align="right">5 (5)</td><td>**</td><td>C</td></tr>
	<tr><td>0111</td><td align="right">7 (7)</td><td>***</td><td>D</td></tr>
	<tr><td>1111</td><td align="right">15 (F)</td><td>****</td><td>E</td></tr>
	<tr><td>1110</td><td align="right">14 (E)</td><td>***</td><td>F</td></tr>
</table>
</p><img src="https://github.com/jloughry/subset/raw/master/optimal_4.png"
align="right" width="200" alt="optimal banker's sequence for n=4"/>

The solution was found by using `dot` to draw a directed graph of all possible
one-bit transitions from the starting state 0000 and backtracking from impossible
situations until a solution was found.  The optimal path is highlighted in
<font color="red">red</font>. It is not known whether this solution is
unique or whether any solutions exist for *n* > 4. An automated method for
constructing `dot` or `neato` source code should be developed.

Update 20140115.1225:
---------------------

Added Eric Burnett as co-author on the paper. I have to finish my thesis before
I can finish this paper.

Update 20140604.1658:
---------------------

`minimised_snowflake_order_4.dot` can be compiled to
[PDF](https://github.com/jloughry/subset/blob/master/minimised_snowflake_order_4.pdf?raw=true)
with the command line:

````
$ neato -Goverlap=scale -T pdf minimised_snowflake_order_4.dot -o minimised_snowflake_order_4.pdf
````

It is not known whether the path shown for order-4 is unique, but it is optimal. "Optimal"
in this context means that all state transitions involve setting or resetting a single bit
("flipping a bit") and all *n*-bit states are enumerated before any (*n*+2)-bit states
are enumerated. "Strictly optimal" would have all *n*-bit states enumerated before any
(*n*+1)-bit states are enumerated, but that can't be done by flipping a bit for *n* > 1.

