#ifndef JULIAN
#define JULIAN
#include "european.h"

namespace lab2{
class Julian : public European{
	public:
		Julian();

		Julian (int year, int month, int day);

		Julian (Date & d);

		Julian (Date * d);

		~Julian();

		Julian & operator=(Date &d);
	protected:
		void set_date_from_mod_julian_day(int mod);
		void set_date (int year, int month, int day);
		bool is_leap_year () const;
};
}
#endif