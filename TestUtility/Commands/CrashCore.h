#pragma once

#include "../Module.h"

#include "../CommandCore/TraceCategories.h"
#include <fstream>

namespace WPEFramework {

class CrashCore {
private:
    CrashCore(const CrashCore&) = delete;
    CrashCore& operator=(const CrashCore&) = delete;

public:
    static constexpr const uint8_t DefaultCrashDelay = 3;
    static constexpr const char* PendingCrashFilepath = "/tmp/CrashCore.pending";

public:
    // ToDo: maybe error response should be generic and moved to TestCore
    class ErrorRes : public Core::JSON::Container {
    private:
        ErrorRes(const ErrorRes&) = delete;
        ErrorRes& operator=(const ErrorRes&) = delete;

    public:
        ErrorRes()
            : Core::JSON::Container()
            , ErrorMsg()
        {
            Add(_T("errorMsg"), &ErrorMsg);
        }

        ~ErrorRes() = default;

    public:
        Core::JSON::String ErrorMsg;
    };

public:
    CrashCore() = default;
    virtual ~CrashCore() = default;

    static CrashCore& Instance()
    {
        static CrashCore _singleton;
        return (_singleton);
    }

    string Crash(const uint8_t crashDelay)
    {
        string response = EMPTY_STRING;

        TRACE(TestCore::TestOutput, (_T("Executing crash in %d seconds"), crashDelay));
        sleep(crashDelay);

        uint8_t* tmp = nullptr;
        *tmp = 3; // segmentaion fault

        response = _T("Function should never return");

        return response;
    }

    string CrashNTimes(const uint8_t crashCount)
    {
        string response = EMPTY_STRING;

        uint8_t pendingCrashCount = PendingCrashCount();
        if (pendingCrashCount != 0)
        {
            response = _T("Pending crash already in progress");
        }
        else
        {
            if (!SetPendingCrashCount(crashCount))
            {
                response = _T("Failed to set new pending crash count");
            }
            else
            {
                ExecPendingCrash();
            }
        }

        return response;
    }

    void ExecPendingCrash(void)
    {
        uint8_t pendingCrashCount = PendingCrashCount();
        if (pendingCrashCount > 0)
        {
            pendingCrashCount--;
            if (SetPendingCrashCount(pendingCrashCount))
            {
                Crash(DefaultCrashDelay);
            }
            else
            {
                TRACE(TestCore::TestOutput, (_T("Failed to set new pending crash count")));
            }
        }
        else
        {
            TRACE(TestCore::TestOutput, (_T("No pending crash")));
        }
    }

    // ToDo: maybe error response should be generic and moved to TestCore
    string ErrorResponse(const string& message)
    {
        ErrorRes responseJSON;
        string responseString = _T("");

        if (!message.empty())
        {
            responseJSON.ErrorMsg = message;
            responseJSON.ToString(responseString);
        }

        return responseString;
    }

private:
    uint8_t PendingCrashCount(void)
    {
        uint8_t pendingCrashCount = 0;
        std::ifstream pendingCrashFile;
        pendingCrashFile.open(PendingCrashFilepath, std::fstream::binary);

        if (pendingCrashFile.is_open())
        {
            uint8_t readVal = 0;

            pendingCrashFile >> readVal;
            if (pendingCrashFile.good())
            {
                pendingCrashCount = readVal;
            }
            else
            {
                TRACE(TestCore::TestOutput, (_T("Failed to read value from pendingCrashFile")));
            }
        }
        return pendingCrashCount;
    }

    bool SetPendingCrashCount(const uint8_t newCrashCount)
    {
        bool status = false;
        std::ofstream pendingCrashFile;
        pendingCrashFile.open(PendingCrashFilepath, std::fstream::binary | std::fstream::trunc);

        if (pendingCrashFile.is_open())
        {
            pendingCrashFile << newCrashCount;

            if (pendingCrashFile.good())
            {
                status = true;
            }
            else
            {
                TRACE(TestCore::TestOutput, (_T("Failed to write value to pendingCrashFile ")));
            }
            pendingCrashFile.close();
        }

        return status;
    }
};

} // namespace WPEFramework
