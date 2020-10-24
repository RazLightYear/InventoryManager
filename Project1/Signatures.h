#ifndef SIGNATURES
#define SIGNATURES
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include <list>
#include<algorithm>
#include <fstream> 

#include "Menu.h"
#include"ElectronicsProduct.h"
#include"Groceries.h"
#include"BoxSize.h"

// Definition For Some Constant Actions That Shows Several Times In The Program //
#define QUIT_CHOICE 12
#define PRINT_ACTION_SUCCESSFUL cout << endl << "OPERATION SUCCEEDED! "<<endl;
#define PRINT_CREATION_SUCCESSFUL cout<<endl<<"OPERATION SUCCEEDED! "<<NumberOfTimes<<" '"<<name<<"' "<<"Products Were Created"<<endl;
#define PRINT_DELETION_SUCCESSFUL cout<<endl<<"OPERATION SUCCEEDED! "<<howmany<<" '"<<name<<"' "<<"Products Were Deleted"<<endl;
#define NO_PRODUCTS_PRINT cout <<endl<< "***NO PRODUCTS***" << endl<<endl;
#define NO_PRODUCT_FOUND_PRINT cout << endl << "No Product With The Name: " << name << " Was Found, Please Try Again And Check Your Spelling" << endl;
#define CANT_RESERVE_ALL cout <<endl<<"Please Note That You CANNOT Reserve ALL Of These The Products, Maximum (n-1)"<<endl;
#define THE_DETAILS_WILL_BE_SAVED cout<<endl<<"Please Note That A File With The Products Details Will Be Saved To The Project`s Folder"<<endl<<endl;



// Definition Of Linked-Lists To Save The Input Products //
list<ElectronicsProduct> E;
list<Groceries> G;


// Declarations Of Functions Needed To Get Input From The User //
string Enter_Product_Name();
double Enter_Product_Price();
int Enter_Product_Shelf_Number();
int Enter_Product_Warranty_Years();
bool Enter_Product_WaterProof_Option();
BoxSize Enter_Product_Box_Dimensions();
string Enter_Special_Details_About_Box();
string Enter_Special_Details_About_Product();
int Enter_Number_Of_Products();
bool Enter_Product_Vegean_Option();
Date Enter_Product_Expiary_Date();
string Enter_Product_Allergies_Ingredients();
void Delete_Electronics_Product();
void Delete_Groceries_Product();
void Show_Welcome_Message();

using namespace std;



#endif
