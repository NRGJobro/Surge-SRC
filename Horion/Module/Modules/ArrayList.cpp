#include "ArrayList.h"

#include "../ModuleManager.h"

ArrayList::ArrayList() : IModule(0, Category::VISUAL, "ArrayList") {
	registerFloatSetting("Opacity", &this->opacity, this->opacity, 0.f, 1.f);
}

ArrayList::~ArrayList() {
}

const char* ArrayList::getModuleName() {
	return "ArrayList";
}