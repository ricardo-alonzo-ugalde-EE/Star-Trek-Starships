#include <iostream>
using std::cout;
using std::endl;

class Starship
{
public:
	virtual void attack();

public:
	void setPhotonTorpedoPower(int a);
	

};

class Galaxy : public Starship 
{
public:
	void attack();
	
};

class Constitution : public Starship
{
public:
	void attack();
	
};
