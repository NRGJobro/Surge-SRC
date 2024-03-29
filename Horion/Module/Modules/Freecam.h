#pragma once
#include "Module.h"
class Freecam : public IModule {
private:
	vec3_t oldPos;
	float glideMod = 0.f;
	float glideModEffective = 0;

public:
	float speed = 1.f;
	Freecam();
	~Freecam();

	// Inherited via IModule
	virtual const char* getModuleName() override;
	virtual void onTick(C_GameMode* gm) override;
	virtual void onMove(C_MoveInputHandler* input) override;
	virtual void onEnable() override;
	virtual void onDisable() override;
};

//By Packet