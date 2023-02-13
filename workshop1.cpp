#include <iostream>
#include <vector>

using namespace std;

void bubbleSort1(vector<int>& v) {
	cout << "bubbleSort1" << endl;
	int cmp = 0, swp = 0;

	for (int i = 0; i < v.size() - 1; ++i) {

		for (int j = 0; j < v.size() - 1; ++j) {

			++cmp;
			if (v[j] > v[j + 1]) {
				++swp;
				swap(v[j], v[j + 1]);
			}
		}
	}

	cout << "compare:" << cmp << endl;
	cout << "swap:" << swp << endl;
}

void bubbleSort2(vector<int>& v) {
	cout << endl << "bubbleSort2" << endl;
	int cmp = 0, swp = 0;

	for (int i = 0; i < v.size() - 1; ++i) {

		for (int j = 0; j < v.size() - 1 - i; ++j) {

			++cmp;
			if (v[j] > v[j + 1]) {
				++swp;
				swap(v[j], v[j + 1]);
			}
		}
	}

	cout << "compare:" << cmp << endl;
	cout << "swap:" << swp << endl;
}

void bubbleSort3(vector<int>& v) {
	cout << endl << "bubbleSort3" << endl;
	int cmp = 0, swp = 0;

	for (int i = 0; i < v.size() - 1; ++i) {
		int changed = 0;
		for (int j = 0; j < v.size() - 1 - i; ++j) {
			++cmp;
			if (v[j] > v[j + 1]) {
				++swp;
				changed = 1;
				swap(v[j], v[j + 1]);
			}
		}
		if (changed == 0) break;
	}

	cout << "compare:" << cmp << endl;
	cout << "swap:" << swp << endl;
}


int main() {
	vector <int> vec;

	vec.push_back(5);
	vec.push_back(1);
	vec.push_back(4);
	vec.push_back(6);
	vec.push_back(2);
	vec.push_back(3);

	bubbleSort1(vec);
	vec.clear();

	vec.push_back(5);
	vec.push_back(1);
	vec.push_back(4);
	vec.push_back(6);
	vec.push_back(2);
	vec.push_back(3);

	bubbleSort2(vec);
	vec.clear();

	vec.push_back(5);
	vec.push_back(1);
	vec.push_back(4);
	vec.push_back(6);
	vec.push_back(2);
	vec.push_back(3);

	bubbleSort3(vec);
	vec.clear();
	
	return 0;
}