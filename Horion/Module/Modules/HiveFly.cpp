#include "HiveFly.h"

HiveFly::HiveFly() : IModule(0, Category::CUSTOM, "Fly, but for the hive") {
	registerFloatSetting("Fly Speed", &this->speed, this->speed, 0.1f, 0.9f);
	registerBoolSetting("Blink Fly", &this->Fly, this->Fly);
	registerBoolSetting("Damage Fly", &this->Blinc, this->Blinc);
	registerBoolSetting("PVP Fly", &this->Glide, this->Glide);
}

HiveFly::~HiveFly() {
}

const char* HiveFly::getModuleName() {
	return ("HiveFly");
}

void HiveFly::onEnable() {
	if (this->Blinc) {
		auto player = g_Data.getLocalPlayer();
		player->animateHurt();
	}
	auto player = g_Data.getLocalPlayer();
	g_Data.getLocalPlayer()->setPos((*g_Data.getLocalPlayer()->getPos()).add(0, 1.25, 0));
	return;
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

	if (pressed && Fly && counter >= 0) {
		player->velocity.y = 0.f;
		auto blinkMod = moduleMgr->getModule<Blink>();
		if (this->Fly) {
			blinkMod->setEnabled(true);
		}
	}

	if (pressed && Fly && counter == 1) {
		auto blinkMod = moduleMgr->getModule<Blink>();
		if (blinkMod->isEnabled()) {
			blinkMod->setEnabled(false);
		}
		g_Data.getLocalPlayer()->setPos((*g_Data.getLocalPlayer()->getPos()).add(0, -0.15, 0));
	}

	if (counter == 32) {
		counter = 0;
	} else {
		counter++;
	}
	if (pressed && Glide) {
		*g_Data.getClientInstance()->minecraft->timer = 72.f * 0.30;
		float calcYaw = (player->yaw + 90) * (PI / 180);
		vec3_t moveVec;
		float c = cos(calcYaw);
		float s = sin(calcYaw);
		moveVec2d = {moveVec2d.x * c - moveVec2d.y * s, moveVec2d.x * s + moveVec2d.y * c};
		moveVec.x = moveVec2d.x * 0.23;
		moveVec.y = player->velocity.y;
		moveVec.z = moveVec2d.y * 0.23;
		if (pressed) player->lerpMotion(moveVec);
	} else {
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
}
void HiveFly::onTick(C_GameMode* gm) {
	glideModEffective = glideMod;
	C_GameSettingsInput* input = g_Data.getClientInstance()->getGameSettingsInput();

	if (g_Data.canUseMoveKeys()) {
		if (GameData::isKeyDown(*input->spaceBarKey))
			glideModEffective += 0.5f;
		if (GameData::isKeyDown(*input->sneakKey))
			glideModEffective -= 0.5f;
	}
	gm->player->velocity.y = glideModEffective;
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