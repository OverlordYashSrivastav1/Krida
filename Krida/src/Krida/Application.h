#pragma once

#include "Core.h"

namespace Krida {
	class KRIDA_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//client defined

	Application* CreateApplication();

}

