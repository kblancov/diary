/**************************************************************************                                    
* Type         :  C++ program
* Program      :  Financial Computing MSc at QMUL, Promo 2019/2019  
* Project      :  Coursework, INTRO OBJECT-ORIENTED PROGRAMMING - 2019/20                                           
* License      :  Apache  Ver 2.0, www.apache.org/licenses/LICENSE-2.0           
* Description  :  Complete coursework solution with,
*                 - A Main class "Diary" that contains all the system
*                 - An  abstract class "Item" with the common elmenets
*                 - 3 Sub Classes "Event", "Reminder", "ToDo"
*                 - 2 independent Classes "Date" and "Time"                         
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

/**************************************************************************                                    
* Class        	:  	Date
* Type			:  	Stand Alone
* Scope			: 	Date data type and Management, format, dd-mm-yyyy
* Variables   	:   3
* Functions		:   7                                                                                     
**************************************************************************/
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

/**************************************************************************                                    
* Class        	:  	Time
* Type			:  	Stand Alone
* Scope			: 	Time data type and Management, 24 hours format, hh:mm
* Variables   	:   2
* Functions		:   6                                                                                     
**************************************************************************/
class Time
{
	//Private data fields
	private:
	    int hour;
	    int minute;

	//Publich member functions
	public:
	
	//Default constructor
	Time()
	{
	    hour = 0;
	    minute = 0;
	}

	//Parametrized constructor
	Time(int hh, int mm)
	{
	    if(hh >= 0 && hh <= 23){
			hour = hh;
		}
	    else{
			hour = 0;
			cout<<endl<< "Warning: the entered hour is not valid"<<endl;
			cout<< "Hour value set to: "<<hour<<endl;
		  }
        if(mm >= 0 && mm <= 59){
		    minute = mm;
		}
	    else{
			minute = 0;
			cout<<endl<< "Warning: the entered minute is not valid"<<endl;
			cout<< "Minute value set to: "<<minute<<endl;
		}

	}

	//sets a valid time
	void setTime(int hh, int mm)
	{
	    if(hh >= 0 && hh <= 23){
			hour = hh;
		}
	    else{
			hour = 0;
			cout<<endl<< "Warning: the entered hour is not valid"<<endl;
			cout<< "Hour value set to: "<<hour<<endl;
		  }
        if(mm >= 0 && mm <= 59){
		    minute = mm;
		}
	    else{
			minute = 0;
			cout<<endl<< "Warning: the entered minute is not valid"<<endl;
			cout<< "Minute value set to: "<<minute<<endl;
		}
	}

	//returns the hour and the minute
	void getTime(int &hh, int &mm)
	{
	    hh = hour;
        mm = minute;
	}

	//displays the hour and minute to the screen
	void printTime()
	{
	    if(hour < 10)
		    cout << "0";
	    cout << hour << ":";
        if(minute < 10)
		    cout << "0";
	    cout << minute;
	}
	//Destructor
	~Time()
	{
	}
};

/**************************************************************************                                    
* Class        	:  	Time
* Type			:  	Abstract class, Parent of ToDo, Reminder and Event
* Scope			: 	Common type for Diary Items
* Variables   	:   3
* Functions		:   7 + 1 Pure virtual                                                                                    
**************************************************************************/
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

	//compares the object date data with the parameters
	//Returns 1 if it is the same, else 0. 
	int compareAddedDate(int dd, int mm, int yy)
	{
	    if(addedDate.compareDate(dd, mm, yy)==1)
			return 1;
		return 0;
	}

	//Destructor
	~Item ()
	{

	}
};

/**************************************************************************                                    
* Class        	:  	ToDo
* Type			:  	Child class, Decent from Item
* Scope			: 	ToDo type for Diary Items
* Variables   	:   Parent + 2
* Functions		:   Inherited + 9                                                                                    
**************************************************************************/
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

	//uncheck ToDo data
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
	    cout << "- TD " << id << ", added ";
		addedDate.printDate();
		cout << " | Status: " << status;
		cout << " | Due : ";
		dueDate.printDate();
		cout << " | Desc. " << itemDescription;
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

	//Destructor
	~ToDo ()
	{

	}
};

/**************************************************************************                                    
* Class        	:  	Reminder
* Type			:  	Child class, Decent from Item
* Scope			: 	Reminder type for Diary Items
* Variables   	:   Parent + 3
* Functions		:   Inherited + 7                                                                                    
**************************************************************************/
class Reminder : public Item
{
	//Private data fields
	private:
	//String to store the Type of Reminder
	string remType;
	Date targetDate;
	Time targetTime;
	

