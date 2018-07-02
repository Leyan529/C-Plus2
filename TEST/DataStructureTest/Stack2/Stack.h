#ifndef STACK_H
#define STACK_H
template<typename T , int maxSize>
class Stack
{
public:
	Stack(int);
	~Stack() {
		delete[] stackPtr;
	}
	bool push(const T &);
	bool pop(T &);
	bool isEmpty() const {
		return top == -1;
	}
	bool isFull() const {
		return top == size - 1;
	}
private:
	int size;
	int top;
	T* stackPtr;
};
template<typename T , int maxSize>
Stack<T,maxSize>::Stack(int s)
	:size(s>0 ? s : maxSize),
	top(-1),
	stackPtr(new T[size])
{
}


template<typename T , int maxSize>
bool Stack<T,maxSize>::push(const T &pushvalue)
{
	if (!isFull()) {
		stackPtr[++top] = pushvalue;
		return true;
	}
	return false;
}

template<typename T , int maxSize>
bool Stack<T,maxSize>::pop(T &popvalue)
{
	if (!isEmpty()) {
		popvalue = stackPtr[top--];
		return true;
	}
	return false;
}
#endif 


