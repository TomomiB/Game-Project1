#include "AbstractEnemy.h"
#include "Image.h"

/*float AbstractEnemy::angleEnemyAndPlayer() const
{
	return atan2(playerY - y, playerX - x);
}*/

AbstractEnemy::AbstractEnemy(float x, float y) :
	x(x),
	y(y),
	speed(0),
	angle(0),
	range(0),
	counter(0),
	width(0),
	height(0),
	health(0)//,
	//playerX(0),
	//playerY(0)
{
}

void AbstractEnemy::initialize()
{
	setSize();
}

bool AbstractEnemy::update()
{
	counter++;
	x += cos(angle) * speed;
	y += sin(angle) * speed;
	return isInside();
}

bool AbstractEnemy::isInside() const
{
	if (counter < 60) {
		return true;
	}
	if (x < Define::IN_X || Define::INNER_W + width / 2 < x || y < Define::IN_Y || Define::INNER_H + height / 2 < y) {
		return false;
	}
	return true;
}

void AbstractEnemy::updateHealth(int damage)
{
	health -= damage;
}