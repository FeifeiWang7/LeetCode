int trailingZeroes(int n) 
{
	int sum = 0;
	while(n/5)
	{
		n = n /5;
		sum = sum + n;
	}
	return sum;    
}
