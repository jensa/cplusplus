#include <iostream>
#include "julian.h"

namespace lab2{
		Julian::Julian(){
			set_date_today();
		}

		Julian::Julian (int year, int month, int day) {
			set_date (year, month, day);
		}

		Julian::Julian (Date & d){
			set_date (d.year(), d.month(), d.day());
		}

		Julian::Julian (Date * d){
			set_date (d->year(), d->month(), d->day());
		}

		Julian::~Julian(){}

		Julian & Julian::operator=(Date &d){
			set_date (d.year(), d.month(), d.day());
			return *this;
		}

		void Julian::set_date_from_mod_julian_day(int mod){
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

		void Julian::set_date (int year, int month, int day){
			day_v = day;
			month_v = month;
			year_v = year;
			mod_julian = calculate_julian_day(year, month, day, true);
		}

		bool Julian::is_leap_year () const{
			return year () % 4 == 0;
		}
}