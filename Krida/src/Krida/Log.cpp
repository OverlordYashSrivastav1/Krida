#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Krida {
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		

	}
}
