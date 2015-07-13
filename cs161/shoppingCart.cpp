/****************************************************************************************
Author: Lindsay Tucker
Date created: 10Jan2015
Date last modified: 12Jan2015
Program Filename:  shoppingCart.cpp
****************************************************************************************/

#include <iostream>
#include <vector>
#include<iomanip> //for showpoint, setprecision, fixed

using namespace std;

//GLOBAL CONSTANTS
const int SIZE = 101; //max # of char for 'name'

class Item
{
	private:
	char name [SIZE];
	double price;
	int quantity;

	public:
	//CONSTRUCTORS
	//default (constructor)
	Item (){};

	//initialize all of the members (constructor)
	Item (char n [SIZE], double p, int q)
	{
			for (int i = 0; i < SIZE; i ++)
			{
					name [i] = n [i]; //c-string 'name' equal to input 'n'
			}
			price = p;
			quantity = q;
	}

	//SET FUNCTIONS
	void setName(char name_input [SIZE])
	{
			for (int i = 0; i < SIZE; i ++)
			{
					name [i] = name_input [i]; //c-string 'name' equal to input name_input
			}
	}

	void setPrice(double price_input)
	{
			price = price_input;
	}

	void setQuantity(int quantity_input)
	{
			quantity = quantity_input;
	}

	//GET FUNCTIONS
	char *getName() //found this solution here: http://stackoverflow.com/questions/1496313/returning-c-string-from-a-function
	{
			return name;
	}
			//string getName() // THIS ALSO WORKS, NOT SURE HOW
			//{
					//return name;
			//}

	double getPrice()
	{
			return price;
	}

	int getQuantity()
	{
			return quantity;
	}

};

class ShoppingCart
{
	private:
	vector <Item> itemVector;

	public:
	//CONSTRUCTORS
	//default (constructor)
	ShoppingCart (){};

	//GET FUNCTIONS
	vector<Item> getItemVector() //Needed?  //REMOVE?
	{
			return itemVector;
	}

	//SET FUNCTIONS
	void setItemVector(vector<Item> itemVector_input)  //Needed?  //REMOVE?
	{
			itemVector = itemVector_input;
	}

	//MEMBER FUNCTIONS
	void addItem (Item junk)
	{
			itemVector.push_back(junk);
	}

	void listItems ();
	double totalPrice();

};

//ShoppingCart CONSTRUCTORS
//default (inline)

//ShoppingCart MEMBER FUNCTIONS
void ShoppingCart::listItems ()
{
		if (itemVector.empty())
		{
				cout << "Cart is empty." << endl;
		}

		else
		{
				int num_items = 0;     //local incrementing variable for counting items in vector

				cout << "List of Shopping Cart Contents: " << endl;
				for (int i = 0; i < itemVector.size(); i ++)
				{
						//Display each item in Shopping Cart
						cout << endl;
						cout << "Name: " << itemVector[i].getName() << endl;
						cout << "Price: $ " << fixed << showpoint << setprecision(2) << itemVector[i].getPrice() << endl;
						cout << "Qty: " << itemVector[i].getQuantity() << endl;

						num_items ++;
				}
				//cout<<endl;
				//cout<<"Number of item types in shopping cart: "<<num_items<<endl; //TESTING
				//cout<<endl;
		}
		return;
}

double ShoppingCart::totalPrice()
{
		double total_price = 0;

		//If cart is empty message
		if (itemVector.empty())
		{
				cout << "(cart is empty)" << endl;
		}

		//Calculate total
		for(int i = 0; i < itemVector.size(); i ++)
		{
				total_price += itemVector[i].getPrice() * itemVector[i].getQuantity(); //price multiplied by quantity for each Item in itemVector
		}

		//Return total
		cout << endl;
		//cout<<"Total price of items in Shopping Cart: $ "<<fixed<<showpoint<<setprecision(2)<<total_price<<endl; //TESTING
		return total_price;

}


int main ()
{
	char choice;  //variable for switch

	char n [SIZE]; //variable for name in Item object constructor
	double p;  //variable for price Item object constructor
	int q;  //variable for quantity in Item object constructor

	Item junk (n, p, q); //initializes constructor
	ShoppingCart shoppingCartObject; //initialize a ShoppingCart object to store Item objects in


   //DISPLAY MENU
    cout << "-------------------------------SHOPPING CART-------------------------------" << endl;

    do
	{
        //Display menu and prompt user for choice
        cout << "\nChoose one of the following options: " << endl;
        cout << "1. Add an item" << endl;
        cout << "2. List shopping cart contents" << endl;
        cout << "3. Calculate subtotal " << endl;
        cout << "4. Quit" << endl;
		cout << "Enter an option (1-4): ";
        cin >> choice;
        cin.ignore(100, '\n'); //throw away rest of the line

        //Switch statement for user menu choices
        switch (choice)
		{
            case '1': //////////// ADD ITEM //////////////////////

				cout << "Item name: " << endl;
				cin.get(n, SIZE, '\n');  //stops at SIZE or at newline character
				junk.setName(n);

				cout << "Item price: $";
				cin >> p;
				cin.ignore(100, '\n'); //throw away rest of the line
				junk.setPrice(p);
				while (!cin) //INPUT VALIDATION
				{
							cin.clear(); //clears error code for cin
							cin.ignore(100, '\n'); //throw away garbage entered
							cout << "Invalid price. Enter a double: " << endl;
							cin >> p;
							cin.ignore(100, '\n'); //throw away rest of the line
							junk.setPrice(p);
				}

				cout << "Item quantity: "<<endl;
				cin >> q;
				cin.ignore(100, '\n'); //throw away rest of the line
				junk.setQuantity(q);
				while (!cin) //INPUT VALIDATION
				{
							cin.clear();
							cin.ignore(100, '\n');
							cout << "Invalid quantity. Enter an integer: " << endl;
							cin >> q;
							cin.ignore(100, '\n'); //throw away rest of the line
							junk.setQuantity(q);
				}

				//echo cart addition
				cout << "\nYOU'VE JUST ADDED THE FOLLOWING TO YOUR CART: " << endl;
				cout << "Item: " << n << endl;
				cout << "Price: $" << fixed << showpoint << setprecision(2) << p << endl;
				cout << "Quantity: " << q << endl;

				//entry (Item object: junk)  added to shoppingCart object (pushback to itemVector)
				shoppingCartObject.addItem(junk);
				cout << " -------------------------" << endl;
                break;

            case '2': ////////////////////// LIST ITEM ///////////////////////////
				shoppingCartObject.listItems();
				cout << " -------------------------" << endl;
                break;

            case '3': ////////////////////  TOTAL PRICE ///////////////////
                cout << "Total price of items in shopping cart: ";
				cout << "$ " << fixed << showpoint << setprecision(2) << shoppingCartObject.totalPrice() << endl;
				cout << " -------------------------" << endl;
               break;

            case '4':
                //Exit program
                cout << "Exiting." << endl;
                break;

            default:
                break;

		} //end of SWITCH

		if (choice == '4')
		{
				break;
		}

	} while ((choice = '1') || (choice = '2') || (choice = '3'));

	return 0;
}
