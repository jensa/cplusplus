#include "European.h"

namespace lab2{
		int European::days_per_week () const{
			return 7;
		}
		int European::months_per_year () const{
			return 12;
		}

		std::string European::week_day_name () const{
			return European::day_names[week_day() -1];
		}

		std::string European::month_name () const{
			return month_names[month () - 1];
		}

		int European::week_day () const{
			return (mod_julian % days_per_week())+1;
		}

		int European::days_this_month () const{
			int days = days_in_months[month()-1];
			if (is_leap_year())
				return days+1;
			return days;
		}

		int European::days_next_month () const{
			int next = month () + 1;
			if (month () == months_per_year())
				next = 1;
			int days = days_in_months[next-1];
			if (next > 1){
				if(is_leap_year())
					return days+1;
				return days;
			} else if (next == 1){
				if(is_next_year_leap_year())
					return days+1;
				return days;
			}
			return -1;
		}

		int European::calculate_julian_day (int year, 
			int month, int day, bool julian)const{
			int a = (14 - month) / 12;
			int y = year + 4800 - a;
			int m = month + (12*a) - 3;
			int JDN;
			if (julian)
				JDN = day + ((153*m + 2)/5) + (365*y)+ (y/4) -32083;
			else
				JDN = day + ((153*m + 2)/5) + (365*y)+ (y/4) - (y/100) + (y/400) -32045;
			return JDN - MOD_JULIAN_DAYS;
		}

		void European::set_date_today (){
			int days_since_unix_time = k_time(0) / (24*60*60);
			int mod_julian_date = days_since_unix_time + MOD_JULIAN_UNIX_DAYS;
			set_date_from_mod_julian_day(mod_julian_date);
		}

		void European::modify_day (int num){
			int new_day = mod_julian_day() + num;
			set_date_from_mod_julian_day(new_day);
		}

}