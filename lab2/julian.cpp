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

		int Julian::day()const{
			int year, month, day;
			get_dates(JDN(), year, month, day);
			return day;
		}


		int Julian::month()const{
			int year, month, day;
			get_dates(JDN(), year, month, day);
			return month;
		}


		int Julian::year()const{
			int year, month, day;
			get_dates(JDN(), year, month, day);
			return year;
		}

		void Julian::set_date_from_JDN(long julian_d){
			JDN_v = julian_d;
			
		}

		void Julian::get_dates (long JDN, int & year, int & month, int & day) const{
			
			// Calculate year, month and day.
			// Adaptation from 
			// http://www.tondering.dk/claus/cal/julperiod.php
			long b = 0;
			long c = JDN + 32082;
			long d = (4*c + 3) / 1461;
			long e = c - ((1461*d) / 4);
			long m = ((5*e + 2)/153);
			day = e - ((153*m + 2)/5) + 1;
			month = m + 3 - (12*(m/10));
			year = 100*b + d - 4800 + (m/10);
		}

		void Julian::set_date (int year, int month, int day){
			check_range(year, month, day);
			JDN_v = calculate_julian_day(year, month, day, true);
		}

		bool Julian::is_leap_year (int year) const{
			return year % 4 == 0;
		}
}