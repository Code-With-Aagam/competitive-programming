#include <bits/stdc++.h>
using namespace std;

/**
 * Below function will not compile for
 * 
 * functionWithReference({1, 2, 3});
 * 
 * as this function expects a lvalue reference but
 * we passed a rvalue 
 */
void functionWithReference(vector<int> &arr) {
	for (const auto &ele : arr) {
		cout << ele << "\n";
	}
	cout << "\n\n";
}

/**
 * Below function will compile and run for
 * 
 * functionWithConstReference({1, 2, 3});
 * 
 * as it is equivalent to saying something like:
 * 
 * const vector<int>& arr = {1, 2, 3};
 */
void functionWithConstReference(const vector<int> &arr) {
	for (const auto &ele : arr) {
		cout << ele << "\n";
	}
	cout << "\n\n";	
}

int main() {
	
	// lvalue:-
	// 
	// object which occupy some identifiable location in memory.
	int num;	// It's a lvalue
	int* numAddress = &num;	// as it can be identified by an address in the memory
	cout << "Num Address = " << numAddress << "\n\n";

	// rvalue:-
	//
	// object which is not a lvalue :/
	int num2 = 20;	// 20 is a rvalue
	num2 = num2 + 40;	// num2 + 20 is a rvalue
	// below line will throw ```error: lvalue required as unary ‘&’ operand```
	// reason -> it's a rvalue, hence don't have an address in the memory
	/// int* num2Address = &(num2 + 40);

	// Reference or lvalue Reference
	int num3 = 20;
	int& num3Reference = num3;
	cout << "num3 = " << num3 << "\n";
	cout << "num3Reference = " << num3Reference << "\n\n";
	
	num3Reference = 30;

	cout << "After changing num3Reference to 30" << "\n";
	cout << "num3 = " << num3 << "\n";
	cout << "num3Reference = " << num3Reference << "\n\n";

	cout << "num3 Address = " << &num3 << "\n";
	cout << "num3Reference Address = " << &num3Reference << "\n\n";

	// lvalue can be converted to rvalue
	int num4 = 10;
	// num4 is lvalue, 10 is rvalue
	int num5 = num4 + 5;
	// num5 is lvalue, num4 + 5 is rvalue
	int num6 = num4;
	// num6 is lvalue, num4 is rvalue in above line

	return 0;
}