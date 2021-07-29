#include "Shaders.h"

Shaders::Shaders() : IModule(0, Category::VISUAL, "Puts your gamma to max") {
	registerFloatSetting("Shade", &this->shade, this->shade, -2.f, -0.01f);
}

Shaders::~Shaders() {
}

static float originalGamma = -1;

const char* Shaders::getModuleName() {
	return "Shaders";
}

void Shaders::onTick(C_GameMode* gm) {
	if (gammaPtr != nullptr && *gammaPtr != 10)
		*gammaPtr = 10;
}

void Shaders::onEnable() {
	if (gammaPtr != nullptr) {
		originalGamma = *gammaPtr;
		*gammaPtr = 10;
	}
}

void Shaders::onDisable() {
	if (gammaPtr != nullptr) {
		if (originalGamma >= 0 && originalGamma <= 1)
			*gammaPtr = originalGamma;
		else
			*gammaPtr = 0.5f;
	}
}
