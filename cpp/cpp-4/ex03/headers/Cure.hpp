#include "AMateria.hpp"

class Cure: public virtual AMateria
{
	private:
		/* data */
	public:
		Cure(/* args */);
		Cure(const Cure &_other);
		~Cure();

		AMateria	*clone() const;
		void		use(ICharacter &target);
};

