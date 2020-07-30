#include <iostream>
#include <string>

char* strduplicate (char* destination, char* source) {
	destination = new char[strlen(source) + 1];
	strcpy(destination, source);
	return destination;
}

int main() {
	char test[20];
	char input[10];
	std::cin >> input;

	std::cout << strduplicate(test, input) << std::endl;

}
