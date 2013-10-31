#ifndef GREGORIAN
#define GREGORIAN
#include "european.h"

namespace lab2{
class Gregorian : public European{
	public:
		Gregorian();

		Gregorian (int year, int month, int day);

		Gregorian (Date & d);

		Gregorian (Date * d);

		~Gregorian();

		Gregorian & operator=(Date &d);
	protected:
		void set_date_from_mod_julian_day(int mod);
		void set_date (int year, int month, int day);
		bool is_leap_year () const;
		
	private:
		bool calculate_leap (int year)const;
};
}
#endif