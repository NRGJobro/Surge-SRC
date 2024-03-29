#include "Killaura.h"

Killaura::Killaura() : IModule('P', Category::COMBAT, "Attacks entities around you automatically(2474 helped with rotations)") {
	this->registerBoolSetting("MultiAura", &this->isMulti, this->isMulti);
	this->registerBoolSetting("MobAura", &this->isMobAura, this->isMobAura);
	this->registerFloatSetting("range", &this->range, this->range, 2.f, 7.f);
	this->registerIntSetting("delay", &this->delay, this->delay, 0, 20);
	this->registerBoolSetting("hurttime", &this->hurttime, this->hurttime);
	this->registerBoolSetting("AutoWeapon", &this->autoweapon, this->autoweapon);
	this->registerBoolSetting("Rotations", &this->silent, this->silent);
	//this->registerBoolSetting("Spin Rotations", &this->spin, this->spin);
	this->registerBoolSetting("Move To Target", &this->target, this->target);
	this->registerBoolSetting("NoSwing", &this->swingg, this->swingg);
	this->registerBoolSetting("Strafe", &this->strafe, this->strafe);
	this->registerFloatSetting("Strafe Speed", &this->speed, this->speed, 0.1f, 1.f);
}

Killaura::~Killaura() {
}

const char* Killaura::getModuleName() {
	return ("Killaura");
}

static std::vector<C_Entity*> targetList;

void findEntity(C_Entity* currentEntity, bool isRegularEntity) {
	auto KillauraMod = moduleMgr->getModule<Killaura>();
	if (!g_Data.isInGame())
		KillauraMod->setEnabled(false);
	static auto killauraMod = moduleMgr->getModule<Killaura>();

	if (currentEntity == nullptr)
		return;

	if (currentEntity == g_Data.getLocalPlayer())  // Skip Local player
		return;

	if (!g_Data.getLocalPlayer()->canAttack(currentEntity, false))
		return;

	if (!g_Data.getLocalPlayer()->isAlive())
		return;

	if (!currentEntity->isAlive())
		return;

	if (killauraMod->isMobAura) {
		if (currentEntity->getNameTag()->getTextLength() <= 1 && currentEntity->getEntityTypeId() == 63)
			return;
		if (currentEntity->width <= 0.01f || currentEntity->height <= 0.01f)  // Don't hit this pesky antibot on 2b2e.org
			return;
		if (currentEntity->getEntityTypeId() == 64)  // item
			return;
	} else {
		if (!Target::isValidTarget(currentEntity))
			return;
	}

	float dist = (*currentEntity->getPos()).dist(*g_Data.getLocalPlayer()->getPos());

	if (dist < killauraMod->range) {
		targetList.push_back(currentEntity);
	}
}
void Killaura::onMove(C_MoveInputHandler* input) {
	if (this->strafe) {
		auto player = g_Data.getLocalPlayer();
		if (player == nullptr) return;

		if (player->isInLava() == 1 || player->isInWater() == 1)
			return;

		if (player->isSneaking())
			return;

		float yaw = player->yaw;

		bool pressed = input->forward || input->backward || input->right || input->left;

		if (input->forward && input->backward)
			return;

		if (input->right) {
			yaw += 90.f;
			if (input->forward)
				yaw -= 45.f;
			else if (input->backward)
				yaw += 45.f;
		}
		if (input->left) {
			yaw -= 90.f;
			if (input->forward)
				yaw += 45.f;
			else if (input->backward)
				yaw -= 45.f;
		}

		if (input->backward && !input->left && !input->right)
			yaw += 180.f;

		float calcYaw = (yaw + 90) * (PI / 180);
		vec3_t moveVec;
		moveVec.x = cos(calcYaw) * speed;
		moveVec.y = player->velocity.y;
		moveVec.z = sin(calcYaw) * speed;
		if (pressed) player->lerpMotion(moveVec);
	}
}

