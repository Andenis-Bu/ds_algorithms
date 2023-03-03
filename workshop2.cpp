#include <iostream>
#include <stdlib.h>

using namespace std;

class List1 {
private:
	int* A;
	int currSize;
	int capacity;

	int LV = 0;
	int RV = 0;

public:
	// Constructor
	List1(int cap = 10) {
		capacity = cap;
		currSize = 0;
		A = new int[capacity];
	}

	// Destructor
	~List1() {
		delete[] A;
	}

	void add(int index, int value) {
		--index;
		if (currSize == capacity) {
			cout << "List is full!" << endl;
			return;
		}

		if (index < 0 || index > currSize) {
			cout << "Invalid index!" << endl;
			return;
		}

		for (int i = currSize; i > index; --i) {

			++LV; ++RV;
			A[i] = A[i - 1];
		}

		++LV;
		A[index] = value;
		++currSize;
	}

	int get(int index) {
		--index;
		if (index < 0 || index >= currSize) {
			cout << "Invalid index!" << endl;
			return -1;
		}

		++RV;
		return A[index];
	}

	void del(int index) {
		--index;
		if (index < 0 || index >= currSize) {
			cout << "Invalid index!" << endl;
			return;
		}

		for (int i = index; i < currSize - 1; ++i) {

			++LV; ++RV;
			A[i] = A[i + 1];
		}

		--currSize;
	}

	int size() {
		return currSize;
	}

	void results() {
		cout << "List1" << endl;
		cout << "Total elements modified: " << LV << endl;
		cout << "Total elements read: " << RV << endl;
	}
};

class List2 {
private:
	int* A;
	int* B;
	int currSize;
	int capacity;

	int LV = 0;
	int RV = 0;

public:
	// Constructor
	List2(int cap = 10) {
		capacity = cap;
		currSize = 0;
		A = new int[capacity];
		B = new int[capacity];

		for (int i = 0; i < capacity; ++i) {
			B[i] = 0;
		}
	}

	// Destructor
	~List2() {
		delete[] A;
		delete[] B;
	}

	void add(int index, int value) {
		--index;
		if (currSize == capacity) {
			cout << "List is full!" << endl;
			return;
		}

		if (index < 0 || index > currSize) {
			cout << "Invalid index!" << endl;
			return;
		}

		if (B[index] == 1) {
			for (int i = currSize; i > index; --i) {

				++LV; ++RV;
				A[i] = A[i - 1];
				B[i] = 1;
			}

			++LV;
			A[index] = value;
			++currSize;
		}
		else {
			++LV;
			A[index] = value;
			B[index] = 1;
			currSize++;
		}
	}

	int get(int index) {
		--index;
		if (index < 0 || index >= currSize) {
			cout << "Invalid index!" << endl;
			return -1;
		}

		++RV;
		return A[index];
	}

	void del(int index) {
		--index;
		if (index < 0 || index >= currSize) {
			cout << "Invalid index!" << endl;
			return;
		}

		B[index] = 0;

		--currSize;
	}

	int size() {
		return currSize;
	}

	void results() {
		cout << "List2" << endl;
		cout << "Total elements modified: " << LV << endl;
		cout << "Total elements read: " << RV << endl;
	}
};

class List3 {
private:
	int* A;
	int* C;
	int currSize;
	int capacity;

	int LV = 0;
	int RV = 0;

public:
	// Constructor
	List3(int cap = 10) {
		capacity = cap;
		currSize = 0;
		A = new int[capacity];
		C = new int[capacity];

		for (int i = 0; i < capacity; ++i) {
			C[i] = -1;
		}
	}

	// Destructor
	~List3() {
		delete[] A;
		delete[] C;
	}

	void add(int index, int value) {
		--index;
		if (currSize == capacity) {
			cout << "List is full!" << endl;
			return;
		}

		if (index < 0 || index > currSize) {
			cout << "Invalid index!" << endl;
			return;
		}

		++currSize;
		for (int i = 0; i < currSize; ++i) {
			if (C[i] == -1){
				++LV;
				A[i] = value;
				C[i] = index;
			}
			else if (C[i] >= index) {
				++C[i];
			}
		}
	}

	int get(int index) {
		--index;
		if (index < 0 || index >= currSize) {
			cout << "Invalid index!" << endl;
			return -1;
		}

		for (int i = 0; i < capacity; ++i) {
			if (C[i] == index) {
				++RV;
				return A[i];
			}
		}	
	}

	void del(int index) {
		--index;
		if (index < 0 || index >= currSize) {
			cout << "Invalid index!" << endl;
			return;
		}
		
		for (int i = 0; i < currSize; ++i) {
			if (C[i] == index) {
				C[i] = -1;
			}
			else if (C[i] > index) {
				--C[i];
			}
		}
		--currSize;
	}

	int size() {
		return currSize;
	}

	void results() {
		cout << "List3" << endl;
		cout << "Total elements modified: " << LV << endl;
		cout << "Total elements read: " << RV << endl;
	}
};

int main() {
	List1 list1;
	list1.add(1, 4);
	list1.add(1, 5);
	list1.get(2);
	list1.add(2, 3);
	list1.del(1);
	list1.add(1, 6);
	list1.del(1);
	list1.size();
	list1.get(1);
	list1.results();

	List2 list2;
	list2.add(1, 4);
	list2.add(1, 5);
	list2.get(2);
	list2.add(2, 3);
	list2.del(1);
	list2.add(1, 6);
	list2.del(1);
	list2.size();
	list2.get(1);
	list2.results();
	
	List3 list3;
	list3.add(1, 4);
	list3.add(1, 5);
	list3.get(2);
	list3.add(2, 3);
	list3.del(1);
	list3.add(1, 6);
	list3.del(1);
	list3.size();
	list3.get(1);
	list3.results();
	
	return 0;
}

