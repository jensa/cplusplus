#include <iostream>
#include "julian.h"

namespace lab2{
		Julian::Julian(){
			set_date_today();
		}

		Julian::Julian (int year, int month, int day) {
			check_range(year, month, day);
			set_date (year, month, day);
		}

		Julian::Julian (const Date & d){
			if (this == &d) {
    			return;
  			}
			set_date_from_JDN(d.JDN());
		}
		
		Julian::Julian (const Date * d){
			set_date_from_JDN(d->JDN());
		}

		//Julian::~Julian(){}

		Julian & Julian::operator=(const Date &d){
			if (this == &d) {
    			return *this;
  			}
			set_date_from_JDN(d.JDN());
			return *this;
		}

		void Julian::set_date_from_JDN(long julian_d){
			long julian_day = julian_d;
			JDN_v = julian_day;
			// Calculate year, month and day.
			// Adaptation from 
			// http://www.tondering.dk/claus/cal/julperiod.php
			long b = 0;
			long c = julian_day + 32082;
			long d = (4*c + 3) / 1461;
			long e = c - ((1461*d) / 4);
			long m = ((5*e + 2)/153);
			day_v = e - ((153*m + 2)/5) + 1;
			month_v = m + 3 - (12*(m/10));
			year_v = 100*b + d - 4800 + (m/10);
		}

		void Julian::set_date (int year, int month, int day){
			day_v = day;
			month_v = month;
			year_v = year;
			JDN_v = calculate_julian_day(year, month, day, true);
		}

		bool Julian::is_leap_year (int year) const{
			return year % 4 == 0;
		}
}