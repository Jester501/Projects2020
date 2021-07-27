//Noe Sancen Inherentice pizza


#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <ctime>

using namespace std;





class Pizza
{
	private:
		string pizzaSize;
		string pizzaType;
		vector <string> pizzaToppings;
		float pizzaPrice;
		
		float calculatePizzaPrice()
		{
			float small = 10.00, medium = 14.00, large = 17.00;
			float price=0;
			
			float sizePrice=0;
			
			if (pizzaSize == "Small")
			{
				sizePrice = small;
			}	
			else if(pizzaSize == "Medium")
			{
				sizePrice = medium;
			}	
			else if (pizzaSize == "Large")
			{
				sizePrice = large;
			}
			cout<<"pizza size "<<pizzaToppings.size();
			price = (pizzaToppings.size() * 2) + sizePrice; //pizzaToppings.size checks how many toppings the user added in the main function below
																// and adds the price fee.
																
			cout<<"price: "<<price;
			return price;
		}
	
	public:
		Pizza(string size, string type, vector <string> top)
		{
			pizzaSize = size;
			pizzaType = type;
			pizzaToppings = top;
			
			pizzaPrice = calculatePizzaPrice();
		}
		
		string getPizzaSize()
		{
			return pizzaSize;
		}
		
		string getPizzaType()
		{
			return pizzaType;
		}
		
		vector <string> getPizzaToppings()
		{
			return pizzaToppings;
		}
		
		float getPizzaPrice()
		{
			return pizzaPrice;
		}
		
		friend ostream& operator <<(ostream& o, Pizza p)
		{
			o << setprecision(2) << fixed;
			
		if (p.pizzaToppings.size() == 0)
		{
			o << "\n\n" << "You ordered a " << p.pizzaSize << " " << p.pizzaType << " Pizza";
			o << "\n\n" << "Pizza Price: $" << p.pizzaPrice << endl;
		}
		else 
		{
			o << "\n\n" << "You ordered a " << p.pizzaSize << " " << p.pizzaType << " with";
			for (string t : p.pizzaToppings)
				o << " " << t;
			o << "\n\n" << "Pizza Price: $" << p.pizzaPrice << endl;			
		}
			
			return o;	
		}
		
		
	
};

class DeliveredPizza : public Pizza
{
	private:
		float deliveryFee;
		float totalPrice;
		string deliveryAddress;
		
	public:
		DeliveredPizza(string size, string type, vector<string> top, string add) : Pizza(size, type, top)
		{
			deliveryAddress = add;
			
			totalPrice = getPizzaPrice();
			if(totalPrice > 20)
			{
				deliveryFee = 3.50;
			}
			else if(totalPrice <= 20)
			{
				deliveryFee = 5;
			}
			
		} 
		
		float getDeliveryFee()
		{
			return deliveryFee;
		}
		
		float getTotalPrice()
		{
			return totalPrice;
		}
	
		friend ostream& operator <<(ostream& o, DeliveredPizza dp)
		{
			o << setprecision(2) << fixed;
			
			if (dp.getPizzaToppings().size() == 0)
		{
			o << "\n\n" << "You ordered a " << dp.getPizzaSize() << " " << dp.getPizzaType()<< " Pizza";
			o << "\n\n" << "Pizza Price: $" << dp.getPizzaPrice() << endl;
			o << "Delivery Fee: $" << dp.getDeliveryFee() << endl;
			o << "Total Price: $" << dp.getPizzaPrice() + dp.getDeliveryFee() << endl;
			o << "\n" << "Delivered to: " << dp.deliveryAddress << endl;
		}
		else 
		{
			o << "\n\n" << "You ordered a " << dp.getPizzaSize() << " " << dp.getPizzaType() << " with";
			for (string d : dp.getPizzaToppings())
				o << " " << d;
			o << "\n\n" << "Pizza Price: $" << dp.getPizzaPrice() << endl;
			o << "Delivery Fee: $" << dp.deliveryFee << endl;
			o << "Total Price: $" << dp.getPizzaPrice() + dp.deliveryFee << endl;  //adds everything together
			o << "\n" << "Delivered to: " << dp.deliveryAddress << endl;
		}
		
			return o;	
		}
	
};
void selection(vector <Pizza> &p, vector <DeliveredPizza> &dp, vector <string> &top);

