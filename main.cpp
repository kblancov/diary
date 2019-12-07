#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

//Date class
class Date
{
	private:
	      int month;
	      int day;
	      int year;

	public:
	//default constructor
	Date()
	{
	      month = 1;
	      day = 1;
	      year = 2000;
	}

	//Parametrized constructor
	Date(int dd, int mm, int yy)
	{
	      if(dd >= 1 && dd <= 31)//makes sure day is valid
		    day = dd;
	      else
		    day = 1;
        if(mm >= 1 && mm <= 12)//makes sure month is valid
		    month = mm;
	      else
		    month = 1;
	      if(yy >= 2000 && yy <= 2099)//makes sure year is valid
		    year = yy;
	      else
		    year = 2000;
	}

	//sets a valid date
	void setDate(int dd, int mm, int yy)
	{
	      if(dd >= 1 && dd <= 31)//makes sure day is valid
		    day = dd;
	      else
		    day = 1;
        if(mm >= 1 && mm <= 12)//makes sure month is valid
		    month = mm;
	      else
		    month = 1;
	      if(yy >= 2000 && yy <= 2099)//makes sure year is valid
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
	      cout << day << "|";
        if(month < 10)
		    cout << "0";
	      cout << month << "|";
	      cout << year;
	}
	//Destructor
	~Date()
	{
	}
};

//Event class
class DiaryItem
{
	private:
	    int id;
	    string itemName;
	    Date itemDay;
	public:

	//default constructor
	DiaryItem ()
	{
 	      itemName="";
 	      id=0;
	}

	//Parametrized constructor
	DiaryItem (int code, string name, int dd, int mm, int yyyy)
	{
	        id=code;
      		itemName = name;
		    itemDay.setDate(dd, mm, yyyy);
	}

	void setDiaryItem(int code, string name, int dd, int mm, int yyyy)
	{
      		id=code;
      		itemName = name;
		    itemDay.setDate(dd, mm, yyyy);
	}

	void printDiaryItemData()
	{
	      cout << "¦ Item " << id << " ¦ ";
	      cout << itemName << " ¦ ";
	      itemDay.printDate();
	      cout << " ¦ " <<endl;
	}

	//Destructor
	~DiaryItem ()
	{

	}
};

//Diary class
class GlobalDiary
{
    private:
    //Counter for the number of Items
    int numItems=0;
    //The of items
    DiaryItem item[10];
    
    public:
    //constructor
    GlobalDiary (){
        numItems=-1;
    }
    
    void newItem(int code)
	{
	    string name;
	    int dd;
	    int mm;
	    int yyyy;
	    cout<<"Please enter name of your new event"<<endl;
        cin>> name;
        cout<<"Please enter Day"<<endl;
        cin>> dd;
        cout<<"Please enter Month"<<endl;
        cin>> mm;
        cout<<"Please enter Year"<<endl;
        cin>> yyyy;
      	item[code].setDiaryItem(code,name,dd,mm,yyyy);	
	}
	
	void printItems (){
	    int i;
	    for (i=0;i<=numItems;i++){
	        item[i].printDiaryItemData();
	    }
	} 
    
    void mainMenu(){        
        
        int option=9;
        
        while (option!=0){
        	//cout << "\x1B[2J\x1B[H"; //mixies based
            cout<<"*****************************************************************"<<endl;
            system("clear");
            cout<< "Wellcome to the Diary App Main Menu"<<endl;
            cout<< "Select one of the next options by entering the option number:"<<endl;
            cout<< "1. Add Item"<<endl;
            cout<< "2. Remove Item"<<endl;
            cout<< "3. Edit Item"<<endl;
            cout<< "4. Save to File"<<endl;
            cout<< "5. Open from File"<<endl;
            cout<< "6. Print all Items"<<endl;
            cout<< "0. to exit"<<endl;
            cout<<"*****************************************************************"<<endl;
            cout<<"Please enter the option"<<endl;
            cin>> option;
            if (option==1){
            	system("clear");
                cout<<"Option 1. Menu: "<<endl;
                numItems=numItems+1;
                newItem(numItems);
                item[numItems].printDiaryItemData();
                cout<<"Press enter to continue"<<endl;
                getchar();
            } else if (option==2){
                cout<<"Option 2. Menu: "<<endl;  
				cout << "Press Enter to Continue";
				cin.ignore();
            } else if (option==3){
                cout<<"Option 3. Menu: "<<endl;
            } else if (option==4){
                cout<<"Option 4. Menu: "<<endl;
            } else if (option==5){
                cout<<"Option 5. Menu: "<<endl;
            } else if (option==6){
                cout<<"Option 6. Menu: "<<endl;
                printItems ();
            } else if (option==0){
                cout<<"Thank you, have a nice day. "<<endl;
            } else {
                cout<<"Invalid Option"<<endl;
            }
            
        }
        

    }
};

int main()

{
      //clearConsole();
      //Declare a GlobalDiary object
      GlobalDiary diary;
      //Call the main Diary menu
      diary.mainMenu();

      return 0;
}