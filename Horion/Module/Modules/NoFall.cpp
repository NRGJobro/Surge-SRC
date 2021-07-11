#include "NoFall.h"

NoFall::NoFall() : IModule(0x0, Category::MOVEMENT, "Fall Fast, Also works as antikb to an extent") {
}	

NoFall::~NoFall() {
}

const char* NoFall::getModuleName() {
	return ("FastFall");
}

void NoFall::onTick(C_GameMode* gm) {
	auto player = g_Data.getLocalPlayer();
	if (player == nullptr) return;

	if (gm->player->onGround && !gm->player->isInWater()) {
		gm->player->velocity.y = -100;
	}
}
