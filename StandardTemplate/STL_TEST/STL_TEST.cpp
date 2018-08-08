#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <functional> // binary_function definition
using namespace std;

/**Container Iterator Test*/
void StdIteratorTest();
void VectorIteratorTest1();
template <typename T> void printVector(const vector<T> &v);
template <typename T> void printRevVector(const vector<T> &v);

void VectorIteratorTest2();

void ListIteratorTest();
template <typename T> void printList(const list<T> &l);

void DequeIteratorTest1();

void SetIteratorTest1();
typedef multiset <int, less<int> > ms; 
//定義ms為multiset<類型,比較函數<類型>> 且具排序特性

void SetIteratorTest2();
typedef set <double, less<double> > DoubleSet;
//定義DoubleSet為set<類型,比較函數<類型>> 且具排序特性

void MapIteratorTest1();
typedef multimap <int, double, less<int>> MultiMap;

void MapIteratorTest2();
typedef map <int, double, less<int>> Map;

/**Adapter Test*/
void StackAdapterTest();
template< typename T > void push(T &stack);
template< typename T > void pop(T &stack);

void QueueAdapterTest();
void PQAdapterTest();

/**Algorithm Test*/
char nextLetter(); // nextLetter作為generate function
void AssignmentTest();
void CompareTest();

bool filter(int); // remove_if方法的過濾器
void RemoveTest();
void ReplaceTest();

void outputSquare(int); // output square of a value
int calculateCube(int); // calculate cube of a value
void MathCalcTest();

void SearchTest();
void SwapTest();
void RangeItemUpdate1();
void RangeItemUpdate2();

void SetOperate();
void RangeBound();

void HeapSortTest();

/**Class bitset*/
void findPrime();

/**Function Objects */
void FunctionTest();
int sumSquares(int total, int value)
{
	return total + value * value;
}

template< typename T >
class SumSquaresClass : public binary_function< T, T, T >
{
public:
	// add square of value to total and return result
	T operator()(const T &total, const T &value)
	{
		return total + value * value;
	} // end function operator()
}; // end class SumSquaresClass



int main() {
	/**Container Iterator Test*/

	//StdIteratorTest();
	//VectorIteratorTest1();
	//VectorIteratorTest2();
	//ListIteratorTest();
	//DequeIteratorTest1();
	//SetIteratorTest1();
	//SetIteratorTest2();
	//MapIteratorTest1();
	//MapIteratorTest2();

	/**Adapter Test*/

	//StackAdapterTest();
	//QueueAdapterTest();
	//PQAdapterTest();
	
	/**Algorithm Test*/

	//AssignmentTest();
	//CompareTest();
	//RemoveElementTest();
	//ReplaceElementTest();
	//MathCalcTest();
	//SearchTest();
	//SwapTest();
	//RangeItemUpdate1();
	//RangeItemUpdate2();
	//SetOperate();
	//RangeBound();
	//HeapSortTest();

	/**Class bitset*/
	//findPrime();

	/**Function Objects */
	FunctionTest();

	system("pause");
}

void StdIteratorTest()
{
	cout << "輸入2個整數" << endl;
	istream_iterator<int> input(cin); // 綁定標準輸入裝置 

	int a = *input;
	int b = *++input;

	ostream_iterator<int> output(cout); // 綁定標準輸出裝置
	cout << "總和是 : ";
	*output = a + b;
	cout << endl<<"相差是 : ";
	*++output = a - b;
	cout << endl;
}

