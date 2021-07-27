/* Noe Sancen
	Exam 2 */

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




class AccountHolder
{
	private:
		string name;
		string address;
		string city;
		string state;
		string zipCode;
		long int socialNum;
		int creditScore;
		
	public:
		AccountHolder(string n, string add, string cit, string sat, string zip, long int sn=0)
		{
			name = n;
			address = add;
			city = cit;
			state = sat;
			zipCode = zip;
			socialNum = sn;
			creditScore = getCreditScore();
		}
		
	int getCreditScore()
	{
		srand(time(NULL));
		int randNum = rand()%(850 - 300) + 300;
		
	
		
		return randNum;	
	}
		
	string getAccountName()
	{
		return name;
	}
	
	string getAccountAddress()
	{
		return address;
	}
	
	string getAccountCity()
	{
		return address;
	}
	
	string getAccountState()
	{
		return state;
	}
	
	string getAccountZipCode()
	{
		return zipCode;
	}
	
	long int getAccountSocialNum()
	{
		return socialNum;
	}
	
	friend ostream& operator <<(ostream& o, AccountHolder ac)
	{
		o <<"Name: "<< ac.name <<" \nAddress:  " << ac.address << endl;
		return o;
	}
		
};

class Transaction
{
	private:
		string transDate;
		string transDescription;
		string transAmount;
		
	public:
		Transaction()
		{
				
		}
		
		void operator+=(double amount)
		{
			this->transAmount += amount;
		}
	
		string getAmount()
		{
			return transAmount;
		}
		
		string getTransDate()
		{
			return transDate;
		}
		
		string getTransDescription()
		{
			return transDescription;
		}
		
		string getTransAmount()
		{
			return transAmount;
		}
	     
		friend ostream& operator <<(ostream& o, Transaction &t)
		{
			o <<"\nDate: "<< t.transDate <<" Description:  " << t.transDescription <<" Amount: "<<t.transAmount << endl;
			return o;
		}
		
		friend istream &operator>>( istream  &in, Transaction &t ) 
		{ 
	         in >>t.transAmount >> t.transDescription >> t.transDate;
	         return in;            
	     }
	

	
};

class CreditCard : public AccountHolder
{	
	
	private:
		long int accountNumber;
	//	AccountHolder ac;
		double creditLimit;
		double balance;
		double intPercent;
		vector <Transaction> trans;
		static int newAccountNumber;
		
		int creditCardScore;
		
		
	public:
		CreditCard(string n, string add, string cit, string sat, string zip, long int sn=0) : AccountHolder(n, add, cit, sat, zip, sn)
		{
			newAccountNumber = 100200;
			creditCardScore = getCreditScore();
			if(creditCardScore < 580)
			{
				cout<<"\nDenied Credit"<<endl;
				//set account Number to 0;
				accountNumber = 0;
			}
			else
			{
				cout<<"\nApproved!"<<endl;
				accountNumber = newAccountNumber;
				newAccountNumber++;
			}
		}
		
		int getCreCardScore()
		{
			return creditCardScore;
		}
		
		double determineLimitInterest()
		{
			//creditLimit & intPercent
			if((creditCardScore >= 800) && (creditCardScore <= 850))
			{
				creditLimit = 20000;
				intPercent = .085;
			}
			else if((creditCardScore >= 740) && (creditCardScore <= 799))
			{
				creditLimit = 15000;
				intPercent = .155;
			}
			else if((creditCardScore >= 670) && (creditCardScore <= 739))
			{
				creditLimit = 10000;
				intPercent = .225;
			}
			else if((creditCardScore >= 580) && (creditCardScore <= 669))
			{
				creditLimit = 5000;
				intPercent = .295;
			}	
			return creditLimit, intPercent;
		}	
		
