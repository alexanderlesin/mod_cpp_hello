#pragma once

namespace openiam
{
    class Plugin
    {
    private:
        bool isEnabled;
    
    public:
        Plugin();
        int processRequest(request_rec* r);

    public:
        void setEnable(const bool& value);
    };
}