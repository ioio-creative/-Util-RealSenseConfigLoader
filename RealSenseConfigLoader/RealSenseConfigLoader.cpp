// RealSenseConfigLoader.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <fstream>
#include <librealsense2/rs.hpp>// Include RealSense Cross Platform API
#include <librealsense2/rs_advanced_mode.hpp>

using namespace rs2;

////Reference: https://www.oipapio.com/question-606677
int main()
{
    //std::cout << "Hello World!\n"; 

	// Obtain a list of devices currently present on the system
	context ctx;
	auto devices = ctx.query_devices();
	size_t device_count = devices.size();
	if (!device_count)
	{
		std::cout << "No device detected. Is it plugged in?\n";
		return EXIT_SUCCESS;
	}

	// Get the first connected device
	auto dev = devices[0];

	// Enter advanced mode
	if (dev.is<rs400::advanced_mode>())
	{
		// Get the advanced mode functionality
		auto advanced_mode_dev = dev.as<rs400::advanced_mode>();

		// Load and configure .json file to device
		//std::ifstream t("E:\\Documents\VisualC++\\RealSenseConfigLoader\\Debug\\presets\\WSD9-2_Camera.json");
		std::ifstream t;
		t.open("./presets/RealSense_config.json");
		if (t.is_open())
		{			
			std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
			std::cout << str;
			advanced_mode_dev.load_json(str);
		}
	}
	else
	{
		std::cout << "Current device doesn't support advanced-mode!\n";
		return EXIT_FAILURE;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
