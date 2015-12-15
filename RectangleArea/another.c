int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int area=(C-A)*(D-B)+(G-E)*(H-F);
    // no overlap
    if (A>=G||E>=C||B>=H||D<=F)
    {
        return area;
    }

    int x1= A>E?A:E;
    int x2= C<G?C:G;

    int y1= B>F?B:F;
    int y2= D<H?D:H;

    return area-(x2-x1)*(y2-y1);
}
