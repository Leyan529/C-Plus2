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
//�w�qms��multiset<����,������<����>> �B��ƧǯS��

void SetIteratorTest2();
typedef set <double, less<double> > DoubleSet;
//�w�qDoubleSet��set<����,������<����>> �B��ƧǯS��

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
char nextLetter(); // nextLetter�@��generate function
void AssignmentTest();
void CompareTest();

bool filter(int); // remove_if��k���L�o��
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
	cout << "��J2�Ӿ��" << endl;
	istream_iterator<int> input(cin); // �j�w�зǿ�J�˸m 

	int a = *input;
	int b = *++input;

	ostream_iterator<int> output(cout); // �j�w�зǿ�X�˸m
	cout << "�`�M�O : ";
	*output = a + b;
	cout << endl<<"�ۮt�O : ";
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
	//rbegin�^�Ǥ@�ӫ��V���ݤ������f�V���N��
	//rend�^�Ǥ@�ӫ��V�e�ݤ������f�V���N��
	for (rit = v.rbegin(); rit != v.rend(); ++rit) 
		cout << *rit << " ";
}

void VectorIteratorTest1()
{
	const int size = 6;
	int array[size] = { 1,2,3,4,5,6 };
	vector<int> v;
	cout << "vector��l�j�p��" << v.size() << endl
		<< "vector��l�e�q��" << v.capacity() << endl;
	for (int i = 1; i < size-2; i++) {
		v.push_back(array[i]);
	}

	cout << "vector�j�p��" << v.size() << endl
		<< "vector�e�q��" << v.capacity() << endl;
	cout << "\n\n �ϥΫ��п�X�}�C:" << endl;

	for (int *ptr = array; ptr != array + size; ptr++)
		cout << *ptr << " ";

	cout << "\n �ϥ�Iterator�覡��XVector" << endl;
	printVector(v);
	cout << "\n ����Vector���e :" << endl;
	printRevVector(v);
	cout << endl;
}

