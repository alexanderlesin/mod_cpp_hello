#include "Plugin.h"

namespace openiam
{
    Plugin::Plugin()
    : isEnabled(false)
    {
    }
    
    int Plugin::processRequest(request_rec* r)
    {

    }

    void Plugin::setEnable(const bool& value)
    {
        isEnabled = value;
    }
}