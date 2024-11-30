#include "Engine.h"
Engine::Engine()
{
	m_Window.create(VideoMode::getDesktopMode(), "Particles", Style::Default);
}
void Engine::run()
{
	//Construct a local Clock object to track Time per frame
	Clock m_Clock;
	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
	p.unitTests();
	cout << "Unit tests complete.  Starting engine..." << endl;
	while (m_Window.isOpen())
	{
		Time time = m_Clock.restart();
		float tSec = time.asSeconds();
		input();
		update(tSec);
		draw();
	}
}
void Engine::input()
{

}
void Engine::update(float dtAsSeconds)
{

}
void Engine::draw()
{

}