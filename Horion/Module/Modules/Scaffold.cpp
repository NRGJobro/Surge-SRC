﻿#include "Scaffold.h"
/*
⠄⠄⠄⠄⠄⠄⣀⣤⣴⣶⣾⠟⠉⠻⣷⣶⣦⣤⣀⠄⠄⠄⠄⠄⠄ 
⠄⠄⠄⢀⣴⣾⣿⣿⣿⠟⠁⠄⠄⠄⣨⣿⣿⣿⣿⣷⣦⡀⠄⠄⠄ 
⠄⠄⣴⣿⣿⣿⣿⠟⠁⠄⠄⠄⣠⣾⣿⣿⣿⠿⣿⣿⣿⣿⣦⠄⠄ 
⠄⣼⣿⣿⣿⣏⠁⠄⠄⠄⠠⣾⣿⣿⡿⠏⠁⠄⠈⠹⢿⣿⣿⣧⠄ 
⢸⣿⡿⣿⣿⣿⣷⣄⠄⠄⠄⠈⠻⠋⠄⠄⠄⠄⠄⠄⠄⠙⢿⣿⡇
⡿⠋⠄⠈⠻⣿⣿⣿⣷⣄⠄⠄⠄⠄⠄⢀⣴⣿⣦⡀⠄⠄⠄⠙⢿ 
⣷⣄⠄⠄⠄⠈⠻⣿⠟⠁⠄⠄⠄⠄⠄⠙⢿⣿⣿⣿⣦⡀⠄⣠⣾ 
⢸⣿⣷⣄⠄⠄⠄⠄⠄⠄⠄⣠⣦⡀⠄⠄⠄⠙⢿⣿⣿⣿⣾⣿⡏ 
⠄⢻⣿⣿⣷⣆⡀⠄⠄⣠⣾⣿⣿⡿⠆⠄⠄⠄⢀⣹⣿⣿⣿⡟⠄ 
⠄⠄⠻⣿⣿⣿⣿⣦⣾⣿⣿⡿⠋⠄⠄⠄⢀⣴⣿⣿⣿⣿⠟⠄⠄ 
⠄⠄⠄⠈⠻⢿⣿⣿⣿⣿⡋⠄⠄⠄⢀⣴⣿⣿⣿⣿⠟⠁⠄⠄⠄ 
⠄⠄⠄⠄⠄⠄⠉⠛⠿⠿⢿⣦⣀⣴⣿⠿⠿⠛⠉⠄⠄⠄⠄⠄⠄
*/
#include "../../../Utils/Logger.h"
#include "../../Module/ModuleManager.h"
/*
⠄⠄⠄⠄⠄⠄⣀⣤⣴⣶⣾⠟⠉⠻⣷⣶⣦⣤⣀⠄⠄⠄⠄⠄⠄ 
⠄⠄⠄⢀⣴⣾⣿⣿⣿⠟⠁⠄⠄⠄⣨⣿⣿⣿⣿⣷⣦⡀⠄⠄⠄ 
⠄⠄⣴⣿⣿⣿⣿⠟⠁⠄⠄⠄⣠⣾⣿⣿⣿⠿⣿⣿⣿⣿⣦⠄⠄ 
⠄⣼⣿⣿⣿⣏⠁⠄⠄⠄⠠⣾⣿⣿⡿⠏⠁⠄⠈⠹⢿⣿⣿⣧⠄ 
⢸⣿⡿⣿⣿⣿⣷⣄⠄⠄⠄⠈⠻⠋⠄⠄⠄⠄⠄⠄⠄⠙⢿⣿⡇
⡿⠋⠄⠈⠻⣿⣿⣿⣷⣄⠄⠄⠄⠄⠄⢀⣴⣿⣦⡀⠄⠄⠄⠙⢿ 
⣷⣄⠄⠄⠄⠈⠻⣿⠟⠁⠄⠄⠄⠄⠄⠙⢿⣿⣿⣿⣦⡀⠄⣠⣾ 
⢸⣿⣷⣄⠄⠄⠄⠄⠄⠄⠄⣠⣦⡀⠄⠄⠄⠙⢿⣿⣿⣿⣾⣿⡏ 
⠄⢻⣿⣿⣷⣆⡀⠄⠄⣠⣾⣿⣿⡿⠆⠄⠄⠄⢀⣹⣿⣿⣿⡟⠄ 
⠄⠄⠻⣿⣿⣿⣿⣦⣾⣿⣿⡿⠋⠄⠄⠄⢀⣴⣿⣿⣿⣿⠟⠄⠄ 
⠄⠄⠄⠈⠻⢿⣿⣿⣿⣿⡋⠄⠄⠄⢀⣴⣿⣿⣿⣿⠟⠁⠄⠄⠄ 
⠄⠄⠄⠄⠄⠄⠉⠛⠿⠿⢿⣦⣀⣴⣿⠿⠿⠛⠉⠄⠄⠄⠄⠄⠄
*/
Scaffold::Scaffold() : IModule(0, Category::WORLD, "it makes me mad how bad u r at coding - packet") {
	registerBoolSetting("Freecam Scaffold", &this->free, this->free);
	registerBoolSetting("Timer", &this->timerBool, this->timerBool);
	registerBoolSetting("AirPlace", &this->airplace, this->airplace);
	registerBoolSetting("Scaffold Box", &this->box, this->box);
	registerBoolSetting("Working Spoof", &this->AutoSort, this->AutoSort);
	registerBoolSetting("Staircase Mode", &this->staircaseMode, this->staircaseMode);
	registerBoolSetting("Andromeda Bridge", &this->andromeda, this->andromeda);
	registerBoolSetting("Tower", &this->tower, this->tower);
	//registerBoolSetting("Auto select", &this->AutoSelect, this->AutoSelect);
	registerBoolSetting("Thick", &this->extend, this->extend);
	registerFloatSetting("Thick Radius", &thicc, thicc, 0.1f, 0.7f);
	registerBoolSetting("Rotations", &this->rot, this->rot);
	this->registerIntSetting("TPS", &this->timer, this->timer, 20, 200);
	registerFloatSetting("Tower Speed", &towerspeed, towerspeed, 0.5f, 3.f);
}
/*
⠄⠄⠄⠄⠄⠄⣀⣤⣴⣶⣾⠟⠉⠻⣷⣶⣦⣤⣀⠄⠄⠄⠄⠄⠄ 
⠄⠄⠄⢀⣴⣾⣿⣿⣿⠟⠁⠄⠄⠄⣨⣿⣿⣿⣿⣷⣦⡀⠄⠄⠄ 
⠄⠄⣴⣿⣿⣿⣿⠟⠁⠄⠄⠄⣠⣾⣿⣿⣿⠿⣿⣿⣿⣿⣦⠄⠄ 
⠄⣼⣿⣿⣿⣏⠁⠄⠄⠄⠠⣾⣿⣿⡿⠏⠁⠄⠈⠹⢿⣿⣿⣧⠄ 
⢸⣿⡿⣿⣿⣿⣷⣄⠄⠄⠄⠈⠻⠋⠄⠄⠄⠄⠄⠄⠄⠙⢿⣿⡇
⡿⠋⠄⠈⠻⣿⣿⣿⣷⣄⠄⠄⠄⠄⠄⢀⣴⣿⣦⡀⠄⠄⠄⠙⢿ 
⣷⣄⠄⠄⠄⠈⠻⣿⠟⠁⠄⠄⠄⠄⠄⠙⢿⣿⣿⣿⣦⡀⠄⣠⣾ 
⢸⣿⣷⣄⠄⠄⠄⠄⠄⠄⠄⣠⣦⡀⠄⠄⠄⠙⢿⣿⣿⣿⣾⣿⡏ 
⠄⢻⣿⣿⣷⣆⡀⠄⠄⣠⣾⣿⣿⡿⠆⠄⠄⠄⢀⣹⣿⣿⣿⡟⠄ 
⠄⠄⠻⣿⣿⣿⣿⣦⣾⣿⣿⡿⠋⠄⠄⠄⢀⣴⣿⣿⣿⣿⠟⠄⠄ 
⠄⠄⠄⠈⠻⢿⣿⣿⣿⣿⡋⠄⠄⠄⢀⣴⣿⣿⣿⣿⠟⠁⠄⠄⠄ 
⠄⠄⠄⠄⠄⠄⠉⠛⠿⠿⢿⣦⣀⣴⣿⠿⠿⠛⠉⠄⠄⠄⠄⠄⠄
*/
Scaffold::~Scaffold() {
}
/*
⠄⠄⠄⠄⠄⠄⣀⣤⣴⣶⣾⠟⠉⠻⣷⣶⣦⣤⣀⠄⠄⠄⠄⠄⠄ 
⠄⠄⠄⢀⣴⣾⣿⣿⣿⠟⠁⠄⠄⠄⣨⣿⣿⣿⣿⣷⣦⡀⠄⠄⠄ 
⠄⠄⣴⣿⣿⣿⣿⠟⠁⠄⠄⠄⣠⣾⣿⣿⣿⠿⣿⣿⣿⣿⣦⠄⠄ 
⠄⣼⣿⣿⣿⣏⠁⠄⠄⠄⠠⣾⣿⣿⡿⠏⠁⠄⠈⠹⢿⣿⣿⣧⠄ 
⢸⣿⡿⣿⣿⣿⣷⣄⠄⠄⠄⠈⠻⠋⠄⠄⠄⠄⠄⠄⠄⠙⢿⣿⡇
⡿⠋⠄⠈⠻⣿⣿⣿⣷⣄⠄⠄⠄⠄⠄⢀⣴⣿⣦⡀⠄⠄⠄⠙⢿ 
⣷⣄⠄⠄⠄⠈⠻⣿⠟⠁⠄⠄⠄⠄⠄⠙⢿⣿⣿⣿⣦⡀⠄⣠⣾ 
⢸⣿⣷⣄⠄⠄⠄⠄⠄⠄⠄⣠⣦⡀⠄⠄⠄⠙⢿⣿⣿⣿⣾⣿⡏ 
⠄⢻⣿⣿⣷⣆⡀⠄⠄⣠⣾⣿⣿⡿⠆⠄⠄⠄⢀⣹⣿⣿⣿⡟⠄ 
⠄⠄⠻⣿⣿⣿⣿⣦⣾⣿⣿⡿⠋⠄⠄⠄⢀⣴⣿⣿⣿⣿⠟⠄⠄ 
⠄⠄⠄⠈⠻⢿⣿⣿⣿⣿⡋⠄⠄⠄⢀⣴⣿⣿⣿⣿⠟⠁⠄⠄⠄ 
⠄⠄⠄⠄⠄⠄⠉⠛⠿⠿⢿⣦⣀⣴⣿⠿⠿⠛⠉⠄⠄⠄⠄⠄⠄
*/
const char* Scaffold::getModuleName() {
	return "Scaffold";
}
/*
⠄⠄⠄⠄⠄⠄⣀⣤⣴⣶⣾⠟⠉⠻⣷⣶⣦⣤⣀⠄⠄⠄⠄⠄⠄ 
⠄⠄⠄⢀⣴⣾⣿⣿⣿⠟⠁⠄⠄⠄⣨⣿⣿⣿⣿⣷⣦⡀⠄⠄⠄ 
⠄⠄⣴⣿⣿⣿⣿⠟⠁⠄⠄⠄⣠⣾⣿⣿⣿⠿⣿⣿⣿⣿⣦⠄⠄ 
⠄⣼⣿⣿⣿⣏⠁⠄⠄⠄⠠⣾⣿⣿⡿⠏⠁⠄⠈⠹⢿⣿⣿⣧⠄ 
⢸⣿⡿⣿⣿⣿⣷⣄⠄⠄⠄⠈⠻⠋⠄⠄⠄⠄⠄⠄⠄⠙⢿⣿⡇
⡿⠋⠄⠈⠻⣿⣿⣿⣷⣄⠄⠄⠄⠄⠄⢀⣴⣿⣦⡀⠄⠄⠄⠙⢿ 
⣷⣄⠄⠄⠄⠈⠻⣿⠟⠁⠄⠄⠄⠄⠄⠙⢿⣿⣿⣿⣦⡀⠄⣠⣾ 
⢸⣿⣷⣄⠄⠄⠄⠄⠄⠄⠄⣠⣦⡀⠄⠄⠄⠙⢿⣿⣿⣿⣾⣿⡏ 
⠄⢻⣿⣿⣷⣆⡀⠄⠄⣠⣾⣿⣿⡿⠆⠄⠄⠄⢀⣹⣿⣿⣿⡟⠄ 
⠄⠄⠻⣿⣿⣿⣿⣦⣾⣿⣿⡿⠋⠄⠄⠄⢀⣴⣿⣿⣿⣿⠟⠄⠄ 
⠄⠄⠄⠈⠻⢿⣿⣿⣿⣿⡋⠄⠄⠄⢀⣴⣿⣿⣿⣿⠟⠁⠄⠄⠄ 
⠄⠄⠄⠄⠄⠄⠉⠛⠿⠿⢿⣦⣀⣴⣿⠿⠿⠛⠉⠄⠄⠄⠄⠄⠄
*/
bool Scaffold::tryScaffold(vec3_t blockBelow) {
	blockBelow = blockBelow.floor();
	if (box) {
		DrawUtils::drawBoxScaffold(blockBelow,MC_Color (0, 0, 255), vec3_t(blockBelow).add(1), 1.f);
	}
	C_Block* block = g_Data.getLocalPlayer()->region->getBlock(vec3_ti(blockBelow));
	C_BlockLegacy* blockLegacy = (block->blockLegacy);
	if (blockLegacy->material->isReplaceable) {
		vec3_ti blok(blockBelow);
		/*
⠄⠄⠄⠄⠄⠄⣀⣤⣴⣶⣾⠟⠉⠻⣷⣶⣦⣤⣀⠄⠄⠄⠄⠄⠄ 
⠄⠄⠄⢀⣴⣾⣿⣿⣿⠟⠁⠄⠄⠄⣨⣿⣿⣿⣿⣷⣦⡀⠄⠄⠄ 
⠄⠄⣴⣿⣿⣿⣿⠟⠁⠄⠄⠄⣠⣾⣿⣿⣿⠿⣿⣿⣿⣿⣦⠄⠄ 
⠄⣼⣿⣿⣿⣏⠁⠄⠄⠄⠠⣾⣿⣿⡿⠏⠁⠄⠈⠹⢿⣿⣿⣧⠄ 
⢸⣿⡿⣿⣿⣿⣷⣄⠄⠄⠄⠈⠻⠋⠄⠄⠄⠄⠄⠄⠄⠙⢿⣿⡇
⡿⠋⠄⠈⠻⣿⣿⣿⣷⣄⠄⠄⠄⠄⠄⢀⣴⣿⣦⡀⠄⠄⠄⠙⢿ 
⣷⣄⠄⠄⠄⠈⠻⣿⠟⠁⠄⠄⠄⠄⠄⠙⢿⣿⣿⣿⣦⡀⠄⣠⣾ 
⢸⣿⣷⣄⠄⠄⠄⠄⠄⠄⠄⣠⣦⡀⠄⠄⠄⠙⢿⣿⣿⣿⣾⣿⡏ 
⠄⢻⣿⣿⣷⣆⡀⠄⠄⣠⣾⣿⣿⡿⠆⠄⠄⠄⢀⣹⣿⣿⣿⡟⠄ 
⠄⠄⠻⣿⣿⣿⣿⣦⣾⣿⣿⡿⠋⠄⠄⠄⢀⣴⣿⣿⣿⣿⠟⠄⠄ 
⠄⠄⠄⠈⠻⢿⣿⣿⣿⣿⡋⠄⠄⠄⢀⣴⣿⣿⣿⣿⠟⠁⠄⠄⠄ 
⠄⠄⠄⠄⠄⠄⠉⠛⠿⠿⢿⣦⣀⣴⣿⠿⠿⠛⠉⠄⠄⠄⠄⠄⠄
*/
		// Find neighbour
		if (airplace) {
			static std::vector<vec3_ti*> checklist;
			if (checklist.empty()) {
				checklist.push_back(new vec3_ti(0, -1, 0));
				checklist.push_back(new vec3_ti(0, 1, 0));
			}
			bool foundCandidate = true;
			int i = 0;
			for (auto current : checklist) {
				vec3_ti calc = blok.sub(*current);
				bool Y = ((g_Data.getLocalPlayer()->region->getBlock(calc)->blockLegacy))->material->isReplaceable;
				if (!((g_Data.getLocalPlayer()->region->getBlock(calc)->blockLegacy))->material->isReplaceable) {
					// Found a solid block to click
					foundCandidate = true;
					blok = calc;
					break;
				}
				i++;
			}
			if (foundCandidate) {
				if (spoof) findBlock();
				bool foundCandidate = true;
				g_Data.getCGameMode()->buildBlock(&blok, i);

				return true;
			}
		} else {
			static std::vector<vec3_ti*> checklist;
			if (checklist.empty()) {
				checklist.push_back(new vec3_ti(0, -1, 0));
				checklist.push_back(new vec3_ti(0, 1, 0));

				checklist.push_back(new vec3_ti(0, 0, -1));
				checklist.push_back(new vec3_ti(0, 0, 1));

				checklist.push_back(new vec3_ti(-1, 0, 0));
				checklist.push_back(new vec3_ti(1, 0, 0));
			}
			bool foundCandidate = false;
			int i = 0;
			for (auto current : checklist) {
				vec3_ti calc = blok.sub(*current);
				bool Y = ((g_Data.getLocalPlayer()->region->getBlock(calc)->blockLegacy))->material->isReplaceable;
				if (!((g_Data.getLocalPlayer()->region->getBlock(calc)->blockLegacy))->material->isReplaceable) {
					// Found a solid block to click
					foundCandidate = true;
					blok = calc;
					break;
				}
				i++;
			}
			if (foundCandidate) {
				if (spoof) findBlock();
				bool foundCandidate = true;
				g_Data.getCGameMode()->buildBlock(&blok, i);

				return true;
			}
		}
		return false;
	}
}

