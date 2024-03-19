#include <iostream>
#include "Serializer.hpp"

int main() {
	Data data;
	data.value = "Hello there!";

	uintptr_t serialized = Serializer::serialize(&data);
	Data* deserializedData = Serializer::deserialize(serialized);

	std::cout << "Serialized data:\nStr: '" << deserializedData->value << "'\t---\tAddress: 0x" << std::hex << serialized << std::endl;
	std::cout << std::endl;
	std::cout << "Original data:\nStr: '" << data.value << "'\t---\tAddress: " << &data << std::endl;

	if (deserializedData == &data)
		std::cout << "\nCHECK: Data and deserialized data are the same" << std::endl;
	else
		std::cout << "\nCHECK: Data and deserialized data are NOT the same" << std::endl;
	
	std::cout << "\n----------Changing data----------" << std::endl;
	data.value = "This is a new string!";
	std::cout << "Serialized After change:\nStr: '" << deserializedData->value << "'\t---\tAddress: 0x" << std::hex << serialized << std::endl;
	std::cout << std::endl;
	std::cout << "Original after change:\nStr: '" << data.value << "'\t---\tAddress: " << &data << std::endl;
	return 0;
}
