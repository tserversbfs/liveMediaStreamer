/*
 *  AVFramedQueueMockup - AVFramedQueue class mockup
 *  Copyright (C) 2014  Fundació i2CAT, Internet i Innovació digital a Catalunya
 *
 *  This file is part of media-streamer.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Authors:    David Cassany <david.cassany@i2cat.net>
 *
 */

#ifndef _AVFRAMED_QUEUE_HH
#define _AVFRAMED_QUEUE_HH

#include "AVFramedQueue.hh"
#include "FrameMockup.hh"
#include "StreamInfo.hh"

class AVFramedQueueMock : public AVFramedQueue
{
public:
    AVFramedQueueMock(struct ConnectionData cData, const StreamInfo *si, unsigned max) :
            AVFramedQueue(cData, si, max) {
        config();
    };

protected:
    virtual bool config() {
        for (unsigned i=0; i<max; i++) {
                frames[i] = FrameMock::createNew(i+1);
        }
        return true;
    }
};


#endif
