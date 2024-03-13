#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137, false), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137, false), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (!this->isSigned) throw NotSignedException();
	if (executor.getGrade() > this->gradeToExecute) throw GradeTooHighException();

	std::ofstream ofs(target + "_shrubbery");
	
	ofs << "					,@@@@@@@,					" << std::endl;
	ofs << "		,,,.   ,@@@@@@/@@,  .oo8888o.			" << std::endl;
	ofs << "		,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o		" << std::endl;
	ofs << "	,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'		" << std::endl;
	ofs << "	%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'		" << std::endl;
	ofs << "	%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'		" << std::endl;
	ofs << "	`&%\\ ` /%&'    |.|        \\ '|8'			" << std::endl;
	ofs << "		|o|        | |         | |				" << std::endl;
	ofs << "		|.|        | |         | |				" << std::endl;
	ofs << "	jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;

	// ofs << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⠟⠋⠄⠄⠄⠄⠄⠄⠄⢁⠈⢻⢿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⠃⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⡀⠭⢿⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⡟⠄⢀⣾⣿⣿⣿⣷⣶⣿⣷⣶⣶⡆⠄⠄⠄⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⡇⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠄⠄⢸⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣇⣼⣿⣿⠿⠶⠙⣿⡟⠡⣴⣿⣽⣿⣧⠄⢸⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣾⣿⣿⣟⣭⣾⣿⣷⣶⣶⣴⣶⣿⣿⢄⣿⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣿⣿⣿⡟⣩⣿⣿⣿⡏⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣿⣹⡋⠘⠷⣦⣀⣠⡶⠁⠈⠁⠄⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣿⣍⠃⣴⣶⡔⠒⠄⣠⢀⠄⠄⠄⡨⣿⣿⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣿⣿⣦⡘⠿⣷⣿⠿⠟⠃⠄⠄⣠⡇⠈⠻⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⡿⠟⠋⢁⣷⣠⠄⠄⠄⠄⣀⣠⣾⡟⠄⠄⠄⠄⠉⠙⠻" << std::endl;
	// ofs << "⡿⠟⠋⠁⠄⠄⠄⢸⣿⣿⡯⢓⣴⣾⣿⣿⡟⠄⠄⠄⠄⠄⠄⠄⠄" << std::endl;
	// ofs << "⠄⠄⠄⠄⠄⠄⠄⣿⡟⣷⠄⠹⣿⣿⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄" << std::endl;
	// ofs << "⠄⠄⠄⠄⠄⠄⣸⣿⡷⡇⠄⣴⣾⣿⣿⠃⠄⠄⠄⠄⠄⠄⠄⠄⠄" << std::endl;
	// ofs << "⠄⠄⠄⠄⠄⠄⣿⣿⠃⣦⣄⣿⣿⣿⠇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄" << std::endl;
	// ofs << "⠄⠄⠄⠄⠄⢸⣿⠗⢈⡶⣷⣿⣿⡏⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄" << std::endl;
	// ofs << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠄⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣿⣿⣿⡟⠄⠄⠄⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣿⣿⣿⠇⠄⠄⠄⠄⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⢿⣿⠿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⡃⡛⠈⣹⣋⣲⡐⠂⢸⡇⡘⢣⠄⣠⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣿⣿⠃⠄⠄⠄⠄⠄⠘⣿⣿⣿⣿⣿⣿⠿⠈⠹⢿⣠⠄⢸⣿⠄⠶⠶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡆⠰⠸⠤⢿⣡⣓⡒⡂⣒⡇⢃⢶⠄⣶⣾⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣿⠏⠄⠄⠄⠄⠄⠄⠄⠙⣿⣿⣿⣿⣿⣶⡀⣰⣾⣿⠄⢸⣟⠛⠿⠄⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣶⣿⣾⣿⣿⣿⣶⣿⣷⣿⣿⣶⣿⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣾⣿⣷⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣃⣀⣀⠄⠄⠄⠄⠄⣀⣀⣈⣿⡿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⠿⢿⣿⣿⣿⡿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣿⣿⣿⠄⠄⠄⠄⠄⣿⣿⣿⣇⠄⠷⣤⡼⠋⡉⠻⡿⢉⡉⢻⠉⢹⠋⣉⠛⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢫⣍⣴⣴⢴⣾⣴⣿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣿⣿⣿⠄⠄⠄⠄⠄⣿⣿⣿⡏⠙⠷⠄⠄⠘⠟⠄⣇⠸⠟⢻⠄⢸⠄⠶⠄⣇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠟⠚⠛⠿⢿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣿⣿⣿⠄⠄⠄⠄⠄⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠉⣿⣿⣿⠃⠐⠒⠠⠄⠄⠠⠄⠄⠄⢻⣿⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣿⣿⣿⠄⠄⠄⠄⠄⣿⣿⣿⣿⡿⠛⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⡟⢻⠟⣿⠿⢿⣿⣿⣿⣿⠏⠙⠃⠄⢻⣿⡇⠄⠄⡔⠄⠄⠄⠄⠠⡀⠄⠄⢿⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣿⣿⣿⠄⠄⠄⠄⠄⣿⣿⣿⡏⠄⣶⣦⣼⠉⢉⡝⠉⡉⠙⡏⢉⡁⢸⠁⣏⠄⢸⣿⣿⣿⣿⡆⠄⠄⠄⢸⣿⡆⠄⠘⠄⠄⠄⠄⡀⠄⢱⠄⠄⣾⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣿⣿⣿⠄⠄⠄⠄⠄⣿⣿⣿⣧⡀⠛⠋⢹⠄⢸⣇⠄⠖⠲⡇⠻⠃⢸⠄⣿⠄⢸⣿⣿⣿⣿⣧⡀⢀⣤⣾⣿⣷⡄⠸⡀⠄⢡⠰⠄⠄⡎⠄⣴⣿⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣿⣿⣿⠄⠄⠄⠄⠄⣿⣿⣿⣿⣿⣶⣾⣿⣶⣾⣿⣷⣶⣿⣿⣶⣶⣾⣶⣿⣷⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣵⣀⢸⢀⢀⣨⣴⣾⣿⣿⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣿⣿⣿⠄⠄⠄⠄⠄⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	// ofs << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	ofs.close();
}
