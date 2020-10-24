#ifndef ELRCTRONICS_PRODUCT
#define ELRCTRONICS_PRODUCT
#define _CRT_SECURE_NO_WARNINGS
#define CURRENT_YEAR 2020


#include <iostream>
#include "Product.h"
#include"BoxSize.h"
using namespace std;

/**
	This Class Represent An Electronic Product, Like EveryDay Electric Home-Appliences.
	This Class Inherit From Class Product Its Main Fields Of Data, And Adds Specific Fields
	like Warranty Years Of The Product, Is The Product WaterProof Or Not, And Important Details
	About The Product.
**/

class ElectronicsProduct : public Product
{
	// How many years of warranty the product has //
	int WarrantyYears;

	// WaterProof or not ? //
	bool WaterProof;

	// Important details about the product //
	char* LittleDetails;

	//Is the Product Reserved For A Costumer //
	bool reserved;	

	// To Whom The Product Reserved For //
	char* reservedName;


public:
	

	// Default Constructor //
	ElectronicsProduct();

	// 7 - Arguments Constructor //
	ElectronicsProduct(BoxSize & BoxSize, const char* ProductName, double price, int ShelfNumber,int WarrantyYears, bool WaterProof, const char* LittleDetails);
	
	// 6 - Arguments Constructor //
	ElectronicsProduct(const char* ProductName, double price, int ShelfNumber, int WarrantyYears, bool WaterProof, const char* LittleDetails);

	// Copy Constructor //
	const ElectronicsProduct(const ElectronicsProduct & other);

	// Operator = //
	virtual const ElectronicsProduct& operator=(const ElectronicsProduct& other);

	// Operator == //
	virtual bool operator ==(const ElectronicsProduct &other) const;

	// Operator += for the WarrantyYears - with no extra cost //
	virtual void operator+=(int WarrantyYears);

	// Operator << // 
	friend ostream & operator <<(ostream& out, ElectronicsProduct & E);

	// Method to increase the Warranty years- with extra cost //
	void IncreaseWarrantyYears(int WarrantyYearsAdd);

	// Set Method for WarrantyYears //
	void SetWarrantyYears(int WarrantyYears);

	// Method To Enter Details About reservation //
	void ReservedDetails(const char* ReservedDetails);

	// Set Method for WaterProof //
	void SetWaterProof(bool WaterProof);

	// Get Method for WarrantyYears //
	int GetWarrantyYears();

	// Get Method for WaterProof //
	bool GetWaterProof();

	// Get Method For The Reserve Name //
	const char * GetReservedName() { return this->reservedName; };

	// Method to show the details of the product //
	virtual void show()const;

	// Destructor //
	virtual ~ElectronicsProduct() 
	{		
		delete [] LittleDetails;		
	}

};



#endif
