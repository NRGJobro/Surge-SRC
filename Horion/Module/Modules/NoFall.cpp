#include "NoFall.h"

NoFall::NoFall() : IModule(0x0, Category::MOVEMENT, "Reduces fall damage to half a heart") {
}	

NoFall::~NoFall() {
}

const char* NoFall::getModuleName() {
	return ("NoFall");
}

void NoFall::onTick(C_GameMode* gm) {
	auto player = g_Data.getLocalPlayer();
	if (player == nullptr) return;

	if (gm->player->onGround && !gm->player->isInWater()) {
		gm->player->velocity.y = -99;
	}//Totally not the code from badman
}
