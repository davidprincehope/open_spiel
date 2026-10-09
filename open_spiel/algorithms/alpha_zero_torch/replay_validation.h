// Shape check for persisted replay data before a resumed learner samples it.
#ifndef OPEN_SPIEL_ALGORITHMS_ALPHA_ZERO_TORCH_REPLAY_VALIDATION_H_
#define OPEN_SPIEL_ALGORITHMS_ALPHA_ZERO_TORCH_REPLAY_VALIDATION_H_

#include <cstddef>
#include <stdexcept>
#include <vector>

namespace open_spiel::algorithms::torch_az {
template <class Example>
void ValidateReplayObservations(const std::vector<Example>& records,
                                size_t expected_size) {
  for (const auto& example : records) {
    if (example.observations.size() != expected_size) {
      throw std::runtime_error(
          "Replay observation shape does not match the current game");
    }
  }
}
}  // namespace open_spiel::algorithms::torch_az

#endif  // OPEN_SPIEL_ALGORITHMS_ALPHA_ZERO_TORCH_REPLAY_VALIDATION_H_
