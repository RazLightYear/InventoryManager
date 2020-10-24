#ifndef PRODUCT
#define PRODUCT
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "BoxSize.h"

using namespace std;

/**
This Class Is The Primary Class, Which Acts As A Base Class For Other Classes.
This Class Represnts A General Object(Product),Classes That Inherit From This Class Will Represent A More Specific
Products.
**/

class Product
{

protected:
	// the product name //
	char* ProductName; 

	// the product price //
	double Price; 

	// In which Shelf the product is, in the storage //
	int ShelfNumber; 

	// Product ID //
	int ProductNumber; 

	
	// Product Size //
		BoxSize Size;

public:

		static int ProductCounter ;

	

	// Default constructor //
		Product(); 

	// 3-Arguments constructor //
		Product(const char* ProductName, double Price, int ShelfNumber); 

	// 2-Arguments constructor //
		Product(const char* ProductName, double Price); 

	// Copy Constructor //
		const Product(const Product & P); 

	// Operator = //
		virtual const Product& operator=(const Product & other); 

	// Operator == //
		virtual bool operator==(const Product & other)const; 

	// Operator += //
		virtual void operator+=(double PriceAdd); 

	// Operator -= //
		void operator-=(double PriceReduce); 

	// Operator << // 
		friend ostream & operator <<(ostream& out, Product & P); 

	// Show Method //
		virtual void show() const = 0;

	// Get Method for Price //
		double GetPrice();

	// Get Method for ShelfNumber //
		int GetShelfNumber();

	// Get Method for ProductNumber //
		int GetProductNumber();

	// Get Method for ProductName //
		char* GetProductName();

	// Get Method for ProductBoxSize //
		BoxSize  & GetBoxSize();

	// Set Method for ProductName //
		void SetProductName(const char* ProductName);

	// Set Method for Price //
		void SetPrice(double Price);

	// Set Method for ShelfNumber //
		void SetShelfNumber(int ShelfNumber);

	// Set Method for Size //
		void setBoxSize(BoxSize size);

	// Method to add to the name //
		void  AddName(const char* AddName);

	// Show Product Price In USD,EUR And GBP For Abroad Costumers //
		void showInDiffCurrency();

	// Destructor //
		virtual ~Product();
};

#endif 



