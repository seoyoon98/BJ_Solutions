#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int elementN; // Number of elements
int cnt; // count of retry
vector<int> vec; // Vector's size is elementN.
vector<int> Temp; // where temporary values are stored.

void Print();
void Input();
void Solution();
void Result();

int main(void) {
	Result();
	return 0;
}

void Print() {
	for (int i = 0; i < cnt; ++i)
		cout << Temp[i] << "\n";
}

void Input() {
	cin >> elementN;
	vec.resize(elementN, 0);
	
	int i;
	int temp;
	for (i = 0; i < elementN; ++i) {
		cin >> temp;
		vec[i] = temp;
	}
	
	sort(vec.begin(), vec.end());
	
	cin >> cnt;
	Temp.resize(cnt, -1);
}

void Solution() {
	int key;
	
	for (int i = 0; i < cnt; ++i) {
		bool found = false;
		cin >> key;
		
		int pl = 0;
		int pr = elementN - 1;
		do {
			int pc = (pl + pr) / 2;
			if (vec[pc] == key) {
				Temp[i] = 1;
				found = true;
				break;
			}
			else if (vec[pc] < key)
				pl = pc + 1;
			else
				pr = pc - 1;
		} while(pl <= pr);
		
		if (!found) Temp[i] = 0;
	}
}

void Result() {
	Input();
	Solution();
	Print();
}