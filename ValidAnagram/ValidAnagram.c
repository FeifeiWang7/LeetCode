count(char *s, char *scount)
{
	int i;
	for(i = 0; i < 26; i++) scount[i] = 0;
	for(i = 0; i < strlen(s); i++)
	{
		scount[s[i] - 'a'] ++;
	}
}
bool isAnagram(char* s, char* t) 
{
	char scount[26];
	char tcount[26];
	count(s, scount);    
	count(t, tcount);    
	int i;
	for(i = 0; i < 26; i++)
	{
		if(scount[i] != tcount[i]) return false;
	}
	return true;
}
