#pragma once
#include <string>
#include <map>
#include <mutex>
#include <memory>
#include "Plugin.h"
namespace openiam
{
    class PluginPool
    {
    private:
        std::map<std::string, std::shared_ptr<Plugin>> pool;
        std::mutex poolMutex;
    
    public:
        std::shared_ptr<Plugin> operator[](const std::string& virtualServerName);
    };
}