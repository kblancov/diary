#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

//Date class
class Date
{
	//Private data fields
	private:
	      int month;
	      int day;
	      int year;
	
	//Publich member functions
	public:
	
	//Default constructor
	Date()
	{
	      month = 1;
	      day = 1;
	      year = 2000;
	}

	//Parametrized constructor
	Date(int dd, int mm, int yy)
	{
	    if(dd >= 1 && dd <= 31){
			day = dd;
		}
	    else{
			day = 1;
			cout<<endl<< "Warning: the entered day is not valid"<<endl;
			cout<< "Day value set to: "<<day<<endl;
		  }
        if(mm >= 1 && mm <= 12){
		    month = mm;
		}
	    else{
			month = 1;
			cout<<endl<< "Warning: the entered month is not valid"<<endl;
			cout<< "Month value set to: "<<month<<endl;
		}
	    if(yy >= 2000 && yy <= 2099){
		    year = yy;
		}
		else{
			year = 2000;
			cout<<endl<< "Warning: the entered year is not valid"<<endl;
			cout<< "Year value set to: "<<year<<endl;
		}
	}

	//sets a valid date
	void setDate(int dd, int mm, int yy)
	{
	    if(dd >= 1 && dd <= 31){
			day = dd;
		}
	    else{
			day = 1;
			cout<<endl<< "Warning: the entered day is not valid"<<endl;
			cout<< "Day value set to: "<<day<<endl;
		  }
        if(mm >= 1 && mm <= 12){
		    month = mm;
		}
	    else{
			month = 1;
			cout<<endl<< "Warning: the entered month is not valid"<<endl;
			cout<< "Month value set to: "<<month<<endl;
		}
	    if(yy >= 2000 && yy <= 2099){
		    year = yy;
		}
		else{
			year = 2000;
			cout<<endl<< "Warning: the entered year is not valid"<<endl;
			cout<< "Year value set to: "<<year<<endl;
		}
	}

	//returns the month, day and year
	void getDate(int& dd, int& mm, int& yy)
	{
	    dd = day;
        mm = month;
	    yy =year;
	}

	//displays the month, day and year to the screen
	void printDate()
	{
	    if(day < 10)
		    cout << "0";
	    cout << day << "-";
        if(month < 10)
		    cout << "0";
	    cout << month << "-";
	    cout << year;
	}
	//Destructor
	~Date()
	{
	}
};

//Item class
class Item
{
	//Private data fields
	private:
	    int id;
	    string itemDescription;
	    Date itemDate;

	//Public member functions
	public:

	//default constructor
	Item ()
	{
 	    id=0;
		itemDescription="";
	}

	//Parametrized constructor
	Item (int code, string description, int dd, int mm, int yyyy)
	{
	    id=code;
      	itemDescription = description;
		itemDate.setDate(dd, mm, yyyy);
	}

	//Sets Item data
	void setItem(int code, string description, int dd, int mm, int yyyy)
	{
      	id=code;
      	itemDescription = description;
	    itemDate.setDate(dd, mm, yyyy);
	}

	//Sets Item id
	void setId(int code)
	{
      	id=code;
	}

	//Get Item id
	void getId(int& code)
	{
      	code=id;
	}

	//Prints Item Data
	void printItem()
	{
	    cout << "- Item " << id << ": | ";
		itemDate.printDate();
	    cout << " | " << itemDescription << " | " <<endl;
	}

	//Destructor
	~Item ()
	{

	}
};

//Diary class
class Diary
{
	//Private data fields
    private:
    //Counter for the current number of Items
    int numItems;
    //Array of items
    Item itemsArr[100];
    
	//Public member functions
    public:
    //constructor
    Diary (){
        numItems=0;
    }

	// Clear the whole console, provided by Dr. Mustafa Bozkurt
	void clearConsole() {
    	cout << "\x1B[2J\x1B[H";
	}
	
	// Pause execution waiting for a key, provided by Dr. Mustafa Bozkurt
	void menuPause() {
		cout << endl << "Press enter to continue..." << endl;
    	cin.ignore();
    	cin.get();
	}

	// Read a line from the console including spaces
	string readLine(string& description) {
    	cin.ignore();
		getline(cin,description);
	}

	//Print All Items in the Diary
	void printAllItems (){
	    int i;
	    for (i=0;i<numItems;i++){
	        itemsArr[i].printItem();
	    }
	} 