void VectorIteratorTest2()
{
	const int SIZE = 6;
	int array[SIZE] = { 1,2,3,4,5,6 };
	vector<int> v(array, array + SIZE);
	ostream_iterator<int> output(cout, " "); //�j�w��X�˸m,�H" "�������Φr��

	cout << "Vector ���e�]�t: ";
	copy(v.begin(), v.end(), output); 
	//copy : �NVector�d�򤺪��Ҧ���ƽƻs���X��y���N��

	cout << "\n Vector ����1�Ӥ���: " << v.front()
		<< "\n Vector���̫�1�Ӥ���: " << v.back();

	v[0] = 7; //�]�w��0�Ӥ�����7
	v.at(2) = 10; //�]�w��2�Ӥ�����10 (�|�i������ˬd)
	v.insert(v.begin() + 1, 22); //�b��m2�W���J������22

	cout << "\n\n ���ܫ᪺Vector���e: ";
	copy(v.begin(), v.end(), output);

	try {
		v.at(100) = 777;
	}
	catch (out_of_range &outOfRange) {
		cout << "\n\nException: " << outOfRange.what();
	}

	v.erase(v.begin()); //erase :�����d�򤺪�����
	cout << "\n\n �M����1�Ӥ����᪺Vector���e: ";
	copy(v.begin(), v.end(), output);

	v.erase(v.begin(),v.end());
	cout << "\n\n �M���Ҧ������᪺Vector���e: "
		<< (v.empty() ? "����" : "�D��")<<endl;

	v.insert(v.begin(), array, array + SIZE); 
	//�Narray�����Ҧ������qVector����0�Ӧ�m�}�l���J
	cout << "�Narray�����Ҧ������qVector����0�Ӧ�m�}�l���J,"
		<< "�����M���e���e: ";
	copy(v.begin(), v.end(), output); 

	v.clear(); //�����Ҧ�����
	cout << "\n\n �M���Ҧ������᪺Vector���e: "
		<< (v.empty() ? "����" : "�D��") << endl;
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

	cout << "List1 ���e: ";
	printList(list1);

	list1.sort(); // sort values
	cout << "\n�Ƨǫ᪺List1���e: ";
	printList(list1);

	// �Narray�����������s�W��list2                  
	list2.insert(list2.begin(), array, array + SIZE);
	cout << "\n�s�W�᪺List2���e: ";
	printList(list2);

	// void splice ( iterator pos, list<T,Allocator>& x ); 
	// �Nx�����������ʨô��J��pos�᪺��m
	list1.splice(list1.end(), list2);
	cout << "\n�g�Lsplice�ʧ@��, list1�����e: ";
	printList(list1);

	list1.sort(); // sort values
	cout << "\n�g�Lsort�ʧ@��, list1�����e: ";
	printList(list1);

	// �Narray�����������s�W��list2   
	list2.insert(list2.begin(), array, array + SIZE);
	list2.sort();
	cout << "\n�g�Lsort�ʧ@��, list2�����e: ";
	printList(list2);

	// �Nlist2�������������A�ë��ӱƧǦX�֨�list1
	list1.merge(list2);
	cout << "\n�g�Lmerge�ʧ@�� \n list1�����e: ";
	printList(list1);
	cout << "\n list2�����e: ";
	printList(list2);

	list1.pop_front(); // pop_front(�h�Y)
	list1.pop_back(); // pop_back(�h��)
	cout << "\n�g�L pop_front �M pop_back:\n  list1�����e: ";
	printList(list1);

	list1.unique(); // �������Ƥ���
	cout << "\n�g�Lunique�ʧ@�� \n list1�����e: ";
	printList(list1);

	// swap : �Nlist1�Plist2�����e����
	list1.swap(list2);
	cout << "\n�g�Lswap�ʧ@�� \n list1�����e: ";
	printList(list1);
	cout << "\n list2�����e: ";
	printList(list2);

	// �Nlist2���d�򪺤��e������list1��
	list1.assign(list2.begin(), list2.end());
	cout << "\n�g�Lassign�ʧ@�� \n list1�����e: ";
	printList(list1);

	// �Nlist2�������������A�ë��ӱƧǦX�֨�list1
	list1.merge(list2);
	cout << "\n�g�Lmerge�ʧ@�� \n list1�����e: ";
	printList(list1);

	list1.remove(4); // �R��list1���Ҧ��Ȭ�4������
	cout << "\n�g�Lremove(4)�ʧ@�� \n list1�����e: ";
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
	ostream_iterator< double > output(cout, " "); //�j�w��X�˸m

	d1.push_front(2.2);
	d1.push_front(3.5);
	d1.push_back(1.1);

	cout << "d1 �����e��: ";

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
	cout << "Array�����e��: " << endl;
	for (int i = 0; i < SIZE; i++)
		cout << " "<< a[i];

	ms intMultiset; // Ims is typedef for "integer multiset"
	ostream_iterator< int > output(cout, " ");

	cout << "\n�ثe�� " << intMultiset.count(15)
		<< " ��key�Ȭ� 15�������b multiset��\n\n";

	intMultiset.insert(15); // insert 15 in intMultiset
	intMultiset.insert(15); // insert 15 in intMultiset

	cout << "�g�Linsert��,multiset�����e��: \n";
	copy(intMultiset.begin(), intMultiset.end(), output);

	cout << "\n\n�g�Linsert��,�ثe�� " << intMultiset.count(15)
		<< " �ӭȬ� 15�������b multiset��\n\n";

	ms::const_iterator result;

	
	result = intMultiset.find(15); //�^��1�ӫ��Vkey��15��Iterator
								   //�䤣��h�^��end()=-1
	if (result != intMultiset.end()) 
		cout << "���Ȭ�15\n"; // found search value 15

									
	result = intMultiset.find(20);

	if (result == intMultiset.end()) // will be true hence
		cout << "�䤣��Ȭ�20\n"; // did not find 20

										   // insert elements of array a into intMultiset
	intMultiset.insert(a, a + SIZE);
	cout << "\n�g�Linsert��, intMultiset�����e��:\n";
	copy(intMultiset.begin(), intMultiset.end(), output);

	// lower_bound : �^�Ǥ@�Ӥj�󵥩󵹩w�Ȫ�Iterator
	// upper_bound : �^�Ǥ@�Ӥj�󵹩w�Ȫ�Iterator
	cout << "\n\n�j�󵥩�22���Ȭ�: "
		<< *(intMultiset.lower_bound(22));
	cout << "\n�j��22���Ȭ�: " << *(intMultiset.upper_bound(22));

	// p �ΨӪ��pair <first,second> , first�Msecond�Ҭ����c�����ëD���
	pair< ms::const_iterator, ms::const_iterator > p;

	// equal_range : ���o�Ҧ�������22�������d��[first, last)
	p = intMultiset.equal_range(22); //p���������c�˸�equal_range�������d��[first, last)

	cout << "\n\n������22�������d��:" << "\n   Lower bound[]: "
		<< *(p.first) << "\n   Upper bound(): " << *(p.second);
	cout << endl;
}

