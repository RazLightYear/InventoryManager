#include"Signatures.h"
/** 
	The Menu options implementation.
**/


// Default Constructor //
 Menu::Menu()
{
	 Show_Welcome_Message();
	Options();
}

// Actions Activator //
void Menu::Options()
{
	
	while (choice)
	{
		// Show The Menu Options //
		
		showMenu();
		cout <<endl<< "Please Enter Your Choice:" << endl;
		cin >> choice;
		switch (choice)
		{

		// Create New Electronics Product //
		case 1:
			THE_DETAILS_WILL_BE_SAVED
			initElectronicsProducts();
			break;

		// Print the products to the console and write to a File //
		case 2:
			PrintElectronicsProducts();
			break;

		// Add Warranty Years to a Product //
		case 3:
			AddWarrantyYears();
			break;

		// Create New Groceries Product //
		case 4:
			THE_DETAILS_WILL_BE_SAVED
			initGroceriesProducts();
			break;

		// Print the products to the console and write to a File //
		case 5:
			PrintGroceriesProducts();
			break;

		// Add Allergies Ingredients to a Product //
		case 6:
			AddAllergies();
			break;


		case 7:
			CANT_RESERVE_ALL
			ReservElectronics();
			break;
		case 8:
			cout << "There Are " << E.size() << " Electronics Products" << endl;
			break;

		case 9:
			cout << "There Are " << G.size() << " Groceries Products" << endl;
			break;

		case 10:
			Delete_Electronics_Product();
			break;

		case 11:
			Delete_Groceries_Product();
			break;

		// EXIT the Menu Option //
		case QUIT_CHOICE:
			exit(0);
		}
	}
}
	
// Method to show the menu of options to the user //
void Menu::showMenu()
{
	cout << endl;
	cout << "Please Choose An Option" << endl;
	cout << "1. Create new Electronics Product" << endl;
	cout << "2. Display the Electronics Products" << endl;
	cout << "3. Add Warranty Years to an Electronics Product (By the product name) " << endl;
	cout << "4. Create new Groceries Product" << endl;
	cout << "5. Display the Groceries Products" << endl;
	cout << "6. Add New Allergies Ingredients To A Product (By the product name)" << endl;
	cout << "7. Reserve Electronics Products" << endl;
	cout << "8. Count How Many Electronic Products There Are (By Product Name)" << endl;
	cout << "9. Count How Many Groceries Products There Are (By Product Name)" << endl;
	cout << "10. Delete A Electronics Product " << endl;
	cout << "11. Delete A Groceries Product " << endl;
	cout << "12. Exit The Program " << endl;
}

// Method to show A Welcome Message to the user //
void Show_Welcome_Message()
{
	cout << endl << endl << endl;

	cout << "                         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " << endl;
	cout << "                         *               Welcome To The Products Inventory Manager!            * " << endl;
	cout << "			 *                Down Below You Can See The Menu Options.             * " << endl;
	cout << "			 *      There Are Various Operations You Can Preform,But There Are A   * " << endl;
	cout << "			 *    Few Notes: Please Pay Attention To Places Where Only 1 OR 0 are  * " << endl;
	cout << "			 *     Acceptable As Values (Written In Brackets), For Optimal Usage   * " << endl;
	cout << "			 *      Of The Program And Efficient Data Storgae, Please Leave The    * " << endl;
	cout << "			 *    Console Window Open,Although The Data Is Stored In A Text File   * " << endl;
	cout << "			 *    In The Project Folder, The Optimal Way Is To Leave The Console   * " << endl;
	cout << "			 *                          Window Open.                               * " << endl;
	cout << "			 *         For Any Issues Regarding This Program Please Contact        * " << endl;
	cout << "			 *    The Author Of This Program: Raz Ben Aderet : Razgimi@gmail.com   * " << endl;
	cout << "			 *                All Rights Reserved To Raz Ben Aderet                * " << endl;
	cout << "			 *                           ENJOY ! :)                                * " << endl;
	cout << "			 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " << endl;
	cout << endl << endl;
}

