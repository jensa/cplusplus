#include <iostream>
#include "European.h"

namespace lab2{
class Gregorian : European{
	public:
		Gregorian();

		Gregorian (int year, int month, int day);

		Gregorian (Date & d);

		~Gregorian();

		Gregorian & operator=(Date &d);
		int add_month ();
	protected:
		void set_date_from_mod_julian_day(int mod);
		void set_date (int year, int month, int day);
		bool is_leap_year () const;
		bool is_next_year_leap_year () const;
};
}