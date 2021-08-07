#include "ChestESP.h"

ChestESP::ChestESP() : IModule(VK_NUMPAD9, Category::WORLD, "ESP, but for Storage") {
	registerIntSetting("Range", &this->range, this->range, 1, 20);
	//registerBoolSetting("Beds", &this->beds, this->beds);
	//registerBoolSetting("Eggs", &this->eggs, this->eggs);
	////registerBoolSetting("Cakes", &this->cakes, this->cakes);
//	registerBoolSetting("Treasures", &this->treasures, this->treasures);
	registerBoolSetting("Chests", &this->chests, this->chests);
	registerBoolSetting("Barrals", &this->redstone, this->redstone);
	registerBoolSetting("Shulker Box", &this->diamond, this->diamond);
	registerBoolSetting("EnderChests", &this->emerald, this->emerald);
	//registerBoolSetting("HiveNuker", &this->Andisite, this->Andisite);
}

ChestESP::~ChestESP() {
}

const char* ChestESP::getModuleName() {
	return ("StorageESP");
}

void ChestESP::onPostRender(C_MinecraftUIRenderContext* renderCtx) {
	if (!(g_Data.getLocalPlayer() == nullptr || !GameData::canUseMoveKeys())) {
		if (g_Data.isInGame()) {
			vec3_t* pos = g_Data.getLocalPlayer()->getPos();
			for (int x = (int)pos->x - range; x < pos->x + range; x++) {
				for (int z = (int)pos->z - range; z < pos->z + range; z++) {
					for (int y = (int)pos->y - range; y < pos->y + range; y++) {
						vec3_t blockPos = vec3_t(x, y, z);
						C_Block* block = g_Data.getLocalPlayer()->region->getBlock(blockPos);
						int id = block->toLegacy()->blockId;
						bool destroy = false;
						//if (id == 26 && this->beds) destroy = true;      // Beds
						//if (id == 122 && this->eggs) destroy = true;     // Dragon Eggs
						//if (id == 92 && this->cakes) destroy = true;     // Cakes
						if (id == 54 && this->chests) {//chest
							destroy = true;
						}	
						if (id == 146 && this->chests) {//trapped chest
							destroy = true;
						}	
						if (id == 218 && this->diamond) {//shulkerbox
							destroy = true;
						}	
						if (id == 205 && this->diamond) {  //shulkerbox
							destroy = true;
						}	
						if (id == 130 && this->emerald) {//enderchest
							destroy = true;
						}	
						if (id == 458 && this->redstone) {//barrel
							destroy = true;
						}	
						if (destroy) {
							DrawUtils::setColor(0.f, 0.f, 1.f, 1);
							DrawUtils::drawBox(blockPos, vec3_t(blockPos).add(1), 1.f);
						}  
						// Chests
						//if (id == 73 && this->redstone) destroy = true;  // Redstone
						//if (id == 56 && this->diamond) destroy = true;   // Diamond
						//if (id == 129 && this->emerald) destroy = true;  // Emerald
						/*	
				if (id == 1 && this->andisite) destroy = true;  // Andisite
				if (id == 56 && this->andisite) destroy = true;  // Andisite
				if (id == 73 && this->andisite) destroy = true;  // Andisite
				if (id == 3 && this->andisite) destroy = true;  // Andisite
				if (id == 2 && this->andisite) destroy = true;  // Andisite
				if (id == 82 && this->andisite) destroy = true;  // Andisite
				if (id == 44 && this->andisite) destroy = true;  // Andisite
				if (id == 107 && this->andisite) destroy = true;   // Andisite
				if (id == 15 && this->andisite) destroy = true;   // Andisite
				if (id == 21 && this->andisite) destroy = true;  // Andisite
				if (id == 14 && this->andisite) destroy = true;   // Andisite
				if (id == 129 && this->andisite) destroy = true;  // Andisite
				if (id == 35 && this->andisite) destroy = true;   // Andisite
				if (id == 159 && this->andisite) destroy = true;   // Andisite
				if (id == 252 && this->andisite) destroy = true;   // Andisite
				if (id == 5 && this->andisite) destroy = true;    // Andisite
				if (id == 17 && this->andisite) destroy = true;     // Andisite
				if (id == 139 && this->andisite) destroy = true;    // Andisite
				if (id == 188 && this->andisite) destroy = true;     // Andisite
				if (id == 251 && this->andisite) destroy = true;    // Andisite
				if (id == 12 && this->andisite) destroy = true;     // Andisite
				if (id == 44 && this->andisite) destroy = true;    // Andisite
				if (id == 24 && this->andisite) destroy = true;     // Andisite
				if (id == 164 && this->andisite) destroy = true;    // Andisite
				if (id == 160 && this->andisite) destroy = true;     // Andisite
				if (id == 4 && this->andisite) destroy = true;      // Andisite
				if (id == 155 && this->andisite) destroy = true;       // Andisite
				if (id == 156 && this->andisite) destroy = true;      // Andisite
				if (id == 189 && this->andisite) destroy = true;         // Andisite
				if (id == 18 && this->andisite) destroy = true;        // Andisite
				if (id == 168 && this->andisite) destroy = true;           // Andisite
				if (id == 216 && this->andisite) destroy = true;         // Andisite
				if (id == 172 && this->andisite) destroy = true;             // Andisite
				if (id == 162 && this->andisite) destroy = true;         // Andisite
				if (id == 126 && this->andisite) destroy = true;             // Andisite
				*/

						//if (destroy) {
							//DrawUtils::setColor(0.f, 0.f, 1.f, 1);
							//DrawUtils::drawBox(blockPos, vec3_t(blockPos).add(1), 1.f);
							//gm->destroyBlock(&blockPos, 0);
							//if (!moduleMgr->getModule<NoSwing>()->isEnabled())
							//	g_Data.getLocalPlayer()->swingArm();
							//return;
						//}
					}
				}
			}
		}
	}
}

	////if (this->treasures) {
	//	g_Data.forEachEntity([](C_Entity* ent, bool b) {
		//	std::string name = ent->getNameTag()->getText();
		//	int id = ent->getEntityTypeId();
		//	if (name.find("Treasure") != std::string::npos && g_Data.getLocalPlayer()->getPos()->dist(*ent->getPos()) <= 5) {
		//		g_Data.getCGameMode()->attack(ent);
				//if (!moduleMgr->getModule<NoSwing>()->isEnabled())
				//g_Data.getLocalPlayer()->swingArm();
		//	}
		//});
	//}
//}