	//Public member functions
	public:

	//default constructor
	Reminder () : Item ()
	{
		this->remType="";
	}

	//Parametrized constructor
	Reminder (int code, string description, int dd, int mm, int yyyy, int type, int hour, int minu) :
			Item (code,description)
	{
		this->targetDate.setDate(dd, mm, yyyy);
		this->targetTime.setTime(hour,minu);
		//set the reminder type acording to the options 
		if (type==1)
			this->remType="Deadline";
		else if (type==2)
			this->remType="Birthday";
		else if (type==3)
			this->remType="Aniversary";
		else if (type==4)
			this->remType="Travel";
		else if (type==5)
			this->remType="Public Holiday";
		else
			this->remType="";
	}

	//Sets Reminder data
	void setReminder(int code, string description, int dd, int mm, int yyyy, int type, int hour, int minu)
	{
      	this->id=code;
      	this->itemDescription = description;
	    this->targetDate.setDate(dd, mm, yyyy);
		this->targetTime.setTime(hour,minu);
		//set the reminder type acording to the options 
		if (type==1)
			this->remType="Deadline";
		else if (type==2)
			this->remType="Birthday";
		else if (type==3)
			this->remType="Aniversary";
		else if (type==4)
			this->remType="Travel";
		else if (type==5)
			this->remType="Public Holiday";
		else
			this->remType="";
	}

	//Loads the Reminder Data from a given open ofstream
	void loadReminder(ifstream &myStream, int code)
	{
      	int day;
        int month;
	    int year;
		int hour;
		int minu;

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
			targetDate.setDate(day,month,year);
			myStream.ignore();
			getline(myStream,remType);
			myStream >> hour;
			myStream >> minu;
			targetTime.setTime(hour,minu);
		}
		  
	}

	//Prints Reminder Data to the terminal
	void printItem()
	{
	    cout << "- Rem " << id << ", added ";
		addedDate.printDate();
		cout << " | Target: ";
		targetDate.printDate();
		cout << " at ";
		targetTime.printTime();
		cout << " | Type: " << remType;
		cout << " | Desc. " << itemDescription;
	    cout << " | "<<endl;
	}

	//Saves Reminder Data to a given file
	void saveReminder(string fileName)
	{
		int day;
        int month;
	    int year;
		int hour;
		int minu;

		ofstream myStream(fileName, ios::app);
		if (myStream.is_open()) {
			myStream << "Reminder" << endl;
			myStream << id << endl;
			addedDate.getDate(day, month, year);
			myStream << day << endl;
			myStream << month << endl;
			myStream << year << endl;
			myStream << itemDescription << endl;
			targetDate.getDate(day, month, year);
			myStream << day << endl;
			myStream << month << endl;
			myStream << year << endl;
			myStream << remType << endl;
			targetTime.getTime(hour,minu);
			myStream << hour << endl;
			myStream << minu << endl;
		}
		myStream.close();
	}

	//Destructor
	~Reminder ()
	{

	}
};

/**************************************************************************                                    
* Class        	:  	Event
* Type			:  	Child class, Decent from Item
* Scope			: 	Event type for Diary Items
* Variables   	:   Parent + ...
* Functions		:   Inherited + ...                                                                                    
**************************************************************************/
class Event : public Item
{
	//Private data fields
	private:
	//String to store the Type of Event
	string eventType;
	string location;
	string attendees;
	Date startDate;
	Date endDate;
	Time startTime;
	Time endTime;
	

	//Public member functions
	public:

	//default constructor
	Event () : Item ()
	{
		this->eventType="";
		this->location="";
		this->attendees="";
	}

	//Parametrized constructor
	Event (int code, string description, int type, string loc, string att, int start_dd, int start_mm, int start_yyyy, int start_hour, int start_minu, int end_dd, int end_mm, int end_yyyy, int end_hour, int end_minu) :
			Item (code,description)
	{
		
		//set the Event type acording to the options 
		if (type==1)
			this->eventType="Meeting";
		else if (type==2)
			this->eventType="Conference";
		else if (type==3)
			this->eventType="Seminar";
		else if (type==4)
			this->eventType="Talk";
		else if (type==5)
			this->eventType="Team-building event";
		else
			this->eventType="";

		this->location=loc;
		this->attendees=att;

		this->startDate.setDate(start_dd, start_mm, start_yyyy);
		this->startTime.setTime(start_hour,start_minu);
		this->endDate.setDate(end_dd, end_mm, end_yyyy);
		this->endTime.setTime(end_hour,end_minu);
	}

