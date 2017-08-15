#pragma once

namespace openiam
{
    class PluginPool
    {
    private:
        std::map<std::string, std::shared_ptr<Plugin>> pool;
        std::mutext poolMutex;
    
    public:
        std::shared_ptr<Plugin> operator[](const std::string& virtualServerName);
    }
}