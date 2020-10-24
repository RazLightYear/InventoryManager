#include "Groceries.h"

#define VEGEAN_CHECK_PRINT if(G.Vegean==true) out<<"This Product is Vegean Friendly!"<<endl; else out<<"This Product is NOT Vegean Friendly"<<endl;
#define DATE_PRINT out << "This Product Expiery Date: " << G.ExpieryDate << endl;
#define ALLERGIES_WARNINGS out<< "This Product Contains: "<<G.Allergies<<endl;

// Default Constructor //
Groceries::Groceries() :Product()
{
	this->Vegean = false;
	this->ExpieryDate = Date();
	this->Allergies = new char[strlen("NONE") + 1];
	strcpy(this->Allergies, "NONE");
}

// 7 - Arguments Constructor //
Groceries::Groceries(BoxSize & BoxSize, const char * ProductName, double price, int ShelfNumber, bool Vegean,Date ExpieryDate, const char * Allergies) :Product(ProductName, price, ShelfNumber)
{
	this->Size = BoxSize;
	this->Vegean = Vegean;
	this->ExpieryDate = ExpieryDate;
	this->Allergies = new char[strlen(Allergies) + 1];
	strcpy(this->Allergies, Allergies);
}

// 6 - Arguments Constructor //
Groceries::Groceries(const char * ProductName, double price, int ShelfNumber, bool Vegean, Date ExpieryDate, const char * Allergies) :Product(ProductName, price, ShelfNumber)
{
	this->Vegean = Vegean;
	this->ExpieryDate = ExpieryDate;
	this->Allergies = new char[strlen(Allergies) + 1];
	strcpy(this->Allergies, Allergies);
}

// 5 - Arguments Constructor //
Groceries::Groceries(const char * ProductName, double price, int ShelfNumber, bool Vegean, const char * Allergies):Product(ProductName,price,ShelfNumber)
{
	this->Vegean = Vegean;
	this->Allergies = new char[strlen(Allergies) + 1];
	strcpy(this->Allergies, Allergies);
}

// Copy Constructor //
Groceries::Groceries(const Groceries & other) :Product(other)
{
	*this = other;
}

// Operator = //
const Groceries & Groceries::operator=(const Groceries & other)
{
	if (this != &other)
	{
		Product::operator=(other);
		this->Vegean = other.Vegean;
		this->ExpieryDate = other.ExpieryDate;
		this->Allergies = NULL;
		this->Allergies = new char[strlen(other.Allergies) + 1];
		strcpy(this->Allergies, other.Allergies);
	}
	return *this;
}

// Operator == //
bool Groceries::operator==(const Groceries & other) const
{
	if (Product::operator==(other) == true && (this->Vegean == other.Vegean) && (this->ExpieryDate == other.ExpieryDate)&&(strcmp(this->Allergies,other.Allergies))==0) return true;
	return false;
}

//Operator += //
void Groceries::operator+=(const char * addAllergies)
{
	char *NewAllergies = new char[strlen(this->Allergies) + strlen(addAllergies) + strlen(", ") + 1];
	strcpy(NewAllergies, this->Allergies);
	strcat(NewAllergies, ", ");
	strcat(NewAllergies, addAllergies);
}

// Set Method for Vegean //
void Groceries::SetVegean(bool Vegean)
{
	this->Vegean = Vegean;
}

// Set Method for ExpieryDate //
void Groceries::SetExpieryDate(Date ExpieryDate)
{
	this->ExpieryDate = ExpieryDate;
}

// Get Method for Vegean //
bool Groceries::GetVegean()
{
	return Vegean;
}

// Get Method for ExpieryDate //
Date Groceries::GetExpieryDate()
{
	return ExpieryDate;
}

// Method to add new Allergies warnings //
void Groceries::AddAllergies(const char * AddAllergies)
{
	char *NewAllergies = new char[strlen(this->Allergies) + strlen(AddAllergies) +strlen(", ")+ 1];
	strcpy(NewAllergies, this->Allergies);
	strcat(NewAllergies, ", ");
	strcat(NewAllergies, AddAllergies);

	this->Allergies = new char[strlen(NewAllergies) + 1];
	strcpy(this->Allergies, NewAllergies);
	delete[] NewAllergies;
}

// Method to show the details of the product //
void Groceries::show()const 
{
	cout << "*********************" << endl;
	cout << "Product Name: " << this->ProductName << endl;
	cout << "Product Price: " << this->Price << endl;
	cout << "Product is in shelf no.: " << this->ShelfNumber << endl;
	cout << "Product ID no is: " << this->ProductNumber << endl;
	if (this->Vegean == true) cout << "This Product is Vegean Friendly!" << endl; else cout << "This Product is NOT Vegean Friendly" << endl;
	cout << "This Product Expiery Date: " << this->ExpieryDate << endl;
	cout << "This Product Contains: " << this->Allergies << endl;

}

// Operator << //
ostream & operator<<(ostream & out, Groceries & G)
{
	out << (Product&)G;
	VEGEAN_CHECK_PRINT
	DATE_PRINT	
	ALLERGIES_WARNINGS
	out << "*********************" << endl;
	return out;
}
