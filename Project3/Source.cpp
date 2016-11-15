#include <iostream>
#include <algorithm>
#include <list>
#include <conio.h>

using namespace std;

// Calculates the lowest price with the days stayed, amount of rewards, 
// days to get reward, and the amount of rewards to get a day off
class hotel {
public:
	// Default values
	hotel() {
		drewards = 0;
		dstays = 0;
		rewards = 0;
		pdayoff = 0;
		daysoff = 0;
		total = 0;
	}

	// Gets days staying, days stayed to get a rewards point, amount of rewards to get a day off,
	// and price per day
	void get_info() {
		cout << "How many days are you staying?: \n";

		while (true) {
			cin >> dstays;

			if (dstays != NULL)
				break;
		}

		cout << "How many days until you get a rewards point?: \n";

		while (true) {
			cin >> drewards;

			if (drewards != NULL)
				break;
		}

		cout << "How many rewards points to get a day off?: \n";

		while (true) {
			cin >> pdayoff;

			if (pdayoff != NULL)
				break;
		}

		cout << "Enter price per day: \n";

		int temp;
		for (int i = 0; i < dstays; i++) {
			while (true) {
				cin >> temp;

				if (temp != NULL) {
					pp_day.push_back(temp);
					break;
				}
			}
		}
		rewards = dstays / drewards;
		daysoff = rewards / pdayoff;
	}


	void biggest_value() {
		while (rewards >= pdayoff) { // While you have enough rewards to get a day off
			pos = max_element(pp_day.begin(), pp_day.end()); // Sets iterator to the node with the highest value
			cout << "\nErasing: " << *pos << "\n";
			pp_day.erase(pos);
			rewards -= pdayoff; // Decrements the rewards for using them
		}
	}

	double get_total() {
		for (pos = pp_day.begin(); pos != pp_day.end(); pos++) // Adds the total together
			total += *pos;

		return total;
	}

	void print() { // Displays the variable values for debugging purposes
		cout << "\ndrewards: " << drewards << "\n";
		cout << "dstays: " << dstays << "\n";
		cout << "pdayoff: " << pdayoff << "\n";
		cout << "rewards: " << rewards << "\n";
		cout << "daysoff: " << daysoff << "\n";

		cout << "pp_day: \n";
		int temp = 1;
		for (pos = pp_day.begin(); pos != pp_day.end(); pos++) {
			cout << temp << ".) " << *pos << "\n";
			temp++;
		}
		cout << "\n";
	}

private:
	int drewards; // Days to get rewards
	int dstays; // Days stayed
	int pdayoff; // Amount of rewards to get a day off
	int daysoff; // Days you get off
	list<double>::iterator pos; // Iterator
	list<double> pp_day; // The prices per day
	int rewards; // Rewards points
	double total; // Total amount of savings
};

int main() {

	hotel garuda;
	garuda.get_info();
	cout << "\nTotal: $" << garuda.get_total();
	garuda.biggest_value();
	garuda.print();
	cout << "\nTotal (with days off): $" << garuda.get_total();

	cout << "\n\n";
	_getch();
	return 0;
}