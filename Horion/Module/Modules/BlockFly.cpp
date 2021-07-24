#include "BlockFly.h"

BlockFly::BlockFly() : IModule(0, Category::CUSTOM, "Fly, but for the hive") {
	//registerFloatSetting("Fly Speed", &this->speed, this->speed, 0.1f, 0.9f);
	registerBoolSetting("BlockFly", &this->Fly, this->Fly);
	//registerBoolSetting("Damage Fly", &this->Blinc, this->Blinc);
	//registerBoolSetting("PVP Fly", &this->Glide, this->Glide);
}

BlockFly::~BlockFly() {
}

const char* BlockFly::getModuleName() {
	return ("BlockFly");
}

void BlockFly::onEnable() {
	if (this->Blinc) {
		auto player = g_Data.getLocalPlayer();
		player->animateHurt();
	}
}

void BlockFly::onMove(C_MoveInputHandler* input) {
	auto player = g_Data.getLocalPlayer();
	if (player == nullptr) return;

	if (player->isInLava() == 1 || player->isInWater() == 1)
		return;

	if (player->isSneaking())
		return;

	vec2_t moveVec2d = {input->forwardMovement, -input->sideMovement};
	bool pressed = moveVec2d.magnitude() > 0.01f;

	if (pressed && Glide) {
		player->velocity.y = -0.24f;
	}

	if (pressed && Fly && counter >= 0) {
		auto blinkMod = moduleMgr->getModule<Scaffold>();
		if (blinkMod->isEnabled()) {
			blinkMod->setEnabled(false);
		}
	}
	if (pressed && Fly && counter == 2) {
		auto blinkMod = moduleMgr->getModule<Scaffold>();
		if (this->Fly) {
			blinkMod->setEnabled(true);
		}
	}
	if (pressed && Fly && counter == 4) {
		auto selectedItem = g_Data.getLocalPlayer()->getSelectedItem();
		if (!selectedItem->isValid() || !(*selectedItem->item)->isBlock())  // Block in hand?
			return;
		auto player = g_Data.getLocalPlayer();
		player->jumpFromGround();
	}

	if (counter == 11) {
		counter = 0;
	} else {
		counter++;
	}
}

void BlockFly::onTick(C_GameMode* gm) {
	auto blinkMod = moduleMgr->getModule<Scaffold>();
	blinkMod->spoof = false;
}

void BlockFly::onDisable() {
	auto blinkMod = moduleMgr->getModule<Scaffold>();
	auto player = g_Data.getLocalPlayer();
	blinkMod->spoof = true;

	if (blinkMod->isEnabled()) {
		blinkMod->setEnabled(false);
	}
}