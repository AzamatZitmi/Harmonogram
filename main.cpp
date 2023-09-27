#include <iostream>
#include "time.h"
#include "harmonogram.h"
using namespace std;


int main(){

Time time1(12, 1), time2(12,63,9), time3(127), time4(53, 48, 54), time5(12,32,17);
int amount_of_times = 5;
Time zestawienie[amount_of_times];
zestawienie[0] = time1;
zestawienie[1] = time2;
zestawienie[2] = time3;
zestawienie[3] = time4;
zestawienie[4] = time5;

Harmonogram harmonogram1(amount_of_times);
harmonogram1.set_times(zestawienie);
// Harmonogram harmonogram2(harmonogram1, time4);			//Testy
// harmonogram1.print();									//Testy
// cout << endl;											//Testy
// harmonogram2.print();									//Testy
// harmonogram2 = harmonogram1;								//Testy
// cout << endl;											//Testy
// harmonogram2.print();									//Testy

int choice = 1;
int n;

do{
	cout << "\n\n\n1 - Print harmonogram.\n";
	cout << "2 - Copy and print first n elements.\n";
	cout << "3 - Copy and print using time.\n";
	cout << "4 - Select and increase time.\n";
	cout << "0 - Exit\n\n";
	cout << "Your choice: ";
	cout << "\n";
	cin >> choice;
	cout << "\n\n";
	switch(choice){

		case 1:
			harmonogram1.print();
			break;

		case 2:
			cout << "Input n: ";
			cin >> n;
			if (n > 5 && n < 0)
			{
				cout << "Wybierz od 0 do 5";
				break;
			}
			if(1){
			Harmonogram harmonogram2(harmonogram1, n);
			harmonogram2.print();
			}
			break;

		case 3:
			if(1){
			int sec, min, hour;
			cout << "Input seconds: ";
			cin >> sec;
			cout << "\nInput minutes: ";
			cin >> min;
			cout << "\nInput hours: ";
			cin >> hour;
			cout << endl;
			Time t(sec, min, hour);
			Harmonogram harmonogram3(harmonogram1, t);
			harmonogram3.print();
			}
			break;

		case 4:

			int sec, n;
			cout << "Choose time to add seconds(1-5): ";
			cin >> n;
			cout << endl;
			harmonogram1.get(n).print();
			cout << "\nInput seconds to ad: ";
			cin >> sec;
			harmonogram1.get(n) += sec;
			harmonogram1.get(n).print();
	}

} while (choice != 0);


return 0;
}