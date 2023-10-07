// This is a proxy auto configuration file.
// You can host this file and feed it to your browser.
//
// To host this file on a local server, use this command:
// .\static-web-server.exe --host 127.0.0.1 --port 20000 --root ./ --directory-listing
//
// Note that this is not a system wide configuration.
// Any traffic from the outside of the apps that facilitate Windows's proxy settings
// will be sent to native network interface directly.

function FindProxyForURL(url, host) {
    if (shExpMatch(host, "hub.socket.io")) {
        // Any requests into hub.socket.io will be forwarded to local SOCKS5 proxy.
        // The port 2160 is a default listening port of the proxy_client.
        return "SOCKS5 127.0.0.1:2160";
    }

    return "DIRECT";
}