#pragma once
#include "Module.h"
#include "../../DrawUtils.h"
class ArrayList : public IModule {
public:
	float opacity = 0.f;
	bool enabled = true;
	bool bar = false;
	bool underbar = false;
	bool ice = true;
	bool rgb = true;
	bool rgbtext = true;

	ArrayList();
	~ArrayList();

	// Inherited via IModule
	virtual const char* getModuleName() override;
};