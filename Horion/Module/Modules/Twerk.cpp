#include "Twerk.h"

Twerk::Twerk() : IModule(0x0, Category::MOVEMENT, "For testing") {
this->registerIntSetting("amount", &this->amount, this->amount, 1, 5000);
}

Twerk::~Twerk() {
}

const char* Twerk::getModuleName() {
	return ("Test Mod");
}

void Twerk::onTick(C_GameMode* gm) {
	auto player = g_Data.getLocalPlayer();
	player->addExperience(amount);
}