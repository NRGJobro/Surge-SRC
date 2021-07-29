#pragma once
#include "Module.h"
class Shaders : public IModule {
public:
	float* gammaPtr = nullptr;
	Shaders();
	~Shaders();

	// Inherited via IModule
	virtual const char* getModuleName() override;
	virtual void onTick(C_GameMode* gm) override;
	virtual void onEnable() override;
	virtual void onDisable() override;
};
