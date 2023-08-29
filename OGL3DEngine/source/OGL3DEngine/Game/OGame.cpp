#include <OGL3DEngine/Game/OGame.h>
#include <OGL3DEngine/Window/OWindow.h>
#include <Windows.h>

OGame::OGame()
{
	m_display = std::unique_ptr<OWindow>(new OWindow());
}

OGame::~OGame()
{
}

void OGame::run()
{
	while (m_isRunning && !m_display->isClosed())
	{
		MSG msg = {};
		if (PeekMessage(&msg, HWND(), NULL, NULL, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				m_isRunning = false;
				continue;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			Sleep(1);
		}
	}
	printf("you got there");
}

void OGame::quit()
{
	m_isRunning = false;
}
