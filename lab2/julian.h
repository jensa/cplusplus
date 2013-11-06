#ifndef JULIAN
#define JULIAN
#include "european.h"

namespace lab2{
class Julian : public European{
	public:
		Julian();

		Julian (int year, int month, int day);

		Julian (const Date & d);

		Julian (const Date * d);

		//~Julian();

		Julian & operator=(const Date &d);
	protected:
		void set_date_from_JDN(long julian_day);
		void set_date (int year, int month, int day);
		bool is_leap_year (int year) const;
};
}
#endif