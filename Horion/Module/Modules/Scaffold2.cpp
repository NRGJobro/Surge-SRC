#include "Scaffold2.h"

Scaffold2::Scaffold2() : IModule(0, Category::CUSTOM, "Fly, but for the hive") {
	//registerFloatSetting("Fly Speed", &this->speed, this->speed, 0.1f, 0.9f);
	registerBoolSetting("Blink Fly", &this->Fly, this->Fly);
	//registerBoolSetting("Damage Fly", &this->Blinc, this->Blinc);
	//registerBoolSetting("PVP Fly", &this->Glide, this->Glide);
}

Scaffold2::~Scaffold2() {
}

const char* Scaffold2::getModuleName() {
	return ("BlockFly");
}

void Scaffold2::onEnable() {
	if (this->Blinc) {
		auto player = g_Data.getLocalPlayer();
		player->animateHurt();
	}
}

void Scaffold2::onMove(C_MoveInputHandler* input) {
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

	if (pressed && Fly && counter == 1) {
		auto blinkMod = moduleMgr->getModule<Scaffold>();
		if (this->Fly) {
			blinkMod->setEnabled(true);
		}
	}
	if (pressed && Fly && counter == 2) {
		auto blinkMod = moduleMgr->getModule<Scaffold>();
		if (this->Fly) {
			blinkMod->setEnabled(true);
		}
	}
	if (pressed && Fly && counter == 4) {
		auto player = g_Data.getLocalPlayer();
		player->jumpFromGround();
	}

	if (counter == 11) {
		counter = 0;
	} else {
		counter++;
	}
}
void Scaffold2::onTick(C_GameMode* gm) {
}

void Scaffold2::onDisable() {
	auto blinkMod = moduleMgr->getModule<Scaffold>();
	auto player = g_Data.getLocalPlayer();

	if (blinkMod->isEnabled()) {
		blinkMod->setEnabled(false);
	}
}