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
			return ((JDN_v) % days_per_week())+1;
		}

		int European::days_in_month (int month, int year) const{
			int days = days_in_months[month-1];
			if (is_leap_year(year) && month == 2)
				return days+1;
			return days;
		}

		int European::days_this_month () const{
			return days_in_month (month(), year());
		}

		int European::days_next_month () const{
			int next = month () + 1;
			if (month () == months_per_year())
				next = 1;
			int days = days_in_months[next-1];
			if (next == 2 && is_leap_year(year()))
				days++;
			return days;
		}

		int European::days_previous_month () const{
			int prev = month () - 1;
			if (month () == 0)
				prev = months_per_year();
			int days = days_in_months[prev-1];
			if (prev == 2 && is_leap_year(year()))
				days++;
			return days;
		}

		//returns the current year after the operation
		int European::add_year (int n){
			int new_day = day ();
			if (!is_leap_year(year()+n) && day () == 29 && month() == 2)
				new_day = 28;
			int new_year = year () + n;
			set_date (new_year, month (), new_day);
			return year ();
		}



		long European::calculate_julian_day (int year, 
			int month, int day, bool julian)const{
			long a = (14 - month) / 12;
			long y = year + 4800 - a;
			long m = month + (12*a) - 3;
			long jul_day;
			if (julian)
				jul_day = day + ((153*m + 2)/5) + (365*y)+ (y/4) -32083;
			else
				jul_day = day + ((153*m + 2)/5) + (365*y)+ (y/4) - (y/100) + (y/400) -32045;
			return jul_day;
		}

		void European::set_date_today (){
			long days_since_unix_time = k_time(0) / (24*60*60);
			long julian_day = days_since_unix_time + MOD_JULIAN_UNIX_DAYS+ MOD_JULIAN_DAYS;
			set_date_from_JDN(julian_day);
		}

		void European::modify_day (int num){
			long new_day = JDN () + num;
			set_date_from_JDN(new_day);
		}

		int European::add_month () {
			int new_month = (month () +1 ) % 13;
			int new_year = year ();
			if (new_month == 0){
				new_month++;
				new_year++;
			}
			if (days_in_month (new_month, new_year) < day())
				modify_day(30);
			else
				set_date(new_year, new_month, day());
			return month ();
		}

		int European::subtract_month(){
			int new_month = (month () -1 ) % 13;
			int new_year = year ();
			if (new_month == 0){
				new_month = 12;
				new_year--;
			}
			if (days_in_month (new_month, new_year) < day())
				modify_day(-30);
			else
				set_date(new_year, new_month, day());
			return month ();
		}

		void European::check_range (int year, int month, int day)const {
			if (year < 1 || month < 1 || day < 1)
				throw std::out_of_range("Out of range! < 1");
			if(month > months_per_year())
				throw std::out_of_range("Out of range! > months_per_year");
			if(day != 29 && day > days_in_month(month, year))
				throw std::out_of_range("Out of range! > days_in_month");
			else if (day == 29 && month == 2 && !is_leap_year(year))
				throw std::out_of_range("Out of range! lolfi");
		}

}