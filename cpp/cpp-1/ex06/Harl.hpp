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
		void	complain(int level);
};

enum e_level
{
	DEBUG,
	INFO,
	WARMING,
	ERROR,
};

struct s_complaine
{
	std::string	level;
	void		(Harl::*func)(void);
};