bool Scaffold::findBlock() {
	if (this->AutoSelect) {
		C_PlayerInventoryProxy* supplies = g_Data.getLocalPlayer()->getSupplies();
		C_Inventory* inv = supplies->inventory;
		float damage = 0;
		int slot = supplies->selectedHotbarSlot;
		for (int n = 0; n < 9; n++) {
			C_ItemStack* stack = inv->getItemStack(n);
			if (stack->item != nullptr) {
				if ((*stack->item)->isBlock()) {
					slot = n;
				}
			}
		}
		supplies->selectedHotbarSlot = slot;
		return false;
	}
}

void Scaffold::onLevelRender() {
	auto freecamMod = moduleMgr->getModule<Freecam>();
	auto towerMod = moduleMgr->getModule<Tower>();
	freecamMod->speed = 0.32f;
	towerMod->motion = 0.5f * towerspeed;
	if (g_Data.getLocalPlayer() == nullptr)
		return;
	if (!g_Data.canUseMoveKeys())
		return;
	if (this->free) {
		freecamMod->setEnabled(true);
	}
	if (this->tower) {
		towerMod->setEnabled(true);
	}
	if (timerBool) {
		*g_Data.getClientInstance()->minecraft->timer = static_cast<float>(this->timer);
	}
	if (!timerBool) {
		*g_Data.getClientInstance()->minecraft->timer = 20.f;
	}

	auto selectedItem = g_Data.getLocalPlayer()->getSelectedItem();
	if ((selectedItem == nullptr || selectedItem->count == 0 || selectedItem->item == nullptr || !selectedItem->getItem()->isBlock()) && !spoof && !box)  // Block in hand?
		return;

	// Adjustment by velocity
	float speed = g_Data.getLocalPlayer()->velocity.magnitudexz();
	vec3_t vel = g_Data.getLocalPlayer()->velocity;
	vel = vel.normalize();  // Only use values from 0 - 1
	vec3_t blockBelow = g_Data.getLocalPlayer()->eyePos0;  // Block below the player
	blockBelow.y -= g_Data.getLocalPlayer()->height;
	blockBelow.y -= 0.5f;
	if (this->rot) {
		auto player = g_Data.getLocalPlayer();
		//player->bodyYaw = blockBelow.y;
		player->bodyYaw = blockBelow.y;
	}
	if (extend) {
		vec3_t blockBelow = g_Data.getLocalPlayer()->eyePos0;  // Block below the player
		blockBelow.x -= 0.1f;
		blockBelow.z -= 0.f * thicc;
		blockBelow.y -= g_Data.getLocalPlayer()->height;
		blockBelow.y -= 0.5f;

		if (!tryScaffold(blockBelow)) {
			if (speed > 0.05f) {  // Are we actually walking?
				blockBelow.z -= vel.z * 0.4f;
				if (!tryScaffold(blockBelow)) {
					blockBelow.x -= vel.x * 0.4f;
					if (!tryScaffold(blockBelow) && g_Data.getLocalPlayer()->isSprinting()) {
						blockBelow.z += vel.z;
						blockBelow.x += vel.x;
						tryScaffold(blockBelow);
					}
				}
			}
		}
	}

	if (extend) {
		vec3_t blockBelow = g_Data.getLocalPlayer()->eyePos0;  // Block below the player
		blockBelow.x -= 0.1f;
		blockBelow.z += 0.f * thicc;
		blockBelow.y -= g_Data.getLocalPlayer()->height;
		blockBelow.y -= 0.5f;

		if (!tryScaffold(blockBelow)) {
			if (speed > 0.05f) {  // Are we actually walking?
				blockBelow.z -= vel.z * 0.4f;
				if (!tryScaffold(blockBelow)) {
					blockBelow.x -= vel.x * 0.4f;
					if (!tryScaffold(blockBelow) && g_Data.getLocalPlayer()->isSprinting()) {
						blockBelow.z += vel.z;
						blockBelow.x += vel.x;
						tryScaffold(blockBelow);
					}
				}
			}
		}
	}

	if (extend) {
		vec3_t blockBelow = g_Data.getLocalPlayer()->eyePos0;  // Block below the player
		blockBelow.x -= 0.1f;
		blockBelow.z -= 1.f * thicc;
		blockBelow.y -= g_Data.getLocalPlayer()->height;
		blockBelow.y -= 0.5f;

		if (!tryScaffold(blockBelow)) {
			if (speed > 0.05f) {  // Are we actually walking?
				blockBelow.z -= vel.z * 0.4f;
				if (!tryScaffold(blockBelow)) {
					blockBelow.x -= vel.x * 0.4f;
					if (!tryScaffold(blockBelow) && g_Data.getLocalPlayer()->isSprinting()) {
						blockBelow.z += vel.z;
						blockBelow.x += vel.x;
						tryScaffold(blockBelow);
					}
				}
			}
		}
	}
	if (extend) {
		vec3_t blockBelow = g_Data.getLocalPlayer()->eyePos0;  // Block below the player
		blockBelow.x -= 0.1f;
		blockBelow.z += 1.f * thicc;
		blockBelow.y -= g_Data.getLocalPlayer()->height;
		blockBelow.y -= 0.5f;

		if (!tryScaffold(blockBelow)) {
			if (speed > 0.05f) {  // Are we actually walking?
				blockBelow.z -= vel.z * 0.4f;
				if (!tryScaffold(blockBelow)) {
					blockBelow.x -= vel.x * 0.4f;
					if (!tryScaffold(blockBelow) && g_Data.getLocalPlayer()->isSprinting()) {
						blockBelow.z += vel.z;
						blockBelow.x += vel.x;
						tryScaffold(blockBelow);
					}
				}
			}
		}
	}

	if (extend) {
		vec3_t blockBelow = g_Data.getLocalPlayer()->eyePos0;  // Block below the player
		blockBelow.x -= 0.1f;
		blockBelow.z -= 2.f * thicc;
		blockBelow.y -= g_Data.getLocalPlayer()->height;
		blockBelow.y -= 0.5f;

		if (!tryScaffold(blockBelow)) {
			if (speed > 0.05f) {  // Are we actually walking?
				blockBelow.z -= vel.z * 0.4f;
				if (!tryScaffold(blockBelow)) {
					blockBelow.x -= vel.x * 0.4f;
					if (!tryScaffold(blockBelow) && g_Data.getLocalPlayer()->isSprinting()) {
						blockBelow.z += vel.z;
						blockBelow.x += vel.x;
						tryScaffold(blockBelow);
					}
				}
			}
		}
	}
	if (extend) {
		vec3_t blockBelow = g_Data.getLocalPlayer()->eyePos0;  // Block below the player
		blockBelow.x -= 0.1f;
		blockBelow.z += 2.f * thicc;
		blockBelow.y -= g_Data.getLocalPlayer()->height;
		blockBelow.y -= 0.5f;

		if (!tryScaffold(blockBelow)) {
			if (speed > 0.05f) {  // Are we actually walking?
				blockBelow.z -= vel.z * 0.4f;
				if (!tryScaffold(blockBelow)) {
					blockBelow.x -= vel.x * 0.4f;
					if (!tryScaffold(blockBelow) && g_Data.getLocalPlayer()->isSprinting()) {
						blockBelow.z += vel.z;
						blockBelow.x += vel.x;
						tryScaffold(blockBelow);
					}
				}
			}
		}
	}
	if (extend) {
		vec3_t blockBelow = g_Data.getLocalPlayer()->eyePos0;  // Block below the player
		blockBelow.x -= 0.1f;
		blockBelow.z -= 3.f * thicc;
		blockBelow.y -= g_Data.getLocalPlayer()->height;
		blockBelow.y -= 0.5f;

		if (!tryScaffold(blockBelow)) {
			if (speed > 0.05f) {  // Are we actually walking?
				blockBelow.z -= vel.z * 0.4f;
				if (!tryScaffold(blockBelow)) {
					blockBelow.x -= vel.x * 0.4f;
					if (!tryScaffold(blockBelow) && g_Data.getLocalPlayer()->isSprinting()) {
						blockBelow.z += vel.z;
						blockBelow.x += vel.x;
						tryScaffold(blockBelow);
					}
				}
			}
		}
	}

	if (extend) {
		vec3_t blockBelow = g_Data.getLocalPlayer()->eyePos0;  // Block below the player
		blockBelow.x -= 0.1f;
		blockBelow.z += 3.f * thicc;
		blockBelow.y -= g_Data.getLocalPlayer()->height;
		blockBelow.y -= 0.5f;

		if (!tryScaffold(blockBelow)) {
			if (speed > 0.05f) {  // Are we actually walking?
				blockBelow.z -= vel.z * 0.4f;
				if (!tryScaffold(blockBelow)) {
					blockBelow.x -= vel.x * 0.4f;
					if (!tryScaffold(blockBelow) && g_Data.getLocalPlayer()->isSprinting()) {
						blockBelow.z += vel.z;
						blockBelow.x += vel.x;
						tryScaffold(blockBelow);
					}
				}
			}
		}
	}
	if (extend) {
		vec3_t blockBelow = g_Data.getLocalPlayer()->eyePos0;  // Block below the player
		blockBelow.x -= 0.1f;
		blockBelow.z -= 4.f * thicc;
		blockBelow.y -= g_Data.getLocalPlayer()->height;
		blockBelow.y -= 0.5f;

		if (!tryScaffold(blockBelow)) {
			if (speed > 0.05f) {  // Are we actually walking?
				blockBelow.z -= vel.z * 0.4f;
				if (!tryScaffold(blockBelow)) {
					blockBelow.x -= vel.x * 0.4f;
					if (!tryScaffold(blockBelow) && g_Data.getLocalPlayer()->isSprinting()) {
						blockBelow.z += vel.z;
						blockBelow.x += vel.x;
						tryScaffold(blockBelow);
					}
				}
			}
		}
	}
	if (extend) {
		vec3_t blockBelow = g_Data.getLocalPlayer()->eyePos0;  // Block below the player
		blockBelow.x -= 0.1f;
		blockBelow.z += 4.f * thicc;
		blockBelow.y -= g_Data.getLocalPlayer()->height;
		blockBelow.y -= 0.5f;

		if (!tryScaffold(blockBelow)) {
			if (speed > 0.05f) {  // Are we actually walking?
				blockBelow.z -= vel.z * 0.4f;
				if (!tryScaffold(blockBelow)) {
					blockBelow.x -= vel.x * 0.4f;
					if (!tryScaffold(blockBelow) && g_Data.getLocalPlayer()->isSprinting()) {
						blockBelow.z += vel.z;
						blockBelow.x += vel.x;
						tryScaffold(blockBelow);
					}
				}
			}
		}
	}
	if (this->andromeda) {
		vec3_t blockBelow = g_Data.getLocalPlayer()->eyePos0;  // Block 1 block below the player
		blockBelow.y -= g_Data.getLocalPlayer()->height;
		blockBelow.y -= 0.5f;

		vec3_t blockBelowBelow = g_Data.getLocalPlayer()->eyePos0;  // Block 3 blocks above the player
		blockBelowBelow.y -= g_Data.getLocalPlayer()->height;
		blockBelowBelow.y += 3.0f;

		if (!tryScaffold(blockBelow) && !tryScaffold(blockBelowBelow)) {
			if (speed > 0.05f) {  // Are we actually walking?
				blockBelow.z -= vel.z * 0.4f;
				blockBelowBelow.z -= vel.z * 0.4f;
				if (!tryScaffold(blockBelow) && !tryScaffold(blockBelowBelow)) {
					blockBelow.x -= vel.x * 0.4f;
					blockBelowBelow.x -= vel.x * 0.4f;
					if (!tryScaffold(blockBelow) && !tryScaffold(blockBelowBelow) && g_Data.getLocalPlayer()->isSprinting()) {
						blockBelow.z += vel.z;
						blockBelow.x += vel.x;
						blockBelowBelow.z += vel.z;
						blockBelowBelow.x += vel.x;
						tryScaffold(blockBelow);
						tryScaffold(blockBelowBelow);
					}
				}
			}
		}
	}
	if (this->staircaseMode) {
		vec3_t blockBelow = g_Data.getLocalPlayer()->eyePos0;  // Block 1 block below the player
		blockBelow.y -= g_Data.getLocalPlayer()->height;
		blockBelow.y -= 1.5f;

		vec3_t blockBelowBelow = g_Data.getLocalPlayer()->eyePos0;  // Block 2 blocks below the player
		blockBelowBelow.y -= g_Data.getLocalPlayer()->height;
		blockBelowBelow.y -= 2.0f;

		if (!tryScaffold(blockBelow) && !tryScaffold(blockBelowBelow)) {
			if (speed > 0.05f) {  // Are we actually walking?
				blockBelow.z -= vel.z * 0.4f;
				blockBelowBelow.z -= vel.z * 0.4f;
				if (!tryScaffold(blockBelow) && !tryScaffold(blockBelowBelow)) {
					blockBelow.x -= vel.x * 0.4f;
					blockBelowBelow.x -= vel.x * 0.4f;
					if (!tryScaffold(blockBelow) && !tryScaffold(blockBelowBelow) && g_Data.getLocalPlayer()->isSprinting()) {
						blockBelow.z += vel.z;
						blockBelow.x += vel.x;
						blockBelowBelow.z += vel.z;
						blockBelowBelow.x += vel.x;
						tryScaffold(blockBelow);
						tryScaffold(blockBelowBelow);
					}
				}
			}
		}
	} else {
		vec3_t blockBelow = g_Data.getLocalPlayer()->eyePos0;  // Block below the player
		blockBelow.y -= g_Data.getLocalPlayer()->height;
		blockBelow.y -= 0.5f;
		if (!tryScaffold(blockBelow)) {
			if (speed > 0.05f) {
				if (this->rot) {
					auto player = g_Data.getLocalPlayer();
					player->bodyYaw = blockBelow.y;
					player->bodyYaw = blockBelow.x;
				}
				blockBelow.z -= vel.z * 0.4f;
				if (!tryScaffold(blockBelow)) {
					blockBelow.x -= vel.x * 0.4f;
					if (!tryScaffold(blockBelow) && g_Data.getLocalPlayer()->isSprinting()) {
						blockBelow.z += vel.z;
						blockBelow.x += vel.x;
						tryScaffold(blockBelow);
					}
				}
			}
		}
		if (!tryScaffold(blockBelow)) {
			if (speed > 0.05f) {  // Are we actually walking?
				blockBelow.z -= vel.z * 0.4f;
				if (!tryScaffold(blockBelow)) {
					blockBelow.x -= vel.x * 0.4f;
					if (!tryScaffold(blockBelow) && g_Data.getLocalPlayer()->isSprinting()) {
						blockBelow.z += vel.z;
						blockBelow.x += vel.x;
						tryScaffold(blockBelow);
					}
				}
			}
		}
		if (!tryScaffold(blockBelow)) {
			if (speed > 0.05f) {
				if (this->rot) {
					auto player = g_Data.getLocalPlayer();
					player->bodyYaw = blockBelow.y;
					player->bodyYaw = blockBelow.x;
				}
				blockBelow.z -= vel.z * 0.4f;
				if (!tryScaffold(blockBelow)) {
					blockBelow.x -= vel.x * 0.4f;
					if (!tryScaffold(blockBelow) && g_Data.getLocalPlayer()->isSprinting()) {
						blockBelow.z += vel.z;
						blockBelow.x += vel.x;
						tryScaffold(blockBelow);
					}
				}
			}
		}
	}
	if (shouldChange) {
		shouldChange = true;
	}
	this->delay++;
	if (supplies == nullptr)
		supplies = g_Data.getLocalPlayer()->getSupplies();
	if (inv == nullptr)
		inv = supplies->inventory;
	if (this->delay == 0) {
		return;
	}

	if (this->AutoSort && tower) {
		return;
	} else {
		if (this->AutoSort) {
			C_PlayerInventoryProxy* supplies = g_Data.getLocalPlayer()->getSupplies();
			C_Inventory* inv = supplies->inventory;
			supplies->selectedHotbarSlot = slot;
		}
	}
	if (this->delay >= 2) {
		this->delay = 0;
		return;
	}
}
/*
⠄⠄⠄⠄⠄⠄⣀⣤⣴⣶⣾⠟⠉⠻⣷⣶⣦⣤⣀⠄⠄⠄⠄⠄⠄ 
⠄⠄⠄⢀⣴⣾⣿⣿⣿⠟⠁⠄⠄⠄⣨⣿⣿⣿⣿⣷⣦⡀⠄⠄⠄ 
⠄⠄⣴⣿⣿⣿⣿⠟⠁⠄⠄⠄⣠⣾⣿⣿⣿⠿⣿⣿⣿⣿⣦⠄⠄ 
⠄⣼⣿⣿⣿⣏⠁⠄⠄⠄⠠⣾⣿⣿⡿⠏⠁⠄⠈⠹⢿⣿⣿⣧⠄ 
⢸⣿⡿⣿⣿⣿⣷⣄⠄⠄⠄⠈⠻⠋⠄⠄⠄⠄⠄⠄⠄⠙⢿⣿⡇
⡿⠋⠄⠈⠻⣿⣿⣿⣷⣄⠄⠄⠄⠄⠄⢀⣴⣿⣦⡀⠄⠄⠄⠙⢿ 
⣷⣄⠄⠄⠄⠈⠻⣿⠟⠁⠄⠄⠄⠄⠄⠙⢿⣿⣿⣿⣦⡀⠄⣠⣾ 
⢸⣿⣷⣄⠄⠄⠄⠄⠄⠄⠄⣠⣦⡀⠄⠄⠄⠙⢿⣿⣿⣿⣾⣿⡏ 
⠄⢻⣿⣿⣷⣆⡀⠄⠄⣠⣾⣿⣿⡿⠆⠄⠄⠄⢀⣹⣿⣿⣿⡟⠄ 
⠄⠄⠻⣿⣿⣿⣿⣦⣾⣿⣿⡿⠋⠄⠄⠄⢀⣴⣿⣿⣿⣿⠟⠄⠄ 
⠄⠄⠄⠈⠻⢿⣿⣿⣿⣿⡋⠄⠄⠄⢀⣴⣿⣿⣿⣿⠟⠁⠄⠄⠄ 
⠄⠄⠄⠄⠄⠄⠉⠛⠿⠿⢿⣦⣀⣴⣿⠿⠿⠛⠉⠄⠄⠄⠄⠄⠄
*/
void Scaffold::onPostRender(C_MinecraftUIRenderContext* renderCtx) {
	vec3_t blockBelow = g_Data.getLocalPlayer()->eyePos0;  // Block below the player
	blockBelow.y -= g_Data.getLocalPlayer()->height;
	blockBelow.y -= 0.5f;

	// Adjustment by velocity
	//float speed = g_Data.getLocalPlayer()->velocity.magnitudexy();
	//vec3_t vel = g_Data.getLocalPlayer()->velocity;
	//vel.normalize();  // Only use values from 0 - 1

	if (!tryScaffold(blockBelow)) {
	} else {
		if (box) {
			(blockBelow.y);
		}
	}
}
/*
⠄⠄⠄⠄⠄⠄⣀⣤⣴⣶⣾⠟⠉⠻⣷⣶⣦⣤⣀⠄⠄⠄⠄⠄⠄ 
⠄⠄⠄⢀⣴⣾⣿⣿⣿⠟⠁⠄⠄⠄⣨⣿⣿⣿⣿⣷⣦⡀⠄⠄⠄ 
⠄⠄⣴⣿⣿⣿⣿⠟⠁⠄⠄⠄⣠⣾⣿⣿⣿⠿⣿⣿⣿⣿⣦⠄⠄ 
⠄⣼⣿⣿⣿⣏⠁⠄⠄⠄⠠⣾⣿⣿⡿⠏⠁⠄⠈⠹⢿⣿⣿⣧⠄ 
⢸⣿⡿⣿⣿⣿⣷⣄⠄⠄⠄⠈⠻⠋⠄⠄⠄⠄⠄⠄⠄⠙⢿⣿⡇
⡿⠋⠄⠈⠻⣿⣿⣿⣷⣄⠄⠄⠄⠄⠄⢀⣴⣿⣦⡀⠄⠄⠄⠙⢿ 
⣷⣄⠄⠄⠄⠈⠻⣿⠟⠁⠄⠄⠄⠄⠄⠙⢿⣿⣿⣿⣦⡀⠄⣠⣾ 
⢸⣿⣷⣄⠄⠄⠄⠄⠄⠄⠄⣠⣦⡀⠄⠄⠄⠙⢿⣿⣿⣿⣾⣿⡏ 
⠄⢻⣿⣿⣷⣆⡀⠄⠄⣠⣾⣿⣿⡿⠆⠄⠄⠄⢀⣹⣿⣿⣿⡟⠄ 
⠄⠄⠻⣿⣿⣿⣿⣦⣾⣿⣿⡿⠋⠄⠄⠄⢀⣴⣿⣿⣿⣿⠟⠄⠄ 
⠄⠄⠄⠈⠻⢿⣿⣿⣿⣿⡋⠄⠄⠄⢀⣴⣿⣿⣿⣿⠟⠁⠄⠄⠄ 
⠄⠄⠄⠄⠄⠄⠉⠛⠿⠿⢿⣦⣀⣴⣿⠿⠿⠛⠉⠄⠄⠄⠄⠄⠄
*/
void Scaffold::onMove(C_MoveInputHandler* input) {
	auto player = g_Data.getLocalPlayer();
	vec2_t moveVec2d = {input->forwardMovement, -input->sideMovement};
	vec3_t blockBelow = g_Data.getLocalPlayer()->eyePos0;  // Block below the player
	bool pressed = moveVec2d.magnitude() > 0.01f;
	if (player == nullptr) return;
}
/*
⠄⠄⠄⠄⠄⠄⣀⣤⣴⣶⣾⠟⠉⠻⣷⣶⣦⣤⣀⠄⠄⠄⠄⠄⠄ 
⠄⠄⠄⢀⣴⣾⣿⣿⣿⠟⠁⠄⠄⠄⣨⣿⣿⣿⣿⣷⣦⡀⠄⠄⠄ 
⠄⠄⣴⣿⣿⣿⣿⠟⠁⠄⠄⠄⣠⣾⣿⣿⣿⠿⣿⣿⣿⣿⣦⠄⠄ 
⠄⣼⣿⣿⣿⣏⠁⠄⠄⠄⠠⣾⣿⣿⡿⠏⠁⠄⠈⠹⢿⣿⣿⣧⠄ 
⢸⣿⡿⣿⣿⣿⣷⣄⠄⠄⠄⠈⠻⠋⠄⠄⠄⠄⠄⠄⠄⠙⢿⣿⡇
⡿⠋⠄⠈⠻⣿⣿⣿⣷⣄⠄⠄⠄⠄⠄⢀⣴⣿⣦⡀⠄⠄⠄⠙⢿ 
⣷⣄⠄⠄⠄⠈⠻⣿⠟⠁⠄⠄⠄⠄⠄⠙⢿⣿⣿⣿⣦⡀⠄⣠⣾ 
⢸⣿⣷⣄⠄⠄⠄⠄⠄⠄⠄⣠⣦⡀⠄⠄⠄⠙⢿⣿⣿⣿⣾⣿⡏ 
⠄⢻⣿⣿⣷⣆⡀⠄⠄⣠⣾⣿⣿⡿⠆⠄⠄⠄⢀⣹⣿⣿⣿⡟⠄ 
⠄⠄⠻⣿⣿⣿⣿⣦⣾⣿⣿⡿⠋⠄⠄⠄⢀⣴⣿⣿⣿⣿⠟⠄⠄ 
⠄⠄⠄⠈⠻⢿⣿⣿⣿⣿⡋⠄⠄⠄⢀⣴⣿⣿⣿⣿⠟⠁⠄⠄⠄ 
⠄⠄⠄⠄⠄⠄⠉⠛⠿⠿⢿⣦⣀⣴⣿⠿⠿⠛⠉⠄⠄⠄⠄⠄⠄
*/
void Scaffold::onDisable() {
	auto freecamMod = moduleMgr->getModule<Freecam>();
	auto towerMod = moduleMgr->getModule<Tower>();
	freecamMod->speed = .55f;
	if (freecamMod->isEnabled()) {
		freecamMod->setEnabled(false);
	}
	if (towerMod->isEnabled()) {
		towerMod->setEnabled(false);
	}
	*g_Data.getClientInstance()->minecraft->timer = 20.f;
	if (g_Data.getLocalPlayer() == nullptr)
			return;
		__int64 id = *g_Data.getLocalPlayer()->getUniqueId();
		C_PlayerInventoryProxy* supplies = g_Data.getLocalPlayer()->getSupplies();
		C_MobEquipmentPacket a(id, *g_Data.getLocalPlayer()->getSelectedItem(), supplies->selectedHotbarSlot, supplies->selectedHotbarSlot);
		g_Data.getClientInstance()->loopbackPacketSender->sendToServer(&a);
	}
