#include "stdafx.hpp"
#include "Tetris3D.hpp"

inline void Tetris3D::SetWindowIcon()
{

#ifdef SFML_SYSTEM_WINDOWS
	HINSTANCE hinst = (HINSTANCE)GetModuleHandle(NULL);
	HICON IconBig = (HICON)LoadImage(hinst, MAKEINTRESOURCE(IDI_TETRIS3D), IMAGE_ICON, NULL, NULL, LR_DEFAULTCOLOR | LR_LOADTRANSPARENT);
	HICON IconSmall = (HICON)LoadImage(hinst, MAKEINTRESOURCE(IDI_SMALL), IMAGE_ICON, NULL, NULL, LR_DEFAULTCOLOR | LR_LOADTRANSPARENT);
	SendMessage(Window->getSystemHandle(), WM_SETICON, ICON_BIG, (LPARAM)IconBig);
	SendMessage(Window->getSystemHandle(), WM_SETICON, ICON_SMALL, (LPARAM)IconSmall);
#elif SFML_SYSTEM_LINUX
# TODO: For Linux
#endif
}

inline void Tetris3D::InitializeOpenGL()
{
	// Enable Z-buffer read and write
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glClearColor(1.0f, 1.0f, 1.0f, 0.5f);
	glClearDepth(1.f);

	// Disable lighting
	glDisable(GL_LIGHTING);

	Resize(Window->getSize().x, Window->getSize().y);
}

void Tetris3D::Resize(GLsizei x, GLsizei y)
{
	glViewport(0, 0, x, y);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLfloat ratio = static_cast<float>(x) / y;
	glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

Tetris3D::Tetris3D()
{
	// Request a 32-bits depth buffer when creating the window
	sf::ContextSettings contextSettings;
	contextSettings.depthBits = 32;

	Window = new sf::RenderWindow(sf::VideoMode::getFullscreenModes()[0], "Tetris3D", sf::Style::Fullscreen, contextSettings);
	// Make it the active window for OpenGL calls
	Window->setActive();

	SetWindowIcon();
	InitializeOpenGL();
}

Tetris3D::~Tetris3D()
{
	delete Window;
}

void Tetris3D::ProcessEvents()
{
	sf::Event event;
	while (Window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed: // Close window : exit
			Window->close();
			break;
		case sf::Event::GainedFocus:
			break;
		case sf::Event::LostFocus:
			break;
		case sf::Event::Resized:
			Resize(event.size.width, event.size.height);
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case  sf::Keyboard::Escape: // Escape key : exit
				Window->close();
				break;
			}
		}
	}
}

void Tetris3D::Run()
{
	sf::Clock clock;
	Field.Start(10, 10, 22);
	this->State = GameState::Play;
	while (Window->isOpen())
	{
		sf::Time ElapsedTime = clock.restart();
		ProcessEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (State == GameState::Play)
		{
			if (Field.HaveSpace())
			{
				Field.Update(ElapsedTime);
			}
			else
			{
				State = GameState::End;
			};
		};
		Field.Draw();
		Window->display();
	};
	Field.Destroy();
}
