#include <drogon/drogon.h>

auto main() -> int
{
  const auto http_port = 80;
  const auto num_threads = 16;

  drogon::app()
      .setLogPath("./")
      .setLogLevel(trantor::Logger::kWarn)
      .addListener("0.0.0.0", http_port)
      .setThreadNum(num_threads)
      .enableRunAsDaemon()
      .run();
}