// Create New Electronic Product //
void Menu::initElectronicsProducts()
{
	string tempname, templittledetails,tempBoxDescriptions;
	double price;
	int shelf, warranty,height,width,length,NumberOfTimes;
	bool water;		
	BoxSize B1;

	tempname = Enter_Product_Name();
	const char * name = tempname.c_str();	

	price = Enter_Product_Price();		
	shelf = Enter_Product_Shelf_Number();	
	warranty=Enter_Product_Warranty_Years();	
	water = Enter_Product_WaterProof_Option();

	B1 = Enter_Product_Box_Dimensions();
	tempBoxDescriptions = Enter_Special_Details_About_Box();
	const char * BoxDescription = tempBoxDescriptions.c_str();	

	templittledetails = Enter_Special_Details_About_Product();
	const char * little_details = templittledetails.c_str();

	NumberOfTimes = Enter_Number_Of_Products();

	B1.AddGeneral(BoxDescription);

	ElectronicsProduct EE(B1,name, price, shelf, warranty, water, little_details);	

	ofstream Efile("ElectronicsInventory.txt", ios::app);
	for ( int i = 0; i < NumberOfTimes; i++)
	{
		E.push_front(EE);
		Efile << EE << endl;
		
	}
	PRINT_CREATION_SUCCESSFUL
}

// Print Electronic Products details //
void Menu::PrintElectronicsProducts()
{	
	if (E.begin() == E.end()) NO_PRODUCTS_PRINT
	list<ElectronicsProduct>::iterator i;
	for (i = E.begin(); i != E.end(); ++i)
	{		
		cout << *i << endl;				
	}	
}

// method to add warranty years //
void Menu::AddWarrantyYears()
{
	// if the list of products is empty //
	if (E.begin() == E.end()) NO_PRODUCTS_PRINT

	// if the list of products is not empty //
	else
	{
		string tmpName;
		bool YesNo;
		int Yearsadd;

		tmpName = Enter_Product_Name();
		const char *name = tmpName.c_str();
		
		cout << "please enter number of years extansion: " << endl; // add years amount // 
		cin >> Yearsadd;
		cout << "Does The Warranty Extansion cost extra? (1 For YES, 0 For NO)" << endl; // choice: extra cost or not //
		cin >> YesNo;

		list<ElectronicsProduct>::iterator j;
		list<ElectronicsProduct>::iterator i;
		for (i = E.begin(); i != E.end(); ++i)
		{		
				// if the right product name was found and an extra cost is needed//		
				if (strcmp(i->GetProductName(), name) == 0 && YesNo == 1)
				{
					cout<<"This Warranty Extansion Cost An Extra Of: "<< Yearsadd *(i->GetPrice()/6)<<endl;														
					i->IncreaseWarrantyYears(Yearsadd);					
					PRINT_ACTION_SUCCESSFUL
				}
			
				// if the right product name was found and an extra cost is not needed//
				else if (strcmp(i->GetProductName(), name) == 0 && YesNo == 0)
				{
					i->operator+=(Yearsadd);
					PRINT_ACTION_SUCCESSFUL
				}
				
				// if the right product name was not found //
				else if (strcmp(i->GetProductName(), name) == 1 && i==E.end())
				{
					NO_PRODUCT_FOUND_PRINT
					break;
				}
				
				//Write The New Products Details To The File //
				{
					
					ofstream Efile("ElectronicsInventory.txt", ios::trunc);
					for (j = E.begin(); j != E.end(); ++j)
					{				
							Efile << *j << endl;
					}
				}
		}
	}
}

// Create New Electronic Product //
void Menu::initGroceriesProducts()
{
	string tempname, tempAllergies, tempBoxDescriptions;
	double price;
	int shelf,height,width,length, NumberOfTimes;
	bool vegean;
	Date D1;
	BoxSize B1;

	tempname = Enter_Product_Name();
	const char * name = tempname.c_str();

	price = Enter_Product_Price();
	shelf = Enter_Product_Shelf_Number();
	vegean=Enter_Product_Vegean_Option();

	B1 = Enter_Product_Box_Dimensions();
	D1 = Enter_Product_Expiary_Date();

	tempBoxDescriptions = Enter_Special_Details_About_Box();
	const char * BoxDescription = tempBoxDescriptions.c_str();
	
	tempAllergies = Enter_Product_Allergies_Ingredients();
	const char * allergies = tempAllergies.c_str();
	
	NumberOfTimes = Enter_Number_Of_Products();

	Groceries GG(B1, name, price, shelf, vegean, D1, allergies);

	ofstream Gfile("GroceriesInventory.txt", ios::app);
	for (int i = 0; i < NumberOfTimes; i++)
	{
		G.push_front(GG);
		Gfile << GG << endl;
	}
	PRINT_CREATION_SUCCESSFUL

}

