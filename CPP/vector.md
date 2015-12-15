### Vector

```c++
#include <vector>
```
##### initialize, assign

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

##### empty
Returns whether the vector is empty (i.e. whether its size is 0).

```c++
vector<int> myvector;
int sum (0);

for (int i=1;i<=10;i++) myvector.push_back(i);

while (!myvector.empty())
{
	sum += myvector.back();
	myvector.pop_back();
}

cout << "total: " << sum << '\n';
```
##### erase, clear
###### erase
Removes from the vector either a single element (position) or a range of elements ([first,last)).
```c++
vector<int> myvector;

for (int i=1; i<=10; i++) myvector.push_back(i);

myvector.erase (myvector.begin()+5); //erase the 6th element

myvector.erase (myvector.begin(),myvector.begin()+3); //erase the first 3 elements

for (unsigned i=0; i<myvector.size(); ++i)
	cout << ' ' << myvector[i]; // 4 5 7 8 9 10
cout << '\n';
```
###### clear
Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
```c++
  myvector.clear();
```
##### reference (at, front, back)

###### at
Returns a reference to the element at position n in the vector, throwing an out_of_range exception if n is greater or equal than its size.
 
```c++
	vector<int> v (10);
	for(unsigned i = 0; i < v.size(); i++)
		v.at(i) = i;
```
###### front, back
front: Returns a reference to the first element in the vector.

back: Returns a reference to the last element in the vector. Calling this function on an empty container causes undefined behavior.

```c++
	vector<int> v;
	v.push_back(10);
	while(v.back() != 0)
		v.push_back(v.back() - 1);
	
	myvector.front() -= myvector.back();
```

##### iterator (begin, end, cbegin, cend, rbegin, rend, crbegin, crend

###### begin, end
begin: Returns an iterator pointing to the first element in the vector.
end: Returns an iterator referring to the past-the-end element in the vector container.
```c++
	vector<int> v;
	for( int i = 1; i <=5; i ++) v.push_back(i);
	
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';
```
###### cbegin, cend
Returns a const_iterator pointing to the first element in the container. A const_iterator is an iterator that points to const content. This iterator can be increased and decreased (unless it is itself also const), just like the iterator returned by vector::begin, but it cannot be used to modify the contents it points to, even if the vector object is not itself const.

```c++
vector<int> myvector = {10,20,30,40,50};

for (auto it = myvector.cbegin(); it != myvector.cend(); ++it)
	std::cout << ' ' << *it;
cout << '\n';
```
###### rbegin, rend
rbegin: Returns a reverse iterator pointing to the last element in the vector (i.e., its reverse beginning).

Reverse iterators iterate backwards: increasing them moves them towards the beginning of the container.

rbegin points to the element right before the one that would be pointed to by member end.
```c++
vector<int> myvector (5);  // 5 default-constructed ints

int i=0;

vector<int>::reverse_iterator rit = myvector.rbegin();
for (; rit!= myvector.rend(); ++rit)
	*rit = ++i;

for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
	cout << ' ' << *it;
cout << '\n';
```
###### crbegin, crend
crbegin: Returns a const_reverse_iterator pointing to the last element in the container (i.e., its reverse beginning).

crend: Returns a const_reverse_iterator pointing to the theoretical element preceding the first element in the container (which is considered its reverse end).

```c++
vector<int> myvector = {1,2,3,4,5};

for (auto rit = myvector.crbegin(); rit != myvector.crend(); ++rit)
	cout << ' ' << *rit; // 5 4 3 2 1
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

##### operator
Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.

```c++
vector<int> foo (3,0);
vector<int> bar (5,0);

bar = foo;
foo = std::vector<int>();

cout << "Size of foo: " << int(foo.size()) << '\n'; //0
cout << "Size of bar: " << int(bar.size()) << '\n'; //3
```

##### operator[]
Returns a reference to the element at position n in the vector container.

```c++
vector<int> myvector (10);   // 10 zero-initialized elements

vector<int>::size_type sz = myvector.size();

// assign some values:
for (unsigned i=0; i<sz; i++) myvector[i]=i;

// reverse vector using operator[]:
for (unsigned i=0; i<sz/2; i++)
{
	int temp;
	temp = myvector[sz-1-i];
	myvector[sz-1-i]=myvector[i];
	myvector[i]=temp;
}

for (unsigned i=0; i<sz; i++)
	cout << ' ' << myvector[i];
cout << '\n';
```

##### reserve
Request a change in capacity

```c++
vector<int>::size_type sz;

vector<int> foo;
sz = foo.capacity();
cout << "making foo grow:\n";
for (int i=0; i<100; ++i) {
	foo.push_back(i);
	if (sz!=foo.capacity()) {
	sz = foo.capacity();
	cout << "capacity changed: " << sz << '\n';
	}
}

