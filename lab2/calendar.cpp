#include "calendar.h"

namespace lab2{

	Calendar::Calendar(){}

	bool Calendar::set_date(int year, int month, int day){
		return false;
	}

	bool Calendar::add_event(std::string name){
		return add_event(name, -1, -1, -1);
	}

	bool Calendar::add_event(std::string name, int year){
		return add_event(name, year, -1, -1);
	}

	bool Calendar::add_event(std::string name, int year, int month){
		return add_event(name, year, month, -1);
	}

	bool Calendar::add_event(std::string name, int year, int month, int day){
		if (year == -1 || month == -1 || day == -1){
			//Sätt dagens datum vafan
		}
		return false;
	}
}

int main(){
		lab2::Calendar cal;
		cal.add_event("lolfi",1,2,3);
		return 0;
}

