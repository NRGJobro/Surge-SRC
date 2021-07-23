#pragma once
#include "Module.h"
class Scaffold : public IModule {
private:
	bool free = false;
	bool timerBool = false;
	bool airplace = true;
	int timer = 20;
	bool AutoSelect = true;
	bool FinishSelect = false;
	int prevSlot;
	int delay = 0;
	bool tower = false;
	bool staircaseMode = false;
	bool extend = false;
	bool andromeda = false;
	bool rot = true;
	bool tryScaffold(vec3_t blockBelow);
	bool findBlock();
	float thicc = 5.f;
	float towerspeed = 1.5f;
	C_PlayerInventoryProxy* supplies = nullptr;
	C_Inventory* inv = nullptr;

public:
	Scaffold();
	~Scaffold();
	bool shouldChange = false;
	bool spoof = true;

	// Inherited via IModule
	virtual const char* getModuleName() override;
	virtual void onTick(C_GameMode* gm) override;
	void onMove(C_MoveInputHandler* input);
	virtual void onDisable() override;
};