void SetIteratorTest2()
{
	const int SIZE = 5;
	double a[SIZE] = { 2.1, 4.2, 9.5, 2.1, 3.7 };
	DoubleSet doubleSet(a, a + SIZE);;
	ostream_iterator< double > output(cout, " ");

	cout << "doubleSet ���e��: ";
	copy(doubleSet.begin(), doubleSet.end(), output);

	// p represents pair containing const_iterator and bool
	pair< DoubleSet::const_iterator, bool > p;
	
	p = doubleSet.insert(13.8); //p���������c�˸�insert()�^�Ǵ��J��,�O�_���J
	cout << "\n\n" << *(p.first)
		<< (p.second ? " �w�Q" : " ���Q") << " ���J�L";
	cout << "\ndoubleSet ���e��: ";
	copy(doubleSet.begin(), doubleSet.end(), output);

	// insert 9.5 in doubleSet
	p = doubleSet.insert(9.5); //p���������c�˸�insert()�^�Ǵ��J��,�O�_���J
	cout << "\n\n" << *(p.first)
		<< (p.second ? " �w�Q" : " ���Q") << " ���J�L";
	cout << "\ndoubleSet ���e��: ";
	copy(doubleSet.begin(), doubleSet.end(), output);
	cout << endl;
}

void MapIteratorTest1()
{
	MultiMap map; // declare the multimap pairs

	cout << "�ثe�� " << map.count(15)
		<< " ��key�Ȭ�15�������bmultimap��\n";

	// MultiMap::value_type(key,value) : �إ߱���J��MultiMap��pair����
	map.insert(MultiMap::value_type(15, 2.7));
	map.insert(MultiMap::value_type(15, 99.3));

	cout << "�g�L inserts��, �ثe�� " << map.count(15)
		<< " ��key�Ȭ�15�������bmultimap��\n\n";

	// insert five value_type objects in pairs
	map.insert(MultiMap::value_type(30, 111.11));
	map.insert(MultiMap::value_type(10, 22.22));
	map.insert(MultiMap::value_type(25, 33.333));
	map.insert(MultiMap::value_type(20, 9.345));
	map.insert(MultiMap::value_type(5, 77.54));

	cout << "Multimap �����e��:\nKey\tValue\n";

	// use const_iterator t���XMultimap�����C�Ӥ���
	for (MultiMap::const_iterator iter = map.begin();
		iter != map.end(); ++iter)
		cout << iter->first << '\t' << iter->second << '\n';

	cout << endl;
}

void MapIteratorTest2()
{
	Map map;

	// Map::value_type(key,value) : �إ߱���J��Map��pair����
	map.insert(Map::value_type(15, 2.7));
	map.insert(Map::value_type(30, 111.11));
	map.insert(Map::value_type(5, 1010.1));
	map.insert(Map::value_type(10, 22.22));
	map.insert(Map::value_type(25, 33.333));
	map.insert(Map::value_type(5, 77.54)); // key�ȭ��Ʃ���
	map.insert(Map::value_type(20, 9.345));
	map.insert(Map::value_type(15, 99.3)); // key�ȭ��Ʃ���

	cout << "Map���e��:\nKey\tValue\n";

	// �ϥ� const_iterator �h���Xmap���Ҧ�������
	for (Map::const_iterator iter = map.begin();
		iter != map.end(); ++iter)
		cout << iter->first << '\t' << iter->second << '\n';

	map[25] = 9999.99; // use subscripting�ק�
	map[40] = 8765.43; // use subscripting���J

	cout << "\nAfter subscript �ާ@, map�����e��:\nKey\tValue\n";

	// use const_iterator to walk through elements of pairs
	for (Map::const_iterator iter = map.begin();
		iter != map.end(); ++iter)
		cout << iter->first << '\t' << iter->second << '\n';

	cout << endl;
}

