#include "harmonogram.h"

Harmonogram::Harmonogram(){
	times = nullptr;
	times = new Time;
	size = 1;

}

Harmonogram::Harmonogram(int size){
	times = nullptr;
	times = new Time[size];
	this->size = size;
}

Time& Harmonogram::get(int index) const{
	return times[index - 1];
	}

Harmonogram::Harmonogram(const Harmonogram& obj){
	size = obj.get_amount();
	times = new Time[size];
	for (int i = 0; i < size; ++i)
	{
		times[i] = obj.get(i+1);
	}
}

Harmonogram::Harmonogram(const Harmonogram& obj, int n){
	size = n;
	times = new Time[size];
	for (int i = 0; i < size; ++i)
	{
		times[i] = obj.get(i+1);
	}
}

Harmonogram::Harmonogram(const Harmonogram& obj, Time t){
	Time a;
	int n;
	for (int i = 0; i < size; i++) {
		a = a + obj.get(i+1);
		if(a > t){
			n = i;
			break; 
		}
	}
	size = n;
	times = new Time[size];
	for (int i = 0; i < n; i++)
	{
		times[i] = obj.get(i+1);
	}
}

void Harmonogram::set_times(Time input_times[]){
	for (int i = 0; i < size; ++i){
		times[i].set_time(input_times[i].get_seconds(), 
							input_times[i].get_minutes(), 
							input_times[i].get_hours());
	}
}

void Harmonogram::print(){
	 for (int i = 0; i < size; i++) {
	 	std::cout << i+1 << "-> ";
         times[i].print();
      }
}

Time Harmonogram::sum(){
	Time a;
	for (int i = 0; i < size; i++) {
		a = a + times[i];
	}
      return a;
}

int Harmonogram::get_amount() const{
	return size;
}

void Harmonogram::add_time(Time t){
	Time tmp[size];
	for (int i = 0; i < size; ++i)
	{
		tmp[i] = times[i];
	}
	size++;
	delete[] times;
	times = new Time[size];
	for (int i = 0; i < size; ++i)
	{
		times[i] = tmp[i];
	}
	times[size-1] = t;
}

Harmonogram::~Harmonogram(){
	delete[] times;
}

Harmonogram& Harmonogram::operator=(const Harmonogram& h)
{

 if (&h == this) return *this; 
 delete[] times; 
 size= h.get_amount();
 times = new Time[size];
 	for (int i = 0; i < size; ++i)
	{
		times[i] = h.get(i+1);
	}
 return *this;
}