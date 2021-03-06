#include "protocol.h"
#include "exceptions/malformed_components.h"

const std::string protocol::HTTP_BEGIN = "HTTP/";

protocol protocol::parse(const std::string& str)
{
    protocol p;

    std::string version = str.substr(HTTP_BEGIN.length());

    if (version.length() != 3 || version[1] != '.')
        throw malformed_protocol();

    p.v_major = atoi(version.substr(0, 1).c_str());
    p.v_minor = atoi(version.substr(2, 1).c_str());

    return p;
}

std::string protocol::to_string() const
{
    return HTTP_BEGIN + std::to_string(v_major) + "." + std::to_string(v_minor);
}