	friend ostream& operator <<(ostream& o, CreditCard cc)
	{
	/*	if(cc.creditLimit != 0)
		{
			o <<"Name: "<< cc.getAccountName() <<"\nAddress:  " << cc.getAccountAddress() <<"\nCity: "
			<< cc.getAccountCity()<<"\nState: "<< cc.getAccountState() <<"\nZipCode: "<< cc.getAccountZipCode()<<"\nCreditLimit: "<<cc.creditLimit <<"\nPercentage: "
			<< cc.intPercent << endl;
		}
		else
		{*/
			o <<"Name: "<< cc.getAccountName() <<"\nAddress:  " << cc.getAccountAddress() <<"\nCity: "
			<< cc.getAccountCity()<<" \nState: "<< cc.getAccountState() <<" \nZipCode: "<< cc.getAccountZipCode() << endl;
	//	}
		
		return o;
	}
			
};
int CreditCard::newAccountNumber=0;

int displayMenu();
void createAccount(vector <CreditCard> &cc);
void displayBalance(vector <Transaction> &tra);
void printStatement(vector <CreditCard> &cc, vector <AccountHolder> &ac, vector <Transaction> &tra);
void inputTransaction(vector <Transaction> &tra);


int main()
{
	vector <CreditCard> cc;
	vector <AccountHolder> ac;
	vector <Transaction> tra;
	

	
	int choice = displayMenu();
	
	do
	{
		switch(choice)
		{	
			case 0:
				break;
			case 1:
				createAccount(cc);
				break;
			case 2: 
				displayBalance(tra);
				break;
			case 3:
				inputTransaction(tra);
				break;
				case 4:
				printStatement(cc, ac, tra);
				break;
		}
		if(choice == 0)
		{
			break;
		}
		else
		{
			choice = displayMenu();
		}
	} while(choice != 0);
	
	cout<<"\nThank you";
	
	
	
	return 0;
}

void createAccount(vector <CreditCard> &cc)
{
	string name, address, city, state, zipCode;
	
	
	cout<<"\nEnter Name: ";
	cin.ignore();
    getline(cin, name);
    cout<<"Enter Address: ";
   	cin.ignore();
    getline(cin, address);
    cout<<"Enter City: ";
    cin>>city;
    cout<<"Enter State: ";
    cin>>state;
    cout<<"Enter ZipCode: ";
    cin>>zipCode;
	
	CreditCard credit(name, address, city, state, zipCode);
	cc.push_back(credit);	
	
}

void printStatement(vector <CreditCard> &cc, vector <AccountHolder> &ac, vector <Transaction> &tra)
{
		
	for (int i = 0; i < cc.size(); i++) 
	{
        cout << cc[i];
    }
    
   /* for (int i = 0; i < ac.size(); i++) // didnt finish but was going to other classes "ostream"
   											//ran out of time to implement
	{
        cout << ac[i];
    }*/
    
   /* for (int i = 0; i < tra.size(); i++) 
	{
        cout << tra[i];
    }*/
						
}

void displayBalance(vector <Transaction> &tra)
{
	string num;
	
	cout<<"Enter the account number for credit on a existing account.";
	cin>>num;
	
	
	
}

void inputTransaction(vector <Transaction> &tra)
{
	string tranAmount;
	Transaction t;
	
	
	cout<<"\nEnter Account Number: ";
	cin>>t;//tranAmount
	//cout<<
	
	
	
	
}


int displayMenu()
{
	int choice=0;
	
	cout<<"Choose from one of the following options."<<endl;
	cout<<"\n1. Create an account and applay for a credit card."<<endl;
	cout<<"2. See the balance and avaliable credit for an existing account."<<endl;
	cout<<"3. Input a transaction"<<endl;
	cout<<"4. Print all monthly statements"<<endl;
	cout<<"0. Exit Program"<<endl;
	cin>>choice;
	
	while (cin.fail() || choice > 5 || choice < 0) 
	{
		cout<<"Choose from one of the following options."<<endl;
		cout<<"\n1. Create an account and applay for a credit card."<<endl;
		cout<<"2. See the balance and avaliable credit for an existing account."<<endl;
		cout<<"3. Input a transaction"<<endl;
		cout<<"4. Print all monthly statements"<<endl;
		cout<<"0. Exit Program"<<endl;
		cin>>choice;
		cout<<endl;
	}
		
	return choice;
}





