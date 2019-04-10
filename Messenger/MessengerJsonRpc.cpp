
#include <interfaces/json/JsonData_Messenger.h>
#include "Messenger.h"
#include "Module.h"

namespace WPEFramework {

namespace Plugin {

    using namespace JsonData::Messenger;

    // Registration
    //

    void Messenger::RegisterAll()
    {
        Register<JoinParamsData,JoinResultInfo>(_T("join"), &Messenger::endpoint_join, this);
        Register<JoinResultInfo,void>(_T("leave"), &Messenger::endpoint_leave, this);
        Register<SendParamsData,void>(_T("send"), &Messenger::endpoint_send, this);
    }

    void Messenger::UnregisterAll()
    {
        Unregister(_T("send"));
        Unregister(_T("leave"));
        Unregister(_T("join"));
    }

    // API implementation
    //

    // Joins a messaging room.
    // Return codes:
    //  - ERROR_NONE: Success
    //  - ERROR_ILLEGAL_STATE: User name is already taken (i.e. the user has already joined the room)
    //  - ERROR_BAD_REQUEST: User name or room name was invalid
    uint32_t Messenger::endpoint_join(const JoinParamsData& params, JoinResultInfo& response)
    {
        uint32_t result = Core::ERROR_BAD_REQUEST;
        const string& user = params.User.Value();
        const string& room = params.Room.Value();

        if (!user.empty() && !room.empty()) {
            string roomId = JoinRoom(room, user);
            if (!roomId.empty()) {
                response.Roomid = roomId;
                result = Core::ERROR_NONE;
            }
            else {
                result = Core::ERROR_ILLEGAL_STATE;
            }
        }

        return result;
    }

    // Leaves a messaging room.
    // Return codes:
    //  - ERROR_NONE: Success
    //  - ERROR_UNKNOWN_KEY: The given room ID was invalid
    uint32_t Messenger::endpoint_leave(const JoinResultInfo& params)
    {
        const string& roomid = params.Roomid.Value();

        bool result = LeaveRoom(roomid);

        return result? Core::ERROR_NONE : Core::ERROR_UNKNOWN_KEY;
    }

    // Sends a message to a room.
    // Return codes:
    //  - ERROR_NONE: Success
    //  - ERROR_UNKNOWN_KEY: The given room ID was invalid
    uint32_t Messenger::endpoint_send(const SendParamsData& params)
    {
        const string& roomid = params.Roomid.Value();
        const string& message = params.Message.Value();

        bool result = SendMessage(roomid, message);

        return result? Core::ERROR_NONE : Core::ERROR_UNKNOWN_KEY;
    }

    // Notifies about room status updates.
    void Messenger::event_roomupdate(const string& room, const RoomupdateParamsData::ActionType& action)
    {
        RoomupdateParamsData params;
        params.Room = room;
        params.Action = action;

        Notify(_T("roomupdate"), params);
    }

    // Notifies about user status updates.
    void Messenger::event_userupdate(const string& id, const string& user, const UserupdateParamsData::ActionType& action)
    {
        UserupdateParamsData params;
        params.User = user;
        params.Action = action;

        Notify(_T("userupdate"), params, [&](const string& designator) -> bool {
            const string designator_id = designator.substr(0, designator.find('.'));
            return (id == designator_id);
        });
    }

    // Notifies about new messages in a room.
    void Messenger::event_message(const string& id, const string& user, const string& message)
    {
        MessageParamsData params;
        params.User = user;
        params.Message = message;

        Notify(_T("message"), params, [&](const string& designator) -> bool {
            const string designator_id = designator.substr(0, designator.find('.'));
            return (id == designator_id);
        });
    }

} // namespace Plugin

}

