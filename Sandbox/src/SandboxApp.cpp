#include <GLRE.h>

class Sandbox : public GLRE::App
{
public:
	Sandbox()
	{
		
	}
	~Sandbox()
	{
		
	}
};

GLRE::App* GLRE::CreateApp()
{
	return new Sandbox();
}
