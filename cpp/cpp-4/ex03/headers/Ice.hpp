#include "AMateria.hpp"

class Ice: public virtual AMateria
{
	private:
		/* data */
	public:
		Ice(/* args */);
		Ice(const Ice &_other);
		~Ice();

		AMateria	*clone() const;
		void		use(ICharacter &target);
};

