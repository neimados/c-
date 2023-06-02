#pragma once

# include <iostream>
# include <stdint.h>

typedef struct{
	int	i;
} Data;

class Serializer {
	public :
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private : 
		Serializer();
		Serializer(const Serializer &s);
		Serializer &operator= (const Serializer &s);
		~Serializer();

		Data d;
};