// Print Groceries Products details //
void Menu::PrintGroceriesProducts()
{
	ofstream Gfile("GroceriesInventory.txt", ios::app);
	if (G.begin() == G.end()) NO_PRODUCTS_PRINT
		list<Groceries>::iterator i;
	for (i = G.begin(); i != G.end(); ++i)
	{
		cout << *i << endl;
		Gfile << *i << endl;
	}
}

// method to add Allergies Ingredients //
void Menu::AddAllergies()
{
	// if the list of products is empty //
	if (G.begin() == G.end()) NO_PRODUCTS_PRINT

	// if the list of products is not empty //
	else
	{
		string tmpName,tmpAllergies;
		bool flag=false;
		
		tmpName = Enter_Product_Name();
		const char *name = tmpName.c_str();

		tmpAllergies = Enter_Product_Allergies_Ingredients();
		const char *Allergies = tmpAllergies.c_str();

		list<Groceries>::iterator i;
		for (i = G.begin(); i != G.end(); ++i)
		{
			//if the right product name was found //
			if (strcmp(i->GetProductName(), name) == 0 )
			{
				i->AddAllergies(Allergies);
				flag = true;
			}	

			// if the right product name was not found //
			else 
			{
				NO_PRODUCT_FOUND_PRINT
				break;
			}

			 //Write The New Products Details To The File //
			list<Groceries>::iterator k;
			ofstream Gfile("GroceriesInventory.txt", ios::trunc);
			for (k = G.begin(); k != G.end(); ++k)
			{
				Gfile << *k << endl;
			}
		}
		 if (flag==true) PRINT_ACTION_SUCCESSFUL 
	}
}

// Destructor //
Menu::~Menu()
{
}

// Method To Reserve Electronics Products //
void Menu::ReservElectronics()
{
	// if the list of products is empty //
	if (E.begin() == E.end()) NO_PRODUCTS_PRINT

		// if the list of products is not empty //
	else
	{
		string tmpProdName,TmpCostumerName;
		int HowMany=0;
		tmpProdName = Enter_Product_Name();
		const char* ProdName = tmpProdName.c_str();
		cout << "How Many Products You Want To Reserve? " << endl;
		cin >> HowMany;
		cout << "Enter The Name Of The Costumer: " << endl;
		cin.ignore();
		getline(cin, TmpCostumerName);
		const char* CostumerName = TmpCostumerName.c_str();
		int j = 0;
		
		list<ElectronicsProduct>::iterator i;
		for (i = E.begin(); i != E.end()&&j<HowMany; ++i,++j)
		{
			if (strcmp(i->GetProductName(), ProdName) == 0)
			{
				i->ReservedDetails(CostumerName);
				
			}
		}
		list<ElectronicsProduct>::iterator h;
		ofstream Efile("ElectronicsInventory.txt", ios::trunc);
		for (h = E.begin(); h != E.end(); ++h)
		{
				
				Efile << *h << endl;
		}
			PRINT_ACTION_SUCCESSFUL
	}
}

// Method To Delete A Electronics Product //
void Delete_Electronics_Product()
{
	string tmpname=Enter_Product_Name();
	const char* name = tmpname.c_str();
	int howmany = 0;
	cout << "How Many Of '" << name << "' Do You Want To Delete?" << endl;
	cin >> howmany;
	list<ElectronicsProduct>::iterator l;
	list<ElectronicsProduct>::iterator n;
	int j=0;
	if (E.begin() == E.end()) NO_PRODUCTS_PRINT
	for (l = E.begin(); l != E.end();)
	{
		if (j == howmany) break;

		//if the right product name was found //
		else if (strcmp(l->GetProductName(), name) == 0)
		{
			n = l;
			advance(l, 1);
			E.erase(n);
			j++;
		}
		
		// if the right product name was not found //
		else
		{
			NO_PRODUCT_FOUND_PRINT
				break;
		}
		//Write The New Products Details To The File //
		list<ElectronicsProduct>::iterator k;
		ofstream Efile("ElectronicsInventory.txt", ios::trunc);
		for (k = E.begin(); k != E.end(); ++k)
		{
			Efile << *k << endl;
		}

	}
	PRINT_DELETION_SUCCESSFUL
}