void Killaura::findWeapon() {
	auto KillauraMod = moduleMgr->getModule<Killaura>();
	if (!g_Data.isInGame())
		KillauraMod->setEnabled(false);
	C_PlayerInventoryProxy* supplies = g_Data.getLocalPlayer()->getSupplies();
	C_Inventory* inv = supplies->inventory;
	float damage = 0;
	int slot = supplies->selectedHotbarSlot;
	for (int n = 0; n < 9; n++) {
		C_ItemStack* stack = inv->getItemStack(n);
		if (stack->item != nullptr) {
			float currentDamage = stack->isValid();
			if (currentDamage > damage) {
				damage = currentDamage;
				slot = n;
			}
		}
	}
	supplies->selectedHotbarSlot = slot;
}

void Killaura::onTick(C_GameMode* gm) {
	auto KillauraMod = moduleMgr->getModule<Killaura>();
	if (!g_Data.isInGame())
		this->setEnabled(false);
	//Loop through all our players and retrieve their information
	targetList.clear();

	g_Data.forEachEntity(findEntity);

	Odelay++;
	if (!targetList.empty() && Odelay >= delay) {
		if (autoweapon) findWeapon();

		if (g_Data.getLocalPlayer()->velocity.squaredxzlen() < 0.01) {
			C_MovePlayerPacket p(g_Data.getLocalPlayer(), *g_Data.getLocalPlayer()->getPos());
			g_Data.getClientInstance()->loopbackPacketSender->sendToServer(&p);  // make sure to update rotation if player is standing still
		}

		// Attack all entitys in targetList
		if (isMulti) {
			for (auto& i : targetList) {
				if (!(i->damageTime > 1 && hurttime)) {
					if (swingg) {
						//idk
					} else {
						g_Data.getLocalPlayer()->swing();
					}
					g_Data.getCGameMode()->attack(i);
				}
			}
		} else {
			if (!(targetList[0]->damageTime > 1 && hurttime)) {
				if (swingg) {
					//hi
				} else {
					g_Data.getLocalPlayer()->swing();
				}
				g_Data.getCGameMode()->attack(targetList[0]);
			}
		}
		if (this->target) {
			for (auto& i : targetList) {
				vec2_t angleCock = g_Data.getLocalPlayer()->getPos()->CalcAngle(*i->getPos()).normAngles();
				g_Data.getCGameMode()->player->yaw = angleCock.y;
				g_Data.getCGameMode()->player->yawUnused1 = angleCock.y;
			}
		}
		if (this->spin) {
			vec2_t angle = g_Data.getLocalPlayer()->getPos()->CalcAngle(*targetList[0]->getPos()).normAngles();
			auto player = g_Data.getLocalPlayer();
			g_Data.getLocalPlayer()->applyTurnDelta(&angle);
		}
		if (this->silent) {
			for (auto& i : targetList) {
				vec2_t angle = g_Data.getLocalPlayer()->getPos()->CalcAngle(*i->getPos()).normAngles();
				auto player = g_Data.getLocalPlayer();
				//player->pitch = angle.x;
				//player->pitch = angle.x;
				player->bodyYaw = angle.y;
				//player->bodyYaw = angle.x;
				//player->yawUnused1 = angle.x;
				player->yawUnused1 = angle.y;
			}
		}
	}
}

void Killaura::onLevelRender() {
}

void Killaura::onEnable() {
		auto KillauraMod = moduleMgr->getModule<Killaura>();
		if (!g_Data.isInGame())
			KillauraMod->setEnabled(false);
	if (g_Data.getLocalPlayer() == nullptr)
		this->setEnabled(false);
}

void Killaura::onSendPacket(C_Packet* packet) {
	auto KillauraMod = moduleMgr->getModule<Killaura>();
	if (!g_Data.isInGame())
		KillauraMod->setEnabled(false);
	if (packet->isInstanceOf<C_MovePlayerPacket>() && g_Data.getLocalPlayer() != nullptr) {
		if (!targetList.empty()) {
			auto* movePacket = reinterpret_cast<C_MovePlayerPacket*>(packet);
			vec2_t angle = g_Data.getLocalPlayer()->getPos()->CalcAngle(*targetList[0]->getPos());
			movePacket->pitch = angle.x;
			movePacket->headYaw = angle.y;
			movePacket->yaw = angle.y;
		}
	}
}
