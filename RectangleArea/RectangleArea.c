int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	int width, height;
	if( (A-E) * (G-C) >= 0)
	{
		width = (G-E) > (C-A)? (C-A):(G-E);
	}
	else
	{
		if((G<=A)||(E>=C)) width=0;
		if((A<=G) && (A>=E)) width = G-A;
		if((E<=C) && (E>=A)) width = C-E;
	}    
	if( (D-H) * (F-B) >= 0)
        {
		height = (D-B) > (H-F) ? (H-F):(D-B);
        }
        else
        {
                if((D<=F)||(B>=F)) height=0;
                if((H<=D) && (H>=B)) height = H-B;
                if((F<=D) && (F>=B)) height = D-F;
        }
	return (C-A)*(D-B) + (G-E)*(H-F) - width*height;
}
