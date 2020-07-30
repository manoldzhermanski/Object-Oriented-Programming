#include <iostream>
#include <string>

char* strduplicate (char* destination, char* source) {
	destination = new char[strlen(source) + 1];
	unsigned i = 0;
	for (i; i < strlen(source); i++) {
		destination[i] = source[i];
	}
	destination[i] = '\0';
	return destination;
}

int main() {
	char* test = nullptr;
	char input[10];
	std::cin >> input;

	std::cout << strduplicate(test, input) << std::endl;

}
