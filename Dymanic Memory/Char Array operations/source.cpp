#include <iostream>
#include <cstring>

char car(const char* x) {
	return x[0];
}

char* cdr(char* x) {
	char* result = new char[strlen(x) + 1];
	unsigned i = 0;
	for (i; i < strlen(x); i++) {
		result[i] = x[i + 1];
	}
	result[i] = '\0';
	return result;
	delete[] result;
}

char* cons(char x, const char* y) {
	char* result = new char[strlen(y) + 3];
	unsigned i = 0;
	result[i] = x;
	for (i; i < strlen(y); i++) {
		result[i + 1] = y[i];
	}
	result[i+1] = '\0';
	return result;
	delete[] result;

}

bool eq(const char* x, const char* y) {
	bool are_equal = true;
	for (unsigned i = 0; i < strlen(x); i++) {
		if (x[i] != y[i]) {
			are_equal = false;
		}
	}

	return are_equal;
}

char* reverse(char* x) {
	char* result = new char[strlen(x)];
	unsigned i = 0;
	for (i; i < strlen(x); i++) {
		result[i] = x[strlen(x) - i - 1];
	}
	result[i] = '\0';
	return result;
}

char* copy(char* x) {
	char* result = new char[strlen(x) + 1];
	unsigned i = 0;
	for (i; i < strlen(x); i++) {
		result[i] = x[i];
	}
	result[i] = '\0';
	return result;
}

char* car_n(char* x, int n) {
	char* result = new char[strlen(x) + 1];
	unsigned i = 0;
	if (n > strlen(x)) {
		return x;
	}
	for (i; i < n; i++) {
		result[i] = x[i];
	}
	result[i] = '\0';
	return result;
}

char* cdr_n(char* x, int n) {
	char* result = new char[strlen(x) + 1];
	unsigned i = 0;
	if (n > strlen(x)) {
		return x;
	}
	for (i; i < strlen(x); i++) {
		result[i] = x[strlen(x) - n + i];
	}
	result[i] = '\0';
	return result;
}

int number_of_char(char* x, char ch) {
	int result = 0;
	for (int i = 0; i < strlen(x); i++) {
		if (x[i] == ch) {
			result++;
		}
	}

	return result;
}

int main() {
	const char* test = "moncho";
	char test2[7];
	std::cin >> test2;
	std::cout << car(test) << std::endl;
	std::cout << cdr(test2) << std::endl;
	std::cout << cons('m', "oncho") << std::endl;
	std::cout << std::boolalpha << eq("m", "m") << std::endl;
	std::cout << reverse(test2) << std::endl;
	std::cout << copy(test2) << std::endl;
	std::cout << car_n(test2, 3) << std::endl;
	std::cout << cdr_n(test2, 3) << std::endl;
	std::cout << number_of_char(test2, 'o') << std::endl;
}
