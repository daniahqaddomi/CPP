#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data		original;
	uintptr_t	raw;
	Data		* result;

	original.id = 42;
	original.name = "Marvin";
	original.value = 3.14;

	std::cout << "original address: " << &original << std::endl;

	raw = Serializer::serialize(&original);
	std::cout << "serialized value: " << raw << std::endl;

	result = Serializer::deserialize(raw);
	std::cout << "deserialized address: " << result << std::endl;

	if (result == &original)
		std::cout << "pointers match: yes" << std::endl;
	else
		std::cout << "pointers match: no" << std::endl;

	std::cout << "id: " << result->id << std::endl;
	std::cout << "name: " << result->name << std::endl;
	std::cout << "value: " << result->value << std::endl;

	return (0);
}
