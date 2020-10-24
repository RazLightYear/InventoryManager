#include "ElectronicsProduct.h"
#define WATERPROOF_CHECK if (E.WaterProof == 1) out << "Device is WaterProof"<<endl; else out<< "Device is NOT Water Proof"<<endl;
#define WARRANTY_PRINT	out << "Warranty will end in: " << CURRENT_YEAR + E.WarrantyYears << endl;
#define LITTLE_LETTERS out << "PLEASE READ THE LITTLE DETAILS :"<<E.LittleDetails<<endl;
#define NO_DETAILS_ENTERED "NO DETAILS ENTERED"
#define RESERVATION_CHECK_PRINT if (E.reserved==1) out<<"This Product is Reserved to: "<< E.reservedName<<endl; else out <<"This Product Is Not Reserved To Anyone"<<endl;	

	// Default Constructor //
ElectronicsProduct::ElectronicsProduct():Product()
{
	this->Size = BoxSize();
	this->WarrantyYears = 0;
	this->LittleDetails = NULL;
	this->LittleDetails = new char[strlen(NO_DETAILS_ENTERED) + 1];
	strcpy(this->LittleDetails, NO_DETAILS_ENTERED);
	this->reserved = 0;
	this->reservedName = new char[strlen("NONE") + 1];
	strcpy(this->reservedName, "NONE");
}

	// 7 - Arguments Constructor //
ElectronicsProduct::ElectronicsProduct(BoxSize & BoxSize, const char * ProductName, double price, int ShelfNumber,  int WarrantyYears, bool WaterProof, const char* LittleDetails):Product(ProductName,price,ShelfNumber)
{
	this->Size = BoxSize;
	this->WarrantyYears = WarrantyYears;
	this->WaterProof = WaterProof;
	this->LittleDetails = NULL;
	this->LittleDetails = new char[strlen(LittleDetails) + 1];
	strcpy(this->LittleDetails, LittleDetails);
	this->reserved = 0;
	this->reservedName = new char[strlen("NONE") + 1];
	strcpy(this->reservedName, "NONE");
}

	// 6 - Arguments Constructor //
ElectronicsProduct::ElectronicsProduct(const char * ProductName, double price, int ShelfNumber,  int WarrantyYears, bool WaterProof, const char* LittleDetails):Product(ProductName,price,ShelfNumber)
{
	this->WarrantyYears = WarrantyYears;
	this->WaterProof = WaterProof;
	this->LittleDetails = NULL;
	this->LittleDetails = new char[strlen(LittleDetails) + 1];
	strcpy(this->LittleDetails, LittleDetails);
	this->reserved = 0;
	this->reservedName = new char[strlen("NONE") + 1];
	strcpy(this->reservedName, "NONE");
}

	// Copy Constructor //
ElectronicsProduct::ElectronicsProduct(const ElectronicsProduct & other):Product(other)
{
	*this = other;
}

	// Operator = //
const ElectronicsProduct & ElectronicsProduct::operator=(const ElectronicsProduct & other)
{
	if (this != &other)
	{
		Product::operator=(other);
		this->WarrantyYears = other.WarrantyYears;
		this->WaterProof = other.WaterProof;
		this->LittleDetails = new char[strlen(other.LittleDetails) + 1];
		strcpy(this->LittleDetails, other.LittleDetails);
		this->reserved = other.reserved;
		this->reservedName = new char[strlen(other.reservedName)+1];
		strcpy(this->reservedName, other.reservedName);
	}
	return *this;
}

	// Operator == //
bool ElectronicsProduct::operator==(const ElectronicsProduct & other) const
{
	if (Product::operator==(other) == true && (this->WarrantyYears == other.WarrantyYears) && (this->WaterProof == other.WaterProof)&&(strcmp(this->LittleDetails,other.LittleDetails))==0) return true;
	return false;
}

	// Operator += for the WarrantyYears //
void ElectronicsProduct::operator+=(int WarrantyYears)
{
	this->WarrantyYears += WarrantyYears;
}

// Methode to increase the Warranty years with extra cost //
void ElectronicsProduct::IncreaseWarrantyYears(int WarrantyYearsAdd)
{
	this->operator+=(WarrantyYearsAdd);
	this->Price += (WarrantyYearsAdd)*(this->Price / 6);
}

// Set Method for WarrantyYears //
void ElectronicsProduct::SetWarrantyYears(int WarrantyYears)
{
	this->WarrantyYears = WarrantyYears;
}

// Enter Details About reservation //
void  ElectronicsProduct::ReservedDetails(const char * ReservedDetails)
{
	this->reserved = 1;
	this->reservedName = NULL;
	this->reservedName = new char[strlen(ReservedDetails) + 1];
	strcpy(this->reservedName, ReservedDetails);
}

// Set Method for WaterProof //
void ElectronicsProduct::SetWaterProof(bool WaterProof)
{
	this->WaterProof = WaterProof;
}

// Get Method for WarrantyYears //
int ElectronicsProduct::GetWarrantyYears()
{
	return WarrantyYears;
}

// Get Method for WaterProof //
bool ElectronicsProduct::GetWaterProof()
{
	return WaterProof;
}

// Method to show the details of the product //
void ElectronicsProduct::show()const
{
	cout << "*********************" << endl;
	cout << "Product Name: " << this->ProductName << endl;
	cout << "Product Price: " << this->Price << endl;
	cout << "Product is in shelf no.: " << this->ShelfNumber << endl;
	cout << "Product ID no is: " << this->ProductNumber << endl;
	this->Size.show();
	if (this->WaterProof == 1) cout << "Device is WaterProof" << endl; else cout << "Device is NOT Water Proof" << endl;
	cout << "Warranty will end in: " << CURRENT_YEAR + this->WarrantyYears << endl;
	cout << "PLEASE READ THE LITTLE DETAILS: " << this->LittleDetails << endl;
	if (this->reserved == 1) cout << "This Product is Reserved to: " << this->reservedName << endl; else cout << "This Product Is Not Reserved To Anyone" << endl;
}

// Operator << //
ostream & operator<<(ostream & out, ElectronicsProduct & E)
{
	
	out << (Product&)E ;
		WARRANTY_PRINT		// Implementation in the first rows - #define WARRANTY_PRINT
		WATERPROOF_CHECK	// Implementation in the first rows - #define WATERPROOF_CHECK
		LITTLE_LETTERS		// Implementation in the first rows - #define LITTLE_LETTERS
		RESERVATION_CHECK_PRINT
	out << "*********************" << endl;
	return out;
}
