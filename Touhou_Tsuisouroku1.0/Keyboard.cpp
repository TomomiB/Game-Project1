#include "Keyboard.h"
#include <DxLib.h>

bool Keyboard::update()
{
	char currentKeyStatus[KEY_NUM]; // char array to use in GetHitKeyStateAll()

	/*GetHieKeyStateAll() checks current status of all 256 keys.
	  char array (the parameter) will hold the status*/
	GetHitKeyStateAll(currentKeyStatus);
	for (int i = 0; i < KEY_NUM; i++) {
		if (currentKeyStatus[i] != 0) { // if the user hits the key
			if (releasingCount[i] > 0) {
				releasingCount[i] = 0; // initialize the releasing key count
			}
			pressingCount[i]++;
		}
		else { // if the user isn't using the key
			if (pressingCount[i] > 0) {
				pressingCount[i] = 0; // initialize the pressing count
			}
			releasingCount[i]++;
		}
	}
	return true;
}

/* returns the numer of frames */
int Keyboard::getPressingCount(int keyCode)
{
	if (!isCodeAvailable(keyCode)) {
		return -1;
	}
	return pressingCount[keyCode];
}

int Keyboard::getReleasingCount(int keyCode)
{
	if (!isCodeAvailable(keyCode)) {
		return -1;
	}
	return releasingCount[keyCode];
}

bool Keyboard::isCodeAvailable(int keyCode)
{
	if (!(0 <= keyCode && keyCode < KEY_NUM)) {
		return false;
	}
	return true;
}