void StackAdapterTest()
{
	// stack ���e���Y�����w�w�]�ϥ�deque
	stack< int > dequeStack;

	// stack ���t�ϥ� vector�@���e��
	stack< int, vector< int > > vectorStack;

	// stack ���t�ϥ� list�@���e��
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

										 // �w�]�u���v�Ѥj��p
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
	fill(v.begin(), v.end(), '5'); // �]�w vector �̪����e����5

	cout << "�ثeVector�����e��:\n";
	copy(v.begin(), v.end(), output);

	
	fill_n(v.begin(), 5, 'A');
	cout << "\n\nVector�g�L��J5��A�����e:\n";
	copy(v.begin(), v.end(), output);

	generate(v.begin(), v.end(), nextLetter); //nextLetter���R�A�ϰ�Ѽ�
	cout << "\n\nVector�ϥΥͦ���ƶ�J�r�� A-J:\n";
	copy(v.begin(), v.end(), output);

	generate_n(v.begin(), 5, nextLetter);
	cout << "\n\nVector�ϥΥͦ�����~���J�r�� K-O ��e5�Ӥ���:\n";
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

	cout << "Vector v1 ���e��: ";
	copy(v1.begin(), v1.end(), output);
	cout << "\nVector v2 ���e��: ";
	copy(v2.begin(), v2.end(), output);
	cout << "\nVector v3 ���e��: ";
	copy(v3.begin(), v3.end(), output);

	// eaual: �����ӽd�򤺮e�O�_�۵�
	bool result = equal(v1.begin(), v1.end(), v2.begin());
	cout << "\n\nVector v1 " << (result ? "��" : "����")
		<< "��vector v2.\n";

	// compare vectors v1 and v3 for equality
	result = equal(v1.begin(), v1.end(), v3.begin());
	cout << "\n\nVector v1 " << (result ? "��" : "����")
		<< "��vector v3.\n";

	// location represents pair of vector iterators
	pair< vector< int >::iterator, vector< int >::iterator > location;

	// mismatch : �^�ǥѫe2�Ӥ��۵������Ӧ���pair����,first���d��1���t������,second���d��2���t������
	location = mismatch(v1.begin(), v1.end(), v3.begin());
	cout << "\n v1 �M v3 �������@�Ӯt���A�o�ͦb��m"
		<< (location.first - v1.begin()) << "\n�Bv1���t��������: "
		<< *location.first << ", v3���t��������: " << *location.second
		<< "\n\n";

	char c1[SIZE] = "HELLO";
	char c2[SIZE] = "BYE BYE";

	// lexicographical_comparison : ����Ĥ@�d����r�夺�e�ƧǬO�_�p��ĤG�d��
	result = lexicographical_compare(c1, c1 + SIZE, c2, c2 + SIZE);
	cout << c1 << (result ? " �p�� " :
		" �j�󵥩� ") << c2 << endl;
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
	vector< int > v1(array, array + SIZE); // �Harray�����e�إ�vector v1
	vector< int >::iterator newLastElement;

	cout << "Vector v1 �쥻�����e:\n   ";
	copy(v1.begin(), v1.end(), output);

	// remove :�q���w�d�򤤮��������R���Ҧ�����value������,
	//�æ^�ǳ̫�@�ӥ��Q�d����������}���_�l��Iterator
	newLastElement = remove(v1.begin(), v1.end(), 10);
	cout << "\nVector v1 �����Ҧ�10���᪺���G:\n   ";
	copy(v1.begin(), newLastElement, output);
	cout << "(remove)" << endl;

	vector< int > v2(array, array + SIZE); // �Harray�����e�إ�vector v2
	vector< int > temp1(SIZE, 0); 
	cout << "\n\nVector v2 �쥻�����e:\n   ";
	copy(v2.begin(), v2.end(), output);

	// remove_copy : �N�d��[first,last)�̭��A�Ȥ�����val������
	// �v�@�ƻs��qresult�}�l����m,���������쥻���e
	remove_copy(v2.begin(), v2.end(), temp1.begin(), 10);
	cout << "\n\nVector v2 �����e����:\n   ";
	copy(v2.begin(), v2.end(), output);
	cout << "\nVector temp1 �Q�ƻs�i�h�����e:\n   ";
	copy(temp1.begin(), temp1.end(), output);
	cout << "(remove_copy)" << endl;


	vector< int > v3(array, array + SIZE); // copy of a
	cout << "\n\nVector v3 �쥻�����e:\n   ";
	copy(v3.begin(), v3.end(), output);

	// remove :�q���w�d�򤤥H�L�o�W�h���������R������,
	//�æ^�ǳ̫�@�ӥ��Q�d����������}���_�l��Iterator
	newLastElement = remove_if(v3.begin(), v3.end(), filter);
	cout << "\nVector v3 �g�Lfilter�Ჾ�������e(filter : > 9):"
		<< "\n(�j��9�������Q����):\n   ";
	copy(v3.begin(), newLastElement, output);
	cout << "(remove_if)" << endl;

	vector< int > v4(array, array + SIZE); // copy of a
	vector< int > temp2(SIZE, 0); // instantiate vector c2
	cout << "\n\nVector v4 �쥻�����e:\n   ";
	copy(v4.begin(), v4.end(), output);

	// remove_copy_if : �N�d��[first,last)�̭��A�N���ŦX�L�o�W�h������
	// �v�@�ƻs��qresult�}�l����m,���������쥻���e
	remove_copy_if(v4.begin(), v4.end(), temp2.begin(), filter);
	cout << "\n\nVector v4 �����e����:\n   ";
	copy(v4.begin(), v4.end(), output);
	cout << "\nVector temp2 �Q�ƻs�i�h�����e�A���ŦX�L�o�W�h(filter : > 9)������:\n   ";
	copy(temp2.begin(), temp2.end(), output);
	cout << "(remove_copy_if)" << endl;
	cout << endl;
}

