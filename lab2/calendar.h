#include <iostream>
#include <stdarg.h>
#include <map>
#include "date.h"
#include "julian.h"
#include "gregorian.h"

namespace lab2{
	template<class T>
	class Calendar {

	private:
		Date* calendar;

	public:
		Calendar();
		bool set_date(int year, int month, int day);
		bool add_event(std::string);
		bool add_event(std::string, int year);
		bool add_event(std::string, int year, int month);
		bool add_event(std::string, int year, int month, int day);
	};
}

