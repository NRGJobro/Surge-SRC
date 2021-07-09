#pragma once
#include "Module.h"
#include "../ModuleManager.h"

class Breaker : public IModule {
private:
	int range = 5;
	bool beds = true;
	bool eggs = true;
	bool cakes = true;
	bool treasures = true;
	bool chests = false;
	bool redstone = false;
	bool diamond = false;
	//bool andisite = false;
	//bool nuke = true;

public:
	Breaker();
	~Breaker();

	// Inherited via IModule
	virtual const char* getModuleName() override;
	virtual void onTick(C_GameMode* gm) override;
};
