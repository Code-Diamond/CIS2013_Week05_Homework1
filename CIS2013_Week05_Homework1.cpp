#include <iostream>
#include <sstream>
#include <string> 

//Still working on overall accuracy of printing mechanism

using namespace std;

//Converts an integer to a string
string convertToString(int year)
{
  int number = year;
  string result;          // string which will contain the result
  ostringstream convert;  // stream used for the conversion
  convert << number;      // insert the textual representation of 'Number' in the characters in the stream
  result = convert.str(); 
  return result;
}

//Gets the last two digits of a year
string getLastTwo(string year)
{
  string result = year.substr(2,4);
  return result;
}

//gets the first two digits of a year (redundant)
string getFirstTwo(string year)
{
  string result = year.substr(0,2);
  return result;
}

//Converts a string to an integer
int convertToInt(string s)
{
  int value = atoi(s.c_str()); 
  return value;
}

//Print a calendar
int getDay(int month, int year)
{
  //The key-value (determination of day of week) algorithm

  //For this, the day of the month is always 1
  int day = 1;
  //These key codes provide the algorithm a means to navigate the Gregorian Calendar
    //And determine appropriate day of week
                      //Jan -------------------->December
  int monthCode[12] = {1,   4,4,0,2,5,0,3,6,1,4,6};
                      //1700-->2000
  int centuryCode[4] = {4,2,0,6};
  
  //Convert the year to a string
  string rawYear = convertToString(year);

  //Take the last 2 digits of the year.     
  string lastTwo = getLastTwo(rawYear);
  
  //Divide by 4, and drop any remainder.
  int number = convertToInt(lastTwo);
  number = number / 4;

  //Add the day of the month. 
  number = number + day;

  //Add the month's key value, from the following table. 
  number = number + monthCode[month - 1];

  //If the month is in January or February of a leap year, subtract 1. 
  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
  {
    if(month == 1 || month == 2)
    {
      number--;
    }
  }
  //Change year to be within range of century code and add the century codes value
  if(year < 1700)
  {
      while(year < 1700)
      {
        year = year + 400;
      }

      if(year >= 1700 && year < 1800)
      {
        //Add the century code 
        number = number + centuryCode[0];
      }

      if(year >= 1800 && year < 1900)
      {
        //Add the century code 
        number = number + centuryCode[1];
      }

      if(year >= 1900 && year < 2000)
      {
        //Add the century code 
        number = number + centuryCode[2];
      }

      if(year >= 2000 && year < 2100)
      {
        //Add the century code
        number = number + centuryCode[3];
      }

  }
  else
  {
    if(year > 2100)
    {
        while(year > 2100)
        {
          year = year - 400;
        }

        if(year >= 1700 && year < 1800)
        {
          //Add the century code 
          number = number + centuryCode[0];
        }

        if(year >= 1800 && year < 1900)
        {
          //Add the century code 
          number = number + centuryCode[1];
        }

        if(year >= 1900 && year < 2000)
        {
          //Add the century code 
          number = number + centuryCode[2];
        }

        if(year >= 2000 && year < 2100)
        {
          //Add the century code
          number = number + centuryCode[3];
        }
    }
    else
    {
      if(year >= 1700 && year < 1800)
      {
        //Add the century code 
        number = number + centuryCode[0];
      }

      if(year >= 1800 && year < 1900)
      {
        //Add the century code 
        number = number + centuryCode[1];
      }

      if(year >= 1900 && year < 2000)
      {
        //Add the century code 
        number = number + centuryCode[2];
      }

      if(year >= 2000 && year < 2100)
      {
        //Add the century code
        number = number + centuryCode[3];
      }
    }
  }
  //Add the last two digits of the year. 
  int secondNumber = convertToInt(lastTwo);
  number = number + secondNumber;

  //Modulo last number by 7 days
  int result = number % 7;


  return result;

}

int getNumberOfDays(int month, int year)
{
  switch(month)
  {
    case 1: //January
      return 31;
      break;
    case 2: //February

      //Accounts for leap years

      //A leap year is always divisible by 400
        //A leap year can be a year that is divisible by 4 but not divisible by 100
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);

      break;
    case 3: // March
      return 31;
      break;
    case 4:// April
      return 30;
      break;
    case 5:// May
      return 31;
      break;
    case 6:// June
      return 30;
      break;
    case 7:// July
      return 31;    
      break;
    case 8:// August
      return 31;    
      break;
    case 9:// September
      return 30;    
      break;
    case 10:// October
      return 31;
      break;
    case 11:// November
      return 30;
      break;
    case 12:// December
      return 31;
      break;                              
  }

}

int main()
{
  int month, year;
  string monthNames[] = {"January", "February", "March", "April", "May", "June","July", "August", "September","October", "November", "December"};
  cout << "Enter a month and a year.\n";
  try
  {
    cout << "Month: "; cin >> month;
    cout << "Year: "; cin >> year;  


  //Restrict entry
  if(month < 1 || month > 12)
  {
    cout << "\nYou entered a month out of bounds..(1-12)..Defaulting January.\n";
    month = 1;
  }
  if(year < 1582)
  {
    cout << "\nPlease enter a date after 1582..Defaulting year to 1582..\n";
    year = 1582;
  }
  if(year > 9999)
  {
    cout << "\nWow! That's either really long from now\n Or an incorrect entry.. let's just try the year 9999 instead..\n";
    year = 9999;
  }
  


  //Print the month and days of weeks
  cout <<  "\n                "<< year << endl;
  cout <<  "              "<< monthNames[month-1] << endl;
  cout <<  " Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
  int startingDay = getDay(month, year);

  //Print calendar's leading dashes for that month
  for(int i = 1; i < startingDay; i++)
  {
    cout << ("  -  ");
  }
    
  //Print the calendar
  int calendarCounter = startingDay;
  for(int i = 1; i <= getNumberOfDays(month, year); i++)
  {
    if(i < 10)
    {
      if(calendarCounter<=7)
      {
        cout << "  " << i << "  ";
      }
      if(calendarCounter>7)
      {
        calendarCounter = 1;
        cout << "\n  " << i << "  ";      
      }
      calendarCounter++;       
    }
    else
    {
      if(calendarCounter<=7)
      {
        cout << " " << i << "  ";
      }
      if(calendarCounter>7)
      {
        calendarCounter = 1;
        cout << "\n " << i << "  ";      
      }
      calendarCounter++;          
    }
  }
  //Additional dash for months that are less than 31
  for(int i = getNumberOfDays(month, year); i<=30; i++)
  {
      cout << ("  -  ");  
  }

  cout << "\n\n";
 // cout << "Exiting..";

  }catch(int e)
  {
    cout << "An exception occured. \n \n Exception #:" << e << endl;
  }


  return 0;

}
