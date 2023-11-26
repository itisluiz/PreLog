#include <prelog/console.hh>
#include <Windows.h>
#include <iostream>

namespace prelog
{
	static FILE* fstdin{ nullptr };
	static FILE* fstdout{ nullptr };
	static FILE* fstderr{ nullptr };

	bool assertConsole()
	{
		if (!GetConsoleWindow() && !AllocConsole())
			return false;

		if (freopen_s(&fstdin, "CONIN$", "r", stdin) ||
			freopen_s(&fstdout, "CONOUT$", "w", stdout) ||
			freopen_s(&fstderr, "CONOUT$", "w", stderr))
			return false;

		return true;
	}

	void releaseConsole()
	{
		if (fstdin)
			fclose(fstdin);

		if (fstdout)
			fclose(fstdout);

		if (fstderr)
			fclose(fstderr);

		FreeConsole();
	}

}
