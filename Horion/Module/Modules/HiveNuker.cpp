#include "HiveNuker.h"

HiveNuker::HiveNuker() : IModule(VK_NUMPAD9, Category::MISC, "Hive Nuker Was Packets Idea") {
	registerIntSetting("Range", &this->range, this->range, 1, 6);
	registerBoolSetting("Hive Nuker", &this->andisite, this->andisite);
}

HiveNuker::~HiveNuker() {
}

const char* HiveNuker::getModuleName() {
	return ("HiveNuker");
}

void HiveNuker::onTick(C_GameMode* gm) {
	vec3_t* pos = gm->player->getPos();
	for (int x = (int)pos->x - range; x < pos->x + range; x++) {
		for (int z = (int)pos->z - range; z < pos->z + range; z++) {
			for (int y = (int)pos->y - range; y < pos->y + range; y++) {
				vec3_ti blockPos = vec3_ti(x, y, z);
				bool destroy = false;
				int id = gm->player->region->getBlock(blockPos)->toLegacy()->material->isSolid;

				if (id == 1 && this->andisite) destroy = true;    // Andisite
				if (id == 56 && this->andisite) destroy = true;   // Andisite
				if (id == 73 && this->andisite) destroy = true;   // Andisite
				if (id == 3 && this->andisite) destroy = true;    // Andisite
				if (id == 2 && this->andisite) destroy = true;    // Andisite
				if (id == 82 && this->andisite) destroy = true;   // Andisite
				if (id == 44 && this->andisite) destroy = true;   // Andisite
				if (id == 107 && this->andisite) destroy = true;  // Andisite
				if (id == 15 && this->andisite) destroy = true;   // Andisite
				if (id == 21 && this->andisite) destroy = true;   // Andisite
				if (id == 14 && this->andisite) destroy = true;   // Andisite
				if (id == 129 && this->andisite) destroy = true;  // Andisite
				if (id == 35 && this->andisite) destroy = true;   // Andisite
				if (id == 159 && this->andisite) destroy = true;  // Andisite
				if (id == 252 && this->andisite) destroy = true;  // Andisite
				if (id == 5 && this->andisite) destroy = true;    // Andisite
				if (id == 17 && this->andisite) destroy = true;   // Andisite
				if (id == 139 && this->andisite) destroy = true;  // Andisite
				if (id == 188 && this->andisite) destroy = true;  // Andisite
				if (id == 251 && this->andisite) destroy = true;  // Andisite
				if (id == 12 && this->andisite) destroy = true;   // Andisite
				if (id == 44 && this->andisite) destroy = true;   // Andisite
				if (id == 24 && this->andisite) destroy = true;   // Andisite
				if (id == 164 && this->andisite) destroy = true;  // Andisite
				if (id == 160 && this->andisite) destroy = true;  // Andisite
				if (id == 4 && this->andisite) destroy = true;    // Andisite
				if (id == 155 && this->andisite) destroy = true;  // Andisite
				if (id == 156 && this->andisite) destroy = true;  // Andisite
				if (id == 189 && this->andisite) destroy = true;  // Andisite
				if (id == 18 && this->andisite) destroy = true;   // Andisite
				if (id == 168 && this->andisite) destroy = true;  // Andisite
				if (id == 216 && this->andisite) destroy = true;  // Andisite
				if (id == 172 && this->andisite) destroy = true;  // Andisite
				if (id == 162 && this->andisite) destroy = true;  // Andisite
				if (id == 126 && this->andisite) destroy = true;  // Andisite
				//ORIGIONAL IDEA FROM PACKET

				if (destroy) {
					gm->destroyBlock(&blockPos, 0);
					//if (!moduleMgr->getModule<NoSwing>()->isEnabled())
					//	g_Data.getLocalPlayer()->swingArm();
					return;
				}
			}
		}
	}
}