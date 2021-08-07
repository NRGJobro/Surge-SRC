#pragma once
#include "../ModuleManager.h"
#include "Module.h"

class ChestESP : public IModule {
private:
	int range = 5;
//	bool beds = false;
	//bool eggs = false;
	////bool cakes = false;
//	bool treasures = false;
	bool chests = true;
	bool redstone = true;
	bool diamond = true;
	bool emerald = true;
	//bool andisite = false;
	//bool nuke = true;

public:
	ChestESP();
	~ChestESP();

	// Inherited via IModule
	virtual const char* getModuleName() override;
	//virtual void onTick(C_GameMode* gm) override;
	virtual void onPostRender(C_MinecraftUIRenderContext* renderctx) override;
};
