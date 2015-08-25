#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* addBinary(char* a, char* b)
{
	int lena = strlen(a);
	int lenb = strlen(b);
	int len = lena >= lenb ? lena : lenb;
	char *tmp = (char *)malloc((len+1) * sizeof(char));
	char *result;
	int i, j, k;
	int carry = 0;
	for(i = lena -1, j = lenb - 1, k = len - 1; (i >= 0) || (j >= 0) || (k >= 0); i--, j--, k--)
	{
		if(i < 0)
		{
			tmp[k] = ((b[j] - '0' + carry) % 2) + '0';
			carry = (b[j] - '0' + carry) /2;
			continue;
		}
		if(j < 0)
		{
			tmp[k] = (a[i] - '0' + carry) % 2 + '0';
			carry = (a[i] - '0' + carry) /2;
			continue;
		}
		tmp[k] = (a[i] - '0'+ b[j] - '0' + carry) % 2 + '0';
		carry = (a[i] - '0'+ b[j] - '0' + carry) / 2;
	}
	tmp[len] = '\0';
	if(carry)
	{
		len++;
		result = (char *)malloc(sizeof(char)*(len+1));
		memcpy(result + 1, tmp, len * sizeof(char));
		result[0] = '1';
		result[len] = '\0';
	}
	else
		result = tmp;
	return result;	
}

int main()
{
char a[] = "1111011001010001111100100011101110011101100101110011001000110000111001010010100";
char b[] = "1101001000101110000000001001001111011111000111101101100000110001110101000011001101111100";
	char *c = addBinary(a, b);
	printf("%s \n%s \n%s \n", a, b, c);
}
