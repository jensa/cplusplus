#ifndef EUROPE
#define EUROPE
#include <vector>
#include "date.h"
#include "kattistime.h"

namespace lab2{
class European : public Date{

	protected:
		std::vector<std::string> day_names;
		std::vector<std::string> month_names;
		int days_in_months[12];
		European (){
			day_names.push_back("monday");
			day_names.push_back("tuesday");
			day_names.push_back("wednesday");
			day_names.push_back("thursday");
			day_names.push_back("friday");
			day_names.push_back("saturday");
			day_names.push_back("sunday");

			month_names.push_back("january");
			month_names.push_back("february");
			month_names.push_back("march");
			month_names.push_back("april");
			month_names.push_back("may");
			month_names.push_back("june");
			month_names.push_back("july");
			month_names.push_back("august");
			month_names.push_back("september");
			month_names.push_back("october");
			month_names.push_back("november");
			month_names.push_back("december");

			days_in_months[0] = 31;
			days_in_months[1] = 28;
			days_in_months[2] = 31;
			days_in_months[3] = 30;
			days_in_months[4] = 31;
			days_in_months[5] = 30;
			days_in_months[6] = 31;
			days_in_months[7] = 31;
			days_in_months[8] = 30;
			days_in_months[9] = 31;
			days_in_months[10] = 30;
			days_in_months[11] = 31;
		}

		int days_per_week () const;
		int months_per_year () const;
		std::string week_day_name () const;
		std::string month_name () const;
		int week_day () const;
		int days_this_month () const;
		int days_next_month () const;
		int days_previous_month () const;
		int calculate_julian_day (int year, int month, int day, bool Julian) const;
		void set_date_today ();
		void modify_day (int num);
		int add_month ();
		int subtract_month ();
		virtual void set_date (int day, int month, int year)=0;
		virtual bool is_leap_year () const=0;
		virtual void set_date_from_mod_julian_day(int mod)=0;
};
}
#endif