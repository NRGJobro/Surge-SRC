#include "Tracer.h"
#include "../../DrawUtils.h"

#include "../../../SDK/CCamera.h"

Tracer::Tracer() : IModule('R', Category::VISUAL, "Draws lines to ESP highlighted entities(MADE BY OLD GREGGO!!)") {
}

Tracer::~Tracer() {
}

const char* Tracer::getModuleName() {
	return "Tracer";
}

void Tracer::onPreRender(C_MinecraftUIRenderContext* ctx) {
	if (GameData::canUseMoveKeys())  //sexy 2d shit
		g_Data.forEachEntity([](C_Entity* ent, bool valid) {
			if (Target::isValidTarget(ent) && ent != g_Data.getLocalPlayer())
				DrawUtils::drawTracer(ent);
		});
}
