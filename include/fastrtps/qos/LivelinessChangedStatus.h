// Copyright 2019 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file LivelinessChangedStatus.h
*/

#ifndef _LIVELINESS_CHANGED_STATUS_H_
#define _LIVELINESS_CHANGED_STATUS_H_

#include <fastrtps/rtps/common/InstanceHandle.h>

namespace eprosima {
namespace fastrtps {

//! @brief A struct storing the liveliness changed status
struct LivelinessChangedStatus
{
    //! @brief Constructor
    LivelinessChangedStatus()
        : alive_count()
        , not_alive_count()
        , alive_count_change()
        , not_alive_count_change()
        , last_publication_handle()
    {}

    //! @brief Destructor
    ~LivelinessChangedStatus()
    {}

    //! @brief The total number of currently active publishers that write the topic read by the subscriber
    //! @details This count increases when a newly matched publisher asserts its liveliness for the first time
    //! or when a publisher previously considered to be not alive reasserts its liveliness. The count decreases
    //! when a publisher considered alive fails to assert its liveliness and becomes not alive, whether because
    //! it was deleted normally or for some other reason
    uint32_t alive_count;

    //! @brief The total count of current publishers that write the topic read by the subscriber that are no longer
    //! asserting their liveliness
    //! @details This count increases when a publisher considered alive fails to assert its liveliness and becomes
    //! not alive for some reason other than the normal deletion of that publisher. It decreases when a previously
    //! not alive publisher either reasserts its liveliness or is deleted normally
    uint32_t not_alive_count;

    //! @brief The change in the alive_count since the last time the listener was called or the status was read
    uint32_t alive_count_change;

    //! @brief The change in the not_alive_count since the last time the listener was called or the status was read
    uint32_t not_alive_count_change;

    //! @brief Handle to the last publisher whose change in liveliness caused this status to change
    rtps::InstanceHandle_t last_publication_handle;
};

typedef LivelinessChangedStatus OfferedLivelinessChangedStatus;
typedef LivelinessChangedStatus RequestedLivelinessChangedStatus;

} //end of namespace
} //end of namespace eprosima

#endif /* _LIVELINESS_CHANGED_STATUS_H_ */
