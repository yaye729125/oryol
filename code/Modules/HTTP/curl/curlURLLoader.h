#pragma once
//------------------------------------------------------------------------------
/**
    @class Oryol::_priv::curlURLLoader
    @ingroup _priv
    @brief urlLoader implementation on top of curl
    @see urlLoader
*/
#include "HTTP/base/baseURLLoader.h"
#include "Core/String/StringBuilder.h"
#include "Core/Containers/Map.h"
#include <mutex>

namespace Oryol {
namespace _priv {

class curlURLLoader : public baseURLLoader {
public:
    /// constructor
    curlURLLoader();
    /// destructor
    ~curlURLLoader();
    /// process enqueued requests
    void doWork();

private:
    /// setup curl session
    void setupCurlSession();
    /// discard the curl session
    void discardCurlSession();
    /// synchronously handle a single request
    void doOneRequest(const Ptr<HTTPProtocol::HTTPRequest>& req);
    /// curl write-data callback
    static size_t curlWriteDataCallback(char* ptr, size_t size, size_t nmemb, void* userData);
    /// curl header-data callback
    static size_t curlHeaderCallback(char* ptr, size_t size, size_t nmenb, void* userData);

    static bool curlInitCalled;
    static std::mutex curlInitMutex;
    const String contentTypeString;
    void* curlSession;
    char* curlError;
    StringBuilder stringBuilder;
    Map<String,String> responseHeaders;
};

} // namespace _priv
} // namespace Oryol
