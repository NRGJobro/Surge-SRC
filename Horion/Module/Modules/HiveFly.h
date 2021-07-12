#pragma once
#include "..\ModuleManager.h"
#include "Module.h"

class HiveFly : public IModule {
private:
	int counter = 1;
	float speed = 0.9f;
	bool Fly = true;
	bool Blinc = true;
	bool Glide = false;
	float glideMod = 0.f;
	float glideModEffective = 0;

public:
	HiveFly();
	~HiveFly();

	// Inherited via IModule
	virtual const char* getModuleName() override;
	virtual void onEnable() override;
	virtual void onMove(C_MoveInputHandler* input) override;
	virtual void onTick(C_GameMode* gm);
	virtual void onDisable() override;
};
//fixing up and down later
