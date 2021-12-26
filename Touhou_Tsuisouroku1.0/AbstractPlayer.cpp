#include "AbstractPlayer.h"

using namespace std;

AbstractPlayer::AbstractPlayer() :
	counter(0),
	slow(false),
	boxAngle(0.0),
	x(Define::CENTER_X),
	y(Define::CENTER_Y + 500),
	range(0.0), // Reimu->10.5, Marisa->??
	direction(0), directionCount(0), // for loading correct player image
	power(0), // Reimu->1, Marisa->2
	health(50),
	speed(0), // Reimu->6, Marisa->8
	noHitTimer(0)
{
}

bool AbstractPlayer::update()
{
	HitCheckAndSetNoHitTimer();

	/* after checking all of the bullets in this frame, init the vector */
	//_activeEnemyBullets.clear();
	//_activeBossBullets.clear();

	updateHitBox();

	counter++;
	move();
	shotBullets();
	//_playerShot.initBulletsAfterHittingEnemy(HitCheck::getIns()->getPlayerShotHitIndex());
	//_playerShot.update();
	return true;
}

/* Player's shot properties */
void AbstractPlayer::shotBullets()
{
	//if (Keyboard::getIns()->getPressingCount(KEY_INPUT_SPACE) > 0) {
	//	/* when Slow-move mode, bullets are closer to center. */
	//	if (Keyboard::getIns()->getPressingCount(KEY_INPUT_LSHIFT) > 0) {
	//		playerShot.setBullets(x + 15, y - 8, Define::PI / 2 * 3, power);
	//		playerShot.setBullets(x - 15, y - 8, Define::PI / 2 * 3, power);
	//	}
	//	else {
	//		playerShot.setBullets(x + 25, y - 8, Define::PI / 2 * 3, power);
	//		playerShot.setBullets(x - 25, y - 8, Define::PI / 2 * 3, power);
	//	}
	//}
}

/* Check if enemy's bullet hits the player.
   This function can become very expensive easily, because there can be so many bullets on the screen.
   Check only the area around the player...
   _x-100 < check area < _x+100, _y-100 < check area < _y+100 */
bool AbstractPlayer::didBulletHitMe()
{
	//for (int i = 0; i < _activeEnemyBullets.size(); i++) {
	//	if (_y - 100 < _activeEnemyBullets[i].getY() && _activeEnemyBullets[i].getY() < _y + 100) {
	//		if (_x < _activeEnemyBullets[i].getX() && _activeEnemyBullets[i].getX() < _x + 100) {
	//			if (HitCheck::getIns()->didBulletHitPlayer(_activeEnemyBullets, i, _x, _y, _range)) {
	//				_health -= 10; // all enemy bullets power are 10
	//				PlaySoundMem(Sound::getIns()->getGetHitSound(), DX_PLAYTYPE_BACK); // play hit sound
	//				return true;
	//			}
	//		}
	//	}
	//}

	//for (int i = 0; i < _activeBossBullets.size(); i++) {
	//	if (_y - 100 < _activeBossBullets[i].getY() && _activeBossBullets[i].getY() < _y + 100) {
	//		if (_x < _activeBossBullets[i].getX() && _activeBossBullets[i].getX() < _x + 100) {
	//			if (HitCheck::getIns()->didBulletHitPlayer(_activeBossBullets, i, _x, _y, _range)) {
	//				_health -= 10; // all enemy bullets power are 10
	//				PlaySoundMem(Sound::getIns()->getGetHitSound(), DX_PLAYTYPE_BACK); // play hit sound
	//				return true;
	//			}
	//		}
	//	}
	//}
	return false;
}

void AbstractPlayer::updateHitBox() {
	/* continue rotating hitBox image*/
	if (boxAngle <= 2 * Define::PI) {
		boxAngle += Define::PI / 180;
	}
	else {
		boxAngle = 0.0;
	}
}

/*check if any of enemy bullet hits the player
 *if player gets hit, decrease the player health and set the noHitTimer
 */
void AbstractPlayer::HitCheckAndSetNoHitTimer() {
	if (noHitTimer == 0) {
		if (didBulletHitMe()) {
			noHitTimer = 12;
		}
	}
	else {
		if (counter % 7 == 0)
			noHitTimer--;
	}
}