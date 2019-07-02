                             /*********** e-Confectionary *************/

#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
using namespace std;

/*GLOBAL DECLARATIONS*/
ifstream fin;
ofstream fout;
fstream f;
ifstream fin1;
void menu1();
int menu();
void admin();
void login();
void custmenu1();
void admin_fkart();
int custmenu();
void fkartdelete();
void fkartmodify();
void fkart();


char name[15][30]={"Black Forest","Red Velvet","Cookies'n Cream","Hazelnut Almond","Coffee and Cream",
		  				 "Bourbon","Hide and Seek","Good day","Milk Bikies","Jim Jam ",
		   			 "Pav Bhajji","Kachori","Pakoda","Cutlet","Samosa"};
long int cost[15]={200,250,150,210,120, 200,250,150,210,120,200,250,150,210,120};
		             
		      		
		      int test=1,test1=0,pos,rec=1;
		      float price;
				int qty[15];
				int op2;
		     
class addr
{
	char pin[6];
	char area[20],city[20],state[20];
	public:addr()
	{
		int test=0;                                                          //DEFAULT CONSTRUCTOR
	}
	void get_addr()
	{
		int temp;
		cout<<"\nEnter Address: ";
		cout<<"\nEnter area(characters a-z,A-Z only):";
		cin>>area;
		cout<<"\nEnter city(characters a-z,A-Z only):";
		cin>>city;
		cout<<"\nEnter state(characters a-z,A-Z only): ";
		cin>>state;
		cout<<"\nEnter pin code(numerical only): ";
		cin>>pin;
		
			if(sizeof(pin)!=6)
			{
				cout<<"\nPincode limit exceeded.Re-enter\n";
				cin>>pin;
				test=0;
				//break;
			}
		}

	void disp_addr()
	{
		cout<<"\nAddress: ";
		cout<<"\nArea: ";
		cout<<area;
		cout<<"\nCity: ";
		cout<<city;
		cout<<"\nState: ";
		cout<<state;
		cout<<"\nPIN code: ";
		cout<<pin;
	}

};

class cust
{
	addr a1;
	char name[40],phone[15];
	int pwd,pwd1;
	long int t_cost;
	int usn;
	public:
	void disptotal()
	{
		cout<<"\n\nGRAND TOTAL= Rs."<<t_cost;
	}
	void calctotal(int a)
	{		
		 t_cost+=cost[a]*qty[a];
	}
	void resettotal()
	{
		t_cost=0;
	}
	friend void login();                                               //FRIEND FUNCTION DECLARATION
	void create()
	{
		int test=0,temp;
		cout<<"\n***SIGN UP*** ";
		cout<<"\nEnter name: ";
		cin>>name;
		while(test==0)
		{
		for(temp=0;name[temp]!='\0';temp++)
		{
			if(!isalpha(name[temp]))
			{
				cout<<"\nInvalid character(s) entered.Re-enter\n";
				cin>>name;
				break;

			}
			else
				test=1;
		}
	}
		test=temp=0;
		cout<<"\nEnter phone no. :";
		cin>>phone;
		while(test==0)
		{
		for(temp=0;phone[temp]!='\0';temp++)
		{
			if(isdigit(phone[temp]))
			{
				test=1;
			}
			if(test==0)
			{
				cout<<"\nInvalid character(s) entered.Re-enter\n";
				cin>>phone;
				temp=0;
			}
		}
		for(temp=0;phone[temp]!='\0';temp++);

			if(temp!=9)
			{
				cout<<"\nEnter 10 numerical digits only.Re-enter\n";
				cin>>phone;
				break;
			}
			else
			test=1;

		}
		test=1;
		a1.get_addr();
		cout<<"\nChoose a user ID (numerical,0-6 digits): ";
		cin>>usn;
		while(test==1)
		{
			cout<<"\nCreate a password(numerical,0-6 digits): ";
			cin>>pwd;
			cout<<"\nRe-enter your password: ";
			cin>>pwd1;
			if(pwd==pwd1)
			{
				test=0;
			}
			else
			{
				cout<<"\nPasswords do not match";
				test=1;
			}
		}

		cout<<"\nUser successfully created!";
		cout<<"\nRedirecting to main menu ";
		
	}
	void logindetail()
	{
		cout<<"\nENTER USERNAME: ";
		cin>>usn;
		cout<<"\nENTER PASSWORD: ";
		cin>>pwd;
	}
	int returnusn()
	{
		return usn;
	}
	int returnpwd()
	{
		return pwd;
	}
	void showdetails()
	{
		cout<<"\nUSER ID "<<usn;
		cout<<"\nPASSWORD "<<pwd;
		cout<<"\nNAME:"<<name;;
	   cout<<"\nPHONE:"<<phone;;
		a1.disp_addr();
	}
	void getdetails()
	{
		cout<<"\nENTER NAME: ";
		cin>>name;
		cout<<"\nENTER PHONE NUMBER :";
		cin>>phone;
		a1.get_addr();
	}
}c1,c2;

