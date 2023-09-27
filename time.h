#pragma once
#include <iostream>

class Time{

private:
	int seconds;
	int minutes;
	int hours;
	void time_corection();
	void set_hours(int hours);
	void set_minutes(int minutes);
	void set_seconds(int seconds);

public:
	int get_seconds();
	int get_minutes();
	int get_hours();
	Time();
	Time(int seconds, int minutes = 0, int hours = 0);
	void print();
	void set_time(int seconds, int minutes = 0, int hours = 0);
	Time operator+(Time time);
	Time operator+=(int seconds);
	bool operator==(Time time) ;
	bool operator!=(Time time);
	bool operator<(Time time);
	bool operator>(Time time);
	bool operator>=(Time time);
	bool operator<=(Time time);
};