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
	if (!Shader.isAvailable())
		throw;

	if (!Shader.loadFromFile("Resources/VertexShader.glsl", "Resources/FragmentShader.glsl"))
		throw;

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		throw;

	sf::Shader::bind(&Shader);

	Shader.setBlockBinding("Transformation", (unsigned int)UniformBindings::Transformation);

	World::Bind((unsigned int)UniformBindings::Transformation);

	BaseBlock::Init();
	Field::Init();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glDepthRange(0.0f, 1.0f);
	glDepthFunc(GL_LEQUAL);
	glDepthMask(GL_TRUE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glLineWidth(3.5f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DEPTH_CLAMP);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);

	Resize(Window->getSize().x, Window->getSize().y);
}

inline void Tetris3D::DeInitializeOpenGL()
{
	Field::DeInit();
	BaseBlock::DeInit();
	World::UnBind();
}

void Tetris3D::Resize(GLsizei x, GLsizei y)
{
	glViewport(0, 0, x, y);
	float ratio = static_cast<float>(x) / y;
	World::UpdatePerspective(ratio);
}

Tetris3D::Tetris3D()
{
	sf::ContextSettings contextSettings;
	contextSettings.depthBits = 32;
	contextSettings.stencilBits = 8;
	contextSettings.antialiasingLevel = 8;
	contextSettings.majorVersion = 4;
	contextSettings.minorVersion = 3;

	Window = new sf::RenderWindow(sf::VideoMode::getFullscreenModes()[0], "Tetris3D", sf::Style::Fullscreen, contextSettings);
	Window->setActive();

	SetWindowIcon();
	InitializeOpenGL();
}

Tetris3D::~Tetris3D()
{
	DeInitializeOpenGL();
	delete Window;
}

void Tetris3D::ProcessEvents()
{
	sf::Event event;
	while (Window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			Window->close();
			break;
		case sf::Event::GainedFocus:
			break;
		case sf::Event::LostFocus:
			break;
		case sf::Event::Resized:
			Resize(event.size.width, event.size.height);
			break;
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Button::Left)
			{
				PreviousMousePosition.x = event.mouseButton.x;
				PreviousMousePosition.y = event.mouseButton.y;
			};
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case  sf::Keyboard::R:
				World::ResetView();
				break;
			case  sf::Keyboard::Escape:
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
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			sf::Vector2u size = Window->getSize();
			sf::Vector2i pos = sf::Mouse::getPosition();
			float x = (float)pos.x - PreviousMousePosition.x;
			float y = (float)pos.y - PreviousMousePosition.y;
			PreviousMousePosition.x = pos.x;
			PreviousMousePosition.y = pos.y;
			World::RotateView((x * 6.0f) / (float)size.x, glm::vec3(0.0f, 1.0f, 0.0f));
			World::RotateView((y * 6.0f) / (float)size.y, glm::vec3(1.0f, 0.0f, 0.0f));
		};
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