vector<int> bar;
sz = bar.capacity();
bar.reserve(100);   // this is the only difference with foo above
cout << "making bar grow:\n";
for (int i=0; i<100; ++i) {
bar.push_back(i);
if (sz!=bar.capacity()) {
	sz = bar.capacity();
	cout << "capacity changed: " << sz << '\n';
	}
}
```
##### resize
Change size. Resizes the container so that it contains n elements. If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them). If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.

If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.
```c++
vector<int> myvector;

// set some initial content:
for (int i=1;i<10;i++) myvector.push_back(i);

myvector.resize(5);
myvector.resize(8,100);
myvector.resize(12);

cout << "myvector contains:";
for (int i=0;i<myvector.size();i++)
	cout << ' ' << myvector[i]; //1 2 3 4 5 100 100 100 0 0 0 0 
cout << '\n';
```

##### shrink_to_fit
Requests the container to reduce its capacity to fit its size.
```c++
vector<int> myvector (100);
cout << "1. capacity of myvector: " << myvector.capacity() << '\n';

myvector.resize(10);
cout << "2. capacity of myvector: " << myvector.capacity() << '\n';

myvector.shrink_to_fit();
cout << "3. capacity of myvector: " << myvector.capacity() << '\n';
```

##### swap
Exchanges the content of the container by the content of x, which is another vector object of the same type. Sizes may differ.

After the call to this member function, the elements in this container are those which were in x before the call, and the elements of x are those which were in this. All iterators, references and pointers remain valid for the swapped objects.
```c++
vector<int> foo (3,100);   // three ints with a value of 100
vector<int> bar (5,200);   // five ints with a value of 200

foo.swap(bar); //foo (200 200 200 200 200) bar (100 100 100)
```
##### relational operators
Performs the appropriate comparison operation between the vector containers lhs and rhs.

The equality comparison (operator==) is performed by first comparing sizes, and if they match, the elements are compared sequentially using operator==, stopping at the first mismatch (as if using algorithm equal).

The less-than comparison (operator<) behaves as if using algorithm lexicographical_compare, which compares the elements sequentially using operator< in a reciprocal manner (i.e., checking both a<b and b<a) and stopping at the first occurrence.
```c++
vector<int> foo (3,100);   // three ints with a value of 100
vector<int> bar (2,200);   // two ints with a value of 200

if (foo!=bar) std::cout << "foo and bar are not equal\n";
if (foo< bar) std::cout << "foo is less than bar\n";
if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
```
##### data
Returns a direct pointer to the memory array used internally by the vector to store its owned elements.

```c++
vector<int> myvector (5);

int* p = myvector.data();

*p = 10;
++p;
*p = 20;
 p[2] = 100;

for (unsigned i=0; i<myvector.size(); ++i)
	cout << ' ' << myvector[i]; // 10 20 0 100 0
cout << '\n';
```

##### insert, emplace, emplace_back

###### insert
The vector is extended by inserting new elements before the element at the specified position, effectively increasing the container size by the number of elements inserted.

Returns an iterator that points to the first of the newly inserted elements.
```c++
vector<int> myvector (3,100);
vector<int>::iterator it;

it = myvector.begin();
it = myvector.insert ( it , 200 ); // insert one value 200

myvector.insert (it,2,300); //insert two values 300

// "it" no longer valid, get a new one:
it = myvector.begin();

vector<int> anothervector (2,400);
myvector.insert (it+2,anothervector.begin(),anothervector.end()); //insert a range of values

int myarray [] = { 501,502,503 };
myvector.insert (myvector.begin(), myarray, myarray+3); //insert a range of values

for (it=myvector.begin(); it<myvector.end(); it++)
	cout << ' ' << *it;
cout << '\n';
```
###### emplace
The container is extended by inserting a new element at position. This new element is constructed in place using args as the arguments for its construction.

```c++
vector<int> myvector = {10,20,30};

auto it = myvector.emplace ( myvector.begin()+1, 100 );
myvector.emplace ( it, 200 );
myvector.emplace ( myvector.end(), 300 );

for (auto& x: myvector)
	cout << ' ' << x;
cout << '\n';
```
###### emplace_back
Inserts a new element at the end of the vector, right after its current last element. This new element is constructed in place using args as the arguments for its constructor.

```c++
vector<int> myvector = {10,20,30};

myvector.emplace_back (100);
myvector.emplace_back (200);

for (auto& x: myvector)
	cout << ' ' << x;
cout << '\n';
```

##### get_allocator
Returns a copy of the allocator object associated with the vector.
```c++
vector<int> myvector;
int * p;
unsigned int i;

// allocate an array with space for 5 elements using vector's allocator:
p = myvector.get_allocator().allocate(5);

// construct values in-place on the array:
for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

for (i=0; i<5; i++) cout << ' ' << p[i];
cout << '\n';

// destroy and deallocate:
for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
myvector.get_allocator().deallocate(p,5);
```
