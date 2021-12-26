#include "GreenFire01.h"
#include "Image.h"

// when the enemy image shows up on the gameboard, it is enlarged 1.2 times.
const float ENLARGE = 1.2;

GreenFire01::GreenFire01(float x, float y) : AbstractEnemy(x, y)
{
	speed = 2.5f;
	angle = Define::PI / 2;
	range = 13.0 * ENLARGE;
	health = 3;
}

bool GreenFire01::update()
{
	boolean retBool = true;

	if (counter < 100) {
		angle = Define::PI / 2;
		x += cos(angle) * speed;
		y += sin(angle) * speed;
	}
	else if (105 <= counter) {
		angle = Define::PI * 3 / 4;
		x += cos(angle) * speed;
		y += sin(angle) * speed;
	}

	retBool = isInside();

	counter++;
	return retBool;
}

void GreenFire01::draw() const
{
	const static int imgID[4] = { 0, 2, 3, 2 };
	const int handle = Image::getIns()->getGreenFire()[imgID[(counter / 5) % 4]];
	DrawRotaGraphF(x, y, ENLARGE, 0.0, handle, TRUE);
}

void GreenFire01::setSize()
{
	int handle = Image::getIns()->getGreenFire()[0];
	GetGraphSize(handle, &width, &height);
}