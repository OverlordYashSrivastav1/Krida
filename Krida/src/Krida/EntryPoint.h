#pragma once

#ifdef KD_PLATFORM_WINDOWS

extern Krida::Application* Krida::CreateApplication();

int main(int argc, char** argv) {

	printf("KRIDA ONLINE! \n");

	Krida::Log::Init();

	KD_CORE_INFO("TEST");

	KD_CORE_WARN("From entrypoint core");
	int a = 100;
	KD_INFO("Client var={0}", a);

	Krida::Log::GetClientLogger()->info(" From Client ");

	auto app = Krida::CreateApplication();
	
	app -> Run();

	delete app;

}

#endif