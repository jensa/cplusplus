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

	public:
	T calendar_date;
	std::multimap<T, std::string> events;

	Calendar(){
		calendar_date = T();
	}

	template<class S>
	Calendar(const Calendar<S> & copy){
		calendar_date = copy.calendar_date;

		typename std::multimap<S, std::string>::const_iterator it;
		for (it = copy.events.begin(); it != copy.events.end(); ++it){
			add_event((*it).second, (*it).first);
		}
	}

	bool set_date(int year, int month, int day){
		try {
			calendar_date = T(year, month, day);
		} catch (std::out_of_range) {
			return false;
		}
		return true;
	}

	bool add_event(std::string name){
		return add_event(name, calendar_date.day(), calendar_date.month(), calendar_date.year());
	}

	bool add_event(std::string name, int day){
		return add_event(name, day, calendar_date.month(), calendar_date.year());
	}

	bool add_event(std::string name, int day, int month){
		return add_event(name, day, month, calendar_date.year());
	}

	bool add_event(std::string name, int day, int month, int year){
		try {
			T d(year, month, day);
			return add_event(name, d);
		} catch (std::out_of_range) {
			return false;
		}
	}

	bool add_event(std::string name, T d){
		std::pair<typename std::multimap<T,std::string>::iterator, typename std::multimap<T,std::string>::iterator> ret;
		ret = events.equal_range(d);
		typename std::multimap<T, std::string>::iterator it;
		
		for (it = ret.first; it != ret.second; ++it){
			if ((*it).second == name)
				return false;
		}

		events.insert(std::pair<T, std::string>(d, name));
		return true;
	}

	bool remove_event(std::string name){
		return remove_event(name, calendar_date.day(), calendar_date.month(), calendar_date.year());
	}

	bool remove_event(std::string name, int day){
		return remove_event(name, day, calendar_date.month(), calendar_date.year());
	}

	bool remove_event(std::string name, int day, int month){
		return remove_event(name, day, month, calendar_date.year());
	}

	bool remove_event(std::string name, int day, int month, int year){
		try {
			T d = new T(year, month, day);
			return remove_event(name, d);
		} catch (std::out_of_range) {
			return false;
		}
	}

	bool remove_event(std::string name, T d){
		std::pair<typename std::multimap<T, std::string>::iterator, typename std::multimap<T, std::string>::iterator> ret;
		ret = events.equal_range(d);
		typename std::multimap<T, std::string>::iterator it;
		
		for (it = ret.first; it != ret.second; ++it){
			if ((*it).second == name){
				events.erase(it);
				return true;
			}
		}
		return false;
	}

	std::string to_string() const{
		std::stringstream stream;
		typename std::multimap<T, std::string>::const_iterator it;

		for (it = events.begin(); it != events.end(); ++it){
			if ((*it).first > calendar_date)
				stream << (*it).first.to_string() << " : " << (*it).second << std::endl;
		}
		return stream.str();
	}

	friend std::ostream& operator<<(std::ostream &os, const Calendar<T> & cal){
		os << cal.to_string();
		return os;
	}
	};
}
#endif