int main()
{
	cust c1,c2;                                                    //OBJECT CREATION OF CLASS CUST
	int op;
	menu1();
}		      
		      
void menu1()
{
	system("clear");
	int op=menu();
	switch(op)
	{
		case 1:
		login();
		break;

		case 2:
		c1.create();
		fout.open("u.dat",ios::app);
		fout.write((char*)&c1,sizeof(c1));
		fout.close();
		menu1();
		break;

		case 3:admin();
		break;

		case 4:system("clear");
		cout<<"\n\n\tThank you for purchasing.Please visit again.";
		cout<<"\n\t\t More offers coming soon!!";
		exit(0);
		default:cout<<"\nWrong option entered. Exiting program\n";
	}
	
}

int menu()
{
	int op;
	cout<<"\n~Select an option:~ ";
	cout<<"\n1.Customer Login";
	cout<<"\n2.Create customer ID";
	cout<<"\n3.Admin login";
	cout<<"\n4.Exit\n";
	cin>>op;
	return op;
}		      
void admin()
{
	int i;
	char text[20];
	char str[20]={"welcome"};
	cout<<"\n\nEnter Admin password:\n";
	for(i=0;i<strlen(str);i++)
	cin>>text[i];
	if(strcmp(str,text)==0)
	{
		cout<<"\nAdmin access granted.\n";
		admin_fkart();
	}
	else
	{
		cout<<"\nAccess denied. Lock-down initiated\n";
		exit(0);
	}

}

void login()                                                              //FRIEND FUNCTION DEFINITION
{
	int check=0;
	c2.logindetail();
	fin.open("u.dat");
	fin.read((char*)&c1,sizeof(c1));
	while(fin)
	{
		
		cout<<"\nUser ID or password incorrect. Re-enter your details ";
	   menu1();
	   check=0;
	   break;
	}
	 if((c2.returnusn()==c1.returnusn())&&(c2.returnpwd()==c1.returnpwd()))
	{
	
		{
			cout<<"\nLogin successful..\n";
			
			custmenu();
		}
		fin.read((char*)&c1,sizeof(c1));
	   
	}
	else
	{
	   custmenu1();
	}
}

