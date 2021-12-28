#pragma once

#include "stdint.h"
#include "spdlog/spdlog.h"
#include "OTRWindow.h"
#include <memory>

namespace OtrLib {
	class OTRResourceMgr;

	class OTRContext {
		public:
			static std::shared_ptr<OTRContext> GetInstance();
			static std::shared_ptr<OTRContext> CreateInstance(std::string Name, std::string MainPath, std::string PatchesPath);

			std::string GetName() { return Name; }
			std::shared_ptr<OTRWindow> GetWindow() { return Window; }
			std::shared_ptr<OTRResourceMgr> GetResourceManager() { return ResourceMgr; }
			std::shared_ptr<spdlog::logger> GetLogger() { return Logger; }

		protected:

		private:
			static std::shared_ptr<OTRContext> Context;

			OTRContext(std::string Name, std::string mainPath, std::string patchesDirectory);
			~OTRContext();

			std::shared_ptr<OTRResourceMgr> ResourceMgr;
			std::shared_ptr<OTRWindow> Window;
			std::shared_ptr<spdlog::logger> Logger;
			std::string Name;
	};
}