void ReplaceTest()
{
	const int SIZE = 10;
	int a[SIZE] = { 10, 2, 10, 4, 16, 6, 14, 8, 12, 10 };
	ostream_iterator< int > output(cout, " ");

	vector< int > v1(a, a + SIZE); // �Harray�����e�إ�vector v1
	cout << "Vector v1 �쥻�����e:\n   ";
	copy(v1.begin(), v1.end(), output);

	// replace : �H new_value �����d�� [first, last) ���Ҧ������S�w�P�O�зǪ�����
	replace(v1.begin(), v1.end(), 10, 100);
	cout << "\nVector v1 �g�Lreplace�᪺���e:\n   ";
	copy(v1.begin(), v1.end(), output);

	vector< int > v2(a, a + SIZE); 
	vector< int > temp1(SIZE); // instantiate vector c1
	cout << "\n\nVector v2 �쥻�����e:\n   ";
	copy(v2.begin(), v2.end(), output);	

	// replace_copy : �N�줺�e�ƻs��s��}�A
	// �A�H new_value�����d��[first, last)���Ҧ��������󪺤���
	
	replace_copy(v2.begin(), v2.end(), temp1.begin(), 10, 100);
	cout << "\ntemp1 �g�Lreplace_copy�᪺���e:\n   ";
	copy(temp1.begin(), temp1.end(), output);

	vector< int > v3(a, a + SIZE); // copy of a
	cout << "\n\nVector v3 �쥻�����e:\n   ";
	copy(v3.begin(), v3.end(), output);

	// replace : �H new_value �����d�� [first, last) ��
	// �Ҧ�����filter���󪺤���
	replace_if(v3.begin(), v3.end(), filter, 100);
	cout << "\ntemp1 �g�Lreplace_if�᪺���e:"
		<< "\n(filter > 9):\n   ";
	copy(v3.begin(), v3.end(), output);

	vector< int > v4(a, a + SIZE); // copy of a
	vector< int > temp2(SIZE); // instantiate vector c2
	cout << "\n\nVector v4 �쥻�����e\n   ";
	copy(v4.begin(), v4.end(), output);

	// replace_copy : �N�줺�e�ƻs��s��}�A
	// �A�H new_value�����d��[first, last)��
	// �Ҧ�����filter���󪺤���
	replace_copy_if(v4.begin(), v4.end(), temp2.begin(), filter, 100);
	cout << "\ntemp2 �g�Lreplace_copy_if�᪺���e:"
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

	// random_shuffle : �H���ƦC����
	cout << "Vector v before random_shuffle: ";
	copy(v.begin(), v.end(), output);

	random_shuffle(v.begin(), v.end()); // shuffle elements of v
	cout << "\nVector v after random_shuffle: ";
	copy(v.begin(), v.end(), output);

	int a2[SIZE] = { 100, 2, 8, 1, 50, 3, 8, 8, 9, 10 };
	vector< int > v2(a2, a2 + SIZE); // copy of a2
	cout << "\n\nVector v2 contains: ";
	copy(v2.begin(), v2.end(), output);

	// count : �έp�e��������value�������Ӽ�
	int result = count(v2.begin(), v2.end(), 8);
	cout << "\nNumber of elements matching 8: " << result;

	// count_if : �έp�e�����ŦX���󪺤����Ӽ�
	result = count_if(v2.begin(), v2.end(), filter);
	cout << "\nNumber of elements greater than 9: " << result;

	// min_element : �^�ǽd�򤤳̤p������}
	cout << "\n\nMinimum element in Vector v2 is: "
		<< *(min_element(v2.begin(), v2.end()));

	// max_element : �^�ǽd�򤤳̤j������}
	cout << "\nMaximum element in Vector v2 is: "
		<< *(max_element(v2.begin(), v2.end()));

	// accumulate : �N�d�򤺪��ƭȥ[�`�A���ର�ĤT�Ѽƫ��A
	// �P�ĤT�ѼƬۥ[ (�ĤT�ѼƬ����) 
	cout << "\n\nThe total of the elements in Vector v is: "
		<< accumulate(v.begin(), v.end(), 0);

	// for_each : ���Ӷ��ǱN�e�����������N�J����w��ư���
	cout << "\n\nThe square of every integer in Vector v is:\n";
	for_each(v.begin(), v.end(), outputSquare);

	vector< int > cubes(SIZE); // instantiate vector cubes

	// transform : �N�d�򤺪������N�J����w��ơA�ñN�^�Ǥ�����J�s���e����}
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

	cout << "Vector v �����e��: ";
	copy(v.begin(), v.end(), output); // display output vector

									  // locate first occurrence of 16 in v
	vector< int >::iterator location;
	// find : �^�ǲĤ@�Ӻ������󪺭��N�� (���� == 16)
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

	// find_if : �^�ǲĤ@�Ӻ���filter��ƪ����N�� (filter > 9)
	location = find_if(v.begin(), v.end(), filter);

	if (location != v.end()) // found value greater than 9
		cout << "\n\nThe first value greater than 9 is " << *location
		<< "\nfound at location " << (location - v.begin());
	else // value greater than 9 not found
		cout << "\n\nNo values greater than 9 were found";

	// sort : �H���W�Ƨǽd��
	sort(v.begin(), v.end());
	cout << "\n\nVector v after sort: ";
	copy(v.begin(), v.end(), output);

	// binary_search : �H�G���j�M�k�d�߽d�򤺫��w����,���h�^��true
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

	// swap : �洫����w��m����(�ǧ})
	swap(a[0], a[1]);

	cout << "\nArray a after swapping a[0] and a[1] using swap:\n   ";
	copy(a, a + SIZE, output); // display array a

	// iter_swap : �洫����w��m����(�ǰѦ�Iterator)
	iter_swap(&a[0], &a[1]); // swap with iterators                       
	cout << "\nArray a after swapping a[0] and a[1] using iter_swap:\n   ";
	copy(a, a + SIZE, output);

	// swap_ranges : �N�d��A������,�q�d��B�}�l�̧ǰ��洫
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

	cout << "Vector v1 ���쥻���e��: ";
	copy(v1.begin(), v1.end(), output); // display vector output
	cout << "\nVector v2 ���쥻���e��: ";
	copy(v2.begin(), v2.end(), output); // display vector output

	vector< int > results(v1.size());

	// copy_backward : �N�d�򤺪������H�f�Ǥ覡�ƻs��s��}
	// �H�O����۹ﶶ��
	copy_backward(v1.begin(), v1.end(), results.end());
	cout << "\n\nAfter copy_backward, results contains: ";
	copy(results.begin(), results.end(), output);

	vector< int > v3(v1.size() + v2.size());

	// merge : �N��q�d�򪺤����A�ƻs��s���_�l��}�ð��Ƨ�
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	cout << "\n\nAfter merge of v1 and v2 results2 contains:\n";
	copy(v3.begin(), v3.end(), output);

	// unique : �^�Ǯ������Ƥ����d�򪺭��N�����ݦ�}
	vector< int >::iterator endLocation;
	endLocation = unique(v3.begin(), v3.end());

	cout << "\n\nAfter unique v3 contains:\n";
	copy(v3.begin(), endLocation, output);

	// reverse : ����d�򤤪���������
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

	// inplace_merge : �e��������Ӧ��Ǫ��d�򭫷s�X��
	inplace_merge(v1.begin(), v1.begin() + 5, v1.end());

	cout << "\nAfter inplace_merge, v1 contains: ";
	copy(v1.begin(), v1.end(), output);

	vector< int > unique;

	// unique_copy : �ƻs�����Ƥ�����ؼЮe��
	unique_copy(v1.begin(), v1.end(), back_inserter(unique));
	cout << "\nAfter unique_copy results1 contains: ";
	copy(unique.begin(), unique.end(), output);

	vector< int > reverse;

	// reverse_copy : �ƻs�d�򤺪�������s�d�򤤨åH�f�ǱƦC
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

	// includes : �ˬd�w�Ƨǽd��B�O�_���w�Ƨǽd��A���l�ǦC
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

	// set_intersection : ��2�d�򶰦X�t�����e���s�d��_�l��}
	// �æ^�Ƿs�d�����Iterator
	int *ptr = set_difference(a1, a1 + SIZE1,
		a2, a2 + SIZE2, difference);
	cout << "\n\nset_difference of a1 and a2 is: ";
	copy(difference, ptr, output);

	int intersection[SIZE1];

	// set_intersection : ��2�d�򶰦X�涰���e���s�d��_�l��}
	// �æ^�Ƿs�d�����Iterator
	ptr = set_intersection(a1, a1 + SIZE1,
		a2, a2 + SIZE2, intersection);
	cout << "\n\nset_intersection of a1 and a2 is: ";
	copy(intersection, ptr, output);

	int symmetric_difference[SIZE1 + SIZE2];

	// set_intersection : ��2�d�򶰦X��ٮt�����e���s�d��_�l��}
	// �æ^�Ƿs�d�����Iterator (���X��ٮt�� : (A��B)��A��B)
	ptr = set_symmetric_difference(a1, a1 + SIZE1,
		a3, a3 + SIZE2, symmetric_difference);
	cout << "\n\nset_symmetric_difference of a1 and a3 is: ";
	copy(symmetric_difference, ptr, output);

	int unionSet[SIZE3];

	// set_union : ��2�d�򶰦X�X�֤��e���s�d��_�l��}
	// �æ^�Ƿs�d�����Iterator
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

	// lower_bound : �^�ǲĤ@�Ӥj�󵥩���w���������N����}
	vector< int >::iterator lower;
	lower = lower_bound(v.begin(), v.end(), 6);
	cout << "\n\nLower bound of 6 is index "
		<< (lower - v.begin()) << " of vector v";

	// upper_bound : �^�ǲĤ@�Ӥj����w���������N����}
	vector< int >::iterator upper;
	upper = upper_bound(v.begin(), v.end(), 6);
	cout << "\nUpper bound of 6 is index "
		<< (upper - v.begin()) << " of vector v";

	// equal_range : �b�w�ƧǪ�[first,last)���M��value�A
	// �B�^�Ǥ@�ﭡ�N��i�Mj�A���O���b���}�a���Ǫ��e���U
	// �i���J����1�ӥH�γ̫�1�Ӧ�m
	pair< vector< int >::iterator, vector< int >::iterator > eq;
	eq = equal_range(v.begin(), v.end(), 6);
	cout << "\nUsing equal_range:\n   Lower bound of 6 is element "
		<< (eq.first - v.begin()) << " of vector v";
	cout << "\n   Upper bound of 6 is element "
		<< (eq.second - v.begin()) << " of vector v";
	
	cout << "\n\n�ϥ� upper_bound �h��M�b���}�a���Ǫ��e���U\n"
		<< "5�i�H�Q���J��ǦC����first ��m";
	lower = lower_bound(v.begin(), v.end(), 5);
	cout << "\n   Lower bound of 5 is element "
		<< (lower - v.begin()) << " of vector v";

	cout << "\n\n�ϥ� upper_bound �h��M�b���}�a���Ǫ��e���U\n"
		<< "7�i�H�Q���J��ǦC����last ��m";
	upper = upper_bound(v.begin(), v.end(), 7);
	cout << "\n   Upper bound of 7 is element "
		<< (upper - v.begin()) << " of vector v";


	cout << "\n\n�ϥ� equal_range �h��M�b���}�a���Ǫ��e���U\n"
		<< "5�i�H�Q���J��ǦC�� first �M last ��m";
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

	cout << "Vector v �إ�heap�e�����e:\n";
	copy(v.begin(), v.end(), output);

	make_heap(v.begin(), v.end()); // create heap from vector v
	cout << "\nVector v �إ�heap�᪺���e:\n";
	copy(v.begin(), v.end(), output);

	sort_heap(v.begin(), v.end()); // sort elements with sort_heap
	cout << "\nVector v �ϥ�sort_heap�����i��Ƨ�:\n";
	copy(v.begin(), v.end(), output);

	cout << "\n\n�ϥ�push_heap �M push_back �̧ǫإ�heap";
	cout << "\nArray a contains: ";
	copy(a, a + SIZE, output); // display array a
	cout << endl;

	// place elements of array a into v2 and 
	// maintain elements of v2 in heap
	for (int i = 0; i < SIZE; i++)
	{
		v2.push_back(a[i]); // push_back : �C���q�̫᭱���J������Vector
		push_heap(v2.begin(), v2.end()); //push_heap : �N���J�������heap�A���m
		cout << "\nv2 after push_heap(a[" << i << "]): ";
		copy(v2.begin(), v2.end(), output);
	} // end for

	cout << endl;

	// remove elements from max-heap(�w�]) in sorted order
	for (unsigned int j = 0; j < v2.size(); j++)
	{
		cout << "\nv2 after " << v2[0] << " popped from heap\n";
		pop_heap(v2.begin(), v2.end() - j); // pop_heap : �C���N���ݤ����P�̫�@�Ӥ����洫
		copy(v2.begin(), v2.end(), output);
	} // end for

	cout << endl;
}

