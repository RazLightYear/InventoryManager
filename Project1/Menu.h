#ifndef MENU
#define MENU
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

/**
	This Class Represent The Menu That Will Be Presented On The Console,And Will Allow
	The User To Preform Various Actions.
**/

class Menu 
{
	int choice;
	

public:

	// Default Constuctor //
	Menu();

	// Actions Activator //
	void Options();

	// Show Menu Method //
	void showMenu();

	// Create New Electronic Product //
	void initElectronicsProducts();

	// Print The List Of Electronic Products //
	void PrintElectronicsProducts();

	// Add Warranty Years Method //
	void AddWarrantyYears();

	// Create New Groceries Product //
	void initGroceriesProducts();

	// Print The List Of Groceries Products //
	void PrintGroceriesProducts();

	// Add Allergies To An Existing Product //
	void AddAllergies();

	// Method To Reserve Electronics Products //
	void ReservElectronics();

	// Destructor //
	~Menu();
};
#endif