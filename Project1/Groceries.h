#ifndef GROCERIES
#define GROCERIES
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"
#include "Date.h"
#include"ElectronicsProduct.h"

/**
	This Class Represent A Consumable Product, Like EveryDay Groceries.
	This Class Inherit From Class Product Its Main Fields Of Data, And Adds Specific Fields
	like Vegean Check, Expiary Date And Allergies Ingredients.
**/

class Groceries : public Product
{
	// The product is vegean-friendly ? //
	bool Vegean;

	// Expiery Date //
	Date ExpieryDate;

	// Allergies Warnings //
	char * Allergies;

	//Is the Product Reserved For A Costumer //
	bool reserved;

	// To Whom The Product Reserved For //
	char* reservedName;

public:

	// Default Constructor //
	Groceries();

	// 7 - Arguments Constructor //
	Groceries(BoxSize & BoxSize, const char * ProductName, double price, int ShelfNumber, bool Vegean, Date ExpieryDate, const char * Allergies);

	// 6 - Arguments Constructor //
	Groceries(const char * ProductName, double price, int ShelfNumber, bool Vegean, Date ExpieryDate, const char * Allergies);

	// 5 - Arguments Constructor //
	Groceries(const char * ProductName, double price, int ShelfNumber, bool Vegean,const char * Allergies);

	// Copy Constructor //
	const Groceries(const Groceries & other);

	// Operator = //
	virtual const Groceries& operator=(const Groceries& other);

	// Operator == //
	virtual bool operator ==(const Groceries &other) const;

	// Operator << // 
	friend ostream & operator <<(ostream& out, Groceries & G);

	//Operator += //
	virtual void operator+=(const char* addAllergies);

	// Set Method for Vegean //
	void SetVegean(bool Vegean);

	// Set Method for ExpieryDate //
	void SetExpieryDate(Date ExpieryDate);

	// Get Method for Vegean //
	bool GetVegean();

	// Get Method for ExpieryDate //
	Date GetExpieryDate();

	// Method to add new Allergies warnings //
	void  AddAllergies(const char* AddAllergies);

	// Method to show the details of the product //
	virtual void show() const;

	// Destructor //
	~Groceries() { delete [] Allergies; }

	friend void ElectronicsProduct::ReservedDetails(const char* ReservedDetails);
	friend const char* ElectronicsProduct::GetReservedName();
};

#endif
