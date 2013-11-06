#ifndef CALENDAR
#define CALENDAR

#include <iostream>
#include <sstream>
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
		std::multimap<std::string, T> events;

	public:
		Calendar();
		template<class S>
		Calendar (const Calendar<S> &);
		bool set_date(int year, int month, int day);
		bool add_event(std::string);
		bool add_event(std::string, int day);
		bool add_event(std::string, int day, int month);
		bool add_event(std::string, int day, int month, int year);
		bool remove_event(std::string);
		bool remove_event(std::string, int day);
		bool remove_event(std::string, int day, int month);
		bool remove_event(std::string, int day, int month, int year);
		std::string to_string() const;
		template<class D>
		friend std::ostream & operator<<(std::ostream &os, const Calendar<D>& cal);
		Date* getCurrentDate();
		std::multimap<std::string, T> getEvents();
	};
}
#endif