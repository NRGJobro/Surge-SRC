#include "HiveFly.h"

HiveFly::HiveFly() : IModule(0, Category::MOVEMENT, "Hop around like a bunny!") {
	registerFloatSetting("Fly Speed", &this->speed, this->speed, 0.1f,0.9f);
	registerBoolSetting("Hive Fly", &this->Fly, this->Fly);
	registerBoolSetting("Blink Fly", &this->Blinc, this->Blinc);
	registerBoolSetting("Hive Glide", &this->Glide, this->Glide);
}

HiveFly::~HiveFly() {
}

const char* HiveFly::getModuleName() {
	return ("HiveFly");
}

void HiveFly::onMove(C_MoveInputHandler* input) {
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

	if (player->onGround && pressed)
		player->jumpFromGround();

	if (pressed && Fly) {
		player->velocity.y = 0.f;
	}
	

	float calcYaw = (player->yaw + 90) * (PI / 180);
	vec3_t moveVec;
	float c = cos(calcYaw);
	float s = sin(calcYaw);
	moveVec2d = {moveVec2d.x * c - moveVec2d.y * s, moveVec2d.x * s + moveVec2d.y * c};
	moveVec.x = moveVec2d.x * speed;
	moveVec.y = player->velocity.y;
	moveVec.z = moveVec2d.y * speed;
	if (pressed) player->lerpMotion(moveVec);
}
void HiveFly::onTick(C_GameMode* gm) {
auto blinkMod = moduleMgr->getModule<Blink>();
	if (this->Blinc) {
		blinkMod->setEnabled(true);
	}
}

void HiveFly::onDisable() {
	auto blinkMod = moduleMgr->getModule<Blink>();
	auto player = g_Data.getLocalPlayer();
	player->velocity.x = 0.f;
	player->velocity.y = 0.f;
	player->velocity.z = 0.f;
	
	if (blinkMod->isEnabled()) {
		blinkMod->setEnabled(false);
	}
}