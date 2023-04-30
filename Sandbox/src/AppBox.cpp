#include <Krida.h>

class Sandbox : public Krida::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Krida::Application* Krida::CreateApplication() {
	return new Sandbox();
}


/*int main() {
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}*/