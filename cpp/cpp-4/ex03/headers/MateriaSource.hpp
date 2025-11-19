#pragma oncex

#include "IMateriaSource.hpp"

class MateriaSource: public virtual IMateriaSource
{
	private:
		/* data */
	public:
		MateriaSource(void);
		~MateriaSource();

		void		learnMateria(AMateria *_target);
		AMateria	*createMateria(const std::string &_type);
};
