#include <httpd.h>
#include <http_request.h>
#include <http_config.h>
#include <http_core.h>
#include "PluginPool.h"
using namespace openiam;

static const char* setEnable(cmd_parms* command, void* /*config*/, const char* argument);
static void registerHooks(apr_pool_t* );


static const command_rec moduleDirectives[] =
{
    AP_INIT_TAKE1
    (
        "PluginEnabled",            
        reinterpret_cast<cmd_func>(setEnable), 
        NULL, 
        OR_ALL, 
        "Enable or disable mod_ssorest"
    ),

    { NULL }
};

extern "C"
{
    AP_DECLARE_MODULE(cpp_hello) = {
        STANDARD20_MODULE_STUFF,
        NULL,                   /* Per-directory configuration handler */
        NULL,                   /* Merge handler for per-directory configurations */
        NULL,                   /* Per-server configuration handler */
        NULL,                   /* Merge handler for per-server configurations */
        moduleDirectives, 
        registerHooks 
    };
}


namespace openiam
{
    static std::shared_ptr<Plugin> getPluginFrom(server_rec* server)
    {
        static PluginPool pluginPool;
        auto rawVirtualServerName = server->server_hostname;
        if (!rawVirtualServerName)
            throw std::logic_error("ServerName is not set, check virtual server settings");
        std::string virtualServerName(rawVirtualServerName);
        return pluginPool[virtualServerName];
    }
}

static const char* setEnable(cmd_parms* command, void* /*config*/, const char* argument)
{
    auto plugin = getPluginFrom(command->server);
    if (::strcasecmp(argument, "on") == 0)
        plugin->setEnable(true);
    else
        plugin->setEnable(false);
    return NULL;
}

static int processRequest(request_rec* r) {
    auto plugin = getPluginFrom(r->server);
    return plugin->processRequest(r);
}

static void registerHooks(apr_pool_t* ) {
    ::ap_hook_handler(processRequest, NULL, NULL,APR_HOOK_LAST);
}
