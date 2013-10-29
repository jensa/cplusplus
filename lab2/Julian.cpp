#include <iostream>
#include "European.h"
#include "kattistime.h"

namespace lab2{
class Julian : European{
	public:
		Julian(){
			set_date_today();
		}

		Julian (int year, int month, int day) {
			set_date (year, month, day);
		}

		Julian (Date & d){
			calculate_and_set_date(d.mod_julian_day());
		}

		~Julian(){}

		Julian & operator=(Date &d){
			calculate_and_set_date(d.mod_julian_day());
			return *this;
		}

		int add_month () {
			if (day () > days_next_month ()){
				modify_day(30);
				return month ();
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

		virtual int day () const;
		virtual int month () const;
		virtual int year () const; 

	private:

		void calculate_and_set_date (int mod_julian){

		}

		void set_date (int year, int month, int day){

		}

		void set_date_today (){
			int days_since_unix_time = k_time(0) / (24*60*60);
			int mod_julian_date = days_since_unix_time + MOD_JULIAN_UNIX_DAYS;
			calculate_and_set_date(mod_julian_date);
		}
	protected:
		void modify_day (int num){
			int new_day = mod_julian_day() + num;
			calculate_and_set_date(new_day);
		}

		bool is_leap_year () const{
			return year () % 4 == 0;
		}

		bool is_next_year_leap_year () const{
			return (year () +1) % 4 == 0;
		}

};
}