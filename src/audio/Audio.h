#pragma once

#include <string>
#include <memory>
#include <vector>
#include "audio/AudioPlayer.h"

namespace LUS {
enum class AudioBackend { WASAPI, PULSE, SDL };

class Audio {
  public:
    void Init();
    std::shared_ptr<AudioPlayer> GetAudioPlayer();
    AudioBackend GetAudioBackend();
    std::shared_ptr<std::vector<AudioBackend>> GetAvailableAudioBackends();
    void SetAudioBackend(AudioBackend backend);

  protected:
    static AudioBackend DetermineAudioBackendFromConfig();
    static std::string DetermineAudioBackendNameFromBackend(AudioBackend backend);

  private:
    std::shared_ptr<AudioPlayer> mAudioPlayer;
    AudioBackend mAudioBackend;
    std::shared_ptr<std::vector<AudioBackend>> mAvailableAudioBackends;
};
} // namespace LUS
