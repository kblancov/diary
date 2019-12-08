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
	      if(dd >= 1 && dd <= 31)
		    day = dd;
	      else
		    day = 1;
        if(mm >= 1 && mm <= 12)
		    month = mm;
	      else
		    month = 1;
	      if(yy >= 2000 && yy <= 2099)
		    year = yy;
	      else
		    year = 2000;
	}

	//sets a valid date
	void setDate(int dd, int mm, int yy)
	{
	      if(dd >= 1 && dd <= 31)
		    day = dd;
	      else
		    day = 1;
        if(mm >= 1 && mm <= 12)
		    month = mm;
	      else
		    month = 1;
	      if(yy >= 2000 && yy <= 2099)
		    year = yy;
	      else
		    year = 2000;
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
 	      itemDescription="";
 	      id=0;
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
    Item itemsArr[10];
    
	//Public member functions
    public:
    //constructor
    Diary (){
        numItems=0;
    }

	//Print All Items in the Diary
	void printAllItems (){
	    int i;
		clearConsole();
		cout<<"*****************************************************************"<<endl;
		cout<< "			Print all Items"<<endl<<endl;
	    for (i=0;i<numItems;i++){
	        itemsArr[i].printItem();
	    }
		cout<<endl<<"Going back to previous menu."<<endl;
		menuPause();
	} 

	// Clear the whole console, provided by Dr. Mustafa Bozkurt
	void clearConsole() {
    	cout << "\x1B[2J\x1B[H";
	}
	
	// Pause execution waiting for a key, provided by Dr. Mustafa Bozkurt
	void menuPause() {
		cout << endl << "Press any key to continue..." << endl;
    	cin.ignore();
    	cin.get();
	}

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
			cin>> description;
			cout<<"Please enter Day"<<endl;
			cin>> dd;
			cout<<"Please enter Month"<<endl;
			cin>> mm;
			cout<<"Please enter Year"<<endl;
			cin>> yyyy;
			numItems++;
			itemsArr[numItems-1].setItem(numItems,description,dd,mm,yyyy);
			cout<<endl<<"The item:"<<numItems<<" was added to your Diary:"<<endl;
			itemsArr[numItems-1].printItem();
			cout<<endl<<"Going back to previous menu."<<endl;
			menuPause();
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
                cout<<"Option 2. Menu: "<<endl;
            } else if (option==3){
                cout<<"Option 3. Menu: "<<endl;
            } else if (option==4){
                cout<<"Option 4. Menu: "<<endl;
            } else if (option==5){
                cout<<"Option 5. Menu: "<<endl;
            } else if (option==6){
                printAllItems ();
            } else if (option==0){
                cout<<"Thank you for using The Diary App, have a nice day. "<<endl;
            } else {
                cout<<"Invalid Option"<<endl;
            }
            
        }
        

    }
};

int main()

{
      
      //Declare a GlobalDiary object
      Diary diary;
      //Call the main Diary menu
      diary.mainMenu();

      return 0;
}