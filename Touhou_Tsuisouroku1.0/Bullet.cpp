#include "Bullet.h"
#include "ImageBullet.h"

Bullet::Bullet() :
	x(0.0),
	y(0.0),
	speed(0.0),
	angle(0.0),
	counter(0),
	flag(0),
	power(0),
	bulletType(0),
	bulletColor(0)
{
}

Bullet::Bullet(float x, float y, float speed, float angle, int flag, int power, int bulletType, int bulletColor) :
	x(x),
	y(y),
	speed(speed),
	angle(angle),
	counter(0),
	flag(flag),
	power(power),
	bulletType(bulletType),
	bulletColor(bulletColor)
{
}

bool Bullet::update()
{
	counter++;
	x += cos(angle) * speed;
	y += sin(angle) * speed;
	return isInside();
}

void Bullet::draw() const
{
	DrawRotaGraphF(x, y, 1.6f, angle + Define::PI / 2, ImageBullet::getIns()->getImage(static_cast<ImageBullet::eBulletType>(bulletType), static_cast<ImageBullet::eBulletColor>(bulletColor)), TRUE);
}

void Bullet::initializeBullet()
{
	x = 0.0;
	y = 0.0;
	angle = 0.0;
	power = 0;
	counter = 0;
	flag = 0;
	range = 0.0;
}

bool Bullet::isInside()
{
	if (counter < 60) {
		return true;
	}

	// ******************** Maybe I should let the bullets move beyond the boarders a bit *****************
	/* bullet's size and gameboard border*/
	float bulletWidth = (float)ImageBullet::getIns()->getSize(bulletType)->getWidth();
	float bulletHeight = (float)ImageBullet::getIns()->getSize(bulletType)->getHeight();
	float leftBorder = Define::IN_X + (bulletWidth / 2);
	float rightBorder = Define::IN_X + Define::INNER_W - (bulletWidth / 2);
	float upperBorder = Define::IN_Y;
	float bottomBorder = Define::IN_Y + Define::INNER_H - (bulletHeight / 2);

	if (x < leftBorder || rightBorder < x || y < upperBorder || bottomBorder < y) {
		flag = 0; // temporarily mutable
		return false;
	}
	return true;
}