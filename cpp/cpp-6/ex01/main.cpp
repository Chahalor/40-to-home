#include "all.hpp"
#include "Serializer.hpp"

int	main(void)
{
	{
		void		*bob = (void *)0x25;

		uintptr_t	_raw = Serializer::serialize((Data *)bob);
		void		*_bob = Serializer::deserialize(_raw);

		outl(_bob);
	}

	{
		void		*bob = (void *)0x125;
	
		uintptr_t	_raw = Serializer::serialize((Data *)bob);
		void		*_bob = Serializer::deserialize(_raw);
	
		outl(_bob);
	}

	{
		uintptr_t	_raw = 0x12FFFFFFFFFULL;

		void		*_bob = Serializer::deserialize(_raw);

		outl(_bob);
	}

	{
		uintptr_t	_raw = -0x1;

		void		*_bob = Serializer::deserialize(_raw);

		outl(_bob);
	}
}