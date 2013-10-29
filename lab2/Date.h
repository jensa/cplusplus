#include <iostream>
#include <sstream>
//Days between Nov 17 1858 and Jan 1 1970.
#define MOD_JULIAN_UNIX_DAYS 40587

namespace lab2 {

class Date {

	public:
		//returns the current year after the operation
		int add_year (int n){
			int year_v = year ();
			int new_year = year_v + n;
			set_date (day(), month (), new_year);
			return year ();
		}
		std::string to_string () const{
			std::stringstream stream;
			stream << year () << "-" << month () << "-" << day ();
			return stream.str();
		}
		int mod_julian_day () const {
			return mod_julian;
		}
		
		virtual int days_per_week () const;
		virtual int months_per_year () const;
		virtual int add_month ();
		virtual int week_day () const= 0;
		virtual int days_this_month () const= 0;
		virtual int day () const;
		virtual int month () const;
		virtual int year () const; 
		virtual void set_date (int day, int month, int year);
		virtual std::string week_day_name () const;
		virtual std::string month_name () const;
	
		//returns the current month after the operation
		virtual int add_month (int n) {
			for (int i = 0;i<n;i++)
				add_month();
			return month ();
		}

		Date & operator++() {
			modify_day (1);
			return *this;
 		};
 		Date & operator--(){
 			modify_day(-1);
 			return *this;
 		}
 		Date & operator +=(int num){
 			modify_day(num);
 			return *this;
 		}
 		Date & operator -=(int num){
 			modify_day(-num);
 			return *this;
 		}
 		bool operator ==(const Date & d) const{
 			return mod_julian_day() == d.mod_julian_day();
 		}
 		bool operator !=(const Date & d) const{
 			return mod_julian_day() != d.mod_julian_day();
 		}
 		bool operator <(const Date & d) const{
 			return mod_julian_day() < d.mod_julian_day();
 		}
 		bool operator <=(const Date & d) const{
 			return mod_julian_day() <= d.mod_julian_day();
 		}
 		bool operator >(const Date & d) const{
 			return mod_julian_day() > d.mod_julian_day();
 		}
 		bool operator >=(const Date & d) const{
 			return mod_julian_day() >= d.mod_julian_day();
 		}
 		int operator -(const Date & d) const{
 			return mod_julian_day() - d.mod_julian_day();
 		}
 		friend std::ostream & operator<<(std::ostream &os, const Date& d);

	protected:
		virtual void modify_day (int num);
		virtual bool is_leap_year () const;
		virtual bool is_next_year_leap_year () const;
		int mod_julian;

	 
};

std::ostream& operator<<(std::ostream& os, const Date & d){
	return os << d.to_string ();
}
}



