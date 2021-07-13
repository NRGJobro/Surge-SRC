#include "SuperSaiyan.h"

SuperSaiyan::SuperSaiyan() : IModule(0x0, Category::MOVEMENT, "Fukin Insane") {
}

SuperSaiyan::~SuperSaiyan() {
}

const char* SuperSaiyan::getModuleName() {
	return ("SuperSaiyan");
}

void SuperSaiyan::onTick(C_GameMode* gm) {
auto player = g_Data.getLocalPlayer();
player->setGameModeType(1);
}