	//Sets Event data
	void setEvent(int code, string description, int type, string loc, string att, int start_dd, int start_mm, int start_yyyy, int start_hour, int start_minu, int end_dd, int end_mm, int end_yyyy, int end_hour, int end_minu)
	{
		//set the Event type acording to the options
		this->id=code;
      	this->itemDescription = description; 
		if (type==1)
			this->eventType="Meeting";
		else if (type==2)
			this->eventType="Conference";
		else if (type==3)
			this->eventType="Seminar";
		else if (type==4)
			this->eventType="Talk";
		else if (type==5)
			this->eventType="Team-building event";
		else
			this->eventType="";

		this->location=loc;
		this->attendees=att;

		this->startDate.setDate(start_dd, start_mm, start_yyyy);
		this->startTime.setTime(start_hour,start_minu);
		this->endDate.setDate(end_dd, end_mm, end_yyyy);
		this->endTime.setTime(end_hour,end_minu);

	}

	//Loads the Event Data from a given open ofstream
	void loadEvent(ifstream &myStream, int code)
	{

      	int day;
        int month;
	    int year;
		int hour;
		int minu;

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
			startDate.setDate(day,month,year);
			myStream >> hour;
			myStream >> minu;
			startTime.setTime(hour,minu);

			myStream >> day;
			myStream >> month;
			myStream >> year;
			endDate.setDate(day,month,year);
			myStream >> hour;
			myStream >> minu;
			endTime.setTime(hour,minu);

			myStream.ignore();
			getline(myStream,eventType);

			//myStream.ignore();
			getline(myStream,location);

			//myStream.ignore();
			getline(myStream,attendees);
		}
	}

	//Prints Event Data to the terminal
	void printItem()
	{
	    cout << "- Event " << id << ", added on ";
		addedDate.printDate();
		cout << " | Starts ";
		startDate.printDate();
		cout << " at ";
		startTime.printTime();
		cout << " | Ends ";
		endDate.printDate();
		cout << " at ";
		endTime.printTime();
		cout << " | Type: " << eventType;
		cout << " | Loc: " << location;
		cout << " | Atts: " << attendees;
		cout << " | Desc: " << itemDescription;
	    cout << " | "<<endl;
	}

	//Saves Event Data to a given file
	void saveEvent(string fileName)
	{
		int day;
        int month;
	    int year;
		int hour;
		int minu;

		ofstream myStream(fileName, ios::app);
		if (myStream.is_open()) {
			myStream << "Event" << endl;
			myStream << id << endl;
			addedDate.getDate(day, month, year);
			myStream << day << endl;
			myStream << month << endl;
			myStream << year << endl;
			myStream << itemDescription << endl;
			startDate.getDate(day, month, year);
			myStream << day << endl;
			myStream << month << endl;
			myStream << year << endl;
			startTime.getTime(hour,minu);
			myStream << hour << endl;
			myStream << minu << endl;
			endDate.getDate(day, month, year);
			myStream << day << endl;
			myStream << month << endl;
			myStream << year << endl;
			endTime.getTime(hour,minu);
			myStream << hour << endl;
			myStream << minu << endl;
			myStream << eventType << endl;
			myStream << location << endl;
			myStream << attendees << endl;
		}
		myStream.close();
	}

	//Destructor
	~Event ()
	{

	}
};

/**************************************************************************                                    
* Class        	:  	Diary
* Type			:  	Top Class composed, contains all events
* Scope			: 	All App
* Variables   	:   9
* Functions		:   Extense, divided in Groups of functions                                                                                    
**************************************************************************/
class Diary
{
	//Private data fields
    private:

	//Maximun number of Items per type
	int maxToDos;
	int maxReminders;
	int maxEvents;

    //Counter for the current number of Items per type
    int numToDo;
	int numReminders;
	int numEvents;

    //Pointer to a dynamics arrays per type
    ToDo* toDosArr;
	Reminder* remindersArr;
	Event* eventsArr;

	//Public member functions
    public:

/**************************************************************************                                    
* Group of Class:  	Diary
* Function Group:  	General
* Socope		: 	Member functions for general propouses  
* Numel      	:   4 Functions.                                                                                        
**************************************************************************/

