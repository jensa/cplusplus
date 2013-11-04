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

		~Gregorian();

		Gregorian & operator=(Date &d);
	protected:
		void set_date_from_JDN(long julian_day);
		void set_date (int year, int month, int day);
		bool is_leap_year (int year) const;
		
	private:
		bool calculate_leap (int year)const;
};
}
#endif