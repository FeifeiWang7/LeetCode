### Vector

```c++
#include <vector>
```
##### initialize and assign

```c++
	vector<int> v1; //empty vector
	
	vector<int> v2 (10); // 10 zero-initialized ints
	vector<int> v2 (4, 100); // four ints with value 100
	v2.assign (7,100);

	vector<int> v3 (v2); // a copy of v2

	vector<int> v4 (v3.begin()+1, v3.end()-1); // 2-3 elements in v3
	v4.assign (v3.begin()+1, v3.end()-1);

	int array[]={10,21,10,27}; //initialize with array
	vector<int> v5 (array, array+sizeof(array)/sizeof(int)); // (array, array + num of elements)
	v5.assign(array, array+4);
```

##### reference (at, back)

###### at
Returns a reference to the element at position n in the vector, throwing an out_of_range exception if n is greater or equal than its size.
 
```c++
	vector<int> v (10);
	for(unsigned i = 0; i < v.size(); i++)
		v.at(i) = i;
```
###### back
Returns a reference to the last element in the vector. Calling this function on an empty container causes undefined behavior.

```c++
	vector<int> v;
	v.push_back(10);
	while(v.back() != 0)
		v.push_back(v.back() - 1);
```

##### iterator (begin,

###### begin
Returns an iterator pointing to the first element in the vector.

```c++
	vector<int> v;
	for( int i = 1; i <=5; i ++) v.push_back(i);
	
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';
```

##### size, capacity, max_size
```c++
vector<int> v;
for (int i=0; i<100; i++) myvector.push_back(i);

cout << "size: " << (int) myvector.size() << '\n';
cout << "capacity: " << (int) myvector.capacity() << '\n';
cout << "max_size: " << (int) myvector.max_size() << '\n';
```


