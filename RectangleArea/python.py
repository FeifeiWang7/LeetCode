def computeArea(self, A, B, C, D, E, F, G, H):
    overlap = max(min(C,G)-max(A,E), 0)*max(min(D,H)-max(B,F), 0)
    return (A-C)*(B-D) + (E-G)*(F-H) - overlap


We should consider the following two problems:

How to know whether the two rectangle areas are not overlapped.
If the two rectangle areas are overlapped, how to calculate the overlapped area.
For me, both situations are not intuitive to see. I tried the intuitive solution, but I gave up as it needs too many lines of code. Here I write down a smarter way in plain language which is actually from other user's codes to solve the problem.

1, To know whether the two areas are not overlapped:

We actually only need to consider four situations: B>=H or E>=C or F>=D or A>=G. For example, if B is larger than H, the area (A,B,C,D) is definitely not overlapped with area (E,F,G,H), and we even know that area (A,B,C,D) is on the upper area of the plot compared with area (E,F,G,H). You can also check if other situations work.
2, To calculate the overlapped area:

When the two areas are overlapped, we only need to know the bottom left corner and top right corner of the overlapped area: the larger one of A and E, the larger one of B and F, the smaller one of C and G, and the smaller one of D and H. For example, in the case of the given figure of the original problem, we just consider the point (E,B) and the point (C,H), and the overlapped area is (E,B,C,H) which could be calculated intuitively. So how about other kinds of overlapping? The formula given above never change! You can try imagining other kind of overlapped area, you will see that in any case we only need to know max(A,E), max(B,F), min(C,G), and min(D,H) to calculate the overlapped area.
I don't consider this problem as an easy one, if you try to solve it intuitively.
Adding to what @shintanoid has said

4 conditions for overlapping are
rectangle 1's rightmost point(c,d) is before the rectangle2's leftmost point.
rectangle 1's left most point ie(a,b) starts after the rectangle 2's rightmost point (g,h)
rectangle 1's bottom most point starts above rectangle 2's topmost point
rectangle 1's topmost point starts below rectangle 2's bottommost point

