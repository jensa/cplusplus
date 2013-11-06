#include "calendar.h"

namespace lab2{

	template<class T>
	Calendar<T>::Calendar(){
		//Kompilerar bara om T ärver från basklassen Date
		calendar = new T();
	}

	template<class T>
	template<class S>
	Calendar<T>::Calendar(const Calendar<S> & copy){
		//Kompilerar bara om T ärver från basklassen Date
		calendar = copy.getCurrentDate();
		events = copy.getEvents();
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
	bool Calendar<T>::add_event(std::string name, int day){
		return add_event(name, day, -1, -1);
	}

	template<class T>
	bool Calendar<T>::add_event(std::string name, int day, int month){
		return add_event(name, day, month, -1);
	}

	template<class T>
	bool Calendar<T>::add_event(std::string name, int day, int month, int year){
		if (year == -1){
			year = calendar -> year();
		}
		if (month == -1){
			month = calendar -> month();
		}
		if (day == -1){
			day = calendar -> day();
		}

		std::pair<typename std::multimap<std::string,T>::iterator, typename std::multimap<std::string,T>::iterator> ret;
		ret = events.equal_range(name);
		typename std::multimap<std::string,T>::iterator it;
		
		for (it = ret.first; it != ret.second; ++it){
			if ((*it).second.day() == day && (*it).second.month() == month && (*it).second.year() == year)
				return false;
		}

		events.insert(std::pair<std::string, T>(name, new T(year, month, day)));
		return true;
	}

	template<class T>
	bool Calendar<T>::remove_event(std::string name){
		return remove_event(name, -1, -1, -1);
	}

	template<class T>
	bool Calendar<T>::remove_event(std::string name, int day){
		return remove_event(name, day, -1, -1);
	}

	template<class T>
	bool Calendar<T>::remove_event(std::string name, int day, int month){
		return remove_event(name, day, month, -1);
	}

	template<class T>
	bool Calendar<T>::remove_event(std::string name, int day, int month, int year){
		if (year == -1){
			year = calendar -> year();
		}
		if (month == -1){
			month = calendar -> month();
		}
		if (day == -1){
			day = calendar -> day();
		}

		std::pair<typename std::multimap<std::string,T>::iterator, typename std::multimap<std::string,T>::iterator> ret;
		ret = events.equal_range(name);
		typename std::multimap<std::string,T>::iterator it;
		
		for (it = ret.first; it != ret.second; ++it){
			if ((*it).second.day() == day && (*it).second.month() == month && (*it).second.year() == year){
				events.erase(it);
				return true;
			}
		}
		return false;
	}

	template<class T>
	std::string Calendar<T>::to_string() const{
		std::stringstream stream;
		typename std::multimap<std::string, T>::const_iterator it;

		for (it = events.begin(); it != events.end(); ++it){
			if ((*it).second >= *calendar)
				stream << (*it).second.to_string() << " : " << (*it).first << std::endl;
		}
		return stream.str();
	}

	template<class T>
	std::ostream& operator<<(std::ostream &os, const Calendar<T> & cal){
		os << cal.to_string();
		return os;
	}

	template<class T>
	Date* Calendar<T>::getCurrentDate(){
		return calendar;
	}

	template<class T>
	std::multimap<std::string, T>Calendar<T>::getEvents(){
		return events;
	}
}

