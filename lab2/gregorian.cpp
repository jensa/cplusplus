#include <iostream>
#include "gregorian.h"

namespace lab2{
		Gregorian::Gregorian(){
			set_date_today();
		}

		Gregorian::Gregorian (int year, int month, int day) {
			check_range(year, month, day);
			set_date (year, month, day);
		}

		Gregorian::Gregorian (const Date * d){
			set_date (d->year(), d->month(), d->day());
		}

		Gregorian::Gregorian (const Date & d){
			set_date (d.year(), d.month(), d.day());
		}

		Gregorian::~Gregorian(){}

		Gregorian & Gregorian::operator=(Date &d){
			set_date (d.year(), d.month(), d.day());
			return *this;
		}

		void Gregorian::set_date_from_JDN(long julian_d){
			long julian_day = julian_d;
			JDN_v = julian_day;
			// Calculate year, month and day.
			// Adaptation from 
			// http://www.tondering.dk/claus/cal/julperiod.php
			long a = julian_day + 32044;
			long b = ((4*a) + 3) / 146097;
			long c = a - ((146097*b)/4);
			long d = (4*c + 3) / 1461;
			long e = c - ((1461*d) / 4);
			long m = ((5*e + 2)/153);
			day_v = e - ((153*m + 2)/5) + 1;
			month_v = m + 3 - (12*(m/10));
			year_v = 100*b + d - 4800 + (m/10);
		}

		void Gregorian::set_date (int year, int month, int day){
			day_v = day;
			month_v = month;
			year_v = year;
			JDN_v= calculate_julian_day(year, month, day, false);
		}

		bool Gregorian::is_leap_year (int year) const{
			return calculate_leap(year);
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