#pragma once

#include <tiny_websockets/ws_config_defs.hpp>
#include <string>
#include <Arduino.h>

namespace websockets {
    typedef std::string WSString;
    typedef String WSInterfaceString;

    namespace internals {
        WSString fromInterfaceString(const WSInterfaceString& str);
        WSString fromInterfaceString(const WSInterfaceString&& str);
        WSInterfaceString fromInternalString(const WSString& str);
        WSInterfaceString fromInternalString(const WSString&& str);
    }
}

#define PLATFORM_DOES_NOT_SUPPORT_BLOCKING_READ

#include <tiny_websockets/network/esp32/esp32_tcp.hpp>
#define WSDefaultTcpClient websockets::network::Esp32TcpClient
#define WSDefaultTcpServer websockets::network::Esp32TcpServer

#ifndef _WS_CONFIG_NO_SSL
    // OpenSSL Dependent
    #define WSDefaultSecuredTcpClient websockets::network::SecuredEsp32TcpClient
#endif //_WS_CONFIG_NO_SSL

