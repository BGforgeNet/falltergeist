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

#ifndef FALLTERGEIST_AUDIO_IMIXER_H
#define FALLTERGEIST_AUDIO_IMIXER_H

// C++ standard includes
#include <string>

// Falltergeist includes

// Third party includes

namespace Falltergeist {
    namespace UI {
        class MvePlayer;
    }
    namespace Audio {
        class IMixer {
        public:
            enum class Category {
                SPEECH,
                SFX,
                MUSIC
            };

            virtual ~IMixer() = default;
            virtual void playFile(Category category, std::string path, bool repeat = false) = 0;

            /**
             * @brief Sets volume of music
             * @param category MUSIC, SFX, SPEECH
             * @param volume from 0.0 to 1.0
             */
            virtual void setVolume(Category category, double volume) = 0;
            virtual double volume(Category category) = 0;
            virtual void lowerHalfVolume(Category category) = 0;
            virtual void increaseHalfVolume(Category category) = 0;
            virtual void stop() = 0;
            virtual void pause(Category category) = 0;
            virtual void resume(Category category) = 0;
            virtual void playMovieMusic(UI::MvePlayer* mve) = 0;
        };
    }
}

#endif //FALLTERGEIST_AUDIO_IMIXER_H