int main()
{
	
	vector <string> top = {"","Pepperoni", "Mushrooms", "Onions", "Green Pepper", "Tomatoes", "Jalapenos"};
	vector <Pizza> p;
    vector <DeliveredPizza> dp;
    
    selection(p,dp, top);
    
	for (int i = 0; i < p.size(); i++) 			//these for loops use the << operator within the classes
	{
        cout << p[i];
    }

    for (int i = 0; i < dp.size(); i++) 
	{
        cout << dp[i];
    }
	
	
	return 0;
}

void selection(vector <Pizza> &p, vector <DeliveredPizza> &dp, vector <string> &top)
{
	
	int userSize=0, userCrust=0, userToppings=0, userDelivery=0;
	string userType, userPizzaSize, userAddress;
	vector <string> topSelected;
	
	

	cout<<"What size pizza would you like to order?\n\t1 - Small\n\t2 - Medium\n\t3 - Large\n\t";
	cin>>userSize;
	
	cout<<"\nWhat type of crust would you like to order?\n\t1 - Classic\n\t2 - Deep Dish\n\t3 - Thin Crust\n\t";
	cin>> userCrust;
	
	cout<<"\nChoose from the following toppings or 0 to quit\n\t";
	cout<<"1: Pepperoni\n\t2: Mushrooms\n\t3: Onions\n\t4: Green Pepper\n\t";
	cout<<"5: Tomatoes\n\t6: Jalapenos\n\t";
	cin>>userToppings;
	
	while (cin.fail() || userToppings < 0) 
	{
	    cin.clear();
	    cin.ignore(86, '\n');
	    cin.clear();
	    cout << "\nERROR, enter from the list above!\n";
	    cin >> userToppings;
 	 }

	while(userToppings != 0 )
	{
		 for (int i = 1; i <= top.size(); i++) 
		 {
            if (userToppings == i) 
			{
                userToppings = i;
                topSelected.push_back(top.at(userToppings));	// increments the size number onto the new vector
             
            }

       	 }
       	 cout<<"\nChoose from the following toppings or 0 to quit\n\t";
	  	 cout<<"1: Pepperoni\n\t2: Mushrooms\n\t3: Onions\n\t4: Green Pepper\n\t";
		 cout<<"5: Tomatoes\n\t6: Jalapenos\n\t";
	 	 cin>>userToppings;
       	 
		while (cin.fail() || userToppings < 0) 
		{
	        cin.clear();
	        cin.ignore(86, '\n');
	        cin.clear();
	        cout << "\nERROR, enter from the list above!\n";
	        cin >> userToppings;
  	 	 }
	}
	
	switch(userSize)
	{
		case 1: 
			userPizzaSize = "Small";
			break;
		case 2: 
			userPizzaSize = "Medium";
			break;
		case 3: 
			userPizzaSize = "Large";
			break;
	}
	
	switch (userCrust) 
	{
    case 1:
        userType = "Classic";			//switches from int to a string for pizza type
        break;
    case 2:
        userType = "Deep Dish";
        break;
    case 3:
        userType = "Thin Crust";
        break;

    }
	cout<<"\nWould you like 1 - pick up or 2 - delivery? ";
	cin>>userDelivery;
	
	if(userDelivery == 1)			//decides which class to go to.
	{
	 Pizza pizza(userPizzaSize, userType, topSelected);
        p.push_back(pizza);
	}
	else if (userDelivery == 2)
	{
		cout<<"\nPlease enter your address: ";
        cin.ignore();
        getline(cin, userAddress);
        DeliveredPizza del(userPizzaSize, userType, topSelected, userAddress);
        dp.push_back(del);
	}	
}





