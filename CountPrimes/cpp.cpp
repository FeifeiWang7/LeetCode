use new bool array. 2. only traverse odd numbers. 3. count and sieve at the same time.
trick 1, thanks to 27ms,16 lines, C++ solution

trick 2, for the inspiration, thanks to my C solutions in 13ms,use Sieve of Eratosthenes and only test 6n-1 and 6n+1

trick 3, thanks to my C solutions in 44ms, time nearly O(n), and space nearly O(n) and my easy one round c++ code

int countPrimes(int n) {
    if (n <= 2) return 0;
    int res=n>>1, m=sqrt(n-1); // intilize res to n/2, removes all even number(not 2) and 1
    bool *table=new bool[n];
    for(int i=3,j,step;i<=m;i+=2)
        if(!table[i]) { // i is an odd prime
            for(step=i<<1, j=i*i;j<n;j+=step) // step=i*2, ignore even numbers
            if(!table[j]) { table[j]=1; --res; }
        }
    delete []table;
    return res;
}
