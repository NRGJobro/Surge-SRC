#include "Disabler.h"

Disabler::Disabler() : IModule('0', Category::MISC, "Disabler Made By Packet") {
	registerBoolSetting("Hive", &this->hive, this->hive);
	registerBoolSetting("Elytra Fly", &this->elytra, this->elytra);
	registerFloatSetting("Fly Speed", &this->speed, this->speed, 0.1f, 10.f);
}

const char* Disabler::getModuleName() {
	return ("Disabler");
}

void Disabler::onTick(C_GameMode* gm) {
	if (this->elytra && g_Data.isInGame()) {
	//gm->player->aabb.upper.y = gm->player->aabb.lower.y;
		if (gm->player->onGround) {
		g_Data.getLocalPlayer()->setPos((*g_Data.getLocalPlayer()->getPos()).add(0, 1.25, 0));
		}
	gm->player->fallDistance = 0;
	//gm->player->aabb.upper.y = 0.f;  // vertical
	glideModEffective = glideMod;
	C_GameSettingsInput* input = g_Data.getClientInstance()->getGameSettingsInput();

	if (g_Data.canUseMoveKeys()) {
		if (GameData::isKeyDown(*input->spaceBarKey))
			glideModEffective += speed;
		if (GameData::isKeyDown(*input->sneakKey))
			glideModEffective -= speed;
	}
	gm->player->velocity.y = glideModEffective;
		C_PlayerActionPacket p;
		p.action = 15;  //stop crouch packet
		//p.action = 16;
		p.entityRuntimeId = g_Data.getLocalPlayer()->entityRuntimeId;
		g_Data.getClientInstance()->loopbackPacketSender->sendToServer(&p);
	}
}

void Disabler::onMove(C_MoveInputHandler* input) {
	if (this->elytra && g_Data.isInGame()) {
		auto player = g_Data.getLocalPlayer();
		if (player == nullptr) return;

		vec2_t moveVec2d = {input->forwardMovement, -input->sideMovement};
		bool pressed = moveVec2d.magnitude() > 0.00f;

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