void custmenu1()
{
		system("clear");
		int i=0,op5,cvv;
		long double cardno;
		char temp[20],op3;
		switch(custmenu())
		{
			case 1:fkart();
			break;

			case 2:
			//view cart:
			if(test1==1)
			{
			system("clear");
			ifstream fin1("bill.txt");
			cout<<"\n -----------------------------------\n";
			cout<<"|\t\tITEM";
			cout<<"\t\t\tQTY";
			cout<<"\t\t\tCOST";
			cout<<"\t | ";
			cout<<"\n -----------------------------------\n";
			while(fin1.eof()==0)
			{
				fin1.getline(temp,20);
				if(i%3==0)
				cout<<"|";
				cout<<"\n\n\n"<<temp;   
				i++;
				if(i%3==0)
				{
					cout<<"|"<<"\n";
				}
			}
			
			cout<<"\n\t\t |";
			cout<<"\t |---------------------------------|\n";
			c1.disptotal();
			fin1.close();
			c1.resettotal();
			cout<<"\n\nProceed to checkout?(y/n)";
			cin>>op3;
			if((op3=='Y')||(op3=='y'))
			{
				printf("SELECT MODE OF PAYMENT: ");
				cout<<"\n";
				printf("1. Cash On Delivery");
				cout<<"\n";
				printf("2. Credit/Debit Card");
				cout<<"\n";
				cin>>op5;
				if(op5==1)
				{
					cout<<"\n\n";
					printf("THANK YOU FOR SHOPPING!!");
					system("clear");
					cout<<"\n\t";
					printf("Product(s) will be delivered in 3 business days.");
					exit(0);
				}
				if(op5==2)
				{
					cout<<"\n";
					printf("Enter credit/debit card details:");
					cout<<"\n";
					printf("Enter credit/debit card number(12 digits)");
					cout<<"\n";
					cin>>cardno;
					printf("Enter CVV number:");
					cout<<"\n";
					cin>>cvv;
					cout<<"\n";
					system("clear");
					cout<<"\n\n\n\n\n\n\t\t\t\t";
					printf("Verifying card details");
					for(int j=0;j<10;j++)
					{
						//delay(250);
						cout<<" .";
						//delay(250);
						cout<<" .";
						//delay(250);
						cout<<" .";
						//delay(250);
						system("clear");
						cout<<"\n\n\n\n\n\n\n\t\t\t";printf("Verifying card details");
					}
					system("clear");
					cout<<"\n\n\n\n\n\n\n\t\t\t";;printf("Payment Sucessful");
		    		system("clear");
					cout<<"\n\n\tBill number:";
					unsigned int seedval;
					time_t t;
					seedval=(unsigned)time(&t);
					srand(seedval);
					cout<<rand();
					cout<<"\n\n\t";
			      printf("THANK YOU FOR SHOPPING !\n");
					exit(0);
				}
			}
			else
				custmenu1();
			}
			else
			{
				cout<<"\nYou must buy an item first\n";
				custmenu1();
			}
			break;

			case 3:
			//edit cust details
			system("clear");
			cout<<"\n YOUR DETAILS:\n";
			c1.showdetails();
			c1.getdetails();
			f.open("u.dat",ios::in|ios::out);
			f.read((char*)&c2,sizeof(c2));
			while(f.eof()==0)
			{
				if(c2.returnusn()==c1.returnusn())
				{
					f.seekp(ios::beg);
					f.seekp((rec-1)*sizeof(c1));
					f.write((char*)&c1,sizeof(c1));
					break;
				}
				else
				{
					f.read((char*)&c2,sizeof(c2));
					rec++;
				}
			}
			f.close();
			custmenu1();
			break;

			case 4:fkartdelete();
			break;

			case 5:fkartmodify();
			break;

			case 6:system("clear");
			cout<<"\nAll unsaved changes will be lost.";
		   system("clear");
			cout<<"\n\n\n\t\tThank you for Purchasing. Please visit again.\n";
			cout<<"\n\t\t  More offers coming soon!!";
			exit(0);

			default:cout<<"\nWrong choice entered\n";
			   		system("clear");
						custmenu();
					
		}
		fin.close();
}
void admin_fkart()
{
	system("clear");
	int op2;
	ifstream fin1;
	ofstream foutdel;
	cout<<"\n\n\t\tADMIN MENU\n";
	cout<<"\t---------------------------\n\n";
	cout<<"\n\t1.VIEW CUSTOMER DETAILS";
	cout<<"\n\t2.DELETE CUSTOMER DETAILS";
	cout<<"\n\t3.VIEW CUSTOMER KART";
	cout<<"\n\t4.BACK TO MAIN MENU\n\t";
	cin>>op2;
	int temp=10;
	switch(op2)
	{
		case 2: temp=0;
		case 1:
		fin.open("u.dat");
		fin.seekg(0,ios::beg);
		fin.read((char*)&c1,sizeof(c1));
		while(fin)
		{
			system("clear");
			c1.showdetails();
			fin.read((char*)&c1,sizeof(c1));
			cout<<"\nPress any key continue...";
			getchar();
		}
		fin.close();
		if(temp==10)
		{
			break;
		}
		//delete
		if(temp==0)
		{cout<<"\nenter username to delete:\n";
		cin>>temp;
		ofstream foutdel("temp.dat");
		try                                                               //EXCEPTION HANDLING
		{
		
		fin.open("u.dat");
		fin.seekg(0,ios::beg);
		if(((fin.tellg())==0)||(!fin))
		throw 100;
		}
		catch(int i)
		{
			cout<<"File doesn't exist\n";
		}
		fin.read((char*)&c1,sizeof(c1));
		while(fin)
		{
			if(c1.returnusn()==temp);
			else
				foutdel.write((char*)&c1,sizeof(c1));
			fin.read((char*)&c1,sizeof(c1));

		}
		foutdel.close();
		fin.close();
		remove("u.dat");
		rename("temp.dat","u.dat");
		system("clear");
		cout<<"\nafter deletion:\n";
		//getch();
		fin.open("u.dat");
		fin.seekg(0,ios::beg);
		fin.read((char*)&c1,sizeof(c1));
		while(fin)
		{
			system("clear");
			c1.showdetails();
			fin.read((char*)&c1,sizeof(c1));
			cout<<"\nPress any key continue...";
			getchar();
		}
		fin.close();
		}

		break;

		case 3:
		system("clear");
		char temp[20];
		int i;
	   fin1.open("bill.txt");
		cout<<"\n ------------------------------------------------------------------------------------------------------\n";
		cout<<" | ";
		cout<<"\t\t\t"<<"ITEM";
		cout<<"\t\t\t"<<"QTY";
		cout<<"\t\t\t"<<"COST";
		cout<<"|";
		cout<<"\n -----------------------------------\n";
		while(fin1.eof()==0)
		{
			fin1.getline(temp,20);
			if(i%3==0)
				cout<<"|";
			cout<<"\t\t"<<temp; 
			i++;
			if(i%3==0)
			{
				cout<<"|"<<"\n";
			}
		}
		cout<<"\t\t"<<"  ";
		cout<<"   ";
		cout<<"\t\t"<<"|";
		cout<<"\n |---------------------------------|\n";
		fin1.close();
		c1.resettotal();
		break;

		case 4:menu1();
				break;

		default:cout<<"\n\nENTER CORRECT CHOICE.PROGRAM WILL CLOSE\n";
		exit(0);
	}
	if((op2!=4)&&(op2>=1)&&(op2<=4))
		admin_fkart();
}

