#pragma once

#ifdef KD_PLATFORM_WINDOWS

extern Krida::Application* Krida::CreateApplication();

int main(int argc, char** argv) {

	printf("KRIDA ONLINE!");

	//Krida::Log::Init();
	auto app = Krida::CreateApplication();
	//Sandbox* sandbox = new Sandbox();
	app -> Run();
	//sandbox->Run();
	delete app;
	//delete sandbox;
}

#endif