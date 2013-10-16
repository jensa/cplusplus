#include <iostream>

namespace lab2 {


class Date {

	int year_v;
	int month_v;
	int day_v;
	int days_per_week_v;
	int months_per_year_v;

	public:
	 int year (){ return year_v;}
	 int month () {return month_v;}
	 int day () { return day_v;}
	 int days_per_week () { return days_per_week_v;}
	 int months_per_year () {return months_per_year_v;}
	 virtual int week_day () = 0;
	 virtual int days_this_month () = 0;
	 virtual std::string week_day_name ();
	 virtual std::string month_name ();
};
}



