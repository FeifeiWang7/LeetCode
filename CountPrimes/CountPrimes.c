int countPrimes(int n) 
{
        char isPrime[n]; 
        int i;
        for(i = 2; i < n; i++) isPrime[i] = 1;
        for(i = 2; i*i < n; i++)
        {
                if(isPrime[i] == 1) 
                {
                        int j;
                        for(j = i*i; j < n; j= j+i)       isPrime[j] = 0;
                }
        }
        int count = 0;
        for(i = 2; i < n; i++)
                if(isPrime[i] == 1) count++;
        return count;
}


//// This method takes too much time to create list when n is big!!!
#include <stdio.h>
#include <stdlib.h>
int* createPrime(int n)
{
	int* result = (int *)malloc(sizeof(int)*n);
	result[0] = 1;
	result[1] = 2;
	int i;
	for(i = 2; i < n; i++)
	{
		int j;
		for(j = result[i-1] + 1; j <= n; j++)
		{
			int k;
			for(k = 1; k < i; k++)
			{
				if( j % result[k] == 0) break;
			}
			if(k == i) 
			{
				result[i] = j;
				break;
			}
		}
	}
	return result;
}
int countPrimes(int n) 
{
	int *a = createPrime(n, n);
	int i; int count = 0;
	for(i = 1; i < n; i++)
	{
		if(a[i] < n) count++;
		else break;
	}
	return count;
}

int main()
{
	int *a = createPrime(20000);
	int i;
	for(i = 0; i < 20000; i++)
		printf("%d\n",a[i]);

}
