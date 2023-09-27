#include "time.h"





	void Time::time_corection(){
		while(this->seconds >= 60 || this->minutes >= 60){
			if (this->seconds >= 60){
				this->seconds -= 60;
				this->minutes++;
			}

			if (this->minutes >= 60){
				this->minutes -= 60;
				this->hours++;
			}
		}
	}


	//************************************************************

	Time::Time(){
	this->seconds = 0;
	this->minutes = 0;
	this->hours = 0;		
	}
	
	Time::Time(int seconds, int minutes, int hours){   
		if(seconds>=0 && minutes>=0 && hours >=0){
			this->seconds = seconds;
			this->minutes = minutes;
			this->hours = hours;
			time_corection();
		}
		else
			throw std::invalid_argument("Hours, minutes, sekonds can't be negative.");
	}

	
	//************************************************************

	void Time::print(){
		std::cout << "Time " << this->hours << ":"
						<< this->minutes << ":"
						<< this->seconds << "\n";
	}

	int Time::get_seconds(){
		return this->seconds;
	}
	int Time::get_minutes(){
		return this->minutes;
	}
	int Time::get_hours(){
		return this->hours;
	}

	void Time::set_time(int seconds, int minutes, int hours){
		set_hours(hours);
		set_minutes(minutes);
		set_seconds(seconds);
	}

	void Time::set_hours(int hours){
		if (hours>=0){
			this->hours = hours;
		}
		else
			throw std::invalid_argument("Hours can't be negative.");
	}

	void Time::set_minutes(int minutes){
		if (minutes>=0){
			this->minutes = minutes;
			time_corection();
		}
		else
			throw std::invalid_argument("Minutes can't be negative.");
	}

	void Time::set_seconds(int seconds){
		if (seconds>=0){
			this->seconds = seconds;
			time_corection();
		}
		else
			throw std::invalid_argument("Hours can't be negative.");
	}
//********************************************************operatory
Time Time::operator+(Time time){
	Time tmp = time;
	tmp.seconds += this->seconds;
	tmp.minutes += this->minutes;
	tmp.hours += this->hours;
	tmp.time_corection();
	return tmp;
}

Time Time::operator+=(int seconds){
	this->seconds += seconds;
	time_corection();
	return *this;
}

bool Time::operator==(Time time) {
	return hours == time.hours && minutes == time.minutes && seconds == time.seconds;
}

bool Time::operator!=(Time time) {
	return !(*this == time);
}

bool Time::operator<(Time time){
	if(hours < time.hours) return true;
	if(hours == time.hours && minutes < time.minutes) return true;
	if(hours == time.hours && minutes == time.minutes && seconds < time.seconds) return true;
	else return false;
}

bool Time::operator>(Time time){
	return !(*this < time);
}

bool Time::operator>=(Time time){
	return (*this == time)||(*this > time);
}

bool Time::operator<=(Time time){
	return (*this == time)||(*this < time);
}
//********************************************************operatory


