#pragma once
#include <iostream>
#include "time.h"

class Harmonogram{
private:
	Time* times;
public:
	int size;

public:
	void set_times(Time input_times[]);
	Harmonogram();
	Harmonogram(int size);
	Harmonogram(const Harmonogram& obj, int n);
	Harmonogram(const Harmonogram& obj, Time t);
	int get_amount() const;
	Harmonogram(const Harmonogram& copy);
	void print();
	Time& get(int index) const;
	Time sum();
	void add_time(Time t);
	Harmonogram& operator=(const Harmonogram& h);
	~Harmonogram();

	
	
};