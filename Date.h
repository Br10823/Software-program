#ifndef Date_h
#define Date_h
using namespace std;
class Date
#include <iostream>
{
  private:
  int Day;
  int Month;
  int Year;
  string sNameOfMonth;

  public:
  Date();
  Date(int, int, int);
  int getDay();
  void setDay(int);
  int getMonth();
  int daysOfMonth();
  void setMonth(int);
  int getYear();
  void setYear(int);
  void setDate(int, int, int);
  friend Date operator +(Date,int);
  friend bool operator>=(Date,Date);
  friend bool operator>(Date,Date);
  friend bool operator<=(Date,Date);
  friend bool operator<(Date,Date);
  friend bool operator==(Date,Date);
  friend istream &operator>>(istream&, Date&);
  friend ostream &operator<<(ostream&, Date);
  string nameOfMonth();
  bool bisiesto();
  
  };

  Date::Date()
  {
    Day=0;
    Month=0;
    Year=0;
  }
  Date::Date(int iDay, int iMonth, int iYear)
  {
    Day=iDay;
    Month=iMonth;
    Year=iYear;
  }
  int Date::getDay()
  {
    return Day;
  }
  int Date::getMonth()
  {
    return Month;
  }
  int Date::getYear()
  {
    return Year;
  }
  void Date::setDay(int iD)
  {
    Day=iD;
  }
  void Date::setMonth(int iM)
  {
    Month=iM;
  }
  void Date::setYear(int iY)
  {
    Year=iY;
  }
  void Date::setDate(int iD, int iM, int iY)
  {
    Day=iD;
    Month=iM;
    Year=iY;
  }
  string Date::nameOfMonth() {
    string month;
    
    switch(Month) {
        case 1:
            month = "Jan";
            break;

        case 2:
            month = "Feb";
            break;

        case 3:
            month = "Mar";
            break;

        case 4:
            month = "Apr";
            break;

        case 5:
            month = "May";
            break;

        case 6:
            month = "Jun";
            break;

        case 7:
            month = "Jul";
            break;

        case 8:
            month = "Aug";
            break;

        case 9:
            month = "Sep";
            break;

        case 10:
            month = "Oct";
            break;

        case 11: 
            month = "Nov";
            break;

        case 12: 
            month = "Dec";
            break;
    }
    return month;
}

int Date::daysOfMonth() {
    int days;
    Date D1( Day,  Month,  Year);

    switch(Month) {
        case 1: 
        days = 31;
        break;

        case 2: 
        if(D1.bisiesto()) {
            days = 29;
        } else {
            days = 28;
        }
        break;

        case 3:
        days = 31;
        break;  

        case 4:
        days = 30;
        break;

        case 5:
        days = 31;
        break;

        case 6:
        days = 30;
        break;

        case 7:
        days  = 31;
        break;

        case 8:
        days = 31;
        break;

        case 9:
        days = 30;
        break;

        case 10:
        days = 31;

        case 11:
        days = 30;

        case 12:
        days = 31;
        break;
    }
    return days;
} 

Date operator+(Date DD, int x) { // // // // // // // // //
    int d = DD.Day;
    int m = DD.Month;
    int y = DD.Year;
    if(d > DD.daysOfMonth()) 
        {
          d -= DD.daysOfMonth();
        }
    Date D3(d, m, y);
    return D3;
}

bool Date::bisiesto() {
    if((Year % 4 == 0) || (Year % 100 != 0 && Year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

istream& operator >> (istream& input, Date &Date) {
    cout << "Day: ";
    input >> Date.Day;
    cout << "Month: ";
    input >> Date.Month;
    cout << "Year: ";
    input >> Date.Year;
    return input;
}

ostream& operator << (ostream& output, Date Date) 
{
    output << Date.Day << "/" << Date.nameOfMonth() << "/" << Date.Year;
    return output;
}

bool operator==(Date D1, Date D2) {
    if((D1.Day == D2.Day) && (D1.Month == D2.Month) && (D1.Year == D2.Year)) {
        return true;
    } else {
        return false;
    }
}

bool operator<(Date D1, Date D2) 
    {
      if(D1.Day < D2.Day) {
        return true;
    } else if (D1.Day > D2.Day) {
        return false;
    } else {
        if(D1.Month < D2.Month) {
            return true;
        } else if(D1.Month > D2.Month) {
            return false;
        } else {
            if(D1.Year < D2.Year) {
                return true;
            } else if(D1.Year > D2.Year) {
                return false;
            }
        }
    }
    return true;
}

bool operator>(Date D1, Date D2) {
    if(D1.Day > D2.Day) {
        return true;
    } else if (D1.Day < D2.Day) {
        return false;
    } else {
        if(D1.Month > D2.Month) {
            return true;
        } else if(D1.Month < D2.Month) {
            return false;
        } else {
            if(D1.Year > D2.Year) {
                return true;
            } else if(D1.Year < D2.Year) {
                return false;
            }
        }
    }
    return true;
}

bool operator>=(Date D1, Date D2) {
    if(D1.Day >= D2.Day) {
        return true;
    } else if(D1.Day <= D2.Day) {
        return false;
    } else {
        if(D1.Month >= D2.Month) {
            return true;
        } else if(D1.Month <= D2.Month) {
            return false;
        } else {
            if(D1.Year >= D2.Year) {
                return true;
            } else if(D1.Year <= D2.Year) {
                return false;
            }
        }
    }
    return true;
}

bool operator<=(Date D1, Date D2) {
    if(D1.Day <= D2.Day) {
        return true;
    } else if(D1.Day >= D2.Day) {
        return false;
    } else {
        if(D1.Month <= D2.Month) {
            return true;
        } else if(D1.Month >= D2.Month) {
            return false;
        } else {
            if(D1.Year <= D2.Year) {
                return true;
            } else if(D1.Year >= D2.Year) {
                return false;
            }
        }
    }
    return true;
}

#endif