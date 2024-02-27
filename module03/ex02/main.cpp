#include "FragTrap.hpp"

// class test {
// 	private:
// 		std::string name;
// 		std::string surname;
// 		int age;
// 	public:
// 		test(std::string name, std::string surname);
// 		void display(void);
// };

// test::test(std::string name, std::string surname)
// 	: name(name),
// 	surname(surname)
// {
// 	this->age = 20;
// }

// void test::display(void) {
// 	std::cout << "Name: " << name << std::endl;
// 	std::cout << "Surname: " << surname << std::endl;
// 	std::cout << "age " << age << std::endl;
// }

// 	test a("Bob", "glebows");
// 	a.display();

int main(void) {
	FragTrap f1("Bob");
	f1.attack("Jerry");
	f1.beRepaired(10);
	f1.highFiveGuys();
	return 0;
}
