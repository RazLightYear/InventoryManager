#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"
#define NO_DETAILS_ENTERED "NO DETAILS ENTERED"

using namespace std;

int Product::ProductCounter = 1;

// Default constructor//
Product::Product() :Price(0),ShelfNumber(0),ProductNumber(ProductCounter++)
{
	this->ProductName = new char[strlen(NO_DETAILS_ENTERED) + 1];
	strcpy(this->ProductName, NO_DETAILS_ENTERED);
}

// 3-Arguments constructor//
Product::Product(const char* ProductName, double Price, int ShelfNumber) : Price(Price),ShelfNumber(ShelfNumber), ProductNumber(ProductCounter++)
{
	this->ProductName = new char[strlen(ProductName) + 1];
	strcpy(this->ProductName, ProductName);
}

// 2-Arguments constructor
Product::Product(const char* ProductName, double Price):Price(Price), ProductNumber(ProductCounter++)
{
	this->ProductName = new char[strlen(ProductName) + 1];
	strcpy(this->ProductName, ProductName);
}

// Copy Constructor //
Product::Product(const Product &P) 
{
	*this = P;
}

// Operator = //
const Product & Product::operator=(const Product & other) 
{
	
	if (this != &other) {
		this->Price = other.Price;
		this->ProductNumber = ProductCounter++;
		this->ShelfNumber = other.ShelfNumber;
		this->ProductName = new char[strlen(other.ProductName) + 1];
		strcpy(this->ProductName, other.ProductName);
		this->Size = other.Size;
	}
	return *this;
}

// Operator == //
bool Product::operator==(const Product & other)const
{
	if ((Price == other.Price) && (ShelfNumber==other.ShelfNumber) && (strcmp(ProductName,other.ProductName))==0)
		return true;
	return false;

}

// Method to add the new price //
void Product::operator+=(double PriceAdd)
{
	this->Price += PriceAdd;
}

// Method to Reduce the new price //
void Product::operator-=(double PriceAdd)
{
	this->Price -= PriceAdd;
}

// Method to return the price //
double Product::GetPrice()
{
	return this->Price;
}

// Method to return the Shelf Number //
int Product::GetShelfNumber()
{
	return this->ShelfNumber;
}

// Method to return the ProductNumber //
int Product::GetProductNumber()
{
	return this->ProductNumber;
}

// Method to return the ProductName //
char * Product::GetProductName()
{
	return this->ProductName;
}

// Method to return the BoxSize //
BoxSize & Product::GetBoxSize()
{
	return this->Size;
}

// Set Methode for ProductName //
void Product::SetProductName(const char * ProductName)
{
	this->ProductName = NULL;
	this->ProductName = new char[strlen(ProductName) + 1];
	strcpy(this->ProductName, ProductName);
}

// Set Method for Price //
void Product::SetPrice(double Price)
{
	this->Price = Price;
}

// Set Method for ShelfNumber //
void Product::SetShelfNumber(int ShelfNumber)
{
	this->ShelfNumber = ShelfNumber;
}

// Set Method for Size //
void Product::setBoxSize(BoxSize size)
{
	this->Size = size;
}

// Method to add to the name //
void Product::AddName(const char * AddName)
{
	char *NewName = new char[strlen(this->ProductName) + strlen(AddName) + strlen(", ") + 1];
	strcpy(NewName, this->ProductName);
	strcat(NewName, ", ");
	strcat(NewName, AddName);

	this->ProductName = new char[strlen(NewName) + 1];
	strcpy(this->ProductName, NewName);
	delete[] NewName;
}

// Show Product Price In USD,EUR And GBP For Abroad Costumers //
void Product::showInDiffCurrency()
{
	cout << "Price In USD: " << this->Price / 3.4 << endl;
	cout << "Price In EUR: " << this->Price / 3.8 << endl;
	cout << "Price In GBP: " << this->Price / 4.3 << endl;
}

// Operator << //
ostream & operator<<(ostream & out, Product & P) 
{
	out << "*********************" << endl;
	out << "Product Name: " << P.ProductName << endl;
	out << "Product Price: " << P.Price << endl;
	out << "Product is in shelf no.: " << P.ShelfNumber << endl;
	out << "Product ID no is: " << P.ProductNumber << endl;
	out << P.Size;
	return out;
}

// Destructor //
Product::~Product() 
{
	ProductCounter--;
	delete [] ProductName;
}