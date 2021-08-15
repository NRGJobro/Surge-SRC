#pragma once
#include "Module.h"
#include "../ModuleManager.h"
#include "../../../Utils/Target.h"

class Killaura : public IModule
{
private:
	bool isMulti = true;
	int delay = 0;
	int Odelay = 0;
	bool autoweapon = true;
	void findWeapon();
	bool strafe = false;
	bool target = true;
	bool spin = false;
	bool swingg = false;

public:
	bool shouldChange = false;
	bool isMobAura = false;
	bool hurttime = true;
	float range = 6;
	float speed = 0.25;


	Killaura();
	~Killaura();

	// Inherited via IModule
	virtual const char* getModuleName() override;
	//virtual void onTick(C_GameMode* gm) override;
	virtual void onEnable() override;
	virtual void onSendPacket(C_Packet* packet) override;
	void onMove(C_MoveInputHandler* input);
	bool silent = true;
	virtual void onTick(C_GameMode* gm) override;
	virtual void onLevelRender() override;
};

