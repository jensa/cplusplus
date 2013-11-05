#include "calendar.h"

namespace lab2{

	template<class T>
	Calendar<T>::Calendar(){
		//Kompilerar bara om T tillhör basklassen Date
		calendar = new T();
	}

	template<class T>
	bool Calendar<T>::set_date(int year, int month, int day){
		calendar -> set_date(year, month, day);
		//TODO: Returnera false om kalendern blir jätteledsen och kastar out of range eller nåt
		return true;
	}

	template<class T>
	bool Calendar<T>::add_event(std::string name){
		return add_event(name, -1, -1, -1);
	}

	template<class T>
	bool Calendar<T>::add_event(std::string name, int year){
		return add_event(name, year, -1, -1);
	}

	template<class T>
	bool Calendar<T>::add_event(std::string name, int year, int month){
		return add_event(name, year, month, -1);
	}

	template<class T>
	bool Calendar<T>::add_event(std::string name, int year, int month, int day){
		if (year == -1 || month == -1 || day == -1){
			set_date(year, month, day);
		}
		return false;
	}
}

int main(){
	time_t mytime;
    time(&mytime);
    set_k_time(mytime);
	lab2::Calendar<lab2::Julian> julian_cal;
	julian_cal.set_date(2013, 12, 24);
	return 0;
}

