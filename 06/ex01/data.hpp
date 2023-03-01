#pragma once

# include <iostream>
# include <stdint.h>

struct Data {
	int	i;
};

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);