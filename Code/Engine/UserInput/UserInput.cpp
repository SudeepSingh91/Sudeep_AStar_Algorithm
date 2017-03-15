#include "UserInput.h"

#include <Windows.h>

namespace
{
	bool IsVirtualKeyPressed(const int i_virtualKeyCode);
}

namespace Engine
{
	namespace UserInput
	{
		bool IsKeyPressed(const int i_virtualKeyCode)
		{
			return IsVirtualKeyPressed(i_virtualKeyCode);
		}

		bool IsMousePressed(const int i_virtualKeyCode)
		{
			return IsVirtualKeyPressed(i_virtualKeyCode);
		}
	}
}

namespace
{
	bool IsVirtualKeyPressed(const int i_virtualKeyCode)
	{
		short keyState = GetAsyncKeyState(i_virtualKeyCode);
		const short isKeyDown = ~1;
		return (keyState & isKeyDown) != 0;
	}
}