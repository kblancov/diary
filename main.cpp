#include<iostream>
#include<string>

using namespace std;

//Time class
class Time
{     		
	private:
	      int hour;
	      int minu;
	public:

	//default constructor
	Time()
	{     
	      hour = 0;
	      minu = 0;
	}
	
	//Parametrized constructor
	Time(int hours, int minutes)
	{     
	      if(0 <= hours && hours < 24)//makes sure hours are valid
		    hour = hours;
	      else
		    hour = 0;
	      if(0 <= minutes && minutes < 60)//makes sure minutes are valid
		    minu = minutes;
	      else
		    minu = 0;
	}
	
	//sets a valid time
	void setTime(int hours, int minutes)
	{     
	      if(0 <= hours && hours < 24)
		    hour = hours;
	      else
		    hour = 0;
	      if(0 <= minutes && minutes < 60)
		    minu = minutes;
	      else
		    minu = 0;
	}

	//returns the hours and minutes
	void getTime(int& hours, int& minutes)
	{     
	      hours = hour;
	      minutes = minu;
	}

	//displays the hours and minutes to the screen
	void printTime()
	{     
	      if(hour < 10)
		    cout << "0";
	      cout << hour << ":";
	      if(minu < 10)
		    cout << "0";
	      cout << minu << endl;
	}
	//Destructor
	~Time()
	{     
	}
};

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
	Date(int mm, int dd, int yy)
	{
	      if(mm >= 1 && mm <= 12)//makes sure month is valid
		    month = mm;
	      else
		    month = 1;
	      if(dd >= 1 && dd <= 31)//makes sure day is valid
		    day = dd;
	      else
		    day = 1;
	      if(yy >= 2000 && yy <= 2099)//makes sure year is valid
		    year = yy;
	      else
		    year = 2000;
	}

	//sets a valid date
	void setDate(int mm, int dd, int yy)
	{
	      if(mm >= 1 && mm <= 12)//makes sure month is valid
		    month = mm;
	      else
		    month = 1;
	      if(dd >= 1 && dd <= 31)//makes sure day is valid
		    day = dd;
	      else
		    day = 1;
	      if(yy >= 2000 && yy <= 2099)//makes sure year is valid
		    year = yy;
	      else
		    year = 2000;
	}

	//returns the month, day and year
	void getDate(int& mm, int& dd, int& yy)
	{
	      mm = month;
	      dd = day;
	      yy =year;
	}

	//displays the month, day and year to the screen
	void printDate()
	{
	      if(month < 10)
		    cout << "0";
	      cout << month << "|";
	      if(day < 10)
		    cout << "0";
	      cout << day << "|";
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
	      string itemName;
	      Date itemDay;
	public:

	//default constructor
	DiaryItem ()
	{
 	      itemName="";
	}

	//Parametrized constructor
	DiaryItem (int mm, int dd, int yyyy, string name)
	{
      		itemName = name;
		itemDay.setDate(mm, dd, yyyy);
	}

	void setDiaryItemData(int mm, int dd, int yyyy, string name)
	{
      		itemName = name;
		itemDay.setDate(mm, dd, yyyy);
	}

	void printDiaryItemData()
	{
	      cout << itemName << " is on ";
	      itemDay.printDate();
	}

	//Destructor
	~DiaryItem ()
	{

	}
};

int main()

{
      DiaryItem exam( 12, 13, 2019, "Exam");
      exam.printDiaryItemData();
	cout << endl;
      return 0;
}