/*
⠄⠄⠄⠄⠄⠄⣀⣤⣴⣶⣾⠟⠉⠻⣷⣶⣦⣤⣀⠄⠄⠄⠄⠄⠄ 
⠄⠄⠄⢀⣴⣾⣿⣿⣿⠟⠁⠄⠄⠄⣨⣿⣿⣿⣿⣷⣦⡀⠄⠄⠄ 
⠄⠄⣴⣿⣿⣿⣿⠟⠁⠄⠄⠄⣠⣾⣿⣿⣿⠿⣿⣿⣿⣿⣦⠄⠄ 
⠄⣼⣿⣿⣿⣏⠁⠄⠄⠄⠠⣾⣿⣿⡿⠏⠁⠄⠈⠹⢿⣿⣿⣧⠄ 
⢸⣿⡿⣿⣿⣿⣷⣄⠄⠄⠄⠈⠻⠋⠄⠄⠄⠄⠄⠄⠄⠙⢿⣿⡇
⡿⠋⠄⠈⠻⣿⣿⣿⣷⣄⠄⠄⠄⠄⠄⢀⣴⣿⣦⡀⠄⠄⠄⠙⢿ 
⣷⣄⠄⠄⠄⠈⠻⣿⠟⠁⠄⠄⠄⠄⠄⠙⢿⣿⣿⣿⣦⡀⠄⣠⣾ 
⢸⣿⣷⣄⠄⠄⠄⠄⠄⠄⠄⣠⣦⡀⠄⠄⠄⠙⢿⣿⣿⣿⣾⣿⡏ 
⠄⢻⣿⣿⣷⣆⡀⠄⠄⣠⣾⣿⣿⡿⠆⠄⠄⠄⢀⣹⣿⣿⣿⡟⠄ 
⠄⠄⠻⣿⣿⣿⣿⣦⣾⣿⣿⡿⠋⠄⠄⠄⢀⣴⣿⣿⣿⣿⠟⠄⠄ 
⠄⠄⠄⠈⠻⢿⣿⣿⣿⣿⡋⠄⠄⠄⢀⣴⣿⣿⣿⣿⠟⠁⠄⠄⠄ 
⠄⠄⠄⠄⠄⠄⠉⠛⠿⠿⢿⣦⣀⣴⣿⠿⠿⠛⠉⠄⠄⠄⠄⠄⠄
*/