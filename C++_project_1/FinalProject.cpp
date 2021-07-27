/* Noe Sancen
	final Project*/

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
#include <bits/stdc++.h> 

using namespace std;



class Invoice
{
	private:
		string firstName;
		string lastName;
		string address;
		string partName;
		int id;
		
		string partSize;
		string typeName;
		float sizePrice;
		
		float calculateSizePrice()
		{
			float price=0;
			
		    if (partSize == "Car")
		    	price = 50.00;
		    else if (partSize == "SUV")
		        price = 75.00;
		    else if (partSize == "Van")
		        price = 100.00;
		    else if(partSize == "Jeep")
		    	price = 125.00;
		    else if(partSize == "Truck")
		    	price = 150.00;	
		    
		   
		
		    return price;
		}
		
	public:
	
	Invoice(string f, string l, int i, string add, string pn, string sizeName, string type)
	{
		firstName = f;
		lastName = l;
		partName = pn;
		id = i;
		address = add;
		partSize = sizeName;
		typeName = type;
		sizePrice = calculateSizePrice();
		
	}
	
	bool operator==(int cId)
		{
			if (id = cId)
			{
				return true;
			}
			else
				return false;
		}
	
	string getFirstName()
	{
		return firstName;
	}
	
	
	string getLastName()
	{
		return lastName;
	}	
	
	int getId()
	{
		return id;
	}
	
	string getAddress()
	{
		return address;
	}
	

	
	string getPartName()
	{
		return partName;
	}
	
	string getPartSize()
	{
		return partSize;
	}
	
	string getTypeName()
	{
		return typeName;
	}
	
	float getSizePrice()
	{
		return sizePrice;
	}
	
	friend ostream& operator <<(ostream& o, Invoice inv)
	{
		o << setprecision(2) << fixed;
		
		o <<"Name: "<< inv.firstName << " " << inv.lastName << " \nID number:  " << inv.id <<" \nAddress: "<< inv.address
		<<"\nPartName: "<< inv.partName<<"\nPrice: $"<<inv.sizePrice; 
		return o;
	}
	
	
};

class Part : public Invoice
{
	private:		
	
		float deliveryFee;
		
		 

		
		
	public:
		Part(string f, string l, int id, string add, string pn, string sizeName, string type, float dvry) : Invoice( f, l,  id,  add, pn, sizeName, type)
		{
			deliveryFee = dvry;
		}
		
		float getDeliveryFee()
		{
			return deliveryFee;
		}
		
		bool operator==(int cDeliver)
		{
			if (deliveryFee = cDeliver)
			{
				return true;
			}
			else
				return false;
		}

		friend ostream& operator <<(ostream& o, Part part)
		{
			o << setprecision(2) << fixed;
			
		
			o <<"\nName: "<< part.getFirstName() << " " << part.getLastName() << " \nID number:  " << part.getId() <<" \nAddress: "<< part.getAddress()
			<<"\nPartName: "<< part.getPartName()<<"\nDeliveryFee: $"<<part.deliveryFee
			<<"\nSizePrice: $"<<part.getSizePrice()<<endl; 
		
			return o;
		}
	
};




void addInvoice(vector <Invoice> &inv, vector <Part> &part);
void manageInvoice(vector <Invoice> &inv, vector <Part> &part);
void displayInvoice(vector <Invoice> &inv, vector <Part> &part);
int displayMenu();
void displayId(vector <Invoice> &inv, vector <Part> &part);




int main()
{
	
	vector <Invoice> invoice;
	vector <Part> part;
	
	int choice=0;
	

	
	choice = displayMenu();
	
	do
	{
		switch(choice)
		{
			case 1:
				addInvoice(invoice, part);
				break;
			case 2: 
				manageInvoice(invoice, part);
				break;
			case 3:
				displayId(invoice, part);
			case 4:
				displayInvoice(invoice, part);
				break;
					
				
		}
		if(choice == 5)
		{
			break;
		}
		else
		{
			choice = displayMenu();
		}
	} while(choice != 5);
	
	cout<<"\nThank you";

	
	
}


