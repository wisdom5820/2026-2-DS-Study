#include<iostream>
#include<string>
using namespace std;

struct person {
	string name;
	int price;
};

int main() {
	string bid = "NONE";
	int prc = 0;
	int N;
	cin >> N;
	person prsn_lst[100];
	int idx_lst[10001] = {};

	int idx_person = 0;
	for (; idx_person < N; idx_person++) {
		cin >> prsn_lst[idx_person].name >> prsn_lst[idx_person].price;
		idx_lst[prsn_lst[idx_person].price] += 1;
	}

	for (idx_person = 0; idx_person < N; idx_person++) {
		if ((idx_lst[prsn_lst[idx_person].price] == 1) && (prsn_lst[idx_person].price > prc)) {
			prc = prsn_lst[idx_person].price;
			bid = prsn_lst[idx_person].name;
		}
	}

	cout << bid;
}