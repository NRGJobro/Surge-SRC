#include "ClickGuiMod.h"
#include "../../Menu/ClickGui.h"

ClickGuiMod::ClickGuiMod() : IModule(VK_INSERT, Category::VISUAL, "The clickgui - toggle everything by just clicking on it!") {
	registerEnumSetting("Font", &type, 0);
	type = SettingEnum(this)
			   .addEntry(EnumEntry("Font 1", 0))
			   .addEntry(EnumEntry("Font 2", 1))
			   .addEntry(EnumEntry("Font 3", 2))
			   .addEntry(EnumEntry("Font 4", 3))
			   .addEntry(EnumEntry("Font 5", 4))
			   .addEntry(EnumEntry("Font 6", 5))
			   .addEntry(EnumEntry("Font 7", 6))
			   .addEntry(EnumEntry("Font 8", 7))
			   .addEntry(EnumEntry("Font 9", 8));
			   //.addEntry(EnumEntry("Font 10", 9))
			   //.addEntry(EnumEntry("Font 11", 10))
			   //.addEntry(EnumEntry("Font 12", 11))
			   //.addEntry(EnumEntry("Font 13", 12))
			   //.addEntry(EnumEntry("Font 14", 13))
			   //.addEntry(EnumEntry("Font 15", 14))
			   //.addEntry(EnumEntry("Font 16", 15))
			   //.addEntry(EnumEntry("Font 17", 16))
			  // .addEntry(EnumEntry("Font 18", 17))
			  // .addEntry(EnumEntry("Font 19", 18));
	registerBoolSetting("Show Tooltips", &this->showTooltips, this->showTooltips);
	registerBoolSetting("RGB", &this->RGB, this->RGB);
	registerFloatSetting("Opacity", &this->opacity, this->opacity, 0.f, 1.f);
}

ClickGuiMod::~ClickGuiMod() {
}

const char* ClickGuiMod::getModuleName() {
	return ("ClickGui");
}

void ClickGuiMod::onEnable() {
	g_Data.getClientInstance()->releaseMouse();
}

bool ClickGuiMod::allowAutoStart() {
	return false;
}

void ClickGuiMod::onDisable() {
	g_Data.getClientInstance()->grabMouse();
}

void ClickGuiMod::onPostRender(C_MinecraftUIRenderContext* renderCtx) {
	if (GameData::canUseMoveKeys())
		g_Data.getClientInstance()->releaseMouse();
}
void ClickGuiMod::onLoadConfig(void* conf) {
	IModule::onLoadConfig(conf);
	ClickGui::onLoadConfig(conf);
}
void ClickGuiMod::onSaveConfig(void* conf) {
	IModule::onSaveConfig(conf);
	ClickGui::onSaveConfig(conf);
}
