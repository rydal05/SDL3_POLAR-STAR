#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
	virtual void Update(double dt) = 0; //update loop will interpret inputs and correspond weapon attack outputs
	virtual void Render() = 0;
	virtual ~Weapon() {}

private:
	int maxAmmo;
	int fireRate;
    int levelReqs[4]; //0->1, 1->2, 2->3, 3->MAX
};

#endif