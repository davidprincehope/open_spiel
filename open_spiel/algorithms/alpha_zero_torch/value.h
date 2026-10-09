// Final self-play return indexed by the player recorded with the position.
#ifndef OPEN_SPIEL_ALGORITHMS_ALPHA_ZERO_TORCH_VALUE_H_
#define OPEN_SPIEL_ALGORITHMS_ALPHA_ZERO_TORCH_VALUE_H_

#include <cstddef>
#include <stdexcept>
#include <vector>

namespace open_spiel::algorithms::torch_az {
inline double PlayerToMoveValueTarget(const std::vector<double>& returns,
                                      int current_player) {
  if (current_player < 0 || static_cast<size_t>(current_player) >= returns.size()) {
    throw std::out_of_range("Invalid self-play player for value target");
  }
  return returns[current_player];
}

inline std::vector<double> PlayerToMoveReturns(double raw_value,
                                                int current_player) {
  if (current_player == 0) return {raw_value, -raw_value};
  if (current_player == 1) return {-raw_value, raw_value};
  throw std::out_of_range("Invalid neural leaf player");
}
}  // namespace open_spiel::algorithms::torch_az

#endif  // OPEN_SPIEL_ALGORITHMS_ALPHA_ZERO_TORCH_VALUE_H_
