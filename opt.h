//
// Created by Administrator on 2023-10-05.
//

#ifndef QUIET_PRACTICE_OPT_H
#define QUIET_PRACTICE_OPT_H

#define QUIET_PROFILE_PATH  "quiet-profiles.json"
#define QUIET_PROFILE  "cable-64k"

/***********************************************************************************************************************
 * Proxy server settings
 **********************************************************************************************************************/

#define PROXY_SERVER_LISTENING_INTERFACE INTERFACE_LWIP // change this: INTERFACE_NATIVE or INTERFACE_LWIP

// When you use INTERFACE_NATIVE, you use the following settings.
#define PROXY_SERVER_NATIVE_LISTENING_ADDRESS "127.0.0.1"
#define PROXY_SERVER_NATIVE_LISTENING_PORT 1080

// When you use INTERFACE_LWIP, you use the following settings.
#define PROXY_SERVER_LWIP_LISTENING_ADDRESS "192.168.0.8"
#define PROXY_SERVER_LWIP_LISTENING_PORT 1080

// This is a setting for the lwip interface.
// When you use INTERFACE_LWIP, you use the following settings.
#define PROXY_SERVER_LWIP_ADDRESS_U32 0xc0a80008 // 192.168.0.8
#define PROXY_SERVER_LWIP_NETMASK_U32 0xffffff00 // 255.255.255.0
#define PROXY_SERVER_LWIP_GATEWAY_U32 0xc0a80001 // 192.168.0.1
#define PROXY_SERVER_LWIP_MAC (uint8_t[]){0x01, 0x02, 0x03, 0x04, 0x05, 0x06}

// These values are automatically set according to the above settings.
#if PROXY_SERVER_LISTENING_INTERFACE == INTERFACE_NATIVE
#define PROXY_SERVER_LISTENING_ADDRESS PROXY_SERVER_NATIVE_LISTENING_ADDRESS
#define PROXY_SERVER_LISTENING_PORT PROXY_SERVER_NATIVE_LISTENING_PORT
#elif PROXY_SERVER_LISTENING_INTERFACE == INTERFACE_LWIP
#define PROXY_SERVER_LISTENING_ADDRESS PROXY_SERVER_LWIP_LISTENING_ADDRESS
#define PROXY_SERVER_LISTENING_PORT PROXY_SERVER_LWIP_LISTENING_PORT
#else
#error "PROXY_SERVER_LISTENING_INTERFACE must be INTERFACE_NATIVE or INTERFACE_LWIP"
#endif

/***********************************************************************************************************************
 * Proxy client settings
 **********************************************************************************************************************/

// Listening side settings.
#define PROXY_CLIENT_LISTENING_PORT 2160

// Remote(maybe the proxy server?) settings.
#define PROXY_CLIENT_REMOTE_ADDRESS PROXY_SERVER_LISTENING_ADDRESS
#define PROXY_CLIENT_REMOTE_PORT PROXY_SERVER_LISTENING_PORT

// This is a setting for the lwip interface.
#define PROXY_CLIENT_LWIP_ADDRESS_U32 0xc0a80002;   // 192.168.0.2
#define PROXY_CLIENT_LWIP_NETMASK_U32 0xffffff00;  // 255.255.255.0
#define PROXY_CLIENT_LWIP_GATEWAY_U32 0xc0a80001;  // 192.168.0.1
#define PROXY_CLIENT_LWIP_MAC (uint8_t[]){0x01, 0x02, 0x03, 0x04, 0x05, 0x07}

/***********************************************************************************************************************
 * Constants: DO NOT CHANGE
 **********************************************************************************************************************/

#define INTERFACE_NATIVE 1
#define INTERFACE_LWIP 2

#endif //QUIET_PRACTICE_OPT_H
