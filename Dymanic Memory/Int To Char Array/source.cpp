#include <iostream>
#include <cstring>

unsigned length(int n) {
	unsigned len = 0;
	do {
		len++;
		n /= 10;
	} while (n);

	return len;
}

char* intToCharArray(int n, char* destination) {
	unsigned len = length(n);
	destination = new char[len + 1];
	unsigned i = 0;
	while (n) {
		destination[i++] = n % 10 + '0';
		n /= 10;
	}
	destination[i] = '\0';

	return destination;
}

int main() {
	char* des = nullptr;
	int test = 546556;
	std::cout << intToCharArray(test,des);
}
