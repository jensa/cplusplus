#include "date.h"

namespace lab2 {
		Date::Date(){}
		Date::Date(Date& d){}
		
		std::string Date::to_string () const{
			std::stringstream stream;
			stream << year () << "-" << month () << "-" << day ();
			return stream.str();
		}
		int Date::mod_julian_day () const {
			return JDN_v - 2400001;
		}

		int Date::day () const{
			return day_v;
		}

		int Date::month () const{
			return month_v;
		}

		int Date::year () const{
			return year_v;
		}
	
		//returns the current month after the operation
		int Date::add_month (int n) {
			if (n > 0){
				for (int i = 0;i<n;i++)
					add_month();
			} else{
				int en = n*-1;
				for (int i=0;i<en;i++){
					subtract_month ();
				}
			}
			return month ();
		}

		Date & Date::operator++() {
			modify_day (1);
			return *this;
 		};
 		Date & Date::operator--(){
 			modify_day(-1);
 			return *this;
 		}
 		Date & Date::operator +=(int num){
 			modify_day(num);
 			return *this;
 		}
 		Date & Date::operator -=(int num){
 			modify_day(-num);
 			return *this;
 		}
 		bool Date::operator ==(const Date & d) const{
 			return mod_julian_day() == d.mod_julian_day();
 		}
 		bool Date::operator !=(const Date & d) const{
 			return mod_julian_day() != d.mod_julian_day();
 		}
 		bool Date::operator <(const Date & d) const{
 			return mod_julian_day() < d.mod_julian_day();
 		}
 		bool Date::operator <=(const Date & d) const{
 			return mod_julian_day() <= d.mod_julian_day();
 		}
 		bool Date::operator >(const Date & d) const{
 			return mod_julian_day() > d.mod_julian_day();
 		}
 		bool Date::operator >=(const Date & d) const{
 			return mod_julian_day() >= d.mod_julian_day();
 		}
 		int Date::operator -(const Date & d) const{
 			return mod_julian_day() - d.mod_julian_day();
 		}		

	std::ostream& operator<<(std::ostream& os, const Date & d){
		return os << d.to_string ();
	}
}



