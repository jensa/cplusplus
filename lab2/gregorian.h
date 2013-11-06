#ifndef GREGORIAN
#define GREGORIAN
#include "european.h"

namespace lab2{
class Gregorian : public European{
	public:
		Gregorian();

		Gregorian (int year, int month, int day);

		Gregorian (const Date & d);

		Gregorian (const Date * d);

		int day() const;
		int month()const;
		int year() const;

		//~Gregorian();

		Gregorian & operator=(const Date &d);
	protected:
		void set_date_from_JDN(long julian_day);
		void set_date (int year, int month, int day);
		bool is_leap_year (int year) const;
		void get_dates (long JDN, int & year, int & month, int & day)const;
		
	private:
		bool calculate_leap (int year)const;
};
}
#endif