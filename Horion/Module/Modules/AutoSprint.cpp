#include "AutoSprint.h"

AutoSprint::AutoSprint() : IModule(0, Category::MOVEMENT, "Automatically sprint without holding the key") {
}

AutoSprint::~AutoSprint() {
}

const char* AutoSprint::getModuleName() {
	return ("AutoSprint");
}

void AutoSprint::onTick(C_GameMode* gm) {
	if (!gm->player->isSprinting() && gm->player->velocity.magnitudexz() > 0.01f) {
		C_GameSettingsInput* input = g_Data.getClientInstance()->getGameSettingsInput();
		if(GameData::isKeyDown(*input->forwardKey))
		gm->player->setSprinting(true);
	}
}
