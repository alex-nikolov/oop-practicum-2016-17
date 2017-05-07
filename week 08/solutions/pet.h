#ifndef PET_H_
#define PET_H_

class Pet
{
	char* name;
	int age;
	char* owner;
	int cuteness;

	void copy(Pet const&);
	void erase();
public:
	Pet(char const*, int, char const*, int);
	
	Pet();
	~Pet();
	Pet(Pet const&);
	Pet& operator=(Pet const&);
	
	int getCuteness() const;
	char const* getName() const;
	
	void setName(char const*);
};

Pet const& cuterPet(Pet const&, Pet const&);

#endif