    //constructor
    Diary (){

		//Initialize parameters
		this->maxToDos=300;
        this->numToDo=0;
		this->maxReminders=200;
		this->numReminders=0;
		this->maxEvents=100;
		this->numEvents=0;

		//Alocate the memory arrays per type in the Heap
		this->toDosArr= new ToDo[this->maxToDos];
		this->remindersArr= new Reminder[this->maxReminders];
		this->eventsArr= new Event[this->maxEvents];
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

/**************************************************************************                                    
* Group of Class:  	Diary
* Function Group:  	ToDo Array 
* Scope			: 	Management of all functionalities related to ToDos
* Numel      	:   5 Functions.                                                                                        
**************************************************************************/

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
		cout<<"Please enter the due Year, number from 2000 to 2099"<<endl;
		cin>> yyyy;
		cout<<"Please enter the due Month, number from 1 to 12"<<endl;
		cin>> mm;
		cout<<"Please enter the due Day, number from 1 to 31"<<endl;
		cin>> dd;		
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
			  cout<<"Please enter the new due Year, number from 2000 to 2099"<<endl;
			  cin>> yyyy;
			  cout<<"Please enter the new due Month, number from 1 to 12"<<endl;
			  cin>> mm;
			  cout<<"Please enter the new due Day, number from 1 to 31"<<endl;
			  cin>> dd;
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

/**************************************************************************                                    
* Group of Class:  	Diary
* Function Group:  	Reminders Array 
* Scope			: 	Management of all functions related to Reminders
* Numel      	:   4 Functions.                                                                                        
**************************************************************************/

	//Print All Reminders in the Diary
	void printAllReminders (){
	    int i;
	    for (i=0;i<numReminders;i++){
	        remindersArr[i].printItem();
	    }
	} 

	//Member function for adding an Reminders
	void addReminder()
	{	
		clearConsole();
	    string description="";
	    int dd=0;
	    int mm=0;
	    int yyyy=0;
		int type=0;
		int hour;
		int minu;
		cout<<"*****************************************************************"<<endl;
		cout<< "			Add Reminder Option"<<endl<<endl;
		cout<<"Please enter description of your new Reminder"<<endl;
		cin.ignore();
		getline(cin,description);
		cout<<"Please enter the target Year, number from 2000 to 2099"<<endl;
		cin>> yyyy;
		cout<<"Please enter the target Month, number from 1 to 12"<<endl;
		cin>> mm;
		cout<<"Please enter the target Day, number from 1 to 31"<<endl;
		cin>> dd;
		cout<<"Please enter the target  Hour, number from 0 to 23"<<endl;
		cin>> hour;
		cout<<"Please enter the target Minute, number from 0 to 59"<<endl;
		cin>> minu;
		cout<<endl<<"There are 5 diferents types of Reminders."<<endl;
 		cout<<"Please, select one option by entering the option number:"<<endl<<endl;
        cout<< "1. Deadline"<<endl;
        cout<< "2. Birthday"<<endl;
        cout<< "3. Aniversary"<<endl;
        cout<< "4. Travel"<<endl;
		cout<< "5. Public Holiday"<<endl<<endl;
        cout<<"Please enter the option:"<<endl;
		cin>> type;
		numReminders++;
		remindersArr[numReminders-1].setReminder(numReminders,description,dd,mm,yyyy,type,hour,minu);
		cout<<endl<<"The Reminder:"<<numReminders<<" was added to your Diary:"<<endl;
		remindersArr[numReminders-1].printItem();
		menuPause();
	}

	//Member function for removing an Reminder
	void removeReminder()
	{
	    int code;
		clearConsole();
		cout<<"*****************************************************************"<<endl;
		cout<< "			Remove Reminder Option"<<endl<<endl;
		if(numReminders<1){
			cout<<"There are no Reminders in the App"<<endl;
			menuPause();
		} else {
			cout<<"The current Reminders list is :"<<endl<<endl;
			printAllReminders();
			cout<<endl<<"Enter a Reminder number from 1 to "<<numReminders<<" to be removed"<<endl;
			cin>> code;
			if(code < 1 || code > numReminders){
			  cout<<endl<<"Option out of range"<<endl;
			  menuPause();
			}
			else {
			  int i;
			  for(i=code-1;i<numReminders-1;i++){
				//Use the default shallow asign function
				remindersArr[i]=remindersArr[i+1];
				//Use the Item.setId Method to update the Id
				remindersArr[i].setId(i+1);
			  }
			  numReminders--;
			  cout<<"The new Reminders list is:"<<endl<<endl;
			  printAllReminders();
			  menuPause();
			}
		}
	}

	//Member function for edting a Reminder
	void editReminder()
	{
	    int dd;
	    int mm;
	    int yyyy;
		string description;
		int code;
		int type;
		int hour;
		int minu;
		clearConsole();
		cout<<"*****************************************************************"<<endl;
		cout<< "			Edit Reminders Option"<<endl<<endl;
		if(numReminders<1){
			cout<<"There are no Reminders in the App"<<endl;
			menuPause();
		} else {
			cout<<"Enter the Reminder number to be edited from this list :"<<endl<<endl;
			printAllReminders();
			cout<<endl<<"Enter a number from 1 to "<<numReminders<<endl;
			cin>> code;
			if(code < 1 || code > numReminders){
				cout<<endl<<"Option out of range"<<endl;
				menuPause();
			}
			else {			
				cout<<"Please enter the new description for your Reminder"<<endl;
				cin.ignore();
				getline(cin,description);
				cout<<"Please enter the new target Year, number from 2000 to 2099"<<endl;
				cin>> yyyy;
				cout<<"Please enter the new target Month, number from 1 to 12"<<endl;
				cin>> mm;
				cout<<"Please enter the new target Day, number from 1 to 31"<<endl;
				cin>> dd;
				cout<<"Please enter the new target  Hour, number from 0 to 23"<<endl;
				cin>> hour;
				cout<<"Please enter the new target Minute, number from 0 to 59"<<endl;
				cin>> minu;
				cout<<endl<<"There are 5 diferents types of Reminders."<<endl;
				cout<<"Please, select the new type by entering the option number:"<<endl<<endl;
				cout<< "1. Deadline"<<endl;
				cout<< "2. Birthday"<<endl;
				cout<< "3. Aniversary"<<endl;
				cout<< "4. Travel"<<endl;
				cout<< "5. Public Holiday"<<endl<<endl;
				cout<<"Please enter the option:"<<endl;
				cin>> type;
				remindersArr[code-1].setReminder(code,description,dd,mm,yyyy,type,hour,minu);
				cout<<"The new list of Reminders is:"<<endl<<endl;
				printAllReminders();
				menuPause();
			}
		}
	}

/**************************************************************************                                    
* Group of Class:  	Diary
* Function Group:  	Events Array 
* Scope			: 	Management of all functions related to Events
* Numel      	:   4 Functions.                                                                                        
**************************************************************************/

	//Print All Events in the Diary
	void printAllEvents ()
	{
	    int i;
	    for (i=0;i<numEvents;i++){
	        eventsArr[i].printItem();
	    }
	}

	//Member function for adding an Event
	void addEvent()
	{	
		//Declare and initialize variables
	    string description="";
	    int start_dd=0;
	    int start_mm=0;
	    int start_yyyy=0;
		int start_hour=0;
		int start_minu=0;
		int end_dd=0;
	    int end_mm=0;
	    int end_yyyy=0;
		int end_hour=0;
		int end_minu=0;
		int type=0;
		string location="";
		string attendees="";

		//Print the user interface
		clearConsole();
		cout<<"*****************************************************************"<<endl;
		cout<< "			Add Event Option"<<endl<<endl;
		
		//Read the description
		cout<<"Please enter description of your new Event"<<endl;
		cin.ignore();
		getline(cin,description);
        
		//Read the start hour
		cout<<"Please enter the start Year, number from 2000 to 2099"<<endl;
		cin>> start_yyyy;
		cout<<"Please enter the start Month, number from 1 to 12"<<endl;
		cin>> start_mm;
		cout<<"Please enter the start Day, number from 1 to 31"<<endl;
		cin>> start_dd;
		cout<<"Please enter the start  Hour, number from 0 to 23"<<endl;
		cin>> start_hour;
		cout<<"Please enter the start Minute, number from 0 to 59"<<endl;
		cin>> start_minu;
       
	    //Read the end hour
		cout<<"Please enter the end Year, number from 2000 to 2099"<<endl;
		cin>> end_yyyy;
		cout<<"Please enter the end Month, number from 1 to 12"<<endl;
		cin>> end_mm;
		cout<<"Please enter the end Day, number from 1 to 31"<<endl;
		cin>> end_dd;
		cout<<"Please enter the end Hour, number from 0 to 23"<<endl;
		cin>> end_hour;
		cout<<"Please enter the end Minute, number from 0 to 59"<<endl;
		cin>> end_minu;

        //Select the event type
		cout<<endl<<"There are 5 diferents types of Events"<<endl;
 		cout<<"Please, select one option by entering the option number:"<<endl<<endl;
        cout<< "1. Meeting"<<endl;
        cout<< "2. Conference"<<endl;
        cout<< "3. Seminar"<<endl;
        cout<< "4. Talk"<<endl;
		cout<< "5. Team-building event"<<endl<<endl;
        cout<<"Please enter the option:"<<endl;
		cin>> type;

		//Read the location
		cout<<endl<<"Please enter the location of your new Event"<<endl;
		cin.ignore();
		getline(cin,location);

		//Read the attendee
		cout<<endl<<"Enter the attendees to your new Event, all in the same line"<<endl;
		//cin.ignore();
		getline(cin,attendees);

		numEvents++;
		eventsArr[numEvents-1].setEvent(numEvents,description,type, location, attendees, start_dd, start_mm, start_yyyy, start_hour, start_minu, end_dd, end_mm, end_yyyy, end_hour, end_minu);
		cout<<endl<<"The event:"<<numEvents<<" was added to your Diary:"<<endl;
		eventsArr[numEvents-1].printItem();

		//menuPause() has a Glitch here, so do it manually and ajust
		cout << endl << "Press enter to continue..." << endl;
    	//cin.ignore();
    	cin.get();
	}

	//Member function for removing an Event
	void removeEvent()
	{
	    int code;
		clearConsole();
		cout<<"*****************************************************************"<<endl;
		cout<< "			Remove Event Option"<<endl<<endl;
		if(numEvents<1){
			cout<<"There are no Events in the App"<<endl;
			menuPause();
		} else {
			cout<<"The current Events list is :"<<endl<<endl;
			printAllEvents();
			cout<<endl<<"Enter an Event number from 1 to "<<numEvents<<" to be removed"<<endl;
			cin>> code;
			if(code < 1 || code > numEvents){
			  cout<<endl<<"Option out of range"<<endl;
			  menuPause();
			}
			else {
			  int i;
			  for(i=code-1;i<numEvents-1;i++){
				//Use the default shallow asign function
				eventsArr[i]=eventsArr[i+1];
				//Use the Item.setId Method to update the Id
				eventsArr[i].setId(i+1);
			  }
			  numEvents--;
			  cout<<"The new Event list is:"<<endl<<endl;
			  printAllEvents();
			  menuPause();
			}
		}
	}

	//Member function for editing a Event
	void editEvent()
	{
	    //Declare and initialize variables
	    string description="";
	    int start_dd=0;
	    int start_mm=0;
	    int start_yyyy=0;
		int start_hour=0;
		int start_minu=0;
		int end_dd=0;
	    int end_mm=0;
	    int end_yyyy=0;
		int end_hour=0;
		int end_minu=0;
		int type=0;
		string location="";
		string attendees="";

		int code;
		//Print the user interface
		clearConsole();
		cout<<"*****************************************************************"<<endl;
		cout<< "			Edit Event Option"<<endl<<endl;
		if(numEvents<1){
			cout<<"There are no Events in the App"<<endl;
			menuPause();
		} else {
			cout<<"Enter the Event number to be edited from this list :"<<endl<<endl;
			printAllEvents();
			cout<<endl<<"Enter a number from 1 to "<<numEvents<<endl;
			cin>> code;
			if(code < 1 || code > numEvents){
				cout<<endl<<"Option out of range"<<endl;
				menuPause();
			}
			else {			
				//Read the description
				cout<<"Please enter the new description of your Event"<<endl;
				cin.ignore();
				getline(cin,description);
				
				//Read the start hour
				cout<<"Please enter the new start Year, number from 2000 to 2099"<<endl;
				cin>> start_yyyy;
				cout<<"Please enter the new start Month, number from 1 to 12"<<endl;
				cin>> start_mm;
				cout<<"Please enter the new start Day, number from 1 to 31"<<endl;
				cin>> start_dd;
				cout<<"Please enter the new start  Hour, number from 0 to 23"<<endl;
				cin>> start_hour;
				cout<<"Please enter the new start Minute, number from 0 to 59"<<endl;
				cin>> start_minu;
			
				//Read the end hour
				cout<<"Please enter the new end Year, number from 2000 to 2099"<<endl;
				cin>> end_yyyy;
				cout<<"Please enter the new end Month, number from 1 to 12"<<endl;
				cin>> end_mm;
				cout<<"Please enter the new end Day, number from 1 to 31"<<endl;
				cin>> end_dd;
				cout<<"Please enter the new end Hour, number from 0 to 23"<<endl;
				cin>> end_hour;
				cout<<"Please enter the new end Minute, number from 0 to 59"<<endl;
				cin>> end_minu;

				//Select the event type
				cout<<endl<<"There are 5 diferents types of Events"<<endl;
				cout<<"Please, select the new type by entering the option number:"<<endl<<endl;
				cout<< "1. Meeting"<<endl;
				cout<< "2. Conference"<<endl;
				cout<< "3. Seminar"<<endl;
				cout<< "4. Talk"<<endl;
				cout<< "5. Team-building event"<<endl<<endl;
				cout<<"Please enter the option:"<<endl;
				cin>> type;

				//Read the location
				cout<<endl<<"Please enter the location of your new Event"<<endl;
				cin.ignore();
				getline(cin,location);

				//Read the attendee
				cout<<endl<<"Enter the attendees to your new Event, all in the same line"<<endl;
				//cin.ignore();
				getline(cin,attendees);

				eventsArr[code-1].setEvent(code,description,type, location, attendees, start_dd, start_mm, start_yyyy, start_hour, start_minu, end_dd, end_mm, end_yyyy, end_hour, end_minu);
				cout<<"The new list of Events is:"<<endl<<endl;
				printAllEvents();
				//menuPause() has a Glitch here, so do it manually and ajust
				cout << endl << "Press enter to continue..." << endl;
				//cin.ignore();
				cin.get();
			}
		}
	}

/**************************************************************************                                    
* Group of Class:  	Diary
* Function Group:  	Diary Files
* Scope			: 	Management of all functionalities related to Files
* Numel      	:   2 Functions.                                                                                        
**************************************************************************/

	//Saves Diary Objects to the diary.txt file
	int saveDiary (){
		string fileName="diary.txt";
		
		//First Open diary.txt in new mode and save the word "Diary" to clean the file
		ofstream myStream(fileName);
		if (myStream.is_open()) {
			myStream << "Diary" << endl;
		}
		myStream.close();
		
		//Loop over ToDosArr and append each ToDo data to the file diary.txt
		for (int i=0;i<numToDo;i++){
			toDosArr[i].saveToDo(fileName);
		}
		//Loop over remindersArr and append each Reminder data to the file diary.txt
		for (int i=0;i<numReminders;i++){
			remindersArr[i].saveReminder(fileName);
		}
		//Loop over eventsArr and append each Event data to the file diary.txt
		for (int i=0;i<numEvents;i++){
			eventsArr[i].saveEvent(fileName);
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
				//if the line is a Reminder
				if((line.compare("Reminder")) == 0){
						remindersArr[numReminders].loadReminder(myStream,numReminders+1);
						numReminders++;	
				}
				//if the line is a Reminder
				if((line.compare("Event")) == 0){
						eventsArr[numEvents].loadEvent(myStream,numEvents+1);
						numEvents++;	
				}
			}
			myStream.close();
		}
		return 1;
	} 

/**************************************************************************                                    
* Group of Class:  	Diary
* Function Group:  	Searchs and Reports
* Scope			: 	Management of Searchs and Reports functionalities
* Numel      	:   1 Function.                                                                                        
**************************************************************************/

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
				cout<<"Please enter the Year, number from 2000 to 2099"<<endl;
				cin>> yyyy;
				cout<<"Please enter the Month, number from 1 to 12"<<endl;
				cin>> mm;
				cout<<"Please enter the Day, number from 1 to 31"<<endl;
				cin>> dd;
				clearConsole();
				cout<<endl<<"*****************************************************************"<<endl;
				cout<<"Search Results."<<endl<<endl;
				cout<<"  ToDos :"<<endl<<endl;
				for (int i=0; i<numToDo; i++){
						if(toDosArr[i].compareAddedDate(dd,mm,yyyy)==1){
							toDosArr[i].printItem();
							results++;
						}
				}
				cout<<endl<<"  Reminders :"<<endl<<endl;
				for (int i=0; i<numReminders; i++){
						if(remindersArr[i].compareAddedDate(dd,mm,yyyy)==1){
							remindersArr[i].printItem();
							results++;
						}
				}
				for (int i=0; i<numEvents; i++){
						if(eventsArr[i].compareAddedDate(dd,mm,yyyy)==1){
							eventsArr[i].printItem();
							results++;
						}
				}
				cout<<endl<<"  Total Results :"<<endl<<endl;
				cout<<"-"<<results<<" records found for the entered added date search"<<endl;
				menuPause();
		}
	}
 
