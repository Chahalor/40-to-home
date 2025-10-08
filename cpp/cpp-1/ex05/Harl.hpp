#include "all.hpp"

typedef struct s_complaine	t_complaine;

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
};

struct s_complaine
{
	std::string	level;
	void		(Harl::*func)(void);
};
