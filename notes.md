#### Integer Overflow

* x = -x may lead to overflow (e.g., -2147483648, 2147483648 overflow)

* String to Integer

* Calculation

Detection:

If going to calculate x * 10, 
	
	if (result * 10 / 10 != result), then overflow

or

	if((tmp >> 31 != result >> 31) || (tmp + '0' - *p)/10 != result), then overflow

If using C/C++, 

	#include <limits.h>

	if(result > INT_MAX || result < INT_MIN), then overflow

If using Java,

	if(result > Integer.MAX_VALUE || result < Integer.MIN_VALUE), then overflow




