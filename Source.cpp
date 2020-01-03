#include <iostream>
#include <string> 
#include <fstream>
#include <sstream>
using namespace std;
void menu();
char choice()
{
	char c;
	cout << "\n\nTO CONTINUE FURTHER? (Y/N) : ";
	cin >> c;
	if (c == 'Y' || c == 'y')
	{
		return 'Y';
	}
	else
	{
		return 'N';
	}
}
struct Cnode
{
	char fname[13];					 // first name  
	char lname[13];				     // last name 
	char  city[30];				     // permanent address  
	int price;					     // pricing
	int days;					    // price per day
	long long int CNIC;			   // CNIC  Customer
};

class CustomerNode
{
public:
	Cnode data;
	CustomerNode* next;				// pointer to indicate next node of list
};

class CustomerList
{
public:
	CustomerNode* head;						// creating pointer to head of node 
	CustomerList();							// constructor  
	~CustomerList();						// destructor
	CustomerNode* createnode();				// to create node
	CustomerNode* find(long long int a);	// finding specific node
	void show(CustomerNode* ptr);			// to show node
	void set(CustomerNode* ptr);			// to set at the end of the list
	void delete_node(long long int); 		// delete node according to CNIC number  
	bool check(long long int a);			// to check node if present by using cnic
	bool checkName(string f, string l);     // to check node if present by name
	void Input();							// inserting data at end of list  
	bool isEmpty();							// checking is list is empty 
	void traverse();  						// checking whole file and displaying data saved in each node  
	void search(long long int); 			// to search a record based on CNIC number
	void searchName(string f, string l);    // to search a record based on name
	void customermenu();
	void write();							// writing data to file
	void read();  							// reading data from file 
};
CustomerList::CustomerList()
{
	head = NULL;										//set value of head to NULL
	read();
}
CustomerList::~CustomerList()
{
	head = NULL;										//set value of head to NULL
}
CustomerNode* CustomerList::createnode()				//to create new node
{
	CustomerNode* temp = new CustomerNode;
	cout << endl;
	cout << "\t\t\t\t\t\t\t***********************************************************************************************" << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t* " << "ENTER FIRST NAME : "; cin >> temp->data.fname;
	cout << "\t\t\t\t\t\t\t\t\t\t\t* " << "ENTER LAST NAME : ";	cin >> temp->data.lname;
	cout << "\t\t\t\t\t\t\t\t\t\t\t* " << "ENTER CITY NAME : ";	cin >> temp->data.city;
	cout << "\t\t\t\t\t\t\t\t\t\t\t* " << "ENTER CNIC : "; cin >> temp->data.CNIC;
	cout << "\t\t\t\t\t\t\t\t\t\t\t* " << "ENTER NUMBER OF DAYS FOR THE PACKAGE: "; cin >> temp->data.days;
	cout << endl;
	cout << "\t\t\t\t\t\t\t***********************************************************************************************" << endl;
	temp->data.price = temp->data.days * 2000;
	temp->next = NULL;
	return temp;
}
CustomerNode* CustomerList::find(long long int a)
{
	CustomerNode* ptr = new CustomerNode;
	ptr = head;
	while (ptr != nullptr)
	{
		if (ptr->data.CNIC == a)
		{
			return ptr;
		}
		ptr = ptr->next;
	}
	return nullptr;
}
void CustomerList::show(CustomerNode* ptr)			// to show node
{
	cout << endl;
	cout << "\t\t\t\t\t\t\t***********************************************************************************************" << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t* " << "NAME : " << ptr->data.fname << " " << ptr->data.lname << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t* " << "CITY : " << ptr->data.city << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t* " << "CNIC : " << ptr->data.CNIC << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t* " << "PACKAGE DAYS : " << ptr->data.days << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t* " << "PRICE ACCORDING TO THE PACKAGE: " << ptr->data.price << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t***********************************************************************************************" << endl;
}
void CustomerList::set(CustomerNode* ptr)						//to set node at the end of list
{
	if (head == NULL)
	{
		head = ptr;
	}
	else
	{
		CustomerNode* ptr2 = new CustomerNode;
		ptr2 = head;
		while (ptr2->next != NULL)
		{
			ptr2 = ptr2->next;
		}
		ptr2->next = ptr;
	}
}
bool CustomerList::check(long long int c)
{
	CustomerNode* ptr = new CustomerNode;
	ptr = head;
	while (ptr != nullptr)
	{
		if (ptr->data.CNIC == c)
		{
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}
bool CustomerList::checkName(string f, string l)
{
	CustomerNode* ptr = new CustomerNode;
	ptr = head;
	while (ptr != nullptr)
	{
		if (ptr->data.fname == f && ptr->data.lname == l)
		{
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}
bool CustomerList::isEmpty()
{
	if (head == NULL)												//checking if head is set to NULL 
	{
		cout << "\nYOUR LIST IS EMPTY....";
		return true; 												//list is empty 
	}
	else
	{
		return false; 												//list not  empty
	}
}
void CustomerList::Input()
{
	cout << "\nENTER FOLLOWING DETAILS\n";
	CustomerNode* ptr = createnode();
	set(ptr);
}
void CustomerList::delete_node(long long int data)					// delete node according to given CNIC
{
	if (!check(data))												//if RECORD NOT FOUND   
	{
		cout << "\nDATA NOT FOUND" << endl;
	}
	else
	{
		if (head->data.CNIC == data)
		{
			head = head->next;
		}
		else
		{
			CustomerNode* ptr2 = head;
			CustomerNode* prev = NULL;
			while (ptr2 != NULL)
			{
				if (ptr2->data.CNIC == data)
				{
					prev->next = ptr2->next;
					cout << "\nDATA DELETED FROM LIST\n";
					break;
				}
				prev = ptr2;
				ptr2 = ptr2->next;
			}
		}
	}
}
void CustomerList::traverse()										//traverse list and display it 
{
	CustomerNode* ptr;
	ptr = head;
	cout << "\nSAVED DATA IS : ";
	while (ptr != NULL)
	{
		// displaying data of each node
		show(ptr);
		ptr = ptr->next;											// traversing to next node 
	}
}
void CustomerList::search(long long int search)						//searching node according to CNIC 
{
	if (!check(search))												//if RECORD NOT FOUND   
	{
		cout << "\nDATA NOT FOUND" << endl;
	}
	else
	{
		CustomerNode* ptr2 = head;
		while (ptr2 != NULL)
		{
			if (ptr2->data.CNIC == search)
			{
				show(ptr2);
			}
			ptr2 = ptr2->next;
		}
	}
}
void CustomerList::searchName(string f, string l)
{
	if (!checkName(f, l))												//if RECORD NOT FOUND   
	{
		cout << "\nDATA NOT FOUND" << endl;
	}
	else
	{
		CustomerNode* ptr2 = head;
		while (ptr2 != NULL)
		{
			if (ptr2->data.fname == f && ptr2->data.lname == l)
			{
				show(ptr2);
			}
			ptr2 = ptr2->next;
		}
	}
}
void CustomerList::write()										// write data to file
{
	ofstream fout;
	CustomerNode* ptr = new CustomerNode;
	ptr = head;
	fout.open("C-LIST.dat", ios::trunc | ios::binary | ios::out);//file busdata is being created and it is opened in append and binary mode.
	if (!fout)														  //if there is an error while opening the file the following text will be printed.   
	{
		cout << "\nTHERE WAS ERROR IN OPENING FILE " << endl;
	}
	while (ptr != NULL)
	{
		string a(ptr->data.fname);
		string b(ptr->data.lname);
		string c(ptr->data.city);
		long long int d = ptr->data.CNIC;
		int e = ptr->data.days;
		int f = ptr->data.price;
		stringstream wr(std::string().c_str()); // it is to write the string in the file by copying it
		wr << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f;
		fout << wr.str() << "\n";
		ptr = ptr->next;
	}
	fout.close();												//file closed.
}
void CustomerList::read()										//reading data from file
{
	ifstream fin;
	fin.open("C-LIST.dat", ios::binary | ios::in);
	if (!fin)
	{
		cout << "\nERROR IN OPENING FILE\n";
	}
	fin.seekg(0);
	string str;
	while (getline(fin, str))
	{
		if (fin.eof())
		{
			break;
		}
		CustomerNode* ptr = new CustomerNode;
		stringstream rd(str);
		string txt;
		rd >> txt;					strcpy_s(ptr->data.fname, txt.c_str());
		rd >> txt;					strcpy_s(ptr->data.lname, txt.c_str());
		rd >> txt;					strcpy_s(ptr->data.city, txt.c_str());
		rd >> ptr->data.CNIC;
		rd >> ptr->data.days;
		rd >> ptr->data.price;
		ptr->next = nullptr;
		set(ptr);
	}
	fin.close();
}
void CustomerList::customermenu()
{
	system("cls");
	char cont, check2;
	int y;
	long long int cnc;
	string fn, ln;
	cout << endl << endl << endl;
	cout << "\t\t\t\t\t\t\t***********************************************************************************************" << endl;
	cout << "\t\t\t\t\t\t\t|||||||||||||||||||||||||||||||||| CUSTOMER MANAGEMENT SYSTEM |||||||||||||||||||||||||||||||||\n";
	cout << "\t\t\t\t\t\t\t***********************************************************************************************" << endl;
	cout << endl << endl << endl << endl;
	cout << "\t\t\t\t\t\t\t===============================================================================================" << endl; 
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t      PLEASE CHOOSE AN OPTION: " << "                                       = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t      1. ADD RECORD" << "                                                   = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t      2. DELETE A RECORD" << "                                              = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t      3. DISPLAY THE RECORDS" << "                                          = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t      4. SEARCH A RECORD BY NAME" << "                                      = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t      5. SEARCH A RECORD BY CNIC" << "                                      = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t      6. BACK TO MAIN MENU" << "                                            = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t      7. EXIT" << "                                                         = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t      ENTER YOUR CHOICE : "; cin >> y;
	cout << "\t\t\t\t\t\t\t===============================================================================================" << endl;

	switch (y)
	{
	case 1:
		do
		{
			system("cls");
			Input();
			cont = choice();
			write();
		} while (cont == 'Y' || cont == 'y');
		customermenu();
	case 2:
		do
		{
			cout << "\nDELETE ANY DATA USING CNIC NUMBER (Y,y): ";
			cont = choice();
			if (cont == 'Y' || cont == 'y')
			{
				system("cls");
			}
			else
			{
				break;
			}
			cout << "\nENTER THE PARTICULAR CNIC : ";
			cin >> cnc;
			if (check(cnc))
			{
				cout << "\nRECORD FOUND.....";
				delete_node(cnc);
				write();
			}
			cont = choice();
		} while (cont == 'Y' || cont == 'y');
		customermenu();
	case 3:
		do
		{
			system("cls");
			cout << "DISPLAYING ALL THE RECORDS: \n" << endl;
			traverse();
			cont = choice();
		} while (cont == 'Y' || cont == 'y');
		customermenu();
	case 4:
		do
		{
			system("cls");
			cout << "\nSEARCH ANY DATA USING NAME (Y,y):";
			cin >> check2;
			if (check2 == 'Y' || check2 == 'y')
			{
				cout << "\nENTER THE FIRST NAME: ";
				cin >> fn;
				cout << "\nENTER THE SECOND NAME: ";
				cin >> ln;
				searchName(fn, ln);
				cont = choice();
			}
			else
			{
				break;
			}
		} while (cont == 'Y' || cont == 'y');
	case 5:
		do
		{
			system("cls");
			cout << "\nSEARCH ANY DATA USING CNIC NUMBER (Y,y):" << endl;
			cin >> check2;
			if (check2 == 'Y' || check2 == 'y')
			{
				cout << "\nENTER THE PARTICULAR CNIC : ";
				cin >> cnc;
				search(cnc);
				cont = choice();
			}
			else
			{
				break;
			}
		} while (cont == 'Y' || cont == 'y');
	case 6:
	{
		menu();
	}
	case 7:
	{
		exit(0);
	}
	default:
	{
		break;
	}
	}
}

struct Snode
{
	char fname[15];											// first name  
	char lname[15];											// last name  
	char city[15];											//permanent address  
	char designation[15]; 									// saving designation 
	long long int CNIC; 									//CNIC number 
	int emp_ID; 											// employee ID  
};
class StaffNode
{
public:
	Snode data;
	StaffNode* next; 										// pointer to the next node
};
class StaffList
{
public:
	StaffNode* head;										// creating pointer to head of node 
	StaffList();											// constructor  
	~StaffList();											// destructor
	StaffNode* Screatenode();								// to create node
	StaffNode* Sfind(long long int a);						// finding specific node
	void Sshow(StaffNode* ptr);								// to show node
	void Sset(StaffNode* ptr);								// to set at the end of the list
	void Sdelete_node(long long int);						// delete node according to CNIC number  
	bool ScheckName(string f, string l);                    // to search a node if present by using name
	bool Scheck(long long int a);							// to check node if present by using cnic
	bool ScheckID(int i);                                   // to check node if present by using ID
	void SInput();											// inserting data at end of list  
	bool SisEmpty();										// checking is list is empty 
	void Straverse();  										// checking whole file and displaying data saved in each node  
	void Ssearch(long long int); 							// to search a record based on CNIC  number
	void SsearchID(int _int);								// to search a record based on ID number
	void SsearchName(string f, string l);                        // to search a record based on name
	void Sstaffmenu();
	void Swrite();											// writing data to file
	void Sread();  											// reading data from file
};
StaffList::StaffList()
{
	head = NULL;													//set value of head to NULL
	Sread();
}
StaffList::~StaffList()
{
	head = NULL;													//set value of head to NULL
}
StaffNode* StaffList::Screatenode()
{
	StaffNode* ptr = new StaffNode;
	cout << endl;
	cout << "\t\t\t\t\t\t\t***********************************************************************************************" << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t* " << "ENTER FIRST NAME : ";		cin >> ptr->data.fname;
	cout << "\t\t\t\t\t\t\t\t\t\t\t* " << "ENTER LAST NAME : ";	    cin >> ptr->data.lname;
	cout << "\t\t\t\t\t\t\t\t\t\t\t* " << "ENTER CNIC : ";			    cin >> ptr->data.CNIC;
	cout << "\t\t\t\t\t\t\t\t\t\t\t* " << "ENTER CITY : ";		    cin >> ptr->data.city;
	cout << "\t\t\t\t\t\t\t\t\t\t\t* " << "ENTER DESIGNATION : ";			cin >> ptr->data.designation;
	cout << "\t\t\t\t\t\t\t\t\t\t\t* " << "ENTER ID : ";					cin >> ptr->data.emp_ID;
	cout << endl;
	cout << "\t\t\t\t\t\t\t***********************************************************************************************" << endl;
	ptr->next = NULL;
	return ptr;
}
StaffNode* StaffList::Sfind(long long int a)
{
	StaffNode* ptr = new StaffNode;
	ptr = head;
	while (ptr != nullptr)
	{
		if (ptr->data.CNIC == a)
		{
			return ptr;
		}
		ptr = ptr->next;
	}
	return nullptr;
}
void StaffList::Sshow(StaffNode* ptr)
{
	cout << endl;
	cout << "\t\t\t\t\t\t\t***********************************************************************************************" << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t  * " << " NAME : " << ptr->data.fname << " " << ptr->data.lname << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t  * " << " CNIC : " << ptr->data.CNIC << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t  * " << " CITY : " << ptr->data.city << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t  * " << " DESIGNATION : " << ptr->data.designation << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t  * " << " ID : " << ptr->data.emp_ID << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t***********************************************************************************************" << endl;
}
void StaffList::Sset(StaffNode* ptr)
{
	if (head == NULL)
	{
		head = ptr;
	}
	else
	{
		StaffNode* ptr2 = new StaffNode;
		ptr2 = head;
		while (ptr2->next != NULL)
		{
			ptr2 = ptr2->next;
		}
		ptr2->next = ptr;
	}
}
void StaffList::Sdelete_node(long long int a)
{
	if (!Scheck(a))												//if RECORD NOT FOUND   
	{
		cout << "\nDATA NOT FOUND" << endl;
	}
	else
	{
		if (head->data.CNIC == a)
		{
			head = head->next;
		}
		else
		{
			StaffNode* ptr2 = head;
			StaffNode* prev = NULL;
			while (ptr2 != NULL)
			{
				if (ptr2->data.CNIC == a)
				{
					prev->next = ptr2->next;
					cout << "\n\nDATA DELETED FROM LIST\n\n";
					break;
				}
				prev = ptr2;
				ptr2 = ptr2->next;
			}
		}
	}
}
bool StaffList::Scheck(long long int a)
{
	StaffNode* ptr = new StaffNode;
	ptr = head;
	while (ptr != nullptr)
	{
		if (ptr->data.CNIC == a)
		{
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}
bool StaffList::ScheckName(string f,string l)
{
	StaffNode* ptr = new StaffNode;
	ptr = head;
	while (ptr != nullptr)
	{
		if (ptr->data.fname == f && ptr->data.lname == l)
		{
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}
bool StaffList::ScheckID(int i)
{
	StaffNode* ptr = new StaffNode;
	ptr = head;
	while (ptr != nullptr)
	{
		if (ptr->data.emp_ID == i)
		{
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}
void StaffList::SInput()
{
	cout << "\nENTER FOLLOWING DETAILS\n";
	StaffNode* ptr = Screatenode();
	Sset(ptr);
}
bool StaffList::SisEmpty()
{
	if (head == NULL)												//checking if head is set to NULL 
	{
		cout << "\nYOUR LIST IS EMPTY....";
		return true; 												//list is empty 
	}
	else
	{
		return false; 												//list not  empty
	}
}
void StaffList::Straverse()
{
	StaffNode* ptr;
	ptr = head;
	cout << "\nSAVED DATA IS : ";
	while (ptr != NULL)
	{
		// displaying data of each node
		Sshow(ptr);
		ptr = ptr->next;										// traversing to next node 
	}
}
void StaffList::Ssearch(long long int a)
{
	if (!Scheck(a))												//if RECORD NOT FOUND   
	{
		cout << "\nDATA NOT FOUND" << endl;
	}
	else
	{
		StaffNode* ptr2 = head;
		while (ptr2 != NULL)
		{
			if (ptr2->data.CNIC == a)
			{
				Sshow(ptr2);
			}
			ptr2 = ptr2->next;
		}
	}
}
void StaffList::SsearchID(int _int)
{
	if (!ScheckID(_int))												//if RECORD NOT FOUND   
	{
		cout << "\nDATA NOT FOUND" << endl;
	}
	else
	{
		StaffNode* ptr2 = head;
		while (ptr2 != NULL)
		{
			if (ptr2->data.emp_ID == _int)
			{
				Sshow(ptr2);
			}
			ptr2 = ptr2->next;
		}
	}
}
void StaffList::SsearchName(string f, string l)
{
	if (!ScheckName(f,l))												//if RECORD NOT FOUND   
	{
		cout << "\nDATA NOT FOUND" << endl;
	}
	else
	{
		StaffNode* ptr2 = head;
		while (ptr2 != NULL)
		{
			if (ptr2->data.fname == f && ptr2->data.lname == l)
			{
				Sshow(ptr2);
			}
			ptr2 = ptr2->next;
		}
	}
}
void StaffList::Sstaffmenu()
{
	system("cls");
	int _id;
	int y;
	char cont, check2;
	long long int cnc;
	string fn, ln;
	cout << endl << endl << endl;
	cout << "\t\t\t\t\t\t\t***********************************************************************************************" << endl;
	cout << "\t\t\t\t\t\t\t|||||||||||||||||||||||||||||||||||| STAFF MANAGEMENT SYSTEM ||||||||||||||||||||||||||||||||||\n";
	cout << "\t\t\t\t\t\t\t***********************************************************************************************" << endl;
	cout << endl << endl << endl << endl;
	cout << "\t\t\t\t\t\t\t===============================================================================================" << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t PLEASE CHOOSE AN OPTION: " << "                                             = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t 1. ADD RECORD" << "                                                        = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t 2. DELETE A RECORD" << "                                                   = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t 3. DISPLAY THE RECORDS" << "                                               = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t 4. SEARCH A RECORD BY CNIC" << "                                           = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t 5. SEARCH A RECORD BY NAME" << "                                           = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t 6. SEARCH A RECORD BY ID" << "                                             = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t 7. BACK TO MAIN MENU" << "                                                 = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t 8. EXIT" << "                                                              = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t ENTER YOUR CHOICE : "; cin >> y;
	cout << "\t\t\t\t\t\t\t===============================================================================================" << endl;

	switch (y)
	{
	case 1:
		do
		{
			system("cls");
			SInput();
			cont = choice();
			Swrite();
		} while (cont == 'Y' || cont == 'y');
		Sstaffmenu();
	case 2:
		do
		{
			cout << "\nDELETE ANY DATA USING CNIC NUMBER (Y,y): ";
			cont = choice();
			if (cont == 'Y' || cont == 'y')
			{
				system("cls");
			}
			else
			{
				break;
			}
			cout << "\nENTER THE PARTICULAR CNIC: ";
			cin >> cnc;
			if (Scheck(cnc))
			{
				cout << "\nRECORD FOUND.....";
				Sdelete_node(cnc);
				Swrite();
			}
			cont = choice();
		} while (cont == 'Y' || cont == 'y');
		Sstaffmenu();
	case 3:
		do
		{
			system("cls");
			cout << "\nDISPLAYING ALL THE RECORDS: \n" << endl;
			Straverse();
			cont = choice();
		} while (cont == 'Y' || cont == 'y');
		Sstaffmenu();
	case 4:
		do
		{
			system("cls");
			cout << "\nSEARCH ANY DATA USING CNIC NUMBER (Y,y):";
			cin >> check2;
			if (check2 == 'Y' || check2 == 'y')
			{
				cout << "\nENTER THE PARTICULAR CNIC: ";
				cin >> cnc;
				Ssearch(cnc);
				cont = choice();
			}
			else
			{
				break;
			}
		} while (cont == 'Y' || cont == 'y');
	case 5:
		do
		{
			system("cls");
			cout << "\nSEARCH ANY DATA USING NAME (Y,y):";
			cin >> check2;
			if (check2 == 'Y' || check2 == 'y')
			{
				cout << "\nENTER THE FIRST NAME: ";
				cin >> fn;
				cout << "\nENTER THE SECOND NAME: ";
				cin >> ln;
				SsearchName(fn,ln);
				cont = choice();
			}
			else
			{
				break;
			}
		} while (cont == 'Y' || cont == 'y');
	case 6:
		do
		{
			system("cls");
			system("color 88");
			cout << "\nSEARCH ANY DATA USING ID NUMBER... (Y,y)";
			cout << endl;
			cin >> check2;
			if (check2 == 'Y' || check2 == 'y')
			{
				cout << "\nENTER THE PARTICULAR ID: ";
				cin >> _id;
				SsearchID(_id);
				cont = choice();
			}
			else
			{
				break;
			}
		} while (cont == 'Y' || cont == 'y');
		Sstaffmenu();
	case 7:
	{
		menu();
	}
	case 8:
	{
		exit(0);
	}
	default:
	{
		break;
	}
	}
}
void StaffList::Swrite()
{
	ofstream fout;
	StaffNode* ptr = new StaffNode;
	ptr = head;
	fout.open("S-LIST.dat", ios::trunc | ios::binary | ios::out);//file busdata is being created and it is opened in append and binary mode.
	if (!fout)													//if there is an error while opening the file the following text will be printed.   
	{
		cout << "\nTHERE WAS ERROR IN OPENING FILE " << endl;
	}
	while (ptr != NULL)
	{
		string a(ptr->data.fname);
		string b(ptr->data.lname);
		string c(ptr->data.city);
		string d(ptr->data.designation);
		long long int e = ptr->data.CNIC;
		int f = ptr->data.emp_ID;
		stringstream wr(std::string().c_str());
		wr << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f;
		fout << wr.str() << "\n";
		ptr = ptr->next;
	}
	fout.close();												//file closed.
}
void StaffList::Sread()
{
	ifstream fin;
	fin.open("S-LIST.dat", ios::binary | ios::in);
	if (!fin)
	{
		cout << "\nERROR IN OPENING FILE\n";
	}
	fin.seekg(0);
	string str;
	while (getline(fin, str))
	{
		if (fin.eof())
		{
			break;
		}
		StaffNode* ptr = new StaffNode;
		stringstream rd(str);
		string txt;
		rd >> txt;					strcpy_s(ptr->data.fname, txt.c_str());
		rd >> txt;					strcpy_s(ptr->data.lname, txt.c_str());
		rd >> txt;					strcpy_s(ptr->data.city, txt.c_str());
		rd >> txt;					strcpy_s(ptr->data.designation, txt.c_str());
		rd >> ptr->data.CNIC;
		rd >> ptr->data.emp_ID;
		ptr->next = nullptr;
		Sset(ptr);
	}
	fin.close();
}
int main()
{
	menu(); // calling menu function defined at end 
	system("PAUSE");
	return 0;
}
void menu() // definition of menu function
{
	long long int cnc;
	char cont, check;
	char x;
	system("cls");
	cout << endl << endl << endl;
	cout << "\t\t\t\t\t\t\t***********************************************************************************************" << endl;
	cout << "\t\t\t\t\t\t\t||||||||||||||||||||||||||| WELCOME TO GUEST HOUSE MANAGEMENT SYSTEM ||||||||||||||||||||||||||\n";
	cout << "\t\t\t\t\t\t\t***********************************************************************************************" << endl;
	cout << endl << endl << endl << endl;
	cout << "\t\t\t\t\t\t\t===============================================================================================" << endl;
	cout << "\t\t\t\t\t\t\t= "<< "\t\t\t ENTER YOUR CHOICE : " << "                                                 = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t A) PRESS (A,a) IF YOU ARE A CUSTOMER...." << "                             = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t B) PRESS (B,b) IF YOU ARE A STAFF MEMEBER...." << "                        = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t C) PRESS (C,c) TO TERMINATE THE PROGRAM" << "                              = " << endl;
	cout << "\t\t\t\t\t\t\t= " << "\t\t\t ENTER YOUR CHOICE: "; cin >> x;
	cout << "\t\t\t\t\t\t\t===============================================================================================" << endl;
	
	if (x == 'A' || x == 'a')
	{
		CustomerList Q;
		system("pause");
		Q.customermenu();
	}
	else if (x == 'b' || x == 'B')
	{
		StaffList W;
		system("pause");
		W.Sstaffmenu();
	}
	else  if (x == 'c' || x == 'C')
	{
		exit(0);
	}
	else
	{
		cout << "\nYOU ENTERED WRONG CHOICE !!!!\n";
	}
}