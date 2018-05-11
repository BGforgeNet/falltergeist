/*
 * Copyright 2012-2018 Falltergeist Developers.
 *
 * This file is part of Falltergeist.
 *
 * Falltergeist is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Falltergeist is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Falltergeist.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FALLTERGEIST_AUDIO_MIXER_H
#define FALLTERGEIST_AUDIO_MIXER_H

// C++ standard includes
#include <cstdint>
#include <string>
#include <map>
#include <unordered_map>

// Falltergeist includes
#include "../Audio/IMixer.h"

// Third party includes
#include <SDL_mixer.h>

namespace Falltergeist
{
    namespace UI {
        class MvePlayer;
    }
    namespace Audio {
        class Sdl2Mixer : public virtual IMixer {
            public:
                Sdl2Mixer();
                virtual ~Sdl2Mixer();
                void playFile(Category category, std::string path, bool repeat = false) override;
                void stop() override;
                void setVolume(Category category, double volume) override;
                double volume(Category category) override;
                void lowerHalfVolume(Category category) override;
                void increaseHalfVolume(Category category) override;
                void pause(Category category) override;
                void resume(Category category) override;

                void playACMSpeech(const std::string& filename);
                void playACMSound(const std::string& filename);
                void playMovieMusic(UI::MvePlayer* mve) override;

        private:
                void playACMMusic(const std::string& filename, bool loop = false);
                void _init();
                void _musicCallback(void* udata, uint8_t* stream, uint32_t len);
                void _speechCallback(void* udata, uint8_t* stream, uint32_t len);
                void _movieCallback(void* udata, uint8_t* stream, uint32_t len);
                std::unordered_map<std::string, Mix_Chunk*> _sfx;

                std::map<IMixer::Category, double> _volumes;
                bool _musicLoop = false;

                SDL_AudioFormat _format;
                std::string _lastMusic = "";
                int channelNumber(Category category);
        };
    }
}
#endif // FALLTERGEIST_AUDIO_MIXER_H
