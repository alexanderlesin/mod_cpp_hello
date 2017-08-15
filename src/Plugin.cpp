#include "Plugin.h"

namespace openiam
{
    Plugin::Plugin()
    : isEnabled(false)
    {
    }
    
    int Plugin::processRequest(request_rec* r)
    {
        if(!isEnabled)
            return 400;
        return 404;
    }

    void Plugin::setEnable(const bool& value)
    {
        isEnabled = value;
    }
}