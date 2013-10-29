#include "Date.h"

namespace lab2{
class European : public Date{
	protected:
		std::string day_names[7] = {
		"monday", "tuesday","wednesday", "thursday", 
		"friday", "saturday", "sunday" };

		std::string month_names[12] = {
			"january", "february", "march", "april", "may",
			"june", "july", "august", "september", "october",
			"november", "december" };

		int days_in_months[12] = {
			31,28,31,30,31,30,31,
			31,30,31,30,31};

		int wat = 2;
		virtual int days_per_week () const{
			return 7;
		}
		virtual int months_per_year () const{
			return 12;
		}

		std::string week_day_name () const{
			return day_names[week_day() -1];
		}
		std::string month_name () const{
			return month_names[month () - 1];
		}

		int week_day () const{
			return (mod_julian % days_per_week())+1;
		}
		int days_this_month () const{
			int days = days_in_months[month()-1];
			if (is_leap_year())
				return days+1;
			return days;
		}

		int days_next_month (){
			int next = month () + 1;
			if (month () == months_per_year())
				next = 1;
			int days = days_in_months[next-1];
			if (next > 1){
				if(is_leap_year())
					return days+1;
				return days;
			} else if (next == 1){
				if(is_next_year_leap_year())
					return days+1;
				return days;
			}
		}


};
}