#pragma once
#include <memory>
#include <DxLib.h>
#include "AbstractScene.h"
#include "AbstractStage.h"
//#include "AbstractConversation.h"
#include "AbstractPlayer.h"
#include "GameFrame.h"
//#include "AbstractBackground.h"
//#include "EnemyManager.h"
//#include "YakumoRan.h"
//#include "S1ReimuConversation.h"
//#include "S1MarisaConversation.h"
//#include "SpellCardEffect.h"
//#include "AbstractEndConversation.h"
//#include "S1ReimuEndConversation.h"
//#include "S1MarisaEndConversation.h"
//#include "Reimu.h"
//#include "Marisa.h"

class GameScene : public AbstractScene
{
public:
	GameScene(SceneChangeListener* listener, const SceneParameter& parameter);
	virtual ~GameScene() = default;

	void update() override;
	void draw() const override;
	float getPlayerX() const;
	float getPlayerY() const;
	int getPlayerPower() const;
	int getPlayerHealth() const;

private:
	//int _level;
	std::shared_ptr<AbstractPlayer> player;
	std::shared_ptr<AbstractStage> stage;
	std::shared_ptr<GameFrame> board;
	//std::shared_ptr<AbstractBackground> _background;
	//std::shared_ptr<EnemyManager> _enemyManager;
	//std::shared_ptr<AbstractBoss> _boss;
	//std::shared_ptr<AbstractConversation> _conversation;
	//std::shared_ptr<AbstractEndConversation> _endConversation;
	//SpellCardEffect spellCardEffect;
	//int _currentCharacter = 0;

	//void linkPlayerEnemy(); // pass player's location and power info to EnemyManager class
	//void linkPlayerBoss(); // pass player's location and power info to Boss class
	//void linkPlayerShotAndEnemy(); // pass player's shot info to EnemyManager class
	//void linkPlayerShotAndBoss(); // pass player's shot info to Boss class
	//void linkEnemyShotAndPlayer(); // pass Enemies' shots info to Player class
	//void linkBossShotAndPlayer(); // pass Boss's shots info to Player class
	//void linkPlayerBoard(); // pass player's health and power info to GameBoard class so that health and power can be shown

	// control Sound
	bool isSoundOn = false;
};