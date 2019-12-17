/**************************************************************************                                    
* Type         :  C++ program
* Program      :  Financial Computing MSc at QMUL, Promo 2019/2019  
* Project      :  Coursework, INTRO OBJECT-ORIENTED PROGRAMMING - 2019/20                                           
* License      :  Apache  Ver 2.0, www.apache.org/licenses/LICENSE-2.0           
* Description  :  Basic solution for the Diary Coursework with files
*                                                                             
*                                                                             
* Other files  :  none
* Last Review  :  11-Dic-2019                                                  
* Author       :  Camilo BLANCO                                                 
* Mail         :  camilo.blanco@arcelec.com                                               
**************************************************************************/

#include<iostream>
#include<string>
#include <fstream>
#include <time.h>       
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
	void getDate(int &dd, int &mm, int &yy)
	{
	    dd = day;
        mm = month;
	    yy =year;
	}

	//compares the object date data with the parameters
	//Returns 1 if it is the same, else 0. 
	int compareDate(int dd, int mm, int yy)
	{
	    if( dd == day && mm == month && yy ==year)
			return 1;
		return 0;
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
		Date addedDate;
	    string itemDescription;
	    Date itemDate;

	//Public member functions
	public:

	//default constructor
	Item ()
	{
 	    id=0;
		itemDescription="";

		time_t rawtime;
  		struct tm * timeinfo;
  		time (&rawtime);
  		timeinfo = localtime (&rawtime);				
		int added_dd=timeinfo->tm_mday;
	    int added_mm=timeinfo->tm_mon+1;
	    int added_yyyy=timeinfo->tm_year+1900;
		addedDate.setDate(added_dd,added_mm,added_yyyy);
	}

	//Parametrized constructor
	Item (int code, string description, int dd, int mm, int yyyy)
	{
	    id=code;
      	itemDescription = description;
		itemDate.setDate(dd, mm, yyyy);
		
		time_t rawtime;
  		struct tm * timeinfo;
  		time (&rawtime);
  		timeinfo = localtime (&rawtime);				
		int added_dd=timeinfo->tm_mday;
	    int added_mm=timeinfo->tm_mon+1;
	    int added_yyyy=timeinfo->tm_year+1900;
		addedDate.setDate(added_dd,added_mm,added_yyyy);
	}

	//Sets Item data
	void setItem(int code, string description, int dd, int mm, int yyyy)
	{
      	id=code;
      	itemDescription = description;
	    itemDate.setDate(dd, mm, yyyy);
	}

	//Loads the Item Data from a given open ofstream
	void loadItem(ifstream &myStream, int code)
	{
      	int day;
        int month;
	    int year;

		if (myStream.is_open()) {
			myStream >> id;//skip this line
			id=code;//the id is set bt a parameter
			myStream >> day;
			myStream >> month;
			myStream >> year;
			addedDate.setDate(day,month,year);
			myStream.ignore();
			getline(myStream,itemDescription);
			myStream >> day;
			myStream >> month;
			myStream >> year;
			itemDate.setDate(day,month,year);
			
		}
		  
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

	//Prints Item Data to the terminal
	void printItem()
	{
	    cout << "- Item " << id << ", added on ";
		addedDate.printDate();
		cout << " | Date: ";
		itemDate.printDate();
		cout << " | Description: " << itemDescription;
	    cout << " | "<<endl;
	}

	//Saves Item Data to a given file
	void saveItem(string fileName)
	{
		int day;
        int month;
	    int year;

		ofstream myStream(fileName, ios::app);
		if (myStream.is_open()) {
			myStream << "item" << endl;
			myStream << id << endl;
			addedDate.getDate(day, month, year);
			myStream << day << endl;
			myStream << month << endl;
			myStream << year << endl;
			myStream << itemDescription << endl;
			itemDate.getDate(day, month, year);
			myStream << day << endl;
			myStream << month << endl;
			myStream << year << endl;
		}
		myStream.close();
	}

	//compares the object date data with the parameters
	//Returns 1 if it is the same, else 0. 
	int compareItemDate(int dd, int mm, int yy)
	{
	    if(itemDate.compareDate(dd, mm, yy)==1)
			return 1;
		return 0;
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
		cout<<"Please enter description of your new  diary item"<<endl;
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
			cout<<"The current item list is :"<<endl<<endl;
			printAllItems();
			cout<<endl<<"Enter a Item number from 1 to "<<numItems<<" to be removed"<<endl;
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
			  cout<<"Please enter the new description for your diary item"<<endl;
			  readLine(description);
			  cout<<"Please enter the new Day, number from 1 to 31"<<endl;
			  cin>> dd;
			  cout<<"Please enter the new Month, number from 1 to 12"<<endl;
			  cin>> mm;
			  cout<<"Please enter the new Year, number from 2000 to 2099"<<endl;
			  cin>> yyyy;
			  itemsArr[code-1].setItem(code,description,dd,mm,yyyy);
			  cout<<"The new list is:"<<endl<<endl;
			  printAllItems();
			  menuPause();
			}
		}
	}

	//Saves Diary Objects to the diary.txt file
	int saveDiary (){
		string fileName="diary.txt";
		int option = 0;
		clearConsole();
		cout<<"*****************************************************************"<<endl;
		cout<< "			Save Diary Option"<<endl<<endl;
		cout<<"The file "<<fileName <<" will be overwritten with this Diary data"<<endl;
		cout<<"Are you sure? "<<endl<<endl;
		cout<<"Enter 1 to confirm, or 0 to return to the main menu."<<endl;
		cin>>option;
		
		if (option == 1){
			ofstream myStream(fileName);
			if (myStream.is_open()) {
				myStream << "Diary" << endl;
			}
			myStream.close();
			int i;
			for (i=0;i<numItems;i++){
				//here here
				itemsArr[i].saveItem(fileName);
			}
			cout<<endl<<"Diary saved in "<<fileName <<endl;
			menuPause();
			return 1;
		}
		return 0;
	}

	//Loads Diary Objects from the diary.txt file
	int loadDiary (){
		string fileName="diary.txt";
		int option = 0;
		clearConsole();
		cout<<"*****************************************************************"<<endl;
		cout<< "			Load Diary Option"<<endl<<endl;
		cout<<"The file "<<fileName <<" will be loadded on this Diary"<<endl;
		cout<<"Are you sure? "<<endl<<endl;
		cout<<"Enter 1 to confirm, or 0 to return to the main menu."<<endl;
		cin>>option;
		
		if (option == 1){
			string line;
			ifstream myStream(fileName);
			if (myStream.is_open()) {

				while(getline(myStream,line)){
					if((line.compare("item")) == 0){
						itemsArr[numItems].loadItem(myStream,numItems+1);
						numItems++;
					} 	
				}
			}
			myStream.close();
			cout<<endl<<"Diary loadded from "<<fileName <<endl;
			menuPause();
			return 1;
		}
		return 0;
	} 

	//Reads a Date from the console and print coincidences

	int searchByDate (){
	 	int dd;
	    int mm;
	    int yyyy;
		int results=0;
		clearConsole();
		cout<<"*****************************************************************"<<endl;
		cout<< "			Search by Date Option"<<endl<<endl;
		if(numItems<1){
			cout<<"There are no items in the App"<<endl;
			menuPause();
		} else {
			  cout<<"Please enter the Day, number from 1 to 31"<<endl;
			  cin>> dd;
			  cout<<"Please enter the Month, number from 1 to 12"<<endl;
			  cin>> mm;
			  cout<<"Please enter the Year, number from 2000 to 2099"<<endl;
			  cin>> yyyy;
			  cout<<endl<<"*****************************************************************"<<endl;
			  cout<<"Search Results:"<<endl<<endl;

			  for (int i=0; i<numItems; i++){
					if(itemsArr[i].compareItemDate(dd,mm,yyyy)==1){
						itemsArr[i].printItem();
						results++;
					}
			  }
			  cout<<endl<<results<<" records found for the entered date"<<endl;
			  menuPause();
		}
	}
 
	//Main menu of the Diary Class
    void mainMenu(){        
        
        int option=9;
        
        while (option!=0){
        	clearConsole();
			
            cout<<"*****************************************************************"<<endl;
            cout<< "			The Diary App Ver 1.0"<<endl;
			cout<<"*****************************************************************"<<endl;
            cout<< "			       Main Menu"<<endl<<endl;
            cout<< "Select one of the next options by entering the option number:"<<endl<<endl;
            cout<< "1. Add Item"<<endl;
            cout<< "2. Remove Item"<<endl;
            cout<< "3. Edit Item"<<endl;
            cout<< "4. Print all Items"<<endl;
			cout<< "5. Load Diary from file"<<endl;
			cout<< "6. Save Diary to file"<<endl;
			cout<< "7. Search by Date"<<endl;
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
				clearConsole();
				cout<<"*****************************************************************"<<endl;
				cout<< "			All Diary Items"<<endl<<endl;
                printAllItems ();
				cout<<endl<<"Going back to previous menu."<<endl;
				menuPause();
			} else if (option==5){
                loadDiary ();
            } else if (option==6){
                saveDiary ();
			} else if (option==7){
                searchByDate ();
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