bool isHappy(int n) 
{
	while(n!= 1)
	{
		n = Happy(n);
		if(sum == 4) return false;
	}
	return true;    
}

int Happy(int n)
{
	int sum = 0;
	while(n!= 0)
	{
		int tmp = n%10;
		sum = sum + tmp*tmp;
		n = n/10;
	}
	return sum;
}
