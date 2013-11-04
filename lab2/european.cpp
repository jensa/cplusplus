#include "european.h"

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
			return ((mod_julian_day()+3) % days_per_week());
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
			if (next == 2 && is_leap_year())
				days++;
			return days;
		}

		int European::days_previous_month () const{
			int prev = month () - 1;
			if (month () == 0)
				prev = months_per_year();
			int days = days_in_months[prev-1];
			if (prev == 2 && is_leap_year())
				days++;
			return days;
		}

		//returns the current year after the operation
		int European::add_year (int n){
			int new_day = day ();
			if (is_leap_year() && day () == 29)
				new_day = 1;
			int new_year = year () + n;
			set_date (new_year, month (), new_day);
			return year ();
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
			return JDN;
		}

		void European::set_date_today (){
			int days_since_unix_time = k_time(0) / (24*60*60);
			int julian_day = days_since_unix_time + MOD_JULIAN_UNIX_DAYS+ MOD_JULIAN_DAYS;
			set_date_from_JDN(julian_day);
		}

		void European::modify_day (int num){
			int new_day = JDN () + num;
			set_date_from_JDN(new_day);
		}

		int European::add_month () {
			if (day () > days_next_month ()){
				if (is_leap_year() && day() ==29 && month() == 1){
				} else{
					modify_day(30);
					return month ();
				}
			}
			int new_month = month () + 1;
			int new_year = year ();
			if (new_month > months_per_year()){
				new_month = 1;
				new_year++;
			}
			set_date (new_year, new_month, day ());
			return month ();
		}

		int European::subtract_month(){
			if (day () > days_previous_month ()){
				if (is_leap_year() && day() ==29 && month() == 3){
				} else{
					modify_day(30);
					return month ();
				}
			}
			int new_month = month () - 1;
			int new_year = year ();
			if (new_month > months_per_year()){
				new_month = 1;
				new_year++;
			}
			set_date (new_year, new_month, day ());
			return month ();
		}

}