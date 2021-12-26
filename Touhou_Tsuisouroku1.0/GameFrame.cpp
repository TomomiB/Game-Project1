#include "GameFrame.h"
#include "Image.h"
//#include "AbstractPlayer.h"

bool GameFrame::update()
{
	return true;
}

void GameFrame::draw() const
{
	DrawGraph(1, 0, Image::getIns()->getGameBoard(), TRUE);
	//DrawRotaGraph(Define::INNER_W + 250, Define::CENTER_Y - 250, 1.6, 0.0, Image::getIns()->getHealthText(), TRUE);

	/* drawing health icons*/
	//if (_playerHealth == 0) {
	//	return;
	//}
	//for (int i = 0; i < _playerHealth / 10; i++) {
	//	DrawRotaGraph(Define::INNER_W + 160 + i * 40, Define::CENTER_Y - 200, 1.6, 0.0, Image::getIns()->getHealth(), TRUE);
	//}
}

void GameFrame::setPlayerProperty(int health, int power)
{
	_playerHealth = health;
	_playerPower = power;
}
