#pragma once

#include "Core.h"

namespace GLRE
{
	class GLRE_API App
	{
	public:
		App();
		virtual ~App();

		void Run();
	};

	// To be defined in CLIENT
	App* CreateApp();
}
