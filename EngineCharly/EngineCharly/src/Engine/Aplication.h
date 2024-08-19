#pragma once
#include "Core.h"

namespace Charly {
		class CHARLY_API Aplication {
		
		public:
			Aplication();
			virtual ~Aplication();
			void Run();
	};

		Aplication* CreateApplication();
}