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

// Related headers
#include "../../VM/Handler/Opcode80BEHandler.h"

// C++ standard includes

// Falltergeist includes
#include "../../Logger.h"
#include "../../VM/Script.h"

// Third party includes

namespace Falltergeist {
    namespace VM {
        namespace Handler {
            Opcode80BE::Opcode80BE(std::shared_ptr<VM::Script> script) : OpcodeHandler(script) {
            }

            void Opcode80BE::_run() {
                Logger::debug("SCRIPT") << "[80BE/80C0] [=] object target_obj/obj_being_used_with()" << std::endl;
                _script->dataStack()->push(_script->targetObject());
            }
        }
    }
}
