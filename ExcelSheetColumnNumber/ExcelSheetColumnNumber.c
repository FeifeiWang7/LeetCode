int titleToNumber(char* s) 
{
	int len = strlen(s);
	int i;
	int num = 0;
	for(i = 0; i < len; i ++)
	{
		num = num * 26 + s[i] - 'A' + 1;
	}
	return num;
}
