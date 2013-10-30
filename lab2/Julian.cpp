#include <iostream>
#include "European.h"

namespace lab2{
class Julian : European{
	public:
		Julian(){
			set_date_today();
		}

		Julian (int year, int month, int day) {
			set_date (year, month, day);
		}

		Julian (Date & d){
			set_date (d.year(), d.month(), d.day());
		}

		~Julian(){}

		Julian & operator=(Date &d){
			set_date (d.year(), d.month(), d.day());
			return *this;
		}

		int add_month () {
			if (day () > days_next_month ()){
				modify_day(30);
				return month ();
			}
			int new_month = month () + 1;
			int new_year = year ();
			if (new_month > months_per_year()){
				new_month = 1;
				new_year++;
			}
			set_date (new_year, new_month, day ());
			return month ();
		}
	protected:

		void set_date_from_mod_julian_day(int mod){
			mod_julian = mod;
			// Calculate year, month and day.
			// Adaptation from 
			// http://www.tondering.dk/claus/cal/julperiod.php
			int julian_day = mod + MOD_JULIAN_DAYS;
			int b = 0;
			int c = julian_day + 32082;
			int d = (4*c + 3) / 1461;
			int e = c - ((1461*d) / 4);
			int m = ((5*e + 2)/153);

			day_v = e - ((153*m + 2)/5) + 1;
			month_v = m + 3 - (12*(m/10));
			year_v = 100*b + d - 4800 + (m/10);
		}

		void set_date (int year, int month, int day){
			day_v = day;
			month_v = month;
			year_v = year;
			mod_julian = calculate_julian_day(year, month, day, true);
		}

		bool is_leap_year () const{
			return year () % 4 == 0;
		}

		bool is_next_year_leap_year () const{
			return (year () +1) % 4 == 0;
		}
};
}