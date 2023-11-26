#pragma once
#include <Windows.h>
#include <sstream>

namespace prelog
{
	/**
	 * @brief Output a debug string to debug output listeners like DebugView or Visual Studio's output.
	 *
	 * @param args Debug content.
	 */
	template<typename... Args>
	void debugOut(Args&&... args)
	{
		std::wstringstream oss;
		(oss << ... << std::forward<Args>(args)) << '\n';

		OutputDebugStringW(oss.str().c_str());
	}

}
