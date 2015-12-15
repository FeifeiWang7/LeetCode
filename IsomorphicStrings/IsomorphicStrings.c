bool isIsomorphic(char* s, char* t) 
{
	if((s == NULL) || (t == NULL)) return false;
	int i;
	for(i = 0; i < strlen(s); i++)
	{
		if((strchr(s, s[i]) -s) != (strchr(t, t[i]) -t)) return false;
	}
	return true;
}
