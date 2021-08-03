#include "NoHurtcam.h"
NoHurtcam::~NoHurtcam() {
}
NoHurtcam::NoHurtcam() : IModule(0, Category::VISUAL, "Disables rotation of the camera when hit") {
}
const char* NoHurtcam::getModuleName() {
	return "NoHurtcam";
}

void NoHurtcam::onLevelRender() {
	auto player = g_Data.getLocalPlayer();
	player->respawn();
}