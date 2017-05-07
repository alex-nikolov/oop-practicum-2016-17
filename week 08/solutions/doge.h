#ifndef DOGE_H_
#define DOGE_H_

#include "Pet.h"

class Doge : public Pet {
	char* breed;
	
	void copy(Doge const&);
public:
	Doge();
	~Doge();
	Doge(Doge const&);
	Doge& operator=(Doge const&);
	
	Doge(char const*, int, char const*, int, char const*);
};

#endif