#ifdef COUNT_H
#endif COUNT_H

class Count
{
	friend void setX(Count &, int); // friend declaration
public:
	// constructor
	Count(): x(0) // initialize x to 0
	{
		// empty body
	} // end constructor Count

	  // output x 
	void print() const;
private:
	int x; // data member
}; // end class Count