void addInvoice(vector <Invoice> &inv, vector <Part> &part)
{
	
	string firstName, lastName, address;
	int custId=0, partNum=0;
	char choice, answer;
	
	 string partSize;
	 int sizeChoice, userType;
	
	string partName, typeName;
	float deliveryFee=0, fee=0;

	
	cout<<"\nWhat is the customer's first name?: ";
	cin>>firstName;
	cout<<"Enter your last name: ";
	cin>>lastName;
	cout<<"Generate your ID number: ";
	cin>>custId;
	while (cin.fail() || custId < 0) 
	{
		cin.clear();
		cin.ignore(86, '\n');
		cin.clear();
		
		cout<<"Generate your ID number: ";
		cin>>custId;
		
		
	}
	
	cout<<"Address for invoice to be sent to: ";
	cin.ignore();
    getline(cin, address);
    cout<<"Enter which vehicle for parts."<<endl;
    cout << "1. Car\n2. SUV\n3. Van\n4. Jeep\n5. Truck"<<endl;
	cin >> sizeChoice;
	while (cin.fail() || sizeChoice > 5 || sizeChoice < 1) 
	{
		cin.clear();
		cin.ignore(86, '\n');
		cin.clear();
		
		 cout<<"Enter which vehicle for parts."<<endl;
   		 cout << "1. Car\n2. SUV\n3. Van\n4. Jeep\n5. Truck"<<endl;
		cin >> sizeChoice;
		
	}
	
	switch (sizeChoice) 
	{
		case 1:
			partSize = "Car";
			break;
		case 2:
			partSize = "SUV";
			break;
		case 3:
			partSize = "Van";
			break;
		case 4:
			partSize = "Jeep";
			break;
				
		case 5:
			partSize = "Truck";
			break;
	}
	cout<<"\nPlease Enter which parts you want from the vehicle: "<<endl;
	cout<<"1. Engine\n2. Body\n3. Interior"<<endl;
	cin>>userType;
	

		try 
		{
			if(userType < 1 || userType > 3)
				throw userType;
			
		}
		catch( int userType) {
			cout<<"\nPlease Enter which parts you want from the vehicle: "<<endl;
			cout<<"1. Engine\n2. Body\n3. Interior"<<endl;
			cin>>userType;
				while (cin.fail() || userType > 3 || userType < 1) 
				{
					cin.clear();
					cin.ignore(86, '\n');
					cin.clear();
					
					cout<<"\nPlease Enter which parts you want from the vehicle: "<<endl;
					cout<<"1. Engine\n2. Body\n3. Interior"<<endl;
					cin>>userType;
				}
		}

	
	switch(userType)
	{
		case 1:
			typeName = "Engine";
			break;
		case 2:
			typeName = "Body";
			break;
		case 3: 
			typeName = "Interior";
			break;	
	}
	
	cout<<"Would you like to ship your items home? (Y/N): ";
	cin>>choice;
	
	if (choice == 'y' || choice == 'Y')
	{
		deliveryFee = 25;
		Part p(firstName, lastName, custId, address, partName,partSize, typeName, deliveryFee);
		part.push_back(p);		
	}
	else
	{
		Invoice invoice(firstName, lastName, custId, address, partName, partSize, typeName);
		inv.push_back(invoice);
	}
}


void manageInvoice(vector <Invoice> &inv, vector <Part> &part)
{
	float shipOrder=25;
	
	cout<<"\nShipping Orders: ";
	

	
	for (int x = 0; x < part.size(); x++)
	{
		if (part[x] == shipOrder)
			cout<<part[x]<<endl;
	}	
	
	
}

void displayId(vector <Invoice> &inv, vector <Part> &part)
{
	int id = 0;
	
	cout<<"Find invoice by Customer ID, please enter your ID: ";
	cin>>id;
	cout<<endl;
	
	while (id <0 || cin.fail())
	{
		cin.clear();
		cin.ignore(86, '\n');
		cin.clear();
		cout<<"\nFind invoice by Customer ID, please enter your ID: ";
		cin>>id;
	}
	
	for (int x = 0; x < inv.size(); x++)
	{
		if (inv[x] == id)
			cout<<inv[x]<<endl;
	}	
}

void displayInvoice(vector <Invoice> &inv, vector <Part> &part)
{
	ofstream file;
	file.open("Invoice.txt");
	file << "\t\t\t\t\tInvoice: \n\n\n";
	
	
	
	for (int x = 0; x < inv.size(); x++)
	{
		cout << inv[x]<<endl;
		file << inv[x]<<endl;
	}
	
	for(int x = 0; x < part.size(); x++)
	{
		cout << part[x]<<endl;
		file << part[x]<<endl;
	}
	
}

int displayMenu()
{
	int choice=0;
	
	cout<<"\nPlease select from one of the options"<<endl;
	
		cout<<"1. Make a new order "<< endl;
		cout<<"2. Manage Invoices"<< endl;
		cout<<"3. View Id orders"<<endl;
		cout<<"4. display Invoices"<< endl;
		cout<<"5. Exit Program\n"<<endl;
	cin>>choice;
		
	while (cin.fail() || choice > 5 || choice < 1) 
	{
		cin.clear();
		cin.ignore(86, '\n');
		cin.clear();
		
		cout<<"\nPlease select from one of the options"<<endl;
	
		cout<<"1. Make a new order "<< endl;
		cout<<"2. View shipping orders"<< endl;
		cout<<"3. View Id orders"<<endl;
		cout<<"4. display Invoices"<< endl;
		cout<<"5. Exit Program\n"<<endl;
		cin>>choice;
	}
		
		
	return choice;
}


