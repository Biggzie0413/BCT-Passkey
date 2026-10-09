#include <includes.hpp>

int main() {
	printf("Binary Conversion Tool\n");	

	printf("more than 1 octet should be seperated by a comma\nExample: 01110010, 01101010\nEnter Octet(s) -> ");
	std::getline(std::cin, vars.input);
	vars.length = vars.input.length();

	//capture the amount of octets entered by the user and store them in a vector
	std::stringstream ss(vars.input);
	std::string token;
	std::vector<std::string> octets;

	while(std::getline(ss, token, ',')) {
		octets.push_back(token);//push back each octet found into the vector
	}
	vars.octetCount = octets.size();//storing our octets vector size into our octetCount variable.

	for (int i = 0; i < vars.octetCount; i++) {
		const std::string& octet = octets[i];
		printf("Octet %d (%s):\n", i + 1, octet.c_str());

		if(octet.length() > 8 || octet.length() < 1) {
			logger.Error("Invalid input.\nPlease enter a valid octet (1-8 bits).\n");
			continue;
		}

		bool is_valid = true;
		for (char c : octet) {
			if (c != '0' && c != '1') {
				is_valid = false;
				break;
			}
		}
		if(!is_valid) {
			logger.Error("Invalid input.\nPlease enter a valid octet (1-8 bits).\n");
			continue;
		}
		int value = 0;
		for(size_t j = 0; j < octet.length(); j++) {
			vars.bitValue = octet[j] - '0';
			value = (value << 1) | vars.bitValue;
		}
		printf("Enter Passkey: ");
		std::cin >> vars.passkey;


	}
	printf("plainText: %s\n", vars.plainText.c_str());
}