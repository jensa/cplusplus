#include <iostream>

namespace lab2 {


class Date {

	public:
	 virtual int week_day () = 0;
	 virtual int days_this_month () = 0;
	 virtual std::string week_day_name ();
	 virtual std::string month_name ();

	 Date & Date::operator++(const Date & date) {

	 	 }
};
}