// Method To Delete A Groceries Product //
void Delete_Groceries_Product()
{
	string tmpname = Enter_Product_Name();
	const char* name = tmpname.c_str();
	int howmany = 0;
	cout << "How Many Of '" << name << "' Do You Want To Delete?" << endl;
	cin >> howmany;
	list<Groceries>::iterator l;
	list<Groceries>::iterator n;
	int j = 0;
	if (G.begin() == G.end()) NO_PRODUCTS_PRINT
		for (l = G.begin(); l != G.end();)
		{
			if (j == howmany) break;

			//if the right product name was found //
			else if (strcmp(l->GetProductName(), name) == 0)
			{
				n = l;
				advance(l, 1);
				G.erase(n);
				j++;
			}

			// if the right product name was not found //
			else
			{
				NO_PRODUCT_FOUND_PRINT
					break;
			}
			//Write The New Products Details To The File //
			list<Groceries>::iterator k;
			ofstream Gfile("GroceriesInventory.txt", ios::trunc);
			for (k = G.begin(); k != G.end(); ++k)
			{
				Gfile << *k << endl;
			}

		}
	PRINT_DELETION_SUCCESSFUL
}

// Method For Getting Product Name From The User //
string Enter_Product_Name()
{
	string tempname;
	cout << "enter the product name: " << endl;
	cin.ignore();
	getline(cin, tempname);
	return tempname;
}

// Method For Getting Product Price From The User //
double Enter_Product_Price()
{
	double price;
	cout << "enter the product price: " << endl;
	cin >> price;
	return price;
}

// Method For Getting Product Shelf Number From The User //
int Enter_Product_Shelf_Number()
{
	int shelf;
	cout << "enter the product shelf number: " << endl;
	cin >> shelf;
	return shelf;
}

// Method For Getting Product Warranty Years From The User //
int Enter_Product_Warranty_Years()
{
	int warranty;
	cout << "enter the product warranty years: " << endl;
	cin >> warranty;
	return warranty;
}

// Method For Getting Product WaterProof Option From The User //
bool Enter_Product_WaterProof_Option()
{	
	bool water;
	cout << "is the product waterproof ? (1 for YES , 0 for NO): " << endl;
	cin >> water;	
	return water;
}

// Method For Getting Product Box Dimensions From The User //
BoxSize Enter_Product_Box_Dimensions()
{
	int height, width, length;
	cout << "enter the product box dimensions(In CM): height, width ,length " << endl;
	cin >> height;
	cin >> width;
	cin >> length;
	BoxSize B1(height, width, length);
	return B1;
}

// Method For Getting Special Details About The Box From The User //
string Enter_Special_Details_About_Box()
{
	string tempBoxDescriptions;
	cout << "Anything special about the Box ? FOR EXAMPLE: Fragile" << endl;
	cin.ignore();
	getline(cin, tempBoxDescriptions);
	return tempBoxDescriptions;
}

// Method For Getting Special Details About The Product From The User //
string Enter_Special_Details_About_Product()
{
	string templittledetails;
	cout << "enter Important Details About The Product Itself: " << endl;
	getline(cin, templittledetails);
	return templittledetails;
}

// Method For Getting The Number Of Products From The User //
int Enter_Number_Of_Products()
{
	int NumberOfTimes;
	cout << "How Many Of This Product?" << endl;
	cin >> NumberOfTimes;
	return NumberOfTimes;
}

// Method For Getting Product Vegean Option From The User //
bool Enter_Product_Vegean_Option()
{
	bool vegean;
	cout << "is the product Vegean ? (1 for YES , 0 for NO): " << endl;
	cin >> vegean;
	return vegean;
}

// Method For Getting Product Expiary Date From The User //
Date Enter_Product_Expiary_Date()
{
	string tempBoxDescriptions;
	int Day, Month, Year;
	cout << "enter the product Expiary Date: Day, Month ,Year " << endl;
	cin >> Day;
	cin >> Month;
	cin >> Year;
	Date D1(Day, Month, Year);
	return D1;
}

// Method For Getting Product Allergies Ingredients From The User //
string Enter_Product_Allergies_Ingredients()
{
	string tempAllergies;
	cout << "enter the product Allergies Ingredients: (Nuts,Flower etc.) " << endl;
	getline(cin, tempAllergies);
	return tempAllergies;
}