int custmenu()
{
	int op2;
	cout<<"\n1. Buy\n\n2. View your Kart\n\n3. Edit details\n\n4.Delete item from Kart\n\n5.Change quantity of already bought item\n\n6.Log out and exit\n";
	cin>>op2;
	
	return op2;
}
void fkartdelete()
{
	int op1,op2,i,qty1;
	system("clear");
	cout<<"\n 1. CAKE\n 2. BISCUITS\n 3. SNACKS\n ";
	cin>>op1;
	switch(op1)
	{
		case 1:
		for(i=0;i<5;i++)
		{
			if(qty[i]!=0)
				cout<<"\n "<<i+1<<"\t\t\t"<<name[i]<<"\t\t\t"<<cost[i]<<"\t\t\t\n";
		}
		cin>>op2;
		if((op2>5)||(op2<1))
		{
			cout<<"\nEnter correct choice. Numbers 1-5.\n";
			cout<<"\nEnter again:";
			cin>>op2;
		}
		qty[op2-1]=0;
		break;

		case 2:
		for(i=0;i<5;i++)
		{
			if(qty[i+5]!=0)
				cout<<"\n "<<i+1<<"\t\t\t"<<name[i+5]<<"\t\t\t"<<cost[i]<<"\t\t\t\n";
		}
		cin>>op2;
		if((op2>5)||(op2<1))
		{
			cout<<"\nEnter correct choice. Numbers 1-5.\n";
			cout<<"\nEnter again:";
			cin>>op2;
		}
		qty[op2-1+5]=0;
		break;

		case 3:
		for(i=0;i<5;i++)
		{
			if(qty[i+10]!=0)
				cout<<"\n "<<i+1<<"\t\t\t"<<name[i+10]<<"\t\t\t"<<cost[i]<<"\t\t\t\n";
		}
		cin>>op2;
		if((op2>5)||(op2<1))
		{
			cout<<"\nEnter correct choice. Numbers 1-5.\n";
			cout<<"\nEnter again:";
			cin>>op2;
		}
		qty[op2-1+10]=0;
		break;

		default:
		cout<<"\nEnter correct choice.";

	}
	ofstream foutbill("bill.txt");
	for(int bill=0;bill<15;bill++)
	{
		if(qty[bill]!=0)
		{
			foutbill<<name[bill]<<"\n\t"<<qty[bill]<<"\t\t"<<cost[bill]<<"\t\t\n";
			c1.calctotal(bill);
		}
	}
	foutbill.close();
	custmenu1();
}
void fkartmodify()
{
	int op1,op2,i,qty1;
	system("clear");
	cout<<"\n 1. CAKE\n 2. BISCUITS\n 3. SNACKS\n ";
	cin>>op1;
	switch(op1)
	{
		case 1:
		for(i=0;i<5;i++)
		{
			if(qty[i]!=0)
				cout<<"\n "<<i+1<<"\t\t\t"<<name[i]<<"\t\t\t"<<cost[i]<<"\t\t\t\n";
		}
		cin>>op2;
		if((op2>5)||(op2<1))
		{
			cout<<"\nEnter correct choice. Numbers 1-5.\n";
			cout<<"\nEnter again:";
			cin>>op2;
		}
		cout<<"\nEnter new quantity:";
		cin>>qty1;
		qty[op2-1]=qty1;
		break;

		case 2:
		for(i=0;i<5;i++)
		{
			if(qty[i+5]!=0)
				cout<<"\n "<<i+1<<"\t\t\t"<<name[i+5]<<"\t\t\t"<<cost[i]<<"\t\t\t\n";
		}
		cin>>op2;
		if((op2>5)||(op2<1))
		{
			cout<<"\nEnter correct choice. Numbers 1-5.\n";
			cout<<"\nEnter again:";
			cin>>op2;
		}
		cout<<"\nEnter new quantity:";
		cin>>qty1;
		qty[op2-1+5]=qty1;
		break;

		case 3:
		for(i=0;i<5;i++)
		{
			if(qty[i+10]!=0)
				cout<<"\n "<<i+1<<"\t\t\t"<<name[i+10]<<"\t\t\t"<<cost[i]<<"\t\t\t\n";
		}
		cin>>op2;
		if((op2>5)||(op2<1))
		{
			cout<<"\nEnter correct choice. Numbers 1-5.\n";
			cout<<"\nEnter again:";
			cin>>op2;
		}
		cout<<"\nEnter new quantity:";
		cin>>qty1;
		qty[op2-1+10]=qty1;
		break;

		default:
		cout<<"\nEnter correct choice.";

	}
	ofstream foutbill("bill.txt");
	for(int bill=0;bill<15;bill++)
	{
		if(qty[bill]!=0)
		{
			foutbill<<name[bill]<<"\n\t"<<qty[bill]<<"\t\t"<<cost[bill]<<"\t\t\n";
			c1.calctotal(bill);
		}
	}
	foutbill.close();
	custmenu1();

}
void fkart()
{
	int op1,op2,i,qty1;
	system("clear");
	cout<<"\n 1. CAKE\n 2. BISCUITS\n 3. SNACKS\n ";
	cin>>op1;
	switch(op1)
	{
		case 1:
		for(i=0;i<5;i++)
		{
			cout<<"\n "<<i+1<<"\t\t\t"<<name[i]<<"\t\t\t"<<cost[i]<<"\t\t\t\n";
		}
		cin>>op2;
		if((op2>5)||(op2<1))
		{
			cout<<"\nEnter correct choice. Numbers 1-5.\n";
			cout<<"\nEnter again:";
			cin>>op2;
		}
		cout<<"\nEnter quantity:";
		cin>>qty1;
		qty[op2-1]=qty1;
		break;

		case 2:
		for(i=0;i<5;i++)
		{
			cout<<"\n "<<i+1<<"\t\t\t"<<name[i+5]<<"\t\t\t"<<cost[i]<<"\t\t\t\n";
		}
		cin>>op2;
		if((op2>5)||(op2<1))
		{
			cout<<"\nEnter correct choice. Numbers 1-5.\n";
			cout<<"\nEnter again:";
			cin>>op2;
		}
		cout<<"\nEnter quantity:";
		cin>>qty1;
		qty[op2-1+5]=qty1;
		break;

		case 3:
		for(i=0;i<5;i++)
		{
			cout<<"\n "<<i+1<<"\t\t\t"<<name[i+10]<<"\t\t\t"<<cost[i]<<"\t\t\t\n";
		}
		cin>>op2;
		if((op2>5)||(op2<1))
		{
			cout<<"\nEnter correct choice. Numbers 1-5.\n";
			cout<<"\nEnter again:";
			cin>>op2;
		}
		cout<<"\nEnter quantity:";
		cin>>qty1;
		qty[op2-1+10]=qty1;
		break;

		default:
		cout<<"\nEnter correct choice.";

	}
	ofstream foutbill("bill.txt");
	for(int bill=0;bill<15;bill++)
	{
		if(qty[bill]!=0)
		{
			//cost[bill]+=cost[bill];
			foutbill<<name[bill]<<"\n\t"<<qty[bill]<<"\t\t"<<cost[bill]<<"\t\t\n";
			c1.calctotal(bill);
		}
	}
	foutbill.close();
	test1=1;
	custmenu1();
}
