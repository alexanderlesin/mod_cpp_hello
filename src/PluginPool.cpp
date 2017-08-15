#include "PluginPool.h"

namespace openiam
{
    std::shared_ptr<Plugin> PluginPool::operator[](const std::string& virtualServerName)
    {
        std::lock_guard<std::mutex> locker(poolMutex);
        auto i = pool.find(virtualServerName);
        if (i == pool.cend())
        {
            std::shared_ptr<Plugin> plugin(new Plugin());
            pool[virtualServerName] = plugin;
            return plugin;
        }
        else
        {
            return i->second;
        }
    }
}