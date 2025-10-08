#include "Harl.hpp"
#include "all.hpp"

void	Harl::debug(void)
{
	outl("I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!")
}

void	Harl::info(void)
{
	outl(BLUE "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" RESET)
}

void	Harl::warning(void)
{
	outl(YELLOW "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." RESET)
}

void	Harl::error(void)
{
	outl(RED "This is unacceptable! I want to speak to the manager now." RESET)
}

void	Harl::complain(
	int level
)
{
	switch (level)
	{
		case DEBUG:
			this->debug();
		case INFO:
			this->info();
		case WARMING:
			this->warning();
		case ERROR:
			this->error();
			break;
		default:
			outl("[ Probably complaining about insignificant problems ]");
	}
}

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}