/**************************************************************************                                    
* Group of Class:  	Diary
* Function Group:  	Menu and Sub Menus
* Scope			: 	Management of Main Menu and Sub Menus
* Numel      	:   4 Functions.                                                                                        
**************************************************************************/
	//Sub-Menu ToDo of the Diary Class
    void ToDoMenu(){        
        int option=9;
        while (option!=0){
        	clearConsole();
            cout<<"*****************************************************************"<<endl;
            cout<< "			The Diary App Ver 3.0"<<endl;
			cout<<"*****************************************************************"<<endl;
            cout<< "			       ToDos Menu "<<endl<<endl;
            cout<< "Select one option by entering the option number:"<<endl<<endl;
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

    //Sub-Menu Reminders of the Diary Class
    void RemindersMenu(){        
        int option=9;
        while (option!=0){
        	clearConsole();
            cout<<"*****************************************************************"<<endl;
            cout<< "			The Diary App Ver 3.0"<<endl;
			cout<<"*****************************************************************"<<endl;
            cout<< "			       Reminders Menu"<<endl<<endl;
            cout<< "Select one option by entering the option number:"<<endl<<endl;
            cout<< "1. Add Reminder"<<endl;
            cout<< "2. Delete Reminder"<<endl;
            cout<< "3. Edit Reminder"<<endl;
			cout<< "4. Print all Reminders"<<endl;
            cout<< "0. Back to Main Menu"<<endl;
            cout<<"*****************************************************************"<<endl;
            cout<<"Please enter the option:"<<endl;
            cin>> option;
            if (option==1){
                addReminder();
            } else if (option==2){
                removeReminder();
            } else if (option==3){
                editReminder();
            } else if (option==4){
				clearConsole();
				cout<<"*****************************************************************"<<endl;
				cout<< "			All Reminders"<<endl<<endl;
                printAllReminders ();
				cout<<endl<<"Going back to previous menu."<<endl;
				menuPause();                
            } else if (option==0){
                cout<<endl<<"Going Back to Main Menu "<<endl;
            } else {
                cout<<"Invalid Option"<<endl;
            }
        }
    }

	 //Sub-Menu Events of the Diary Class
    void EventsMenu(){        
        int option=9;
        while (option!=0){
        	clearConsole();
            cout<<"*****************************************************************"<<endl;
            cout<< "			The Diary App Ver 3.0"<<endl;
			cout<<"*****************************************************************"<<endl;
            cout<< "			       Events Menu"<<endl<<endl;
            cout<< "Select one option by entering the option number:"<<endl<<endl;
            cout<< "1. Add an Event"<<endl;
            cout<< "2. Delete an Event"<<endl;
            cout<< "3. Edit an Event"<<endl;
			cout<< "4. Print all Events"<<endl;
            cout<< "0. Back to Main Menu"<<endl;
            cout<<"*****************************************************************"<<endl;
            cout<<"Please enter the option:"<<endl;
            cin>> option;
            if (option==1){
                addEvent();
            } else if (option==2){
                removeEvent();
            } else if (option==3){
                editEvent();
            } else if (option==4){
				clearConsole();
				cout<<"*****************************************************************"<<endl;
				cout<< "			All Events"<<endl<<endl;
                printAllEvents ();
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
            cout<< "Select one option by entering the option number:"<<endl<<endl;
            cout<< "1. Manage ToDos"<<endl;
            cout<< "2. Manage Reminders"<<endl;
            cout<< "3. Manage Events"<<endl;
            cout<< "4. Print all Items by Type"<<endl;
			cout<< "5. Search by Added Date"<<endl;
            cout<< "0. To exit the program"<<endl;
            cout<<"*****************************************************************"<<endl;
            cout<<"Please enter the option:"<<endl;
            cin>> option;
            if (option==1){
                ToDoMenu();
            } else if (option==2){
                RemindersMenu();
            } else if (option==3){
                EventsMenu();
            } else if (option==4){
				clearConsole();
				cout<<"*****************************************************************"<<endl;
				cout<< "			All Diary Items by Type"<<endl<<endl;
                cout<<"  ToDos :"<<endl<<endl;
				printAllToDos ();
				cout<<endl<<"  Reminders :"<<endl<<endl;
				printAllReminders ();
				cout<<endl<<"  Events :"<<endl<<endl;
				printAllEvents ();
				cout<<endl<<"Going back to previous menu."<<endl;
				menuPause();                
			} else if (option==5){
                searchByAddedDate ();
            } else if (option==0){
			 	saveDiary ();
                cout<<endl<<"Thank you for using The Diary App, have a nice day. "<<endl<<endl;
            } else {
                cout<<"Invalid Option"<<endl;
            }
            
        }
        

    }

/**************************************************************************                                    
* Group of Class:  	Diary
* Function Group:  	Destructors
* Scope			: 	Management of Destructors
* Numel      	:   1 Function.                                                                                        
**************************************************************************/

	//Destructor
    ~Diary (){
		//Free the memory of all Arrays in the Heap
		delete[] this->toDosArr;
		delete[] this->remindersArr;
		delete[] this->eventsArr;
    }


};

/**************************************************************************                                    
* Class        	:  	main function
* Type			:  	function
* Scope			: 	All App
* Variables   	:   1
* Functions		:   None                                                                               
**************************************************************************/
int main()

{
      
      //Declare a Diary object
      Diary diary;
      //Call the main Diary menu
      diary.mainMenu();

      return 0;
}