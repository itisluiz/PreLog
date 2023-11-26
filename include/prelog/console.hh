#pragma once

namespace prelog
{
	/**
	 * @brief Assert the existence (or alocate and redirect one if needed) of a console window for standard input and output.
	 *
	 * @return True if the console is successfully asserted or already exists, false otherwise.
	 */
	bool assertConsole();

	/**
	 * @brief Release resources associated with the currently associated console window.
	 */
	void releaseConsole();

}
