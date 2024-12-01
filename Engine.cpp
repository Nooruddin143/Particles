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
	srand(time(0));
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			m_Window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			m_Window.close();
		}
		if (event.type == Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == Mouse::Left)
			{
				Vector2i mousepos = { event.mouseButton.x , event.mouseButton.y };
				for (int i = 0; i < 5; ++i)
				{
					int numPoints = 25 + rand() % 26; // Random number [25, 50]
					m_particles.push_back(Particle(m_Window, numPoints, mousepos));
				}
			}
		}
	}
}
void Engine::update(float dtAsSeconds)
{
	for (auto it = m_particles.begin(); it != m_particles.end(); )
	{
		if (it->getTTL() > 0.0)
		{
			// Call update on that Particle
			it->update(dtAsSeconds);
			++it; // increment the iterator
		}
		else
		{
			/*erase the element the iterator points to
			erase returns an iterator that points to the next element after deletion,
			or end if it is the end of the vector*/
			it = m_particles.erase(it); // Returns an iterator to the next element
		}
	}
}
void Engine::draw()
{
	m_Window.clear();
	for (auto it = m_particles.begin(); it != m_particles.end(); ++it)
	{
		m_Window.draw(*it);
	}
	m_Window.display();
}