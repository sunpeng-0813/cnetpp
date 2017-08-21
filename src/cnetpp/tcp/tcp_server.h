// Copyright (c) 2015, myjfm(mwxjmmyjfm@gmail.com).  All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//   * Neither the name of myjfm nor the names of other contributors may be
// used to endorse or promote products derived from this software without
// specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
#ifndef CNETPP_TCP_TCP_SERVER_H_
#define CNETPP_TCP_TCP_SERVER_H_

#include <cnetpp/tcp/event_center.h>
#include <cnetpp/tcp/tcp_callbacks.h>
#include <cnetpp/tcp/tcp_options.h>
#include <cnetpp/base/end_point.h>

#include <memory>
#include <functional>

namespace cnetpp {
namespace tcp {

namespace {
const size_t kDefaultMaxCommandQueueLen = 1024;
}

class TcpServer final {
 public:
  // you must first call this method before you do any requests
  bool Launch(const base::EndPoint& local_address,
              size_t worker_count = 0,
              const TcpServerOptions& options = TcpServerOptions());
  bool Shutdown();

 private:
  std::shared_ptr<EventCenter> event_center_;

  // all callbacks
  ConnectedCallbackType connected_callback_;
  ClosedCallbackType closed_callback_;
  ReceivedCallbackType received_callback_;
  SentCallbackType sent_callback_;
};

}  // namespace tcp
}  // namespace cnetpp

#endif  // CNETPP_TCP_TCP_SERVER_H_
