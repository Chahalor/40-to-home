#pragma once

#include <stdint.h>

typedef struct s_Data	Data;

struct s_Data
{
	char	_dummy;
};

class Serializer
{
	private:
		//...

	public:
	/* -Constructors- */
		//...

	/* -Destructors-  */
		//...

	/*    -Getter-    */
		//...

	/*    -Setter-    */
		//...

	/*  -Methods-   */
	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);
	/*  -Operators-   */
		//...
};
