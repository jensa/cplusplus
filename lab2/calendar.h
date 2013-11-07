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
		T calendar;
		std::multimap<T, std::string> events;

	public:
	Calendar(){
		//Kompilerar bara om T ärver från basklassen Date
		calendar = T();
	}

	template<class S>
	Calendar(const Calendar<S> & copy){
		//Kompilerar bara om T ärver från basklassen Date
		calendar = copy.getCurrentDate();

		typename std::multimap<S, std::string>::iterator it;
		for (it = copy.getEvents().begin(); it != copy.getEvents().end(); ++it){
			add_event((*it).second, (*it).first);
		}
	}

	bool set_date(int year, int month, int day){
		try {
			calendar = T(year, month, day);
		} catch (std::out_of_range) {
			return false;
		}
		return true;
	}

	bool add_event(std::string name){
		return add_event(name, -1, -1, -1);
	}

	bool add_event(std::string name, int day){
		return add_event(name, day, -1, -1);
	}

	bool add_event(std::string name, int day, int month){
		return add_event(name, day, month, -1);
	}

	bool add_event(std::string name, int day, int month, int year){
		if (year == -1){
			year = calendar.year();
		}
		if (month == -1){
			month = calendar.month();
		}
		if (day == -1){
			day = calendar.day();
		}
		try {
			T d = new T(year, month, day);
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
		return remove_event(name, -1, -1, -1);
	}

	bool remove_event(std::string name, int day){
		return remove_event(name, day, -1, -1);
	}

	bool remove_event(std::string name, int day, int month){
		return remove_event(name, day, month, -1);
	}

	bool remove_event(std::string name, int day, int month, int year){
		if (year == -1){
			year = calendar.year();
		}
		if (month == -1){
			month = calendar.month();
		}
		if (day == -1){
			day = calendar.day();
		}

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
			if ((*it).first > calendar)
				stream << (*it).first.to_string() << " : " << (*it).second << std::endl;
		}
		return stream.str();
	}

	friend std::ostream& operator<<(std::ostream &os, const Calendar<T> & cal){
		os << cal.to_string();
		return os;
	}

	T getCurrentDate() const {
		return calendar;
	}

	std::multimap<T, std::string>getEvents() const {
		return events;
	}
	};
}
#endif