void findPrime()
{
	const int SIZE = 1024;
	int value;
	bitset< SIZE > sieve; // �إߤj�p��1024��bitset(�w�]�Ҭ�0)
	sieve.flip(); // flip : ����bitset���e��1
	sieve.reset(0); // reset first bit (0:����Prime)         
	sieve.reset(1); // reset second bit (1:����Prime)        
	// ��}i�Y��0�A�N��ƭ�i����Prime
	// ��}i�Y��1�A�N��ƭ�i��Prime
					// perform Sieve of Eratosthenes
	int finalBit = sqrt(static_cast< double >(sieve.size())) + 1;
	// finalBit : �}�ڸ�n + 1

	// �q2�}�l�̧ǧ�Ҧ����ƭ簣���F�A�ΤU�@�ӽ��
	for (int i = 2; i < finalBit; i++)
	{
		if (sieve.test(i)) // bit i is on
		{
			for (int j = 2 * i; j < SIZE; j += i)
				sieve.reset(j); // set bit j off (����Prime)
		} // end if
	} // end for

	cout << "The prime numbers in the range 2 to 1023 are:\n";

	// display prime numbers in range 2-1023
	for (int k = 2, counter = 1; k < SIZE; k++)
	{
		if (sieve.test(k)) // �YK��on�N��k��Prime�N��X
		{
			cout << setw(5) << k;

			if (counter++ % 12 == 0) // counter is a multiple of 12
				cout << '\n'; //�C��X12�ӼƦr�N����
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
	// �ΤG�����sumSquares�D�M�����A�����Ψ�䥪���B���
	// ��1�ѼƬ��e�@��function���^�ǵ��G
	// ��2�ѼƬ�Vector�����e
	result = accumulate(integers.begin(), integers.end(),
		0, sumSquares);

	cout << "\n\nSum of squares of elements in integers using "
		<< "binary\nfunction sumSquares: " << result;

	// calculate sum 
	// �Φۭq�����G�����SumSquaresClass�D�M�����A�����Ψ�䥪���B���
	// ��1�ѼƬ��e�@��function���^�ǵ��G
	// ��2�ѼƬ�Vector�����e
	result = accumulate(integers.begin(), integers.end(),
		0, SumSquaresClass< int >());

	cout << "\n\nSum of squares of elements in integers using "
		<< "binary\nfunction object of type "
		<< "SumSquaresClass< int >: " << result << endl;
}
