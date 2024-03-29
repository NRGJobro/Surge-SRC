#pragma once
#include "Module.h"
#include "../../DrawUtils.h"
class ArrayList : public IModule {
public:
	float opacity = 0.f;
	bool enabled = true;
	bool different = true;
	bool bar = false;
	bool underbar = false;
	bool ice = false;
	bool rgb = false;
	bool bottom = false;
	bool rgbtext = true;

	ArrayList();
	~ArrayList();

	// Inherited via IModule
	virtual const char* getModuleName() override;
};