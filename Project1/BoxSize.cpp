#include "BoxSize.h"
#define NO_DETAILS_ENTERED "NO DETAILS ENTERED"

// Default constructor //
BoxSize::BoxSize() :height(0),width(0),length(0)
{
	this->GeneralDescription = new char[strlen(NO_DETAILS_ENTERED) + 1];
	strcpy(this->GeneralDescription, NO_DETAILS_ENTERED);
}

// 4-Arguments constructor //
BoxSize::BoxSize(int height, int width, int length, const char* GeneralDescription) : height(height),width(width),length(length)
{
	this->GeneralDescription = new char[strlen(GeneralDescription) + 1];
	strcpy(this->GeneralDescription, GeneralDescription);
}

// 3-Arguments constructor //
BoxSize::BoxSize(int height, int width,int length):height(height),width(width),length(length)
{
	this->GeneralInit();
}

// Copy Constructor //
BoxSize::BoxSize(const BoxSize & B)
{
	*this = B;
}

// Operator = //
const BoxSize & BoxSize::operator=(const BoxSize & other)
{
	if (this != &other) {
		this->height = other.height;
		this->width = other.width;
		this->length = other.length;
		this->GeneralDescription = NULL;
		this->GeneralDescription = new char[strlen(other.GeneralDescription) + 1];
		strcpy(this->GeneralDescription, other.GeneralDescription);
	}
	return *this;
}

// Operator == //
bool BoxSize::operator==(const BoxSize & other) const
{
	if ((height == other.height) && (width == other.width) && (length==other.length)&& (strcmp(this->GeneralDescription,other.GeneralDescription))==0)
		return true;
	return false;
}

// Operator += for the height //
void BoxSize::operator+=(int height)
{
	this->height += height;
}

// Operator -= for the height //
void BoxSize::operator-=(int height)
{
	this->height -= height;
}

// Show Method //
void BoxSize::show()const 
{
	cout << "Box dimensions: " << endl;
	cout << "height: " << this->height << ", width: " << this->width << ", length: " << this->length << endl;
	cout << "Box size is: " << this->GeneralDescription << endl;
}

// Get Method for height //
int BoxSize::Getheight()
{
	return this->height;
}

// Get Method for width //
int BoxSize::Getwidth()
{
	return this->width;
}

// Get Method for length //
int BoxSize::Getlength()
{
	return this->length;
}

// set Method for height //
void BoxSize::SethHeight(int height)
{
	this->height = height;
}

// set Method for width //
void BoxSize::SethWidth(int width)
{
	this->width = width;
}

// set Method for length //
void BoxSize::SethLength(int length)
{
	this->length = length;
}

// Method to add general description based on the dimensions //
void BoxSize::GeneralInit()
{
	if (this->height <= 100 && this->width <= 85 && this->length <= 80)
	{
		if (this->height <= 75 && this->width <= 60 && this->length <= 55)
		{
			if (this->height <= 35 && this->width <= 25 && this->length <= 25)
			{
				this->GeneralDescription = NULL;
				this->GeneralDescription = new char[strlen("Small") + 1];
				strcpy(this->GeneralDescription, "Small");
			}
			else
			{
				this->GeneralDescription = NULL;
				this->GeneralDescription = new char[strlen("Medium") + 1];
				strcpy(this->GeneralDescription, "Medium");
			}
		}		
	}
	else
	{
		this->GeneralDescription = NULL;
		this->GeneralDescription = new char[strlen("Big") + 1];
		strcpy(this->GeneralDescription, "Big");
	}
}

// Method to add new General Description //
void BoxSize::AddGeneral(const char * AddGeneral)
{
	char *NewGeneral = new char[strlen(this->GeneralDescription) + strlen(AddGeneral) + strlen(", ") + 1];
	strcpy(NewGeneral, this->GeneralDescription);
	strcat(NewGeneral, ", ");
	strcat(NewGeneral, AddGeneral);

	this->GeneralDescription = new char[strlen(NewGeneral) + 1];
	strcpy(this->GeneralDescription, NewGeneral);
	delete[] NewGeneral;
}

// Destructor //
BoxSize::~BoxSize()
{
	delete []GeneralDescription;
}

// Operator << // 
ostream & operator<<(ostream & out, BoxSize & B)
{
	out << "Box dimensions: " << endl;
	out << "height: " << B.height << ", width: " << B.width << ", length: " << B.length << endl;
	out << "Important Details About The Box: " << B.GeneralDescription << endl;
	return out;
}
