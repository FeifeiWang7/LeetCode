bool isUgly(int num) 
{
//I forgot 0
	if(num == 0) return false;
	while(num%2 == 0) num = num/2;
	while(num%3 == 0) num = num/3;
	while(num%5 == 0) num = num/5;
	if(num == 1) return true;
	else return false;  
	// or return num == 1;  
}