	//Member function for adding an Item
	void addItem()
	{
	    string description;
	    int dd;
	    int mm;
	    int yyyy;
		clearConsole();
		cout<<"*****************************************************************"<<endl;
		cout<< "			Add Item Option"<<endl<<endl;
		cout<<"Please enter description of your new event"<<endl;
		readLine(description);
		cout<<"Please enter Day, number from 1 to 31"<<endl;
		cin>> dd;
		cout<<"Please enter Month, number from 1 to 12"<<endl;
		cin>> mm;
		cout<<"Please enter Year, number from 2000 to 2099"<<endl;
		cin>> yyyy;
		numItems++;
		itemsArr[numItems-1].setItem(numItems,description,dd,mm,yyyy);
		cout<<endl<<"The item:"<<numItems<<" was added to your Diary:"<<endl;
		itemsArr[numItems-1].printItem();
		menuPause();
	}

	//Member function for removing an Item
	void removeItem()
	{
	    int code;
		clearConsole();
		cout<<"*****************************************************************"<<endl;
		cout<< "			Remove Item Option"<<endl<<endl;
		if(numItems<1){
			cout<<"There are no items in the App"<<endl;
			menuPause();
		} else {
			cout<<"Enter the item number to be removed from this list :"<<endl<<endl;
			printAllItems();
			cout<<endl<<"Enter a number from 1 to "<<numItems<<endl;
			cin>> code;
			if(code < 1 || code > numItems){
			  cout<<endl<<"Option out of range"<<endl;
			  menuPause();
			}
			else {
			  int i;
			  for(i=code-1;i<numItems-1;i++){
				//I dont know why i can do this, ask Moustafa
				itemsArr[i]=itemsArr[i+1];
				//Use the Item.set Method to udate the Id
				itemsArr[i].setId(i+1);
			  }
			  numItems--;
			  cout<<"The new list is:"<<endl<<endl;
			  printAllItems();
			  menuPause();
			}
		}
	}

	//Member function for edting an Item
	void editItem()
	{
	    int dd;
	    int mm;
	    int yyyy;
		string description;
		int code;
		clearConsole();
		cout<<"*****************************************************************"<<endl;
		cout<< "			Edit Item Option"<<endl<<endl;
		if(numItems<1){
			cout<<"There are no items in the App"<<endl;
			menuPause();
		} else {
			cout<<"Enter the item number to be edited from this list :"<<endl<<endl;
			printAllItems();
			cout<<endl<<"Enter a number from 1 to "<<numItems<<endl;
			cin>> code;
			if(code < 1 || code > numItems){
			  cout<<endl<<"Option out of range"<<endl;
			  menuPause();
			}
			else {			
			  cout<<"Please enter the new description for your event"<<endl;
			  readLine(description);
			  cout<<"Please enter the new Day, number from 1 to 31"<<endl;
			  cin>> dd;
			  cout<<"Please enter the new Month, number from 1 to 12"<<endl;
			  cin>> mm;
			  cout<<"Please enter the newYear, number from 2000 to 2099"<<endl;
			  cin>> yyyy;
			  itemsArr[code-1].setItem(code,description,dd,mm,yyyy);
			  cout<<"The new list is:"<<endl<<endl;
			  printAllItems();
			  menuPause();
			}
		}
	}
    
    void mainMenu(){        
        
        int option=9;
        char temp='a';
        string userInput="";
        
        while (option!=0){
        	clearConsole();
            cout<<"*****************************************************************"<<endl;
            cout<< "			Diary Main Menu"<<endl<<endl;
            cout<< "Select one of the next options by entering the option number:"<<endl<<endl;
            cout<< "1. Add Item"<<endl;
            cout<< "2. Remove Item"<<endl;
            cout<< "3. Edit Item"<<endl;
            cout<< "4. Save to File"<<endl;
            cout<< "5. Open from File"<<endl;
            cout<< "6. Print all Items"<<endl;
            cout<< "0. To exit the program"<<endl;
            cout<<"*****************************************************************"<<endl;
            cout<<"Please enter the option:"<<endl;
            cin>> option;
            if (option==1){
                addItem();
            } else if (option==2){
                removeItem();
            } else if (option==3){
                editItem();
            } else if (option==4){
                cout<<"Option 4. Menu: "<<endl;
            } else if (option==5){
                cout<<"Option 5. Menu: "<<endl;
            } else if (option==6){
				clearConsole();
				cout<<"*****************************************************************"<<endl;
				cout<< "			Print all Items"<<endl<<endl;
                printAllItems ();
				cout<<endl<<"Going back to previous menu."<<endl;
				menuPause();
            } else if (option==0){
                cout<<endl<<"Thank you for using The Diary App, have a nice day. "<<endl<<endl;
            } else {
                cout<<"Invalid Option"<<endl;
            }
            
        }
        

    }
};

int main()

{
      
      //Declare a Diary object
      Diary diary;
      //Call the main Diary menu
      diary.mainMenu();

      return 0;
}