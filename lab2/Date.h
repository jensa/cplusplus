#include <iostream>
#include <sstream>

namespace lab2 {


class Date {

	int year_v;
	int month_v;
	int day_v;
	int days_per_week_v;
	int months_per_year_v;

	public:
	 int year ()const{ return year_v;}
	 int month ()const {return month_v;}
	 int day () const { return day_v;}
	 int days_per_week () const{ return days_per_week_v;}
	 int months_per_year () const{return months_per_year_v;}
	 //returns the current year after the operation
	 int add_year (int n){
	 	year_v += n;
	 	return year_v;
	 }
	 std::string to_string () const{
	 	std::stringstream stream;
	 	stream << year () << "-" << month () << "-" << day ();
	 	return stream.str();
	 }

	 virtual int week_day () const= 0;
	 virtual int days_this_month () const= 0;
	 virtual int mod_julian_day () const = 0;
	 virtual std::string week_day_name () const;
	 virtual std::string month_name () const;

	 
	 //returns the current month after the operation
	 virtual int add_month (int n);

	 lab2::Date & operator++() {
	 	increment_day (1);
	 	return *this;
 	 };

 	 lab2::Date & operator++(int wat) {
	 	increment_day (1);
	 	return *this;
 	 };

 	 lab2::Date & operator--(){
 	 	decrement_day(1);
 	 	return *this;
 	 }
 	 lab2::Date & operator +=(int num){
 	 	increment_day(num);
 	 	return *this;
 	 }

 	 lab2::Date & operator -=(int num){
 	 	decrement_day(num);
 	 	return *this;
 	 }

 	 bool operator ==(const Date & d){
 	 	return mod_julian_day() == d.mod_julian_day();
 	 }

 	 bool operator !=(const Date & d){
 	 	return mod_julian_day() != d.mod_julian_day();
 	 }

 	 bool operator <(const Date & d){
 	 	return mod_julian_day() < d.mod_julian_day();
 	 }

 	 bool operator <=(const Date & d){
 	 	return mod_julian_day() <= d.mod_julian_day();
 	 }

 	 bool operator >(const Date & d){
 	 	return mod_julian_day() > d.mod_julian_day();
 	 }

 	 bool operator >=(const Date & d){
 	 	return mod_julian_day() >= d.mod_julian_day();
 	 }

 	 int operator -(const Date & d){
 	 	return mod_julian_day() - d.mod_julian_day();
 	 }

 	 friend std::ostream & operator<<(std::ostream &os, const Date& d);

	protected:
	 virtual void increment_day (int num);
	 virtual void decrement_day (int num);

	 
};

std::ostream& operator<<(std::ostream& os, const Date & d){
	return os << d.to_string ();
}
}



