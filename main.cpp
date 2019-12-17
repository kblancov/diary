/**************************************************************************                                    
* Type         :  C++ program
* Program      :  Financial Computing MSc at QMUL, Promo 2019/2019  
* Project      :  Coursework, INTRO OBJECT-ORIENTED PROGRAMMING - 2019/20                                           
* License      :  Apache  Ver 2.0, www.apache.org/licenses/LICENSE-2.0           
* Description  :  Complete coursework solution with,
*                 - A Top class "Diary" that contains all the system
*                 - An  abstract class "Item" with the common elmenets
*                 - 3 Sub Classes "Event", "Reminder", "ToDo"
*                 - 2 indepente suport Classes "Date" and "Time"                         
*                                                                             
* Other files  :  none
* Last Review  :  17-Dic-2019                                                  
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

//Item abstract class
class Item
{
	//Private data fields
	protected:
	    int id;
		Date addedDate;
	    string itemDescription;

	//Public member functions
	public:

	//default constructor
	Item ()
	{
 	    this->id=0;
		this->itemDescription="";

		time_t rawtime;
  		struct tm * timeinfo;
  		time (&rawtime);
  		timeinfo = localtime (&rawtime);				
		int added_dd=timeinfo->tm_mday;
	    int added_mm=timeinfo->tm_mon+1;
	    int added_yyyy=timeinfo->tm_year+1900;
		this->addedDate.setDate(added_dd,added_mm,added_yyyy);
	}

	//Parametrized constructor
	Item (int code, string description)
	{
	    this->id=code;
      	this->itemDescription = description;
		
		time_t rawtime;
  		struct tm * timeinfo;
  		time (&rawtime);
  		timeinfo = localtime (&rawtime);				
		int added_dd=timeinfo->tm_mday;
	    int added_mm=timeinfo->tm_mon+1;
	    int added_yyyy=timeinfo->tm_year+1900;
		this->addedDate.setDate(added_dd,added_mm,added_yyyy);
	}

	//Sets Item data
	void setItem(int code, string description)
	{
      	this->id=code;
      	this->itemDescription = description;
	}

	//Sets Item data
	void setItem(int code, string description, int dd, int mm, int yyyy)
	{
      	this->id=code;
      	this->itemDescription = description;
		this->addedDate.setDate(dd, mm, yyyy);
	}

	//Sets Item id
	void setId(int code)
	{
      	this->id=code;
	}


	//Virtual function to print the data of the Item
	virtual void printItem()=0;

	//Destructor
	~Item ()
	{

	}
};

//ToDo class
class ToDo : public Item
{
	//Private data fields
	private:
	Date dueDate;
	string status;
	//Public member functions
	public:

	//default constructor
	ToDo () : Item ()
	{
		this->status="Incomplete";
		//this->status="Complete";
	}

	//Parametrized constructor
	ToDo (int code, string description, int dd, int mm, int yyyy) :
			Item (code,description)
	{
		//this->id=code;
		//this->itemDescription=description;
		this->dueDate.setDate(dd, mm, yyyy);
		this->status="Incomplete";
	}

	//Sets ToDo data
	void setToDo(int code, string description, int dd, int mm, int yyyy)
	{
      	this->id=code;
      	this->itemDescription = description;
	    this->dueDate.setDate(dd, mm, yyyy);

	}
	//check ToDo data
	void checkToDo(){
		this->status="Complete";
	}

	//check ToDo data
	void uncheckToDo(){
		this->status="Incomplete";
	}

	//Loads the ToDo Data from a given open ofstream
	void loadToDo(ifstream &myStream, int code)
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
			dueDate.setDate(day,month,year);
			myStream.ignore();
			getline(myStream,status);
		}
		  
	}

	//Prints ToDo Data to the terminal
	void printItem()
	{
	    cout << "- ToDo " << id << ", added on ";
		addedDate.printDate();
		cout << " | Status: " << status;
		cout << " | Due date: ";
		dueDate.printDate();
		cout << " | Description: " << itemDescription;
	    cout << " | "<<endl;
	}

	//Saves ToDo Data to a given file
	void saveToDo(string fileName)
	{
		int day;
        int month;
	    int year;

		ofstream myStream(fileName, ios::app);
		if (myStream.is_open()) {
			myStream << "ToDo" << endl;
			myStream << id << endl;
			addedDate.getDate(day, month, year);
			myStream << day << endl;
			myStream << month << endl;
			myStream << year << endl;
			myStream << itemDescription << endl;
			dueDate.getDate(day, month, year);
			myStream << day << endl;
			myStream << month << endl;
			myStream << year << endl;
			myStream << status << endl;
		}
		myStream.close();
	}

	//compares the object date data with the parameters
	//Returns 1 if it is the same, else 0. 
	int compareAddedDate(int dd, int mm, int yy)
	{
	    if(addedDate.compareDate(dd, mm, yy)==1)
			return 1;
		return 0;
	}

	//Destructor
	~ToDo ()
	{

	}
};



//Diary class
class Diary
{
	//Private data fields
    private:
	//Maximun number of ToDos
	int maxToDo;
    //Counter for the current number of ToDos
    int numToDo;
    //Pointer to a dynamic ToDu array
    ToDo* toDosArr;

	//Public member functions
    public:
    //constructor
    Diary (){
		this->maxToDo=100;
        this->numToDo=0;
		//Alocate the memory for maxTodo ToDos in the Heap
		this->toDosArr= new ToDo[this->maxToDo];
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

	//Print All ToDo in the Diary
	void printAllToDos (){
	    int i;
	    for (i=0;i<numToDo;i++){
	        toDosArr[i].printItem();
	    }
	} 

	//Member function for adding an ToDo
	void addToDo()
	{	
		clearConsole();
	    string description="";
	    int dd=0;
	    int mm=0;
	    int yyyy=0;
		cout<<"*****************************************************************"<<endl;
		cout<< "			Add ToDo Option"<<endl<<endl;
		cout<<"Please enter description of your new  diary ToDo"<<endl;
		readLine(description);
		cout<<"Please enter the due Day, number from 1 to 31"<<endl;
		cin>> dd;
		cout<<"Please enter the due Month, number from 1 to 12"<<endl;
		cin>> mm;
		cout<<"Please enter the due Year, number from 2000 to 2099"<<endl;
		cin>> yyyy;
		numToDo++;
		toDosArr[numToDo-1].setToDo(numToDo,description,dd,mm,yyyy);
		cout<<endl<<"The ToDo:"<<numToDo<<" was added to your Diary:"<<endl;
		toDosArr[numToDo-1].printItem();
		menuPause();
	}

	//Member function for removing an ToDo
	void removeToDo()
	{
	    int code;
		clearConsole();
		cout<<"*****************************************************************"<<endl;
		cout<< "			Remove ToDo Option"<<endl<<endl;
		if(numToDo<1){
			cout<<"There are no ToDos in the App"<<endl;
			menuPause();
		} else {
			cout<<"The current ToDo list is :"<<endl<<endl;
			printAllToDos();
			cout<<endl<<"Enter a ToDo number from 1 to "<<numToDo<<" to be removed"<<endl;
			cin>> code;
			if(code < 1 || code > numToDo){
			  cout<<endl<<"Option out of range"<<endl;
			  menuPause();
			}
			else {
			  int i;
			  for(i=code-1;i<numToDo-1;i++){
				//Use the default shallow asign function
				toDosArr[i]=toDosArr[i+1];
				//Use the ToDo.setId Method to update the Id
				toDosArr[i].setId(i+1);
			  }
			  numToDo--;
			  cout<<"The new list is:"<<endl<<endl;
			  printAllToDos();
			  menuPause();
			}
		}
	}

	//Member function for edting a ToDo
	void editToDo()
	{
	    int dd;
	    int mm;
	    int yyyy;
		string description;
		int code;
		clearConsole();
		cout<<"*****************************************************************"<<endl;
		cout<< "			Edit ToDo Option"<<endl<<endl;
		if(numToDo<1){
			cout<<"There are no ToDo in the App"<<endl;
			menuPause();
		} else {
			cout<<"Enter the item number to be edited from this list :"<<endl<<endl;
			printAllToDos();
			cout<<endl<<"Enter a number from 1 to "<<numToDo<<endl;
			cin>> code;
			if(code < 1 || code > numToDo){
			  cout<<endl<<"Option out of range"<<endl;
			  menuPause();
			}
			else {			
			  cout<<"Please enter the new description for your ToDo"<<endl;
			  readLine(description);
			  cout<<"Please enter the new due Day, number from 1 to 31"<<endl;
			  cin>> dd;
			  cout<<"Please enter the new due Month, number from 1 to 12"<<endl;
			  cin>> mm;
			  cout<<"Please enter the new due Year, number from 2000 to 2099"<<endl;
			  cin>> yyyy;
			  toDosArr[code-1].setToDo(code,description,dd,mm,yyyy);
			  toDosArr[code-1].uncheckToDo();
			  cout<<"The new list of ToDos is:"<<endl<<endl;
			  printAllToDos();
			  menuPause();
			}
		}
	}

	//Member function for completing a ToDo
	void completeToDo()
	{
		int code;
		clearConsole();
		cout<<"*****************************************************************"<<endl;
		cout<< "			Complete ToDo Option"<<endl<<endl;
		if(numToDo<1){
			cout<<"There are no ToDo in the App"<<endl;
			menuPause();
		} else {
			cout<<"Enter the ToDo number to be edited from this list :"<<endl<<endl;
			printAllToDos();
			cout<<endl<<"Enter a ToDo number from 1 to "<<numToDo<<endl;
			cin>> code;
			if(code < 1 || code > numToDo){
			  cout<<endl<<"Option out of range"<<endl;
			  menuPause();
			}
			else {			
			  toDosArr[code-1].checkToDo();
			  cout<<endl<<"The new list of ToDos is:"<<endl<<endl;
			  printAllToDos();
			  menuPause();
			}
		}
	}

	//Saves Diary Objects to the diary.txt file
	int saveDiary (){
		string fileName="diary.txt";
		
		//First Open diary.txt in new mode and save the word "Diary" to clean the file
		ofstream myStream(fileName);
		if (myStream.is_open()) {
			myStream << "Diary" << endl;
		}
		myStream.close();
		
		//Then, loop over ToDosArr and append each ToDo data to the file diary.txt
		for (int i=0;i<numToDo;i++){
			toDosArr[i].saveToDo(fileName);
		}
		cout<<endl<<"Diary saved in "<<fileName <<endl;
		return 1;

	}

	//Loads Diary Objects from the diary.txt file
	int loadDiary (){
		string fileName="diary.txt";
		string line;
		ifstream myStream(fileName);
		if (myStream.is_open()) {
			while(getline(myStream,line)){
				//if the line is a ToDo
				if((line.compare("ToDo")) == 0){
						toDosArr[numToDo].loadToDo(myStream,numToDo+1);
						numToDo++;	
				}
			}
			myStream.close();
		}
		return 1;
	} 

	//Reads a Date from the console and print coincidences

	int searchByAddedDate (){
	 	int dd;
	    int mm;
	    int yyyy;
		int results=0;
		clearConsole();
		cout<<"*****************************************************************"<<endl;
		cout<< "			Search by Added Date Option"<<endl<<endl;
		if(numToDo<1){
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

			  for (int i=0; i<numToDo; i++){
					if(toDosArr[i].compareAddedDate(dd,mm,yyyy)==1){
						toDosArr[i].printItem();
						results++;
					}
			  }
			  cout<<endl<<results<<" records found for the entered date"<<endl;
			  menuPause();
		}
	}
 
	//Menu ToDo of the Diary Class
    void ToDoMenu(){        
        
        int option=9;
        while (option!=0){
        	clearConsole();
			
            cout<<"*****************************************************************"<<endl;
            cout<< "			The Diary App Ver 3.0"<<endl;
			cout<<"*****************************************************************"<<endl;
            cout<< "			       Menu ToDos"<<endl<<endl;
            cout<< "Select one of the next options by entering the option number:"<<endl<<endl;
            cout<< "1. Add ToDo"<<endl;
            cout<< "2. Remove ToDo"<<endl;
            cout<< "3. Edit ToDo"<<endl;
            cout<< "4. Complete ToDo"<<endl;
			cout<< "5. Print all ToDos"<<endl;
            cout<< "0. Back to Main Menu"<<endl;
            cout<<"*****************************************************************"<<endl;
            cout<<"Please enter the option:"<<endl;
            cin>> option;
            if (option==1){
                addToDo();
            } else if (option==2){
                removeToDo();
            } else if (option==3){
                editToDo();
			} else if (option==4){
                completeToDo();
            } else if (option==5){
				clearConsole();
				cout<<"*****************************************************************"<<endl;
				cout<< "			All ToDos"<<endl<<endl;
                printAllToDos ();
				cout<<endl<<"Going back to previous menu."<<endl;
				menuPause();                
            } else if (option==0){
                cout<<endl<<"Going Back to Main Menu "<<endl;
            } else {
                cout<<"Invalid Option"<<endl;
            }
            
        }
        

    }

	//Main menu of the Diary Class
    void mainMenu(){        
        
        int option=9;
        loadDiary ();
        while (option!=0){
        	clearConsole();
			
            cout<<"*****************************************************************"<<endl;
            cout<< "			The Diary App Ver 3.0"<<endl;
			cout<<"*****************************************************************"<<endl;
            cout<< "			       Main Menu"<<endl<<endl;
            cout<< "Select one of the next options by entering the option number:"<<endl<<endl;
            cout<< "1. Manage ToDos"<<endl;
            cout<< "2. "<<endl;
            cout<< "3. "<<endl;
            cout<< "4. Print all Items"<<endl;
			cout<< "5. Search by Added Date"<<endl;
            cout<< "0. To exit the program"<<endl;
            cout<<"*****************************************************************"<<endl;
            cout<<"Please enter the option:"<<endl;
            cin>> option;
            if (option==1){
                ToDoMenu();
            } else if (option==2){
                
            } else if (option==3){
                
            } else if (option==4){
				clearConsole();
				cout<<"*****************************************************************"<<endl;
				cout<< "			All Diary Items"<<endl<<endl;
                cout<<endl<<"ToDos:"<<endl<<endl;
				printAllToDos ();
				cout<<endl<<"Going back to previous menu."<<endl;
				menuPause();                
			} else if (option==7){
                searchByAddedDate ();
            } else if (option==0){
			 	saveDiary ();
                cout<<endl<<"Thank you for using The Diary App, have a nice day. "<<endl<<endl;
            } else {
                cout<<"Invalid Option"<<endl;
            }
            
        }
        

    }

	//Destructor
    ~Diary (){
		//Free the memory for ToDos Array from the Heap
		delete[] this->toDosArr;
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