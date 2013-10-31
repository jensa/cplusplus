#include <iostream>
#include "gregorian.h"

namespace lab2{
		Gregorian::Gregorian(){
			set_date_today();
		}

		Gregorian::Gregorian (int year, int month, int day) {
			set_date (year, month, day);
		}

		Gregorian::Gregorian (Date * d){
			set_date (d->year(), d->month(), d->day());
		}

		Gregorian::Gregorian (Date & d){
			set_date (d.year(), d.month(), d.day());
		}

		Gregorian::~Gregorian(){}

		Gregorian & Gregorian::operator=(Date &d){
			set_date (d.year(), d.month(), d.day());
			return *this;
		}

		void Gregorian::set_date_from_mod_julian_day(int mod){
			mod_julian = mod;
			// Calculate year, month and day.
			// Adaptation from 
			// http://www.tondering.dk/claus/cal/julperiod.php
			int julian_day = mod + MOD_JULIAN_DAYS;
			int a = julian_day + 32044;
			int b = ((4*a) + 3) / 146097;
			int c = a - ((146097*b)/4);
			int d = (4*c + 3) / 1461;
			int e = c - ((1461*d) / 4);
			int m = ((5*e + 2)/153);

			day_v = e - ((153*m + 2)/5) + 1;
			month_v = m + 3 - (12*(m/10));
			year_v = 100*b + d - 4800 + (m/10);
		}

		void Gregorian::set_date (int year, int month, int day){
			day_v = day;
			month_v = month;
			year_v = year;
			mod_julian = calculate_julian_day(year, month, day, true);
		}

		bool Gregorian::is_leap_year () const{
			return calculate_leap(year ());
		}
		bool Gregorian::calculate_leap (int y) const{
			if (y % 400 == 0)
				return true;
			if (y % 100 == 0)
				return false;
			if (y % 4 == 0)
				return true;
			return false;
		}
}