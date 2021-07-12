#pragma once
#include "Module.h"
#include "../../DrawUtils.h"
class ArrayList : public IModule {
public:
	float opacity = 0.05;
	bool enabled = true;

	ArrayList();
	~ArrayList();

	// Inherited via IModule
	virtual const char* getModuleName() override;
};