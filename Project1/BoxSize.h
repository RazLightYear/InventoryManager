#ifndef BOX_SIZE
#define BOX_SIZE
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/**
	This class represent the product Box Size and general description
	the general description represent important information about the box like:
	Small box / Medium box / Fragile content etc.
**/

class BoxSize
{
private:

	// General decription Box: Big/ Medium / Small / fragile / Heavy //
	char* GeneralDescription;

	// the height of the box //
	int height;

	// the width of the box //
	int width;

	// length of the box //
	int length;

public:
	// Default constructor //
	BoxSize();

	// 4-Arguments constructor //
	BoxSize(int height, int width,int length,const char* GeneralDescription);

	// 3-Arguments constructor //
	BoxSize(int height, int width,int length);

	// Copy Constructor //
	const BoxSize(const BoxSize & B);

	// Operator = //
	const BoxSize& operator=(const BoxSize & other);

	// Operator == //
	virtual bool operator==(const BoxSize & other)const;

	// Operator += for the height //
	void operator+=(int height);

	// Operator -= for the height //
	void operator-=(int height);

	// Operator << // 
	friend ostream & operator <<(ostream& out, BoxSize & B);

	// Show Method //
	virtual void show()const ;

	// Get Method for height //
	int Getheight();

	// Get Method for width //
	int Getwidth();

	// Get Method for length //
	int Getlength();

	// set Method for height //
	void SethHeight(int height);

	// set Method for width //
	void SethWidth(int width);

	// set Method for length //
	void SethLength(int length);

	// Method to add general description based on the dimensions //
	void GeneralInit();

	// Method to add new General Description //
	void  AddGeneral(const char* AddGeneral);

	// Destructor //
	virtual ~BoxSize();


};

#endif