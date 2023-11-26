#pragma once
#include <Windows.h>
#include <sstream>

namespace prelog
{
	/**
	 * @brief Display a Win32 message box with a specified title and message content.
	 *
	 * @param type The type of the message box. Use constants like MB_OK, MB_YESNO, etc.
	 * @param title The title of the message box.
	 * @param args Message content.
	 * @return The result of the message box, typically the button pressed by the user.
	 */
	template<typename T, typename... Args>
	int msgBox(uint32_t type, const T title, Args&&... args)
	{
		std::wstringstream oss;

		oss << title;
		std::wstring titleStr{ oss.str() };

		oss = std::wstringstream();
		(oss << ... << std::forward<Args>(args));

		return MessageBoxW(NULL, oss.str().c_str(), titleStr.c_str(), type);
	}

}
