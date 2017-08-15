#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import os
import platform

outputFileNameSuffix = ''

environment = Environment()
if not environment.GetOption('clean'):

    platform = sys.platform
    if platform == "linux2":

        flags = '-O2 --std=gnu++11 -Wall -rdynamic -fpermissive -fPIC'
        includePaths = ["/usr/include/apache2", "/usr/include/httpd", "/usr/include/apr-1.0", "/usr/include/apr-1"]
        libraries = ['pthread']
        environment = Environment(LIBS=libraries, CPPFLAGS=flags, CPPPATH=includePaths) 

    else:
        print "Platform '" + platform + "' is not supported"
        sys.exit(1)
    	
sources = [ 'Plugin.cpp',
            'PluginPool.cpp',
            'mod_cpp_hello.cpp']

environment['STATIC_AND_SHARED_OBJECTS_ARE_THE_SAME'] = 1
environment.Replace(SHLIBPREFIX = '')
environment.SharedLibrary(target='mod_cpp_hello' + outputFileNameSuffix, source=sources)
