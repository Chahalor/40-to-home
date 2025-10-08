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
	std::string level
)
{
	static const t_complaine	_complaines[4] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};
	register int				i = -1;

	while (++i < 4)
		if (!level.compare(_complaines[i].level))
			return (this->*(_complaines[i].func))();
	outl("[ Probably complaining about insignificant problems ]");
}

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}
