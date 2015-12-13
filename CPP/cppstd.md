### Vector

```c++
#include <vector>
```
#### initialize

* empty vector

	vector<int> v1;
* same value

	vector<int> v2 (4, 100); // four ints with value 100

* with another vector

	vector<int> v3 (v2); // a copy of v2

* with another vector

	vector<int> v4 (v3.begin()+1, v3.end()-1); // 2-3 elements in v3

* with array

	int array[]={10,21,10,27};
	vector<int> v5 (array, array+sizeof(array)/sizeof(int));

