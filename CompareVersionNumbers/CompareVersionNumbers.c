#include <stdio.h>
#include <string.h>

/*double stringToFloat(char *str)
{
	double num = 0;
	int len = strlen(str);
	int i;
	for( i = 0; i < len; i++)
	{
		if(str[i] != '.')
			num = num*10 + str[i] - '0'; 
		else break;
	}
	double tmp = 0;
	for(i = i + 1; i < len; i ++)
	{
		tmp = tmp+(str[i]- '0')/10;
	}
	return num+tmp;
}	*/	

int compareVersion(char* version1, char* version2)
{
        int len1 = strlen(version1), len2 = strlen(version2);
        int first1 = 0, first2 = 0; int i = 0, j = 0;
        while( (i<len1)||(j<len2))
        {
                first1 = 0; first2 = 0;
                for(; i < len1; i ++)
                {
                        if(version1[i] != '.') first1 = first1*10 + version1[i] - '0';
                        else 
                        {i++;break;}
                }
                for(; j < len2; j ++)
                {
                        if(version2[j] != '.') first2 = first2*10 + version2[j] - '0';
                        else {j++; break;}
                }
                if(first1> first2) return 1;
                if(first1 < first2) return -1;
        }
        if((i == len1) && (j == len2)) return 0;
        else if(i == len1) return -1;
        else return 1;
}
