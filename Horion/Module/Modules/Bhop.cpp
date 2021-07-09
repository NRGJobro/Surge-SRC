#include "Bhop.h"

Bhop::Bhop() : IModule(0, Category::MOVEMENT, "Hop around like a bunny!") {
	registerFloatSetting("Speed", &this->speed, this->speed, 0.1f, 0.8f);
	registerFloatSetting("Timer Speed", &this->tspeed, this->tspeed, 0.21f, 2.f);
	registerBoolSetting("Timer", &this->timer, this->timer);
	registerBoolSetting("Speed", &this->bhopspeed, this->bhopspeed);
	registerBoolSetting("LowHop", &this->LowHop, this->LowHop);
}

Bhop::~Bhop() {
}

const char* Bhop::getModuleName() {
	return ("Bhop");
}

void Bhop::onMove(C_MoveInputHandler* input) {
	auto player = g_Data.getLocalPlayer();
	if (player == nullptr) return;

	if (player->isInLava() == 1 || player->isInWater() == 1) 
		return;
	
	if (player->isSneaking()) 
		return;

	vec2_t moveVec2d = {input->forwardMovement, -input->sideMovement};
	bool pressed = moveVec2d.magnitude() > 0.01f;
	
	if (pressed && LowHop) {
		player->velocity.x = -0.13f;
		player->velocity.y = -0.08f;
	}

	if (player->onGround && pressed)
		player->jumpFromGround();
	
	if (pressed && bhopspeed) {
		player->velocity.y = -0.5f;
	}

	float calcYaw = (player->yaw + 90) * (PI / 180);
	vec3_t moveVec;
	float c = cos(calcYaw);
	float s = sin(calcYaw);
	moveVec2d = {moveVec2d.x * c - moveVec2d.y * s, moveVec2d.x * s + moveVec2d.y * c};
	moveVec.x = moveVec2d.x * speed;
	moveVec.y = player->velocity.y;
	moveVec.z = moveVec2d.y * speed;
	if(pressed) player->lerpMotion(moveVec);
}

void Bhop::onTick(C_GameMode* gm) {
	auto stepMod = moduleMgr->getModule<Step>();
	if (g_Data.getLocalPlayer() == nullptr)
		return;
	if (!g_Data.canUseMoveKeys())
		return;
	if (this->timer) {
		*g_Data.getClientInstance()->minecraft->timer = 72.f * tspeed;
	}
}

void Bhop::onDisable() {
	*g_Data.getClientInstance()->minecraft->timer = 20.f;
}
