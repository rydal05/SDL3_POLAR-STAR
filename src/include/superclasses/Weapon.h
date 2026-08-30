#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
	Weapon();
	explicit Weapon(const char *filepath);

	virtual void Update(double dt) = 0; // update loop will interpret inputs and correspond weapon attack outputs
	virtual void Render() = 0;
	virtual ~Weapon() {}

protected:
	Entity *owner = NULL;
};

#endif