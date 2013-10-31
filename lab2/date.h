#ifndef DATE
#define DATE
#include <iostream>
#include <sstream>
#include "kattistime.h"
//Days between Nov 17 1858 and Jan 1 1970.
#define MOD_JULIAN_UNIX_DAYS 40587
//this might lead to truncation errors, consider putting it at +0.5
#define MOD_JULIAN_DAYS 2400001

namespace lab2 {

class Date {

	public:
		Date();
		Date(Date & d);
		//returns the current year after the operation
		int add_year (int n);
		std::string to_string () const;
		int mod_julian_day () const;
		int day () const;
		int month () const;
		int year () const;
		virtual int days_per_week () const=0;
		virtual int months_per_year () const=0;
		virtual int add_month ()=0;
		virtual int subtract_month ()=0;
		virtual int week_day () const=0;
		virtual int days_this_month () const=0;
		virtual std::string week_day_name () const=0;
		virtual std::string month_name () const=0;
		//returns the current month after the operation
		int add_month (int n);
		Date & operator++();
 		Date & operator--();
 		Date & operator +=(int num);
 		Date & operator -=(int num);
 		bool operator ==(const Date & d) const;
 		bool operator !=(const Date & d) const;
 		bool operator <(const Date & d) const;
 		bool operator <=(const Date & d) const;
 		bool operator >(const Date & d) const;
 		bool operator >=(const Date & d) const;
 		int operator -(const Date & d) const;
 		friend std::ostream & operator<<(std::ostream &os, const Date& d);

	protected:
		virtual void set_date (int day, int month, int year)=0;
		virtual void modify_day (int num)=0;
		virtual bool is_leap_year () const=0;
		int mod_julian;
		int day_v;
		int month_v;
		int year_v;
};
}

#endif

