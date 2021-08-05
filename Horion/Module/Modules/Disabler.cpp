#include "Disabler.h"

Disabler::Disabler() : IModule(0, Category::MISC, "Disables Anticheat") {
	registerBoolSetting("Hive", &this->hive, this->hive);
}

const char* Disabler::getModuleName() {
	return "Disabler";
}

void Disabler::onTick(C_GameMode* gm) {
}

void Disabler::onSendPacket(C_Packet* packet) {
	if (counter == 1) {
		//clientMessageF("Packet Sent");
		PlayerAuthInputPacket* movePacket = reinterpret_cast<PlayerAuthInputPacket*>(packet);
		movePacket->pos;
		this->getMovePlayerPacketHolder()->clear();
		this->getPlayerAuthInputPacketHolder()->clear();
	}
	if (counter == 19) {
		counter = 0;
	} else {
		counter++;
	}
}