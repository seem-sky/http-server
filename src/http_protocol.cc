#include "http_protocol.h"
#include "exceptions/malformed_components.h"

const std::string http_protocol::HTTP_BEGIN = "HTTP/";

http_protocol http_protocol::parse(const std::string& str)
{
    http_protocol p;

    auto pos = str.find(HTTP_BEGIN) + HTTP_BEGIN.length();
    std::string version = str.substr(HTTP_BEGIN.length());

    if (version.length() != 3 || version[1] != '.')
        throw malformed_protocol();

    p.v_major = atoi(version.substr(0, 1).c_str());
    p.v_minor = atoi(version.substr(2, 1).c_str());

    return p;
}