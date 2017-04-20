#pragma once
#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <string>

	class factory
	{
		protected:
			std::string selected;
		public:

			virtual void setOutput(int);
			virtual void convert(const std::string &) = 0;

			enum direction{beep=0, console, disk, blink};
	};
#endif