// Tetris3D.cpp : Defines the entry point for the application.
//

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
	glClearDepth(1.f);

	// Disable lighting
	glDisable(GL_LIGHTING);

	// Configure the viewport (the same size as the window)
	glViewport(0, 0, Window->getSize().x, Window->getSize().y);

	// Setup a perspective projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat ratio = static_cast<float>(Window->getSize().x) / Window->getSize().y;
	glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);
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

void Tetris3D::Run()
{
	while (Window->isOpen())
	{
		sf::Event event;
		while (Window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed: // Close window : exit
				Window->close();
				break;
			case sf::Event::Resized:
				// Adjust the viewport when the window is resized
				glViewport(0, 0, event.size.width, event.size.height);
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
		Window->display();
	}
}
