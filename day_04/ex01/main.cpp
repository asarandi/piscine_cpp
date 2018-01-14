#include <iostream>
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Enemy.hpp"
#include "Character.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

int main()
{
	Character* zaz = new Character("zaz");

		std::cout << *zaz;

		Enemy* b = new RadScorpion();

		AWeapon* pr = new PlasmaRifle();
		AWeapon* pf = new PowerFist();

		zaz->equip(pr);
		std::cout << *zaz;
		zaz->equip(pf);

		zaz->attack(b);
		std::cout << *zaz;
		zaz->equip(pr);
		std::cout << *zaz;
		zaz->attack(b);
		std::cout << *zaz;
		zaz->attack(b);
		std::cout << *zaz;

		std::cout << "-----------------------------------------------" << std::endl;

		Enemy* c = new SuperMutant();
		zaz->equip(pf); std::cout << *zaz;
		zaz->attack(c); std::cout << *zaz;
		zaz->equip(pr); std::cout << *zaz;
		zaz->attack(c); std::cout << *zaz;
		zaz->equip(pf); std::cout << *zaz;
		zaz->attack(c); std::cout << *zaz;
		zaz->equip(pr); std::cout << *zaz;
		zaz->attack(c); std::cout << *zaz;
		zaz->recoverAP();
		zaz->recoverAP();
		zaz->recoverAP();
		zaz->recoverAP();

		zaz->equip(pf); std::cout << *zaz;
		zaz->attack(c); std::cout << *zaz;

		zaz->equip(pr); std::cout << *zaz;
		zaz->attack(c); std::cout << *zaz;


		return 0;
}
