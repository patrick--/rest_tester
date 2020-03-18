#include "http_utility.h"
#include <algorithm>
#include <array>

namespace http_utility {

bool is_valid_status(const std::string &status) {
  std::array<std::string, 19> codes = {
      "100", "200", "202", "204", "206", "301", "302", "303", "304", "400",
      "401", "403", "404", "413", "414", "415", "416", "417", "504"};

  return std::find(codes.begin(), codes.end(), status) != codes.end();
}

} // namespace http_utility