int climbStairs( int n )
{
        if( n < 4 ) return n;
        int a = 2;
        int b = 3;
        for( int i = 3; i < n; ++i )
        {
            if ( i % 2 ) a += b;
            else b += a;
        }
        if( n%2 ) return b;
        return a;
}
