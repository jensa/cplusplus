#include "Date.h"
#include "kattistime.h"

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

		int days_per_week () const;
		int months_per_year () const;
		std::string week_day_name () const;
		std::string month_name () const;
		int week_day () const;
		int days_this_month () const;
		int days_next_month () const;
		int calculate_julian_day (int year, int month, int day, bool Julian) const;
		void set_date_today ();
		void modify_day (int num);
		int add_month ();
		virtual void set_date_from_mod_julian_day(int mod);
};
}