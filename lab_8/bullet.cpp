
#include "bullet.h"

using namespace std;

Bullet::Bullet(double caliber) : _caliber(caliber) {click(); };
Bullet::Bullet() : _caliber(0){};
