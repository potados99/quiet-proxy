// .\static-web-server.exe --host 127.0.0.1 --port 20000 --root ./ --directory-listing
function FindProxyForURL(url, host) {
    if (shExpMatch(host, "socket.server.io")) {
        // Requested domain matches, let's use the proxy.
        return "SOCKS5 127.0.0.1:2160";
    }

    return "DIRECT";
}