template<typename T>
void printVector(const vector<T>& v)
{
	typename vector <T>::const_iterator it;
	for (it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";
}
template<typename T>
void printRevVector(const vector<T>& v)
{
	vector<int> ::const_reverse_iterator rit;
	//rbegin回傳一個指向末端元素的逆向迭代器
	//rend回傳一個指向前端元素的逆向迭代器
	for (rit = v.rbegin(); rit != v.rend(); ++rit) 
		cout << *rit << " ";
}

void VectorIteratorTest1()
{
	const int size = 6;
	int array[size] = { 1,2,3,4,5,6 };
	vector<int> v;
	cout << "vector初始大小為" << v.size() << endl
		<< "vector初始容量為" << v.capacity() << endl;
	for (int i = 1; i < size-2; i++) {
		v.push_back(array[i]);
	}

	cout << "vector大小為" << v.size() << endl
		<< "vector容量為" << v.capacity() << endl;
	cout << "\n\n 使用指標輸出陣列:" << endl;

	for (int *ptr = array; ptr != array + size; ptr++)
		cout << *ptr << " ";

	cout << "\n 使用Iterator方式輸出Vector" << endl;
	printVector(v);
	cout << "\n 反轉Vector內容 :" << endl;
	printRevVector(v);
	cout << endl;
}

void VectorIteratorTest2()
{
	const int SIZE = 6;
	int array[SIZE] = { 1,2,3,4,5,6 };
	vector<int> v(array, array + SIZE);
	ostream_iterator<int> output(cout, " "); //綁定輸出裝置,以" "做為分割字元

	cout << "Vector 內容包含: ";
	copy(v.begin(), v.end(), output); 
	//copy : 將Vector範圍內的所有整數複製到輸出串流迭代器

	cout << "\n Vector 的第1個元素: " << v.front()
		<< "\n Vector的最後1個元素: " << v.back();

	v[0] = 7; //設定第0個元素為7
	v.at(2) = 10; //設定第2個元素為10 (會進行邊界檢查)
	v.insert(v.begin() + 1, 22); //在位置2上插入元素為22

	cout << "\n\n 改變後的Vector內容: ";
	copy(v.begin(), v.end(), output);

	try {
		v.at(100) = 777;
	}
	catch (out_of_range &outOfRange) {
		cout << "\n\nException: " << outOfRange.what();
	}

	v.erase(v.begin()); //erase :移除範圍內的元素
	cout << "\n\n 清除第1個元素後的Vector內容: ";
	copy(v.begin(), v.end(), output);

	v.erase(v.begin(),v.end());
	cout << "\n\n 清除所有元素後的Vector內容: "
		<< (v.empty() ? "為空" : "非空")<<endl;

	v.insert(v.begin(), array, array + SIZE); 
	//將array中的所有元素從Vector的第0個位置開始插入
	cout << "將array中的所有元素從Vector的第0個位置開始插入,"
		<< "此為清除前內容: ";
	copy(v.begin(), v.end(), output); 

	v.clear(); //移除所有元素
	cout << "\n\n 清除所有元素後的Vector內容: "
		<< (v.empty() ? "為空" : "非空") << endl;
}

void ListIteratorTest()
{
	const int SIZE = 4;
	int array[SIZE] = { 2, 6, 4, 8 };
	list< int > list1; // create list of ints
	list< int > list2; // create list of ints

							 // insert items in values
	list1.push_front(1);
	list1.push_front(2);
	list1.push_back(4);
	list1.push_back(3);

	cout << "List1 內容: ";
	printList(list1);

	list1.sort(); // sort values
	cout << "\n排序後的List1內容: ";
	printList(list1);

	// 將array的元素全部新增到list2                  
	list2.insert(list2.begin(), array, array + SIZE);
	cout << "\n新增後的List2內容: ";
	printList(list2);

	// void splice ( iterator pos, list<T,Allocator>& x ); 
	// 將x中的元素移動並插入到pos後的位置
	list1.splice(list1.end(), list2);
	cout << "\n經過splice動作後, list1的內容: ";
	printList(list1);

	list1.sort(); // sort values
	cout << "\n經過sort動作後, list1的內容: ";
	printList(list1);

	// 將array的元素全部新增到list2   
	list2.insert(list2.begin(), array, array + SIZE);
	list2.sort();
	cout << "\n經過sort動作後, list2的內容: ";
	printList(list2);

	// 將list2中的元素移除，並按照排序合併到list1
	list1.merge(list2);
	cout << "\n經過merge動作後 \n list1的內容: ";
	printList(list1);
	cout << "\n list2的內容: ";
	printList(list2);

	list1.pop_front(); // pop_front(去頭)
	list1.pop_back(); // pop_back(去尾)
	cout << "\n經過 pop_front 和 pop_back:\n  list1的內容: ";
	printList(list1);

	list1.unique(); // 移除重複元素
	cout << "\n經過unique動作後 \n list1的內容: ";
	printList(list1);

	// swap : 將list1與list2的內容互換
	list1.swap(list2);
	cout << "\n經過swap動作後 \n list1的內容: ";
	printList(list1);
	cout << "\n list2的內容: ";
	printList(list2);

	// 將list2中範圍的內容指派到list1中
	list1.assign(list2.begin(), list2.end());
	cout << "\n經過assign動作後 \n list1的內容: ";
	printList(list1);

	// 將list2中的元素移除，並按照排序合併到list1
	list1.merge(list2);
	cout << "\n經過merge動作後 \n list1的內容: ";
	printList(list1);

	list1.remove(4); // 刪除list1中所有值為4的元素
	cout << "\n經過remove(4)動作後 \n list1的內容: ";
	printList(list1);
	cout << endl;
} // end main
template < typename T > void printList(const list< T > &listRef)
{
	if (listRef.empty()) // list is empty
		cout << "List is empty";
	else
	{
		ostream_iterator< T > output(cout, " ");
		copy(listRef.begin(), listRef.end(), output);
	} // end else
}

void DequeIteratorTest1()
{
	deque< double > d1; 
	ostream_iterator< double > output(cout, " "); //綁定輸出裝置

	d1.push_front(2.2);
	d1.push_front(3.5);
	d1.push_back(1.1);

	cout << "d1 的內容為: ";

	// use subscript operator to obtain elements of values
	for (unsigned int i = 0; i < d1.size(); i++)
		cout << d1[i] << ' ';

	d1.pop_front(); // remove first element
	cout << "\nAfter pop_front, values contains: ";
	copy(d1.begin(), d1.end(), output);

	// use subscript operator to modify element at location 1
	d1[1] = 5.4;
	cout << "\nAfter values[ 1 ] = 5.4, values contains: ";
	copy(d1.begin(), d1.end(), output);
	cout << endl;
}

void SetIteratorTest1()
{
	const int SIZE = 10;
	int a[SIZE] = { 7, 22, 9, 1, 18, 30, 100, 22, 85, 13 };
	cout << "Array的內容為: " << endl;
	for (int i = 0; i < SIZE; i++)
		cout << " "<< a[i];

	ms intMultiset; // Ims is typedef for "integer multiset"
	ostream_iterator< int > output(cout, " ");

	cout << "\n目前有 " << intMultiset.count(15)
		<< " 個key值為 15的元素在 multiset當中\n\n";

	intMultiset.insert(15); // insert 15 in intMultiset
	intMultiset.insert(15); // insert 15 in intMultiset

	cout << "經過insert後,multiset的內容為: \n";
	copy(intMultiset.begin(), intMultiset.end(), output);

	cout << "\n\n經過insert後,目前有 " << intMultiset.count(15)
		<< " 個值為 15的元素在 multiset當中\n\n";

	ms::const_iterator result;

	
	result = intMultiset.find(15); //回傳1個指向key值15的Iterator
								   //找不到則回傳end()=-1
	if (result != intMultiset.end()) 
		cout << "找到值為15\n"; // found search value 15

									
	result = intMultiset.find(20);

	if (result == intMultiset.end()) // will be true hence
		cout << "找不到值為20\n"; // did not find 20

										   // insert elements of array a into intMultiset
	intMultiset.insert(a, a + SIZE);
	cout << "\n經過insert後, intMultiset的內容為:\n";
	copy(intMultiset.begin(), intMultiset.end(), output);

	// lower_bound : 回傳一個大於等於給定值的Iterator
	// upper_bound : 回傳一個大於給定值的Iterator
	cout << "\n\n大於等於22的值為: "
		<< *(intMultiset.lower_bound(22));
	cout << "\n大於22的值為: " << *(intMultiset.upper_bound(22));

	// p 用來表示pair <first,second> , first和second皆為結構成員並非鍵值
	pair< ms::const_iterator, ms::const_iterator > p;

	// equal_range : 取得所有等價於22的元素範圍[first, last)
	p = intMultiset.equal_range(22); //p的成員結構裝載equal_range的元素範圍[first, last)

	cout << "\n\n等價於22的元素範圍:" << "\n   Lower bound[]: "
		<< *(p.first) << "\n   Upper bound(): " << *(p.second);
	cout << endl;
}

void SetIteratorTest2()
{
	const int SIZE = 5;
	double a[SIZE] = { 2.1, 4.2, 9.5, 2.1, 3.7 };
	DoubleSet doubleSet(a, a + SIZE);;
	ostream_iterator< double > output(cout, " ");

	cout << "doubleSet 內容為: ";
	copy(doubleSet.begin(), doubleSet.end(), output);

	// p represents pair containing const_iterator and bool
	pair< DoubleSet::const_iterator, bool > p;
	
	p = doubleSet.insert(13.8); //p的成員結構裝載insert()回傳插入值,是否插入
	cout << "\n\n" << *(p.first)
		<< (p.second ? " 已被" : " 未被") << " 插入過";
	cout << "\ndoubleSet 內容為: ";
	copy(doubleSet.begin(), doubleSet.end(), output);

	// insert 9.5 in doubleSet
	p = doubleSet.insert(9.5); //p的成員結構裝載insert()回傳插入值,是否插入
	cout << "\n\n" << *(p.first)
		<< (p.second ? " 已被" : " 未被") << " 插入過";
	cout << "\ndoubleSet 內容為: ";
	copy(doubleSet.begin(), doubleSet.end(), output);
	cout << endl;
}

void MapIteratorTest1()
{
	MultiMap map; // declare the multimap pairs

	cout << "目前有 " << map.count(15)
		<< " 個key值為15的元素在multimap中\n";

	// MultiMap::value_type(key,value) : 建立欲放入到MultiMap的pair物件
	map.insert(MultiMap::value_type(15, 2.7));
	map.insert(MultiMap::value_type(15, 99.3));

	cout << "經過 inserts後, 目前有 " << map.count(15)
		<< " 個key值為15的元素在multimap中\n\n";

	// insert five value_type objects in pairs
	map.insert(MultiMap::value_type(30, 111.11));
	map.insert(MultiMap::value_type(10, 22.22));
	map.insert(MultiMap::value_type(25, 33.333));
	map.insert(MultiMap::value_type(20, 9.345));
	map.insert(MultiMap::value_type(5, 77.54));

	cout << "Multimap 的內容為:\nKey\tValue\n";

	// use const_iterator t走訪Multimap中的每個元素
	for (MultiMap::const_iterator iter = map.begin();
		iter != map.end(); ++iter)
		cout << iter->first << '\t' << iter->second << '\n';

	cout << endl;
}

void MapIteratorTest2()
{
	Map map;

	// Map::value_type(key,value) : 建立欲放入到Map的pair物件
	map.insert(Map::value_type(15, 2.7));
	map.insert(Map::value_type(30, 111.11));
	map.insert(Map::value_type(5, 1010.1));
	map.insert(Map::value_type(10, 22.22));
	map.insert(Map::value_type(25, 33.333));
	map.insert(Map::value_type(5, 77.54)); // key值重複忽略
	map.insert(Map::value_type(20, 9.345));
	map.insert(Map::value_type(15, 99.3)); // key值重複忽略

	cout << "Map內容為:\nKey\tValue\n";

	// 使用 const_iterator 去走訪map中所有的元素
	for (Map::const_iterator iter = map.begin();
		iter != map.end(); ++iter)
		cout << iter->first << '\t' << iter->second << '\n';

	map[25] = 9999.99; // use subscripting修改
	map[40] = 8765.43; // use subscripting插入

	cout << "\nAfter subscript 操作, map的內容為:\nKey\tValue\n";

	// use const_iterator to walk through elements of pairs
	for (Map::const_iterator iter = map.begin();
		iter != map.end(); ++iter)
		cout << iter->first << '\t' << iter->second << '\n';

	cout << endl;
}

void StackAdapterTest()
{
	// stack 的容器若不指定預設使用deque
	stack< int > dequeStack;

	// stack 隱含使用 vector作為容器
	stack< int, vector< int > > vectorStack;

	// stack 隱含使用 list作為容器
	stack< int, list< int > > listStack;

	// push the values 0-9 onto each stack 
	cout << "Pushing onto intDequeStack: ";
	push(dequeStack);
	cout << "\nPushing onto intVectorStack: ";
	push(vectorStack);
	cout << "\nPushing onto intListStack: ";
	push(listStack);
	cout << endl << endl;

	// display and remove elements from each stack
	cout << "Popping from intDequeStack: ";
	pop(dequeStack);
	cout << "\nPopping from intVectorStack: ";
	pop(vectorStack);
	cout << "\nPopping from intListStack: ";
	pop(listStack);
	cout << endl;
}

template< typename T > void push(T &stack)
{
	for (int i = 0; i < 10; i++)
	{
		stack.push(i); // push element onto stack
		cout << stack.top() << ' '; // view (and display) top element
	} // end for
} // end function pushElements
template< typename T > void pop(T &stack)
{
	while (!stack.empty())
	{
		cout << stack.top() << ' '; // view (and display) top element
		stack.pop(); // remove top element
	} // end while
} // end function popElements

void QueueAdapterTest()
{
	queue< double > queue; // queue with doubles

							// push elements onto queue values
	queue.push(3.2);
	queue.push(9.8);
	queue.push(5.4);

	cout << "Popping from values: ";

	// pop elements from queue
	while (!queue.empty())
	{
		cout << queue.front() << ' '; // view front element
		queue.pop(); // remove element 
	} // end while

	cout << endl;
}

void PQAdapterTest()
{
	priority_queue< double > priority; // create priority_queue

										 // 預設優先權由大到小
	priority.push(3.2);
	priority.push(9.8);
	priority.push(5.4);

	cout << "Popping from priorities: ";

	// pop element from priority_queue
	while (!priority.empty())
	{
		cout << priority.top() << ' '; // view top element
		priority.pop(); // remove top element
	} // end while

	cout << endl;
}

char nextLetter()
{
	static char letter = 'A';
	return letter++;
	// end function nextLetter
}
void AssignmentTest()
{
	vector< char > v(10);
	ostream_iterator< char > output(cout, " ");
	fill(v.begin(), v.end(), '5'); // 設定 vector 裡的內容全為5

	cout << "目前Vector的內容為:\n";
	copy(v.begin(), v.end(), output);

	
	fill_n(v.begin(), 5, 'A');
	cout << "\n\nVector經過填入5個A的內容:\n";
	copy(v.begin(), v.end(), output);

	generate(v.begin(), v.end(), nextLetter); //nextLetter為靜態區域參數
	cout << "\n\nVector使用生成函數填入字元 A-J:\n";
	copy(v.begin(), v.end(), output);

	generate_n(v.begin(), 5, nextLetter);
	cout << "\n\nVector使用生成函數繼續填入字元 K-O 到前5個元素:\n";
	copy(v.begin(), v.end(), output);

	cout << endl;
}

void CompareTest()
{
	const int SIZE = 10;
	int a1[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int a2[SIZE] = { 1, 2, 3, 4, 1000, 6, 7, 8, 9, 10 };
	vector< int > v1(a1, a1 + SIZE); // copy of a1
	vector< int > v2(a1, a1 + SIZE); // copy of a1
	vector< int > v3(a2, a2 + SIZE); // copy of a2
	ostream_iterator< int > output(cout, " ");

	cout << "Vector v1 內容為: ";
	copy(v1.begin(), v1.end(), output);
	cout << "\nVector v2 內容為: ";
	copy(v2.begin(), v2.end(), output);
	cout << "\nVector v3 內容為: ";
	copy(v3.begin(), v3.end(), output);

	// eaual: 比較兩個範圍內容是否相等
	bool result = equal(v1.begin(), v1.end(), v2.begin());
	cout << "\n\nVector v1 " << (result ? "等" : "不等")
		<< "於vector v2.\n";

	// compare vectors v1 and v3 for equality
	result = equal(v1.begin(), v1.end(), v3.begin());
	cout << "\n\nVector v1 " << (result ? "等" : "不等")
		<< "於vector v3.\n";

	// location represents pair of vector iterators
	pair< vector< int >::iterator, vector< int >::iterator > location;

	// mismatch : 回傳由前2個不相等元素而成的pair物件,first為範圍1的差異元素,second為範圍2的差異元素
	location = mismatch(v1.begin(), v1.end(), v3.begin());
	cout << "\n v1 和 v3 之間有一個差異，發生在位置"
		<< (location.first - v1.begin()) << "\n且v1的差異元素為: "
		<< *location.first << ", v3的差異元素為: " << *location.second
		<< "\n\n";

	char c1[SIZE] = "HELLO";
	char c2[SIZE] = "BYE BYE";

	// lexicographical_comparison : 比較第一範圍按字典內容排序是否小於第二範圍
	result = lexicographical_compare(c1, c1 + SIZE, c2, c2 + SIZE);
	cout << c1 << (result ? " 小於 " :
		" 大於等於 ") << c2 << endl;
}

bool filter(int x)
{
	return x > 9;
} // end function filter

void RemoveTest()
{
	const int SIZE = 10;
	int array[SIZE] = { 10, 2, 10, 4, 16, 6, 14, 8, 12, 10 };
	ostream_iterator< int > output(cout, " ");
	vector< int > v1(array, array + SIZE); // 以array的內容建立vector v1
	vector< int >::iterator newLastElement;

	cout << "Vector v1 原本的內容:\n   ";
	copy(v1.begin(), v1.end(), output);

	// remove :從指定範圍中消除但不刪除所有等於value的元素,
	//並回傳最後一個未被削除的元素位址為起始的Iterator
	newLastElement = remove(v1.begin(), v1.end(), 10);
	cout << "\nVector v1 移除所有10之後的結果:\n   ";
	copy(v1.begin(), newLastElement, output);
	cout << "(remove)" << endl;

	vector< int > v2(array, array + SIZE); // 以array的內容建立vector v2
	vector< int > temp1(SIZE, 0); 
	cout << "\n\nVector v2 原本的內容:\n   ";
	copy(v2.begin(), v2.end(), output);

	// remove_copy : 將範圍[first,last)裡面，值不等於val的元素
	// 逐一複製到從result開始的位置,但不移除原本內容
	remove_copy(v2.begin(), v2.end(), temp1.begin(), 10);
	cout << "\n\nVector v2 的內容不變:\n   ";
	copy(v2.begin(), v2.end(), output);
	cout << "\nVector temp1 被複製進去的內容:\n   ";
	copy(temp1.begin(), temp1.end(), output);
	cout << "(remove_copy)" << endl;


	vector< int > v3(array, array + SIZE); // copy of a
	cout << "\n\nVector v3 原本的內容:\n   ";
	copy(v3.begin(), v3.end(), output);

	// remove :從指定範圍中以過濾規則消除但不刪除元素,
	//並回傳最後一個未被削除的元素位址為起始的Iterator
	newLastElement = remove_if(v3.begin(), v3.end(), filter);
	cout << "\nVector v3 經過filter後移除的內容(filter : > 9):"
		<< "\n(大於9的元素被移除):\n   ";
	copy(v3.begin(), newLastElement, output);
	cout << "(remove_if)" << endl;

	vector< int > v4(array, array + SIZE); // copy of a
	vector< int > temp2(SIZE, 0); // instantiate vector c2
	cout << "\n\nVector v4 原本的內容:\n   ";
	copy(v4.begin(), v4.end(), output);

	// remove_copy_if : 將範圍[first,last)裡面，將不符合過濾規則的元素
	// 逐一複製到從result開始的位置,但不移除原本內容
	remove_copy_if(v4.begin(), v4.end(), temp2.begin(), filter);
	cout << "\n\nVector v4 的內容不變:\n   ";
	copy(v4.begin(), v4.end(), output);
	cout << "\nVector temp2 被複製進去的內容，不符合過濾規則(filter : > 9)的元素:\n   ";
	copy(temp2.begin(), temp2.end(), output);
	cout << "(remove_copy_if)" << endl;
	cout << endl;
}

void ReplaceTest()
{
	const int SIZE = 10;
	int a[SIZE] = { 10, 2, 10, 4, 16, 6, 14, 8, 12, 10 };
	ostream_iterator< int > output(cout, " ");

	vector< int > v1(a, a + SIZE); // 以array的內容建立vector v1
	cout << "Vector v1 原本的內容:\n   ";
	copy(v1.begin(), v1.end(), output);

	// replace : 以 new_value 替換範圍 [first, last) 中所有滿足特定判別標準的元素
	replace(v1.begin(), v1.end(), 10, 100);
	cout << "\nVector v1 經過replace後的內容:\n   ";
	copy(v1.begin(), v1.end(), output);

	vector< int > v2(a, a + SIZE); 
	vector< int > temp1(SIZE); // instantiate vector c1
	cout << "\n\nVector v2 原本的內容:\n   ";
	copy(v2.begin(), v2.end(), output);	

	// replace_copy : 將原內容複製到新位址，
	// 再以 new_value替換範圍[first, last)中所有滿足條件的元素
	
	replace_copy(v2.begin(), v2.end(), temp1.begin(), 10, 100);
	cout << "\ntemp1 經過replace_copy後的內容:\n   ";
	copy(temp1.begin(), temp1.end(), output);

	vector< int > v3(a, a + SIZE); // copy of a
	cout << "\n\nVector v3 原本的內容:\n   ";
	copy(v3.begin(), v3.end(), output);

	// replace : 以 new_value 替換範圍 [first, last) 中
	// 所有滿足filter條件的元素
	replace_if(v3.begin(), v3.end(), filter, 100);
	cout << "\ntemp1 經過replace_if後的內容:"
		<< "\n(filter > 9):\n   ";
	copy(v3.begin(), v3.end(), output);

	vector< int > v4(a, a + SIZE); // copy of a
	vector< int > temp2(SIZE); // instantiate vector c2
	cout << "\n\nVector v4 原本的內容\n   ";
	copy(v4.begin(), v4.end(), output);

	// replace_copy : 將原內容複製到新位址，
	// 再以 new_value替換範圍[first, last)中
	// 所有滿足filter條件的元素
	replace_copy_if(v4.begin(), v4.end(), temp2.begin(), filter, 100);
	cout << "\ntemp2 經過replace_copy_if後的內容:"
		<< "\n(filter > 9):\n   ";
	copy(temp2.begin(), temp2.end(), output);
	cout << endl;
}


void outputSquare(int value)
{
	cout << value * value << ' ';
} // end function outputSquare
int calculateCube(int value)
{
	return value * value * value;
} // end function calculateCube
void MathCalcTest()
{
	const int SIZE = 10;
	int a1[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector< int > v(a1, a1 + SIZE); // copy of a1
	ostream_iterator< int > output(cout, " ");

	// random_shuffle : 隨機排列元素
	cout << "Vector v before random_shuffle: ";
	copy(v.begin(), v.end(), output);

	random_shuffle(v.begin(), v.end()); // shuffle elements of v
	cout << "\nVector v after random_shuffle: ";
	copy(v.begin(), v.end(), output);

	int a2[SIZE] = { 100, 2, 8, 1, 50, 3, 8, 8, 9, 10 };
	vector< int > v2(a2, a2 + SIZE); // copy of a2
	cout << "\n\nVector v2 contains: ";
	copy(v2.begin(), v2.end(), output);

	// count : 統計容器中等於value的元素個數
	int result = count(v2.begin(), v2.end(), 8);
	cout << "\nNumber of elements matching 8: " << result;

	// count_if : 統計容器中符合條件的元素個數
	result = count_if(v2.begin(), v2.end(), filter);
	cout << "\nNumber of elements greater than 9: " << result;

	// min_element : 回傳範圍中最小元素位址
	cout << "\n\nMinimum element in Vector v2 is: "
		<< *(min_element(v2.begin(), v2.end()));

	// max_element : 回傳範圍中最大元素位址
	cout << "\nMaximum element in Vector v2 is: "
		<< *(max_element(v2.begin(), v2.end()));

	// accumulate : 將範圍內的數值加總，並轉為第三參數型態
	// 與第三參數相加 (第三參數為初值) 
	cout << "\n\nThe total of the elements in Vector v is: "
		<< accumulate(v.begin(), v.end(), 0);

	// for_each : 按照順序將容器內的元素代入到指定函數執行
	cout << "\n\nThe square of every integer in Vector v is:\n";
	for_each(v.begin(), v.end(), outputSquare);

	vector< int > cubes(SIZE); // instantiate vector cubes

	// transform : 將範圍內的元素代入到指定函數，並將回傳元素放入新的容器位址
	transform(v.begin(), v.end(), cubes.begin(), calculateCube);
	cout << "\n\nThe cube of every integer in Vector v is:\n";
	copy(cubes.begin(), cubes.end(), output);
	cout << endl;
}

void SearchTest()
{
	const int SIZE = 10;
	int a[SIZE] = { 10, 2, 17, 5, 16, 8, 13, 11, 20, 7 };
	vector< int > v(a, a + SIZE); // copy of a
	ostream_iterator< int > output(cout, " ");

	cout << "Vector v 的內容為: ";
	copy(v.begin(), v.end(), output); // display output vector

									  // locate first occurrence of 16 in v
	vector< int >::iterator location;
	// find : 回傳第一個滿足條件的迭代器 (條件 == 16)
	location = find(v.begin(), v.end(), 16);

	if (location != v.end()) // found 16
		cout << "\n\nFound 16 at location " << (location - v.begin());
	else // 16 not found
		cout << "\n\n16 not found";

	// locate first occurrence of 100 in v
	location = find(v.begin(), v.end(), 100);

	if (location != v.end()) // found 100
		cout << "\nFound 100 at location " << (location - v.begin());
	else // 100 not found 
		cout << "\n100 not found";

	// find_if : 回傳第一個滿足filter函數的迭代器 (filter > 9)
	location = find_if(v.begin(), v.end(), filter);

	if (location != v.end()) // found value greater than 9
		cout << "\n\nThe first value greater than 9 is " << *location
		<< "\nfound at location " << (location - v.begin());
	else // value greater than 9 not found
		cout << "\n\nNo values greater than 9 were found";

	// sort : 以遞增排序範圍
	sort(v.begin(), v.end());
	cout << "\n\nVector v after sort: ";
	copy(v.begin(), v.end(), output);

	// binary_search : 以二元搜尋法查詢範圍內指定元素,找到則回傳true
	if (binary_search(v.begin(), v.end(), 13))
		cout << "\n\n13 was found in v";
	else
		cout << "\n\n13 was not found in v";

	// use binary_search to locate 100 in v
	if (binary_search(v.begin(), v.end(), 100))
		cout << "\n100 was found in v";
	else
		cout << "\n100 was not found in v";

	cout << endl;
}

void SwapTest()
{
	const int SIZE = 10;
	int a[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	ostream_iterator< int > output(cout, " ");

	cout << "Array a contains:\n   ";
	copy(a, a + SIZE, output); // display array a

	// swap : 交換兩指定位置元素(傳址)
	swap(a[0], a[1]);

	cout << "\nArray a after swapping a[0] and a[1] using swap:\n   ";
	copy(a, a + SIZE, output); // display array a

	// iter_swap : 交換兩指定位置元素(傳參考Iterator)
	iter_swap(&a[0], &a[1]); // swap with iterators                       
	cout << "\nArray a after swapping a[0] and a[1] using iter_swap:\n   ";
	copy(a, a + SIZE, output);

	// swap_ranges : 將範圍A的元素,從範圍B開始依序做交換
	swap_ranges(a, a + 5, a + 5);

	cout << "\nArray a after swapping the first five elements\n"
		<< "with the last five elements:\n   ";
	copy(a, a + SIZE, output);
	cout << endl;
}

void RangeItemUpdate1()
{
	const int SIZE = 5;
	int a1[SIZE] = { 1, 3, 5, 7, 9 };
	int a2[SIZE] = { 2, 4, 5, 7, 9 };
	vector< int > v1(a1, a1 + SIZE); // copy of a1
	vector< int > v2(a2, a2 + SIZE); // copy of a2
	ostream_iterator< int > output(cout, " ");

	cout << "Vector v1 的原本內容為: ";
	copy(v1.begin(), v1.end(), output); // display vector output
	cout << "\nVector v2 的原本內容為: ";
	copy(v2.begin(), v2.end(), output); // display vector output

	vector< int > results(v1.size());

	// copy_backward : 將範圍內的元素以逆序方式複製到新位址
	// 以保持其相對順序
	copy_backward(v1.begin(), v1.end(), results.end());
	cout << "\n\nAfter copy_backward, results contains: ";
	copy(results.begin(), results.end(), output);

	vector< int > v3(v1.size() + v2.size());

	// merge : 將兩段範圍的元素，複製到新的起始位址並做排序
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	cout << "\n\nAfter merge of v1 and v2 results2 contains:\n";
	copy(v3.begin(), v3.end(), output);

	// unique : 回傳消除重複元素範圍的迭代器尾端位址
	vector< int >::iterator endLocation;
	endLocation = unique(v3.begin(), v3.end());

	cout << "\n\nAfter unique v3 contains:\n";
	copy(v3.begin(), endLocation, output);

	// reverse : 反轉範圍中的元素順序
	cout << "\n\nVector v1 after reverse: ";
	reverse(v1.begin(), v1.end()); // reverse elements of v1 
	copy(v1.begin(), v1.end(), output);
	cout << endl;
}

void RangeItemUpdate2()
{
	const int SIZE = 10;
	int a1[SIZE] = { 1, 3, 5, 7, 9, 1, 3, 5, 7, 9 };
	vector< int > v1(a1, a1 + SIZE); // copy of a
	ostream_iterator< int > output(cout, " ");

	cout << "Vector v1 contains: ";
	copy(v1.begin(), v1.end(), output);

	// inplace_merge : 容器內分兩個有序的範圍重新合併
	inplace_merge(v1.begin(), v1.begin() + 5, v1.end());

	cout << "\nAfter inplace_merge, v1 contains: ";
	copy(v1.begin(), v1.end(), output);

	vector< int > unique;

	// unique_copy : 複製不重複元素到目標容器
	unique_copy(v1.begin(), v1.end(), back_inserter(unique));
	cout << "\nAfter unique_copy results1 contains: ";
	copy(unique.begin(), unique.end(), output);

	vector< int > reverse;

	// reverse_copy : 複製範圍內的元素到新範圍中並以逆序排列
	reverse_copy(v1.begin(), v1.end(), back_inserter(reverse));
	cout << "\nAfter reverse_copy, results2 contains: ";
	copy(reverse.begin(), reverse.end(), output);
	cout << endl;
}

void SetOperate()
{
	const int SIZE1 = 10, SIZE2 = 5, SIZE3 = 20;
	int a1[SIZE1] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int a2[SIZE2] = { 4, 5, 6, 7, 8 };
	int a3[SIZE2] = { 4, 5, 6, 11, 15 };
	ostream_iterator< int > output(cout, " ");

	cout << "a1 contains: ";
	copy(a1, a1 + SIZE1, output); // display array a1
	cout << "\na2 contains: ";
	copy(a2, a2 + SIZE2, output); // display array a2
	cout << "\na3 contains: ";
	copy(a3, a3 + SIZE2, output); // display array a3

	// includes : 檢查已排序範圍B是否為已排序範圍A的子序列
	if (includes(a1, a1 + SIZE1, a2, a2 + SIZE2))
		cout << "\n\na1 includes a2";
	else
		cout << "\n\na1 does not include a2";

	// determine whether set a3 is completely contained in a1
	if (includes(a1, a1 + SIZE1, a3, a3 + SIZE2))
		cout << "\na1 includes a3";
	else
		cout << "\na1 does not include a3";

	int difference[SIZE1];

	// set_intersection : 取2範圍集合差集內容放到新範圍起始位址
	// 並回傳新範圍尾端Iterator
	int *ptr = set_difference(a1, a1 + SIZE1,
		a2, a2 + SIZE2, difference);
	cout << "\n\nset_difference of a1 and a2 is: ";
	copy(difference, ptr, output);

	int intersection[SIZE1];

	// set_intersection : 取2範圍集合交集內容放到新範圍起始位址
	// 並回傳新範圍尾端Iterator
	ptr = set_intersection(a1, a1 + SIZE1,
		a2, a2 + SIZE2, intersection);
	cout << "\n\nset_intersection of a1 and a2 is: ";
	copy(intersection, ptr, output);

	int symmetric_difference[SIZE1 + SIZE2];

	// set_intersection : 取2範圍集合對稱差集內容放到新範圍起始位址
	// 並回傳新範圍尾端Iterator (集合對稱差集 : (A∪B)－A∩B)
	ptr = set_symmetric_difference(a1, a1 + SIZE1,
		a3, a3 + SIZE2, symmetric_difference);
	cout << "\n\nset_symmetric_difference of a1 and a3 is: ";
	copy(symmetric_difference, ptr, output);

	int unionSet[SIZE3];

	// set_union : 取2範圍集合合併內容放到新範圍起始位址
	// 並回傳新範圍尾端Iterator
	ptr = set_union(a1, a1 + SIZE1, a3, a3 + SIZE2, unionSet);
	cout << "\n\nset_union of a1 and a3 is: ";
	copy(unionSet, ptr, output);
	cout << endl;
}

void RangeBound()
{
	const int SIZE = 10;
	int a1[SIZE] = { 2, 2, 4, 4, 4, 6, 6, 6, 6, 8 };
	vector< int > v(a1, a1 + SIZE); // copy of a1
	ostream_iterator< int > output(cout, " ");

	cout << "Vector v contains:\n";
	copy(v.begin(), v.end(), output);

	// lower_bound : 回傳第一個大於等於指定元素的迭代器位址
	vector< int >::iterator lower;
	lower = lower_bound(v.begin(), v.end(), 6);
	cout << "\n\nLower bound of 6 is index "
		<< (lower - v.begin()) << " of vector v";

	// upper_bound : 回傳第一個大於指定元素的迭代器位址
	vector< int >::iterator upper;
	upper = upper_bound(v.begin(), v.end(), 6);
	cout << "\nUpper bound of 6 is index "
		<< (upper - v.begin()) << " of vector v";

	// equal_range : 在已排序的[first,last)中尋找value，
	// 且回傳一對迭代器i和j，分別為在不破壞次序的前提下
	// 可插入的第1個以及最後1個位置
	pair< vector< int >::iterator, vector< int >::iterator > eq;
	eq = equal_range(v.begin(), v.end(), 6);
	cout << "\nUsing equal_range:\n   Lower bound of 6 is element "
		<< (eq.first - v.begin()) << " of vector v";
	cout << "\n   Upper bound of 6 is element "
		<< (eq.second - v.begin()) << " of vector v";
	
	cout << "\n\n使用 upper_bound 去找尋在不破壞次序的前提下\n"
		<< "5可以被插入到序列中的first 位置";
	lower = lower_bound(v.begin(), v.end(), 5);
	cout << "\n   Lower bound of 5 is element "
		<< (lower - v.begin()) << " of vector v";

	cout << "\n\n使用 upper_bound 去找尋在不破壞次序的前提下\n"
		<< "7可以被插入到序列中的last 位置";
	upper = upper_bound(v.begin(), v.end(), 7);
	cout << "\n   Upper bound of 7 is element "
		<< (upper - v.begin()) << " of vector v";


	cout << "\n\n使用 equal_range 去找尋在不破壞次序的前提下\n"
		<< "5可以被插入到序列中 first 和 last 位置";
	eq = equal_range(v.begin(), v.end(), 5);
	cout << "\n   Lower bound of 5 is element "
		<< (eq.first - v.begin()) << " of vector v";
	cout << "\n   Upper bound of 5 is element "
		<< (eq.second - v.begin()) << " of vector v" << endl;
}

void HeapSortTest()
{
	const int SIZE = 10;
	int a[SIZE] = { 3, 100, 52, 77, 22, 31, 1, 98, 13, 40 };
	vector< int > v(a, a + SIZE); // copy of a
	vector< int > v2;
	ostream_iterator< int > output(cout, " ");

	cout << "Vector v 建立heap前的內容:\n";
	copy(v.begin(), v.end(), output);

	make_heap(v.begin(), v.end()); // create heap from vector v
	cout << "\nVector v 建立heap後的內容:\n";
	copy(v.begin(), v.end(), output);

	sort_heap(v.begin(), v.end()); // sort elements with sort_heap
	cout << "\nVector v 使用sort_heap直接進行排序:\n";
	copy(v.begin(), v.end(), output);

	cout << "\n\n使用push_heap 和 push_back 依序建立heap";
	cout << "\nArray a contains: ";
	copy(a, a + SIZE, output); // display array a
	cout << endl;

	// place elements of array a into v2 and 
	// maintain elements of v2 in heap
	for (int i = 0; i < SIZE; i++)
	{
		v2.push_back(a[i]); // push_back : 每次從最後面插入元素到Vector
		push_heap(v2.begin(), v2.end()); //push_heap : 將插入元素放至heap適當位置
		cout << "\nv2 after push_heap(a[" << i << "]): ";
		copy(v2.begin(), v2.end(), output);
	} // end for

	cout << endl;

	// remove elements from max-heap(預設) in sorted order
	for (unsigned int j = 0; j < v2.size(); j++)
	{
		cout << "\nv2 after " << v2[0] << " popped from heap\n";
		pop_heap(v2.begin(), v2.end() - j); // pop_heap : 每次將頂端元素與最後一個元素交換
		copy(v2.begin(), v2.end(), output);
	} // end for

	cout << endl;
}

void findPrime()
{
	const int SIZE = 1024;
	int value;
	bitset< SIZE > sieve; // 建立大小為1024的bitset(預設皆為0)
	sieve.flip(); // flip : 反轉bitset內容為1
	sieve.reset(0); // reset first bit (0:不為Prime)         
	sieve.reset(1); // reset second bit (1:不為Prime)        
	// 位址i若為0，代表數值i不為Prime
	// 位址i若為1，代表數值i為Prime
					// perform Sieve of Eratosthenes
	int finalBit = sqrt(static_cast< double >(sieve.size())) + 1;
	// finalBit : 開根號n + 1

	// 從2開始依序把所有倍數剔除掉；再用下一個質數
	for (int i = 2; i < finalBit; i++)
	{
		if (sieve.test(i)) // bit i is on
		{
			for (int j = 2 * i; j < SIZE; j += i)
				sieve.reset(j); // set bit j off (不為Prime)
		} // end if
	} // end for

	cout << "The prime numbers in the range 2 to 1023 are:\n";

	// display prime numbers in range 2-1023
	for (int k = 2, counter = 1; k < SIZE; k++)
	{
		if (sieve.test(k)) // 若K為on代表k為Prime就輸出
		{
			cout << setw(5) << k;

			if (counter++ % 12 == 0) // counter is a multiple of 12
				cout << '\n'; //每輸出12個數字就換行
		} // end if          
	} // end for    

	cout << endl;

	// get value from user 
	cout << "\nEnter a value from 2 to 1023 (-1 to end): ";
	cin >> value;

	// determine whether user input is prime
	while (value != -1)
	{
		if (sieve[value]) // prime number
			cout << value << " is a prime number\n";
		else // not a prime number
			cout << value << " is not a prime number\n";

		cout << "\nEnter a value from 2 to 1023 (-1 to end): ";
		cin >> value;
	} // end while
}

void FunctionTest()
{
	const int SIZE = 10;
	int array[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector< int > integers(array, array + SIZE); // copy of array
	ostream_iterator< int > output(cout, " ");
	int result;

	cout << "vector integers contains:\n";
	copy(integers.begin(), integers.end(), output);

	// calculate sum 
	// 用二元函數sumSquares求和元素，並應用到其左側運算數
	// 第1參數為前一個function的回傳結果
	// 第2參數為Vector的內容
	result = accumulate(integers.begin(), integers.end(),
		0, sumSquares);

	cout << "\n\nSum of squares of elements in integers using "
		<< "binary\nfunction sumSquares: " << result;

	// calculate sum 
	// 用自訂類型二元函數SumSquaresClass求和元素，並應用到其左側運算數
	// 第1參數為前一個function的回傳結果
	// 第2參數為Vector的內容
	result = accumulate(integers.begin(), integers.end(),
		0, SumSquaresClass< int >());

	cout << "\n\nSum of squares of elements in integers using "
		<< "binary\nfunction object of type "
		<< "SumSquaresClass< int >: " << result << endl;
}
